/*
 * main.c
 *
 *  Created on: Jun 13, 2018
 *      Author: thomas
 */


#include <xparameters.h>
#include <xgpio.h>



#define GPIO_ALL_LEDS 0xFFFF
#define GPIO_ALL_BUTTONS 0xFFFF

#define Button_Channel 1
#define LED_Channel 1
#define Button_Interrupt

XGpio_Config Config0={XPAR_AXI_GPIO_0_DEVICE_ID,XPAR_AXI_GPIO_0_BASEADDR,XPAR_AXI_GPIO_0_INTERRUPT_PRESENT,XPAR_AXI_GPIO_0_IS_DUAL};
XGpio_Config Config1={XPAR_AXI_GPIO_1_DEVICE_ID,XPAR_AXI_GPIO_1_BASEADDR,XPAR_AXI_GPIO_1_INTERRUPT_PRESENT,XPAR_AXI_GPIO_1_IS_DUAL};
XGpio GPIO0,GPIO1;

int main(){

	int Status;
	u32 Read,Read_old;

	Status=XGpio_Initialize(&GPIO0,Config0.DeviceId);

	if(Status!=XST_SUCCESS){
		xil_printf("GPIO_0 initialization failed\r\n");
		return XST_FAILURE;
	}
	else{
		xil_printf("GPIO_0 initialization SUCCESSFULL\r\n");
	}

	Status=XGpio_Initialize(&GPIO1,Config1.DeviceId);

		if(Status!=XST_SUCCESS){
			xil_printf("GPIO_1 initialization failed\r\n");
			return XST_FAILURE;
		}
		else{
			xil_printf("GPIO_1 initialization SUCCESSFULL\r\n");
		}

	XGpio_SetDataDirection(&GPIO0,1,0x000000FF);
	XGpio_SetDataDirection(&GPIO1,1,0x00000000);
	while(1){
	Read=XGpio_DiscreteRead(&GPIO0,1);
	if(Read==Read_old){
		continue;
	}
	else{
		XGpio_DiscreteWrite(&GPIO1,1,Read);
		xil_printf("Read Value=%d\r\n",Read);
		Read_old=Read;
	}
	}
}
