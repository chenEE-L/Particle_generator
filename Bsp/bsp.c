#include "bsp.h"



#if 0
/*********************************************************************************
*描述：读取CPU的寄存器来确定CPU时钟频率的芯片
*
*返回值：CPU的时钟频率，单位为Hz。
**********************************************************************************/
INT32U  BSP_CPU_ClkFreq (void)
{
    RCC_ClocksTypeDef  rcc_clocks;


    RCC_GetClocksFreq(&rcc_clocks);

    return ((INT32U)rcc_clocks.HCLK_Frequency);
}

/*********************************************************************************
*描述：系统滴答的时钟频率
*
*返回值：时钟频率（系统时钟周期）。
**********************************************************************************/
INT32U  OS_CPU_SysTickClkFreq (void)
{
    INT32U  freq;


    freq = BSP_CPU_ClkFreq();
    return (freq);
}
#endif
