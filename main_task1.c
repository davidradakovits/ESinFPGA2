#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"

XGpio Gpio;

int main(void){

	if (XGpio_Initialize(&Gpio, XPAR_AXI_GPIO_0_DEVICE_ID) == XST_SUCCESS)
		xil_printf("INIT SUCCESSFULL!\r\n");
	else
		xil_printf("INIT FAILED!\r\n");

	XGpio_SetDataDirection(&Gpio, 1, 0xFFFFFFFF);
	u32 switches=0;
	u32 switches_old=0;
	while(1)
	{
		switches = XGpio_DiscreteRead(&Gpio,1);
		if(switches_old!=switches)
		{
			xil_printf("%d ",switches);

			//MSB
			if(switches&0x80) xil_printf("1");
			else xil_printf("0");

			//all other bits
			u32 mask1 = 0x80; // 1000 0000
			u32 mask2 = 0x40; // 0100 0000
			for(u32 i=7; i>0; i--)
			{
				if(i==4) xil_printf(" "); // Leerzeichen
				if(((switches&mask1)>>i)^((switches&mask2)>>(i-1))) xil_printf("1");
				else xil_printf("0");
				mask1=mask1>>1;
				mask2=mask2>>1;
			}
			switches_old=switches;
			xil_printf("\r\n");
		}
	}
	return 0;
}
