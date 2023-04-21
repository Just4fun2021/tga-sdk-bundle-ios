//
//  PickerViewController.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//

import UIKit
import XBDialog
import XBPickerView

/// 协议
public typealias PickerViewProtocol = PickerViewControllerDataSource & PickerViewControllerDelegate

/// MARK - 选择器
public class PickerViewController: UIViewController {

    /// 动画
    private var presentAnimator: XBPresentAnimator!
    
    /// 头部视图
    private lazy var headerView: PickerHeaderView = {
        let temHeaderView = PickerHeaderView()
        temHeaderView.backgroundColor = UIColor.white
        temHeaderView.delegate = self
        temHeaderView.translatesAutoresizingMaskIntoConstraints = false
        return temHeaderView
    }()
    
    /// pickerView
    private lazy var pickerView: PickerView = {
        let temPickerView = PickerView()
        temPickerView.backgroundColor = UIColor.white
        temPickerView.dataSource = self
        temPickerView.delegate = self
        temPickerView.lineColor = UIColor(red: 221/255.0, green: 222/255.0, blue: 223/255.0, alpha: 1.0)
        temPickerView.translatesAutoresizingMaskIntoConstraints = false
        return temPickerView
    }()
    
    /// 默认高度
    public var rowHeight: CGFloat = 50
    /// 默认选择数据高度
    public var dataPickerHeight: CGFloat {
        return self.rowHeight * 5
    }
    public var headerViewHeight: CGFloat = 44.0
    
    /// 组合协议
    private let combinationProtocol: PickerViewProtocol
    
    override public func viewDidLoad() {
         super.viewDidLoad()
         view.backgroundColor = UIColor.white
         configView()
         configLocation()
         configDataSource()
     }
    
    /// 配置默认选择
    private func configDataSource() {
        
        combinationProtocol.pickerDefaultSelected(self)
        headerView.title = combinationProtocol.title
        pickerView.selectedAttributes = combinationProtocol.selectedAttributes
        pickerView.unitAttributedText = combinationProtocol.unitAttributedText
        pickerView.unitLabelLeftConstraint?.constant = combinationProtocol.pickerContentView(self, unitOffsetForComponent: 0)
    }
     
     /// 配置视图
     private func configView() {
         
         view.addSubview(headerView)
         view.addSubview(pickerView)
     }
     
     /// 配置位置
     private func configLocation() {
        
        headerView.leftAnchor.constraint(equalTo: view.leftAnchor).isActive = true
        headerView.rightAnchor.constraint(equalTo: view.rightAnchor).isActive = true
        headerView.topAnchor.constraint(equalTo: view.topAnchor).isActive = true
        headerView.heightAnchor.constraint(equalToConstant: headerViewHeight).isActive = true

        
        pickerView.leftAnchor.constraint(equalTo: view.leftAnchor).isActive = true
        pickerView.rightAnchor.constraint(equalTo: view.rightAnchor).isActive = true
        pickerView.topAnchor.constraint(equalTo: headerView.bottomAnchor).isActive = true
        pickerView.bottomAnchor.constraint(equalTo: view.bottomAnchor, constant: -safeAreaInsetsBottom).isActive = true
     }
    
    /// 安全区域底部
    private var safeAreaInsetsBottom: CGFloat {
        if #available(iOS 11.0, *) {
            return (UIApplication.shared.keyWindow?.rootViewController?.view.safeAreaInsets.bottom ?? 0)
        } else {
            return 0
        }
    }
    
    /// 初始化
   public init(combinationProtocol: PickerViewProtocol) {
        self.combinationProtocol = combinationProtocol
        super.init(nibName: nil, bundle: nil)
        let temHeight = self.dataPickerHeight + self.headerViewHeight
        self.presentAnimator = XBPresentAnimator(self)
        self.presentAnimator.menu { (config) in
           config.presentingScale = 1.0
           config.menuType = .bottomHeight(h: CGFloat(temHeight + safeAreaInsetsBottom))
           config.gestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(eventForDismiss))
        }
    }
    
    
    public override func viewDidLayoutSubviews() {
       super.viewDidLayoutSubviews()
       let path = UIBezierPath(roundedRect: view.bounds, byRoundingCorners: [.topLeft, .topRight], cornerRadii: CGSize(width: 12, height: 12))
       let mask = CAShapeLayer()
       mask.path = path.cgPath
       view.layer.mask = mask
   }
   
   @objc private func eventForDismiss() {
       self.headerViewCancel(self.headerView)
   }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}


// MARK: - UIPickerViewDataSource
extension PickerViewController: UIPickerViewDataSource {
    
    public func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return combinationProtocol.numberOfComponents(in: self)
    }
    
    public func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return combinationProtocol.pickerContentView(self, numberOfRowsInComponent: component)
    }
}


// MARK: - UIPickerViewDelegate
extension PickerViewController: UIPickerViewDelegate {
    
    public func pickerView(_ pickerView: UIPickerView, widthForComponent component: Int) -> CGFloat {
        return combinationProtocol.pickerContentView(self, widthForComponent: component)
    }
    
    public func pickerView(_ pickerView: UIPickerView, rowHeightForComponent component: Int) -> CGFloat {
        return combinationProtocol.pickerContentView(self, rowHeightForComponent: component)
    }
    
    public func pickerView(_ pickerView: UIPickerView, viewForRow row: Int, forComponent component: Int, reusing view: UIView?) -> UIView {
        let cell = PickerCommonView()
        cell.labelTitle.text = combinationProtocol.pickerContentView(self, titleForRow: row, forComponent: component)
        return cell
    }
    
    public func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        combinationProtocol.pickerContentView(self, didSelectRow: row, inComponent: component)
    }
}


// MARK: - PickerHeaderViewDelegate
extension PickerViewController: PickerHeaderViewDelegate {
    
    public func headerViewCancel(_ headerView: PickerHeaderView) {
        combinationProtocol.pickerCancel(self)
    }
    
    public func headerViewConfirm(_ headerView: PickerHeaderView) {
        combinationProtocol.pickerConfim(self)
    }
}

// MARK: - public
extension PickerViewController {
    
    /// 选择行数
    ///
    /// - Parameters:
    ///   - row: row description
    ///   - component: component description
    ///   - animated: animated description
    public func selectRow(_ row: Int, inComponent component: Int, animated: Bool) {
        
        pickerView.selectRow(row, inComponent: component, animated: false)
    }
    
    
    /// 刷新Component
    ///
    /// - Parameter component: component description
    public func reloadComponent(_ component: Int) {
        pickerView.reloadComponent(component)
    }
}
