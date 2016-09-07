//
//  Use this file to import your target's public headers that you would like to expose to Swift.
//

#include <getopt.h>
#include <IOKit/graphics/IOGraphicsLib.h>
#include <ApplicationServices/ApplicationServices.h>

void setMainDisplay(CGDirectDisplayID targetDisplay);

IOOptionBits angle2options(long angle);

void rotate(void);