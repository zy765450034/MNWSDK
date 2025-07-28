//
//  YandexAuthManager.swift
//  YandexTest
//
//  Created by admin on 2025/6/17.
//

import Foundation
import UIKit

@objc @MainActor class YandexAuthManager: NSObject{
    private var yandex :YandexInterface =  YandexInterface()
    private static let instance = YandexAuthManager()
    @objc class func shared() -> YandexAuthManager {
            return instance
    }
    @objc func activate(with clientId: String){
        YandexInterface.activate(with: clientId)
    }
    @objc func handleOpenURL(with url: URL){
        YandexInterface.handleOpenURL(with: url)
    }
    @objc func handleUserActivity(with userActivity: NSUserActivity){
        YandexInterface.handleUserActivity(with: userActivity)
    }
    @objc func addObserver(){
        yandex.addYandexLoginObserver()
    }
    @objc func login(with viewController :UIViewController){
        yandex.login(parentViewController: viewController)
    }
}

