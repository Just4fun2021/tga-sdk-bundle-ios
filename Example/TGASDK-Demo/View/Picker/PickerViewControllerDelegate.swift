//
//  PickerViewControllerDelegate.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit


/// MARK - PickerViewControllerDelegate
public protocol PickerViewControllerDelegate: NSObjectProtocol {
    
    /// 选中索引
    ///
    /// - Parameters:
    ///   - contentView: contentView description
    ///   - row: row description
    ///   - component: component description
    func pickerContentView(_ contentView: PickerViewController, didSelectRow row: Int, inComponent component: Int)
    
    /// 确定
    ///
    /// - Parameter contentView: contentView description
    func pickerConfim(_ contentView: PickerViewController)
    
    /// 取消
    ///
    /// - Parameter contentView: contentView description
    func pickerCancel(_ contentView: PickerViewController)
}

