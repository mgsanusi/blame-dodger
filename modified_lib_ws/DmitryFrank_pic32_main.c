/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */  
    
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "system/common/sys_module.h"

{
    
	/* Initialize all MPLAB Harmony modules, including application(s). */ 
	SYS_Initialize(NULL);
    
	
	    /* Maintain state machines of all polled MPLAB Harmony modules. */ 
	    SYS_Tasks();
    
    


