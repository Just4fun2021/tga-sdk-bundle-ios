//
//  Enum.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import Foundation

/// MARK - 分组
public enum Section: Int, Equatable, CaseIterable {
    case config = 0
    case initTGA
    case openGame

    
    public var name: String {
        switch self {
        case .config:
            return "配置"
        case .initTGA:
            return "初始化"
        case .openGame:
            return "游戏中心"
        }
    }
}

/// MARK - 配置行枚举
public enum ConfigRow: Int, CaseIterable {
    
    case lang
    case theme
    
    public var name: String {
        switch self {
        case .lang:
            return "语言"
        case .theme:
            return "主题"
        }
    }
}

/// MARK - InitTGASDK
public enum InitTGASDK: Int, CaseIterable {
    case initSdk
    
    public var name: String {
        switch self {
        case .initSdk:
            return "初始化SDK"
        }
    }
}

/// MARK - GameCenter
public enum GameCenter: Int, CaseIterable {
    
    case openGame
    case openSec
    
    public var name: String {
        switch self {
        case .openGame:
            return "打开游戏中心"
        case .openSec:
            return "打开游戏中心(二级页面)"
        }
    }
}
