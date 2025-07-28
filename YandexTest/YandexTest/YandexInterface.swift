//
//  YandexInterface.swift
//  YandexTest
//
//  Created by admin on 2025/6/17.
//

import Foundation
import YandexLoginSDK
final class YandexInterface: NSObject{
    private var loginResult: LoginResult? {
        didSet {
           
        }
    }
    
    class func activate(with clientId: String){
        do {
            try YandexLoginSDK.shared.activate(with: clientId)
        } catch {
            errorOccured(error)
        }
    }
    class func handleOpenURL(with url: URL){
        do {
            try YandexLoginSDK.shared.handleOpenURL(url)
        } catch {
            errorOccured(error)
        }
    }
    class func handleUserActivity(with userActivity: NSUserActivity){
        do {
            try YandexLoginSDK.shared.handleUserActivity(userActivity)
        } catch {
            errorOccured(error)
        }
    }
    
    func addYandexLoginObserver(){
        YandexLoginSDK.shared.add(observer: self)
    }
    func login(parentViewController: UIViewController){
        do {
            try YandexLoginSDK.shared.authorize(
                with: parentViewController,
                customValues: nil,
                authorizationStrategy: YandexLoginSDK.AuthorizationStrategy.default
            )
        } catch {
            YandexInterface.errorOccured(error)
        }
    }
    
    func logout(){
        do {
            try YandexLoginSDK.shared.logout()
            self.loginResult = nil
        } catch {
            YandexInterface.errorOccured(error)
        }
    }
}

extension YandexInterface: YandexLoginSDKObserver {
    
     func didFinishLogin(with result: Result<LoginResult, Error>) {
        switch result {
        case .success(let loginResult):
            self.loginResult = loginResult
        case .failure(let error):
            YandexInterface.errorOccured(error)
        }
    }
    
}

extension YandexInterface {
    class  func errorOccured(_ error: Error) {
    
        if let yandexLoginSDKError = error as? YandexLoginSDKError {
//            alertController = UIAlertController(
//                title: "A LoginSDK Error Occured",
//                message: yandexLoginSDKError.message,
//                preferredStyle: .alert
//            )
            print("A LoginSDK Error Occured%@",yandexLoginSDKError.message)
        } else {
//            alertController = UIAlertController(
//                title: "An Error Occured",
//                message: error.localizedDescription,
//                preferredStyle: .alert
//            )
            print("An Error Occured%@",error.localizedDescription)
        }
    }
}
