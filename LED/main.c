
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"

#include <util/delay.h>

#include "standardtypes.h"
#include "utils.h"
#include "DIO.h"
#include "LED.h"

/* Prototypes */
void T_1(void* pvData);
void T_2(void* pvData);
void T_3(void* pvData);
xSemaphoreHandle		bsRes = NULL;

int main(void)
{   LED_vidInit(b, pin0, output);
	LED_vidInit(b,pin1,output);
    LED_vidInit(b,pin2,output);

	/* OS Objects Init. and Creation. */
    vSemaphoreCreateBinary(bsRes);

//xSemaphoreCreate(bsRes);

	/* Create Tasks */
	xTaskCreate(T_1,NULL,100,NULL,1,NULL);

	/* Start OS or Sched */
	vTaskStartScheduler();

}

void T_1(void* pvData){
	while(1){

		DIO_vidWritePinValue(b, pin0, high);

vTaskDelay(1000);
		DIO_vidWritePinValue(b, pin0, low);
		vTaskDelay(1000);

//		xSemaphoreTake(bsRes, portMAX_DELAY);
//		xTaskCreate(T_3,NULL,100,NULL,3,NULL);
//		//xTaskCreate(T_2,NULL,100,NULL,2,NULL);
//		xSemaphoreGive(bsRes);


	}
}
void T_2(void* pvData){
	while(1){
		DIO_vidWritePinValue(b, pin2, high);
		uint32_t ind3 = 0;
					uint32_t ind4 = 0;
					for (ind3 = 0; ind3 < 100; ++ind3) {
						for (ind4 = 0; ind4 < 1250; ++ind4) {
							asm("nop");
						}
					}
		DIO_vidWritePinValue(b, pin2, low);
		for (ind3 = 0; ind3 < 100; ++ind3) {
						for (ind4 = 0; ind4 < 1250; ++ind4) {
							asm("nop");
						}
					}		vTaskDelay(50);
	}
}
void T_3(void* pvData){
	while(1){

		DIO_vidWritePinValue(b, pin1, high);
		uint32_t ind5 = 0;
					uint32_t ind6 = 0;
					for (ind5 = 0; ind5 < 100; ++ind5) {
						for (ind6 = 0; ind6 < 1250; ++ind6) {
							asm("nop");
						}
					}
		DIO_vidWritePinValue(b, pin1, low);
		for (ind5 = 0; ind5 < 100; ++ind5) {
						for (ind6 = 0; ind6 < 1250; ++ind6) {
							asm("nop");
						}
					}
		xSemaphoreTake(bsRes, portMAX_DELAY);
		while(1)
		{

		}


	}
}
