//
//  TableViewCell.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit
import TGASDK

public class NavigationBarCell: UITableViewCell {

    /// 状态改变回调
    public var changedCallback: ((Bool) -> Void)? = nil
    
    
    /// 导航栏开关
    public lazy var navigationSwitch: UISwitch = {
        $0.bounds = CGRect(x: 0, y: 0, width: 100, height: 44)
        $0.addTarget(self, action: #selector(eventForChanged(_:)), for: UIControl.Event.valueChanged)
        return $0
    }(UISwitch())
    
    public override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        contentView.addSubview(navigationSwitch)
        accessoryView = navigationSwitch
    }
    
    
    @objc private func eventForChanged(_ sender: UISwitch) {
        changedCallback?(sender.isOn)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}


/// MARK - TableViewCell
public class TableViewCell: UITableViewCell {
    
    public override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: .value1, reuseIdentifier: reuseIdentifier)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
