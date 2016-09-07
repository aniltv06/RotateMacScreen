//
//  AppDelegate.swift
//  RotateMacScreen
//
//  Created by anilkumar thatha. venkatachalapathy on 07/09/16.
//  Copyright © 2016 Anil T V. All rights reserved.
//

import Cocoa
import Foundation

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!


    func applicationDidFinishLaunching(aNotification: NSNotification) {
        // Insert code here to initialize your application
    }

    func applicationWillTerminate(aNotification: NSNotification) {
        // Insert code here to tear down your application
    }

    @IBAction func buttonTapped(button:NSButton)
    {
        //let angleToRotate : String = button.identifier!
        print(button.identifier)
        if button.identifier == "0" {
            rotate(0)
        }
        else if button.identifier == "90" {
            rotate(90)
        }
        else if button.identifier == "180" {
            rotate(180)
        }
        else if button.identifier == "270" {
            rotate(270)
        }
    }

    func applicationShouldTerminateAfterLastWindowClosed(sender: NSApplication) -> Bool{
        return true
    }
}

