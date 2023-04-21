//
//  PickerViewControllerDataSource.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit

/// MARK - PickerViewControllerDataSource
public protocol PickerViewControllerDataSource: NSObjectProtocol {
    
    /// 标题
    var title: NSAttributedString? { get }
    
    /// 选中的富文本
    var selectedAttributes: [NSAttributedString.Key : Any]? { get }
    
    /// 单位富文本
    var unitAttributedText: NSAttributedString? { get }
    
    /// 默认选择
    ///
    /// - Parameter contentView: contentView description
    /// - Returns: return value description
    func pickerDefaultSelected(_ contentView: PickerViewController)
    
    /// 多少列
    ///
    /// - Parameter contentView: contentView description
    /// - Returns: return value description
    func numberOfComponents(in contentView: PickerViewController) -> Int
    
    /// 每列多少个
    ///
    /// - Parameters:
    ///   - contentView: contentView description
    ///   - component: component description
    /// - Returns: return value description
    func pickerContentView(_ contentView: PickerViewController, numberOfRowsInComponent component: Int) -> Int

    
    /// 每列宽度是多少
    ///
    /// - Parameters:
    ///   - pickerView: pickerView description
    ///   - component: component description
    /// - Returns: return value description
    func pickerContentView(_ contentView: PickerViewController, widthForComponent component: Int) -> CGFloat
    
    
    /// 每列高度是多少
    ///
    /// - Parameters:
    ///   - pickerView: pickerView description
    ///   - component: component description
    /// - Returns: return value description
    func pickerContentView(_ contentView: PickerViewController, rowHeightForComponent component: Int) -> CGFloat
    
    
    /// 每一列展示的内容
    ///
    /// - Parameters:
    ///   - contentView: contentView description
    ///   - row: row description
    ///   - component: component description
    /// - Returns: return value description
    func pickerContentView(_ contentView: PickerViewController, titleForRow row: Int, forComponent component: Int) -> String
    
    
    /// 单位偏移量
    ///
    /// - Parameters:
    ///   - contentView: contentView description
    ///   - component: component description
    /// - Returns: return value description
    func pickerContentView(_ contentView: PickerViewController, unitOffsetForComponent component: Int) -> CGFloat
}



// MARK: - 默认实现
extension PickerViewControllerDataSource {
    
    var title: NSAttributedString? {
        return nil
    }
    
    var unitAttributedText: NSAttributedString? {
        return nil
    }
    
    var selectedAttributes: [NSAttributedString.Key : Any]? {
        return [.font: UIFont.systemFont(ofSize: 22, weight: .medium), .foregroundColor: UIColor.black]
    }
    
    func pickerDefaultSelected(_ contentView: PickerViewController) {
        
    }
    
    func pickerContentView(_ contentView: PickerViewController, widthForComponent component: Int) -> CGFloat {
        return 300
    }
    
    func pickerContentView(_ contentView: PickerViewController, rowHeightForComponent component: Int) -> CGFloat {
        return 40
    }
    
    func pickerContentView(_ contentView: PickerViewController, unitOffsetForComponent component: Int) -> CGFloat {
        return 0
    }
}


