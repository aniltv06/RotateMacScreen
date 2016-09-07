//
//  AppDelegate.swift
//  Rotate
//
//  Created by anilkumar thatha. venkatachalapathy on 06/09/16.
//  Copyright © 2016 Anil T V. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!


    func applicationDidFinishLaunching(aNotification: NSNotification) {
        // Insert code here to initialize your application
        
        print("Start")
        
        var angle = 90
        var options : IOOptionBits
        options = angle2options(angle);
        rotate()
        
        
    }

    func applicationWillTerminate(aNotification: NSNotification) {
        // Insert code here to tear down your application
    }


}

