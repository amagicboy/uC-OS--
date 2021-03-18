#ifndef OS_H
#define OS_H

#ifdef OS_GLOBALS
#define OS_EXT
#else
#define OS_EXT extern 
#endif

#define OS_STATE_OS_STOPPED (OS_STATE)(0u)
#define OS_STATE_OS_RUNNING	(OS_STATE)(1u)

typedef void (*OS_TASK_PTR)(void *p_arg);

typedef enum os_err{
	OS_ERR_NONE 			= 0u,
	OS_ERR__A					= 10000u,
	OS_ERR_ACCEPT_ISR = 10001u,
	OS_ERR_B    			= 11000u,
	OS_ERR_C					= 12000u,
	OS_ERR_CREATE_ISR = 12001u,
	OS_ERR_X 					= 33000u,
	OS_ERR_Y 					= 34000u,
	OS_ERR_YIELD_ISR 	= 34001u,
	OS_ERR_Z 					= 35000u,
}OS_ERR;

OS_EXT OS_RDY_LIST OSRdyList[OS_CFG_PRIO_MAX];

typedef struct os_rdy_list OS_RDY_LIST;

struct od_rdy_list{
	OS_TCB *HeadPtr;
	OS_TCB *TailPtr;
};

OS_EXT OS_TCB 			*OSTCBCurPtr;
OS_EXT OS_TCB 			*OSTCBHighRdyPtr;
OS_EXT OS_RDY_LIST 	OSRdyList[OS_CFG_PRIO_MAX];
OS_EXT OS_STATE 		OSRunning;

#endif