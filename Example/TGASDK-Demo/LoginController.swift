//
//  LoginController.swift
//  Created on 2022/9/22
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 WZLY. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit
import TGASDK


/// MARK - 登陆控制器
final class LoginController: UIViewController {

    /// 完成回调
    internal var completion: ((TGAUserInfo) -> Void)? = nil
    
    private lazy var leftView: UIView = {
        $0.bounds = CGRect(x: 0, y: 0, width: 10, height: 0)
        return $0
    }(UIView())
    
    /// 输入框
    private lazy var textField: UITextField = {
        $0.layer.borderWidth = 1
        $0.placeholder = "模拟登陆，请直接复制authCode进文本框，然后确定"
        $0.layer.borderColor = UIColor.red.cgColor
        $0.layer.cornerRadius = 4
        $0.layer.masksToBounds = true
        $0.textColor = UIColor.red
        $0.leftViewMode = .always
        $0.leftView = self.leftView
        $0.font = UIFont.systemFont(ofSize: 16)
        $0.translatesAutoresizingMaskIntoConstraints = false
        return $0
    }(UITextField())
    
    /// 确定按钮
    private lazy var button: UIButton = {
        $0.layer.cornerRadius = 4
        $0.layer.masksToBounds = true
        $0.setTitle("确定", for: UIControl.State.normal)
        $0.setTitleColor(UIColor.white, for: UIControl.State.normal)
        $0.backgroundColor = UIColor.red
        $0.translatesAutoresizingMaskIntoConstraints = false
        $0.addTarget(self, action: #selector(eventForConfirm), for: UIControl.Event.touchUpInside)
        return $0
    }(UIButton(type: .custom))
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = UIColor.white
        navigationItem.title = "登录控制器"
        view.addSubview(textField)
        view.addSubview(button)
        NSLayoutConstraint.activate([
            textField.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 4),
            textField.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -4),
            textField.topAnchor.constraint(equalTo: view.topAnchor, constant: 100),
            textField.heightAnchor.constraint(equalToConstant: 50),
            
            button.leadingAnchor.constraint(equalTo: textField.leadingAnchor),
            button.trailingAnchor.constraint(equalTo: textField.trailingAnchor),
            button.topAnchor.constraint(equalTo: textField.bottomAnchor, constant: 20),
            button.heightAnchor.constraint(equalToConstant: 44),
        ])
    }
    
    @objc private func eventForConfirm() {
        let userInfo = TGAUserInfo()
        userInfo.userId = textField.text ?? ""
        userInfo.nickname = "测试"
        userInfo.avatar = ""
        completion?(userInfo)
        WZRoute.dismiss()
    }
}
