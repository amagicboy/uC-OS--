#include "cpu.h"
#include "common.h"
#include "os.h"

#define TASK1_STK_SIZE 128
#define TASK2_STK_SIZE 128

static CPU_STK Task1Stk[TASK1_STK_SIZE];
static CPU_STK Task2Stk[TASK2_STK_SIZE];

static OS_TCB Task1TCB;
static OS_TCB TASK2TCB;

uint32_t flag1;
uint32_t flag2;

void delay(uint32_t count)
{
	for(;count!=0;count--);
}

void Task1(void *p_arg)
{
	for(;;)
	{
		flag1 = 1;
		delay(100);
		flag1 = 0;
		delay(100);
	}
}

void Task2(void *p_arg)
{
	for(;;)
	{
		flag2 = 1;
		delay(100);
		flag2 = 0;
		delay(100);
	}
}

int main(void)
{

	OSRDYList[0].HeadPtr = &Task1TCB
	OSRDYList[1].HeadPtr = &Task2TCB;
	
	return 0;
}
