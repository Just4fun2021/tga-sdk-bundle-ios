//
//  ViewController.swift
//  Created on 2022/9/6
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)
//

import UIKit
import TGASDK
import AppLovinSDK

/// MARK - TGA演示控制器
final class ViewController: UIViewController, TGAEventDelegate {
    
    /// 列表
    private lazy var tableView: UITableView = {
        $0.rowHeight = 50
        $0.dataSource = self
        $0.delegate = self
        $0.tableFooterView = UIView()
        $0.register(TableViewCell.self, forCellReuseIdentifier: "TableViewCell")
        $0.register(NavigationBarCell.self, forCellReuseIdentifier: "NavigationBarCell")
        $0.translatesAutoresizingMaskIntoConstraints = false
        return $0
    }(UITableView(frame: CGRect.zero, style: UITableView.Style.grouped))
    
    /// 网页状态栏颜色
    private var statusBarColor: PickerModel?
    
    /// 主题
    private var theme: String = "regular"
    private var themePickerModel: PickerModel?
    
    /// 状态
    private var initStatus: String = "未初始化"
    
    /// 是否点击了打开游戏中心
    private var isChick: Bool = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.navigationItem.title = "TGA测试集合"
        TGASdk.shared.setLogLevel(level: .all)
        view.backgroundColor = UIColor.white
        view.addSubview(tableView)
        NSLayoutConstraint.activate([
            tableView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            tableView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            tableView.topAnchor.constraint(equalTo: view.topAnchor),
            tableView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
        ])
//        TGASdk.shared.configuration.lang = "ja"
//        let key = "test"
//        var dict = [String: [String]]()
//        if dict[key] == nil {
//            dict[key] = [String]()
//        }
//        let list = dict[key]
//        withUnsafePointer(to: list) { pointer in
//            print("The memory address of list is: \(pointer)")
//        }
//
//        withUnsafePointer(to: dict[key]) { pointer in
//            print("The memory address of dict is: \(pointer)")
//        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func onEvent(type: String, param: Any?) {
        
    }
}


/// MARK - UITableViewDataSource
extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return Section.allCases.sorted { $0.rawValue < $1.rawValue }[section].name
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return Section.allCases.count
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        switch Section.allCases[section] {
        case .config:
            return ConfigRow.allCases.count
        case .initTGA:
            return InitTGASDK.allCases.count
        case .openGame:
            return GameCenter.allCases.count
//        case .webTest:
//            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        switch Section.allCases[indexPath.section] {
        case .config:
            return configTableView(tableView, cellForRowAt: indexPath)
        case .initTGA:
            return sdkInitTableView(tableView, cellForRowAt: indexPath)
        case .openGame:
            return openGameTableView(tableView, cellForRowAt: indexPath)
        }
    }
    
    // 配置
    func configTableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        
        switch ConfigRow.allCases[indexPath.row] {
        case .theme:
            let cell = tableView.dequeueReusableCell(withIdentifier: "TableViewCell", for: indexPath)
            cell.textLabel?.textColor = UIColor.black
            cell.textLabel?.text = ConfigRow.allCases[indexPath.row].name
            cell.detailTextLabel?.text = self.theme
            cell.detailTextLabel?.font = UIFont.boldSystemFont(ofSize: 18)
            cell.accessoryType = .disclosureIndicator
            return cell
        case .lang:
            let cell = tableView.dequeueReusableCell(withIdentifier: "TableViewCell", for: indexPath)
            cell.textLabel?.textColor = UIColor.black
            cell.textLabel?.text = ConfigRow.allCases[indexPath.row].name
            cell.detailTextLabel?.text = "\(TGASdk.shared.configuration.lang)(\(LangEnum(rawValue: TGASdk.shared.configuration.lang)!.value))"
            cell.detailTextLabel?.font = UIFont.boldSystemFont(ofSize: 18)
            cell.accessoryType = .disclosureIndicator
            return cell
        }
    }
    
    // 初始化
    func sdkInitTableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
       
        let cell = tableView.dequeueReusableCell(withIdentifier: "TableViewCell", for: indexPath)
        cell.textLabel?.text = InitTGASDK.allCases[indexPath.row].name
        cell.detailTextLabel?.text = initStatus
        cell.detailTextLabel?.textColor = UIColor.red
        cell.detailTextLabel?.font = UIFont.boldSystemFont(ofSize: 18)
        cell.accessoryType = .none
        return cell
    }
    
    // 游戏中心
    func openGameTableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        switch GameCenter.allCases[indexPath.row] {
        case .openGame:
            let cell = tableView.dequeueReusableCell(withIdentifier: "TableViewCell", for: indexPath)
            cell.textLabel?.text = GameCenter.allCases[indexPath.row].name
            cell.accessoryType = .disclosureIndicator
            
            if isChick == true && self.initStatus != "初始化成功" {
                cell.detailTextLabel?.text = "SDK未初始化"
                cell.detailTextLabel?.textColor = UIColor.red
                cell.detailTextLabel?.font = UIFont.boldSystemFont(ofSize: 18)
            } else {
                cell.detailTextLabel?.text = ""
            }
            return cell
        case .openSec:
            let cell = tableView.dequeueReusableCell(withIdentifier: "TableViewCell", for: indexPath)
            cell.textLabel?.text = GameCenter.allCases[indexPath.row].name
            cell.accessoryType = .disclosureIndicator
            
            if isChick == true && self.initStatus != "初始化成功" {
                cell.detailTextLabel?.text = "SDK未初始化"
                cell.detailTextLabel?.textColor = UIColor.red
                cell.detailTextLabel?.font = UIFont.boldSystemFont(ofSize: 18)
            } else {
                cell.detailTextLabel?.text = ""
            }
            return cell
        }
    }
}

/// MARK - UITableViewDelegate
extension ViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        switch Section.allCases[indexPath.section] {
        case .config:
            configSelectTableView(tableView, didSelectRowAt: indexPath)
        case .initTGA:
            self.initStatus = "初始化中..."
            tableView.reloadRows(at: [indexPath], with: UITableView.RowAnimation.none)
            let userInfo = TGAUserInfo()
            userInfo.userId = "11"
            userInfo.nickname = "123"
            userInfo.avatar = ""
            TGASdk.shared.initSdk(env: "", appKey: "c7dd39bedb1711eba8290212f3e42114", userInfo: userInfo, delegate: self)
        case .openGame:
            gameCenterSelectTableView(tableView, didSelectRowAt: indexPath)
//        case .webTest:
//            TGASDK.shared.openWebTest()
//            tableView.deselectRow(at: indexPath, animated: true)
        }
    }
    
    /// 配置选择
    func configSelectTableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch ConfigRow.allCases[indexPath.row] {
        case .theme:
            
            PickerManager.showSingle(type: .webTheme, selected: PickerModel(id: self.theme, name: "")) { result in
                guard let temResult = result else { return }
                self.themePickerModel = temResult
                self.theme = temResult.id
                tableView.reloadRows(at: [indexPath], with: UITableView.RowAnimation.none)
            }
            
        case .lang:
            
            PickerManager.showSingle(type: .lang, selected: PickerModel(id: TGASdk.shared.configuration.lang, name: "")) { result in
                guard let temResult = result else { return }
                TGASdk.shared.configuration.lang = temResult.id
                tableView.reloadRows(at: [indexPath], with: UITableView.RowAnimation.none)
            }
        }
        tableView.deselectRow(at: indexPath, animated: true)
    }
    
    func gameCenterSelectTableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        switch GameCenter.allCases[indexPath.row] {
        case .openGame:
            if initStatus == "初始化成功" {
                TGASdk.shared.openGameCenter(vc: self, secUrl: "", theme: theme)
                isChick = false
            } else {
                isChick = true
                navigationController?.view.shake()
            }
            tableView.reloadRows(at: [indexPath], with: UITableView.RowAnimation.none)
        case .openSec:
            if initStatus == "初始化成功" {
                TGASdk.shared.openGameCenter(vc: self, secUrl: "https://data.just4fun.sg/kule-h5-tool/tool.html", secTitle: "二级页面的标题", theme: theme)
                isChick = false
            } else {
                isChick = true
                navigationController?.view.shake()
            }
            
            tableView.reloadRows(at: [indexPath], with: UITableView.RowAnimation.none)
        }
        tableView.deselectRow(at: indexPath, animated: true)
    }
}


/// MARK - TGASDKDelegate
extension ViewController: TGASdkDelegate {

    func tgaSdkInitSucceed() {
        self.initStatus = "初始化成功"
        tableView.reloadData()
    }
    
    func tgaSdkInitError(_ error: NSError) {
        self.initStatus = "初始化失败\(error.localizedDescription)"
        tableView.reloadData()
    }
    
    func tgaSdkGetUserInfo(completion: @escaping ((TGAUserInfo?) -> Void)) {
//        let userController = LoginController()
//        userController.completion = completion
//        let na = UINavigationController(rootViewController: userController)
//        na.modalPresentationStyle = .fullScreen
//        WZRoute.present(na, animated: true)
        let user = TGAUserInfo()
        user.avatar = "11"
        user.nickname = "222"
        user.userId = "333"
        completion(user)
    }
    
    func tgaSdkOnLogout() {
        debugPrint("登出")
    }
    
    func tgaSdkCloseGameCenter() {
        debugPrint("关闭游戏中心回调")
    }
    
    func tgaOnInAppShare(fromVC: UIViewController, shareInfo: TGAShareInfo, completion: @escaping ((String, Bool) -> Void))
    {
        completion(shareInfo.callbackId, true)
        TGASdk.shared.openGameCenter(vc: fromVC, secUrl: shareInfo.link, secTitle: shareInfo.title)
    }
}
