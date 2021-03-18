;**********************************************
;		常量
;**********************************************
NVIC_INT_CTRL EQU 0xE000ED04	; 中断控制及状态寄存器 SCB_ICSR
NVIC_SYSPRI14 EQU 0xE000ED22	; 系统优先级寄存器SCB_SHPR3
; bit16-32
NVIC_PENDSV_PRI EQU 0xFF		; PendSV优先级的值（最低）
NVIC_PENDSVSET  EQU 0x10000000	; 触发PendSV异常的值 Bit28 PENDSVSET

;**********************************************
;	开始第一次上下文切换
;	1、配置PendSV异常的优先级为最低
;	2、在开始第一次上下文切换的之前，设置psp=0
;	3、触发PendSV异常，开始上下文切换
;**********************************************
OSStartHighRdy
LDR R0, =NVIC_SYSPRI14		;设置PendSV异常优先级为最低
LDR R1, =NVIC_PENDSV_PRI
STRB R1, [R0]

MOVS R0, #0
MSR PSP, R0

LDR R0, =NVIC_INT_CTRL
LDR R1, =NVIC_PENDSVSET
STR R1, [R0]

CPSIE I

OSStartHang
B OSStartHang 