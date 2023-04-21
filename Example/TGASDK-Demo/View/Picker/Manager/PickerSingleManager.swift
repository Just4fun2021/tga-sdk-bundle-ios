//
//  PickerSingleManager.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit
import Foundation

/// MARK - 选择器单选管理类
final class PickerSingleManager: NSObject {
    
    /// 取消CancelHandler
    public typealias CancelHandler = (_ contentView: PickerViewController) -> Void
    
    /// 确定ConfirmHandler
    public typealias ConfirmHandler = (_ contentView: PickerViewController, _ result: PickerDataObject) -> Void
    
    /// 取消回掉
    public var cancelCallBack: CancelHandler?
    
    /// 确定回掉
    public var confirmCallBack: ConfirmHandler?
    
    /// 选择索引
    public var selectIndex: Int = 0
    
    /// 类型
    private let type: PickerSingleType
    
    /// 头部标题
    public var headerTitle: String
    
    /// 数据源
    private let dataSource: [PickerDataObject]
    
    /// 初始化
    /// - Parameter type:
    init(type: PickerSingleType) {
        self.type = type
        self.headerTitle = self.type.title
        self.dataSource = self.type.dataSource
        super.init()
    }
    
    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}

// MARK: - PickerViewControllerDataSource
extension PickerSingleManager: PickerViewControllerDataSource {
    
    var title: NSAttributedString? {
        
        return NSAttributedString(string: headerTitle, attributes: [NSAttributedString.Key.font : UIFont.boldSystemFont(ofSize: 16),
                                                                    NSAttributedString.Key.foregroundColor: UIColor.black])
    }
    
    var unitAttributedText: NSAttributedString? {
        return nil
    }
    
    func pickerDefaultSelected(_ contentView: PickerViewController) {
        contentView.selectRow(selectIndex, inComponent: 0, animated: true)
    }
    
    func numberOfComponents(in contentView: PickerViewController) -> Int {
        return 1
    }
    
    func pickerContentView(_ contentView: PickerViewController, numberOfRowsInComponent component: Int) -> Int {
        return dataSource.count
    }
    
    func pickerContentView(_ contentView: PickerViewController, titleForRow row: Int, forComponent component: Int) -> String {
        return dataSource[row].title
    }
    
    func pickerContentView(_ contentView: PickerViewController, widthForComponent component: Int) -> CGFloat {
        return UIScreen.main.bounds.width
    }
}


// MARK: - PickerViewControllerDelegate
extension PickerSingleManager: PickerViewControllerDelegate {
    
    func pickerContentView(_ contentView: PickerViewController, didSelectRow row: Int, inComponent component: Int) {
        selectIndex = row
    }
    
    func pickerConfim(_ contentView: PickerViewController) {
        confirmCallBack?(contentView, dataSource[selectIndex])
    }
    
    func pickerCancel(_ contentView: PickerViewController) {
        cancelCallBack?(contentView)
    }
}


