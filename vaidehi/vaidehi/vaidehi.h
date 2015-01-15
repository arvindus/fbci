/*
 *  vaidehi.h
 *  vaidehi
 *
 *  Created by arvind sudarsanam on 1/11/15.
 *  Copyright (c) 2015 arvind sudarsanam. All rights reserved.
 *
 */

extern "C" {
#include <CoreFoundation/CoreFoundation.h>

#pragma GCC visibility push(default)

/* External interface to the vaidehi, C-based */

CFStringRef vaidehiUUID(void);

#pragma GCC visibility pop
}
