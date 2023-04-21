//
//  PickerManager.swift
//  Created on 2022/9/21
//  Description <#文件描述#>
//  PD <#产品文档地址#>
//  Design <#设计文档地址#>
//  Copyright © 2022 TGASDK. All rights reserved.
//  @author 刘小彬(liuxiaomike@gmail.com)   
//


import UIKit

/// 选择器数据对象
public typealias PickerDataObject = PickerModelProtocol

/// MARK - 选择管理类
public class PickerManager {
    
   
    
    /// 显示单选
    /// - Parameters:
    ///   - type: 类型
    ///   - selected: 选中的项
    ///   - completion: 完成
    public static func showSingle<T: PickerDataObject>(type: PickerSingleType, selected: T? = nil, completion: @escaping (T?) -> Swift.Void) {
        
        let pickerSingleManager = PickerSingleManager(type: type)
        pickerSingleManager.selectIndex = 0
        
        if let temSelected = selected {
            
            pickerSingleManager.selectIndex = type.dataSource.firstIndex { model -> Bool in
                return model.uuid == temSelected.uuid
                } ?? 0
        }
        
        
        let vc = PickerViewController(combinationProtocol: pickerSingleManager)
        pickerSingleManager.cancelCallBack = { _ in
            completion(nil)
            WZRoute.dismiss()
        }
        
        pickerSingleManager.confirmCallBack = { (_, result) in
            completion(result as? T)
            WZRoute.dismiss()
        }
        WZRoute.present(vc)
    }
}



/// MARK - 路由
internal class WZRoute {
    
    /// 完成类型别名
    internal typealias Completion = (() -> Swift.Void)?
    
    /// push
    ///
    /// - Parameters:
    ///   - viewController: 需要跳转的控制器
    ///   - animated: 是否动画(默认: true)
    ///   - completion: 动画完成回掉(默认: nil)
    internal class func push(_ viewController: UIViewController, animated: Bool = true, completion: Completion = nil) {
        
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        viewController.hidesBottomBarWhenPushed = true
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        navigationController.pushViewController(viewController, animated: animated)
        CATransaction.commit()
        
    }
    
    
    /// pop
    ///
    /// - Parameters:
    ///   - animated: 是否动画(默认: true)
    ///   - completion: completion(默认: nil)
    internal class func pop(_ animated: Bool = true, completion: Completion = nil) {
        
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        navigationController.popViewController(animated: animated)
        CATransaction.commit()
    }
    

    /// popRoot
    ///
    /// - Parameters:
    ///   - animated: 是否动画(默认: true)
    ///   - completion: completion(默认: nil)
    internal class func popRoot(_ animated: Bool = true, completion: Completion = nil) {
        
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        navigationController.popToRootViewController(animated: animated)
        CATransaction.commit()
    }
    
    
    /// present
    ///
    /// - Parameters:
    ///   - viewController: 需要跳转的控制器
    ///   - animated: 是否动画(默认: true)
    ///   - completion: completion(默认: nil)
    internal class func present(_ viewController: UIViewController, animated: Bool = true, completion: Completion = nil) {
        
        guard let fromViewController = UIViewController.topMost else { return  }
        DispatchQueue.main.async {
          fromViewController.present(viewController, animated: animated, completion: completion)
        }
    }
    
    
    /// dismiss
    ///
    /// - Parameters:
    ///   - animated: 是否动画(默认: true)
    ///   - completion: completion(默认: nil)
    internal class func dismiss(animated: Bool = true, completion: Completion = nil) {
        
        guard let fromViewController = UIViewController.topMost else { return  }
        fromViewController.view.endEditing(true)
        fromViewController.dismiss(animated: animated, completion: completion)
    }
    
    
    /// showDetail
    ///
    /// - Parameters:
    ///   - viewController: viewController description
    ///   - sender: sender description
    ///   - completion: Completion
    internal class func showDetail(_ viewController: UIViewController, sender: Any?, completion: Completion = nil) {
        
        guard let fromViewController = UIViewController.topMost else { return  }
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        fromViewController.showDetailViewController(viewController, sender: sender)
        CATransaction.commit()
    }
    
    
    /// setViewControllers
    ///
    /// - Parameters:
    ///   - viewControllers: viewControllers description
    ///   - animated: animated description
    ///   - completion: Completion
    internal class func setViewControllers(_ viewControllers: [UIViewController], animated: Bool = true, completion: Completion = nil) {
        
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        navigationController.setViewControllers(viewControllers, animated: animated)
        CATransaction.commit()
    }
    
    
    /// 获取Window上面的根控制器
    ///
    /// - Returns: <#return value description#>
    internal class func rootViewController() -> UIViewController {
        return UIApplication.shared.keyWindow!.rootViewController!
    }
    
    /// 跳转新控制器移除上个控制器
    /// - Parameters:
    ///   - viewController: viewControllers description
    ///   - animated: animated description
    ///   - completion: Completion
    internal class func setViewControllerRemoveLast(_ viewController: UIViewController, animated: Bool = true, completion: Completion = nil) {
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        var temArray: [UIViewController] = navigationController.viewControllers.dropLast()
        temArray.append(viewController)
        setViewControllers(temArray, animated: animated, completion: completion)
    }
    
    /// 跳转新当前控制器，移除历史栈
    /// - Parameters:
    ///   - viewController: viewControllers description
    ///   - animated: animated description
    ///   - completion: Completion
    internal class func setViewControllerRemoveCurrent(_ viewController: UIViewController, animated: Bool = true, completion: Completion = nil) {
        guard let navigationController = UIViewController.topMost?.navigationController else {
            return
        }
        var temArray: [UIViewController] = []
        for vc in navigationController.viewControllers {
            if vc.classForCoder != viewController.classForCoder {
                temArray.append(vc)
            }
        }
        temArray.append(viewController)
        setViewControllers(temArray, animated: animated, completion: completion)
    }
    
    /// 移除某个控制器
    /// - Parameters:
    ///   - viewController: viewController description
    ///   - animated: animated description
    ///   - completion: completion description
    internal class func popController(_ viewController: UIViewController, animated: Bool = true, completion: Completion = nil) {

        guard let navigationController = viewController.navigationController, let topViewController = UIViewController.topMost else {
            return
        }
        var temArray: [UIViewController] = []
        temArray.append(contentsOf: navigationController.viewControllers)
        temArray.removeAll(where: {$0.classForCoder == viewController.classForCoder})
        
        var isAnimated = animated
        if navigationController.viewControllers.last?.classForCoder == viewController.classForCoder && (viewController.presentedViewController == topViewController || viewController.presentedViewController == nil) {
            
        }else{
            isAnimated = false
        }
        
        viewController.presentedViewController?.dismiss(animated: false, completion: nil)
        CATransaction.begin()
        CATransaction.setCompletionBlock(completion)
        navigationController.setViewControllers(temArray, animated: isAnimated)
        CATransaction.commit()
    }
}


// MARK: - Methods
fileprivate extension UIViewController {
    
    /// sharedApplication
    private class var sharedApplication: UIApplication? {
        let selector = NSSelectorFromString("sharedApplication")
        return UIApplication.perform(selector)?.takeUnretainedValue() as? UIApplication
    }
    
    
    /// 返回当前应用程序的最顶层视图控制器。
    class var topMost: UIViewController? {
        
        guard let currentWindows = self.sharedApplication?.windows else { return nil }
        var rootViewController: UIViewController?
        for window in currentWindows {
            if let windowRootViewController = window.rootViewController {
                rootViewController = windowRootViewController
                break
            }
        }
        
        return self.topMost(of: rootViewController)
    }
    
    
    /// 返回给定视图控制器堆栈中最顶层的视图控制器
    ///
    /// - Parameter viewController: viewController description
    /// - Returns: return value description
    class func topMost(of viewController: UIViewController?) -> UIViewController? {
        
        // presented view controller
        if let presentedViewController = viewController?.presentedViewController {
            return self.topMost(of: presentedViewController)
        }
        
        // UITabBarController
        if let tabBarController = viewController as? UITabBarController,
            let selectedViewController = tabBarController.selectedViewController {
            return self.topMost(of: selectedViewController)
        }
        
        // UINavigationController
        if let navigationController = viewController as? UINavigationController,
            let visibleViewController = navigationController.visibleViewController {
            return self.topMost(of: visibleViewController)
        }
        
        // UIPageController
        if let pageViewController = viewController as? UIPageViewController,
            pageViewController.viewControllers?.count == 1 {
            return self.topMost(of: pageViewController.viewControllers?.first)
        }
        
        // child view controller
        for subview in viewController?.view?.subviews ?? [] {
            if let childViewController = subview.next as? UIViewController {
                return self.topMost(of: childViewController)
            }
        }
        return viewController
    }
}
