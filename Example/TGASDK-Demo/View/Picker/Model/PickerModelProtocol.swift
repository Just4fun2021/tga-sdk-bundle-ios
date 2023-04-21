//
//  PickerModelProtocol.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import Foundation

/// MARK - PickerModelProtocol
public protocol PickerModelProtocol {
    
    /// 唯一标识符
    var uuid: String { get }
    
    /// 标题
    var title: String { get }
}

/// 默认实体
public struct PickerModel {
    
    /// id
    let id: String

    /// 名称
    let name: String
    
    init(id: String, name: String) {
        self.id = id
        self.name = name
    }
}

extension PickerModel: PickerModelProtocol {
    
    public var uuid: String {
        return "\(id)"
    }
    
    public var title: String {
        return name
    }
}
