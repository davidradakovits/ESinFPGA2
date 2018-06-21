#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"

XGpio Gpio0;
XGpio Gpio1;

int main(void){

	if (XGpio_Initialize(&Gpio0, XPAR_AXI_GPIO_0_DEVICE_ID) == XST_SUCCESS &&
		XGpio_Initialize(&Gpio1, XPAR_AXI_GPIO_1_DEVICE_ID) == XST_SUCCESS)
		xil_printf("INIT SUCCESSFULL!\r\n");
	else
		xil_printf("INIT FAILED!\r\n");

	XGpio_SetDataDirection(&Gpio0, 1, 0xFFFFFFFF);
	XGpio_SetDataDirection(&Gpio1, 1, 0x00000000);

	u32 switches;
	u32 switches_old = 0;

	while(1)
	{
		switches = XGpio_DiscreteRead(&Gpio0,1);
		if(switches!=switches_old)
		{
			XGpio_DiscreteWrite(&Gpio1,1,switches);
			xil_printf("%d\r\n",switches);
			switches_old=switches;
		}
	}
	return 0;
}
