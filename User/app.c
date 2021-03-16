#include "cpu.h"
#include "common.h"

#define TASK1_STK_SIZE 128
#define TASK2_STK_SIZE 128

static CPU_STK Task1Stk[TASK1_STK_SIZE];
static CPU_STK Task2Stk[TASK2_STK_SIZE];

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

int main(void)
{

	return 0;
}
