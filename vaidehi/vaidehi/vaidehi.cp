/*
 *  vaidehi.cp
 *  vaidehi
 *
 *  Created by arvind sudarsanam on 1/11/15.
 *  Copyright (c) 2015 arvind sudarsanam. All rights reserved.
 *
 */

#include "vaidehi.h"
#include "vaidehiPriv.h"

CFStringRef vaidehiUUID(void)
{
	Cvaidehi* theObj = new Cvaidehi;
	return theObj->UUID();
}

CFStringRef Cvaidehi::UUID()
{
	return CFSTR("0001020304050607");
}
