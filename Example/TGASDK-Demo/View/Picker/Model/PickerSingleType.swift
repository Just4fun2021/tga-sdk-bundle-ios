//
//  PickerSingleType.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import Foundation


/// MARK - WebThemeColor
public enum WebThemeColor: String, CaseIterable {
    case regular = "regular"
    case lavender = "lavender"
    case orange = "orange"
    case dark = "dark"
    case nightBlue = "night-blue"
    case darkBlue = "dark-blue"
    case gnc = "gnc"
    
    public var value: String {
        switch self {
        case .regular:
            return "#03A9F4"
        case .lavender:
            return "#9879D0"
        case .orange:
            return "#FA9C2A"
        case .dark:
            return "#OFOD14"
        case .nightBlue:
            return "#213042"
        case .darkBlue:
            return "#12172A"
        case .gnc:
            return "#000054"
        }
    }
}

/// MARK - LangEnum
public enum LangEnum: String, CaseIterable {
    case zh
    case en
    case tr
    case ja
    
    public var value: String {
        switch self {
        case .zh:
            return "中文"
        case .en:
            return "英文"
        case .tr:
            return "土耳其"
        case .ja:
            return "日语"
        }
    }
}

/// MARK - NavitaionBarColor
public enum NavitaionBarColor: String, CaseIterable {
    case 蓝色
    case 黑色
    case 黄色
    case 浅灰蓝色
    case 品蓝
    case 橙色
    case 马棕色
    case 红色
    
    public var value: String {
        switch self {
        case .蓝色:
            return "#0000FF"
        case .黑色:
            return "#000000"
        case .黄色:
            return "#FFFF00"
        case .浅灰蓝色:
            return "#B0E0E6"
        case .品蓝:
            return "#4169E1"
        case .橙色:
            return "#FF6100"
        case .马棕色:
            return "#8B4513"
        case .红色:
            return "#FF0000"
        }
    }
}

/// MARK - PickerSingleType
public enum PickerSingleType {
    case webTheme
    case lang
    case navitaionBarColor
    
    /// 数据源
    public var dataSource: [PickerModelProtocol] {
        switch self {
        case .webTheme:
            return WebThemeColor.allCases.map { PickerModel(id: $0.rawValue, name: "\($0.rawValue)(\($0.value))") }
        case .lang:
            return LangEnum.allCases.map { PickerModel(id: $0.rawValue, name: "\($0.rawValue)(\($0.value))") }
        case .navitaionBarColor:
            return NavitaionBarColor.allCases.map { PickerModel(id: $0.value, name: "\($0.rawValue)") }
        }
    }
    
    
    /// 标题
    public var title: String {
        switch self {
        case .webTheme:
            return "请选择网页主题颜色"
        case .lang:
            return "请选择语言"
        case .navitaionBarColor:
            return "请选择导航栏颜色"
        }
    }
}
