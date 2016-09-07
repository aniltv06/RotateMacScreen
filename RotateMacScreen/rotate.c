//
//  rotate.c
//  RotateMacScreen
//
//  Created by anilkumar thatha. venkatachalapathy on 07/09/16.
//  Copyright © 2016 Anil T V. All rights reserved.
//

#include <IOKit/graphics/IOGraphicsLib.h>
#include <ApplicationServices/ApplicationServices.h>

enum {
    kIOBits = 0x00000400,
};

CGDirectDisplayID
cgIDfromU32(uint32_t preId)
{
    CGDisplayErr      displayError;
    CGDisplayCount    displayCount, i;
    CGDisplayCount    maxDisplays = 16;
    CGDirectDisplayID onlineDisplays[16];
    CGDirectDisplayID postId = preId;
    
    displayError = CGGetOnlineDisplayList(maxDisplays, onlineDisplays, &displayCount);
    if (displayError != kCGErrorSuccess) {
        fprintf(stderr, "CGGetOnlineDisplayList: error %d.\n", displayError);
        exit(1);
    }
    for (i = 0; i < displayCount; i++) {
        CGDirectDisplayID dID = onlineDisplays[i];
        if ((dID == preId) || (dID == postId) ||
            (onlineDisplays[i] == preId) || (onlineDisplays[i] == postId)) {
            return dID;
        }
    }
    fprintf(stderr, " Could not find a matching id in onlineDisplays!\n");
    exit(1);
}

IOOptionBits
angle2options(long angle)
{
    static IOOptionBits anglebits[] = {
        (kIOBits | (kIOScaleRotate0)   << 16),
        (kIOBits | (kIOScaleRotate90)  << 16),
        (kIOBits | (kIOScaleRotate180) << 16),
        (kIOBits | (kIOScaleRotate270) << 16)
    };
    
    if ((angle % 90) != 0) // Map arbitrary angles to a rotation reset
        return anglebits[0];
    
    return anglebits[(angle / 90) % 4];
}

void
rotate(long angle)
{
    io_service_t      ioService;
    CGDisplayErr      displayError;
    CGDirectDisplayID displayID = CGMainDisplayID();
    IOOptionBits      options = angle2options(angle);
    CGDirectDisplayID td2 = cgIDfromU32(displayID);
    ioService = CGDisplayIOServicePort(td2);
    displayError = IOServiceRequestProbe(ioService, options);
    if (displayError != kCGErrorSuccess) {
        fprintf(stderr, "IOServiceRequestProbe: error %d\n", displayError);
        exit(1);
    }
    //Exit application
    //exit(0);
}
