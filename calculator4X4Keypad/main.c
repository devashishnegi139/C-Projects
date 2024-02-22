#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint8_t bufferData[30];
uint8_t index = 0;

void delay(){
	for(volatile uint32_t i=0; i<400000; i++);
}

void AdditionLogic(){
	uint32_t sumLeft = 0;
    uint8_t temp = index-1;
    for(uint8_t i=0; i<index; i++){
        sumLeft += ( (bufferData[i]) * pow(10, temp));
        temp--;
    }
    // while() // still stuck
}

int main(void)
{
	// Addresses
	uint32_t *AHB1ENR = (uint32_t *)(0X40023830);
	uint32_t *GPIOC_MODER = (uint32_t *)(0X40020800);
	uint32_t *GPIOC_ODR = (uint32_t *)(0X40020814);
	uint32_t *GPIOC_IDR = (uint32_t *)(0X40020810);
	uint32_t *GPIOC_PUPDR = (uint32_t *)(0X4002080C);

	// Logic
	*AHB1ENR |= (1U<<2);	// Enabled GPIOC Clock
	*GPIOC_MODER |= (0X55);	// 1st 4 pins in OUTPUT MODE = 01
	*GPIOC_MODER &= (0X00FF);	// next 4 pins in INPUT MODE = 00
	/* We could have considered all 16 pins at once
	   *GPIOC_MODER &= (0XFFFF0000); //reset pins = 0
	   *GPIOC_MODER |= (0X00000055); // setting them
	 */
	// Pull up needed only for columns, i.e. pin 4, 5, 6, 7
	*GPIOC_PUPDR &= (0XFFFF0000);
	*GPIOC_PUPDR |= (0X00005500);
	

	while(1){
		// making R1 LOW
		*GPIOC_ODR |= (0X0F);
		*GPIOC_ODR &= ~(1<<0);

		if(!(*GPIOC_IDR & (1<<4))){
			delay();
//			printf("1 is pressed\n");
			bufferData[index++] = 1; 
		}
		if(!(*GPIOC_IDR & (1<<5))){
			delay();
//			printf("2 is pressed\n");
			bufferData[index++] = 2; 
		}
		if(!(*GPIOC_IDR & (1<<6))){
			delay();
//			printf("3 is pressed\n");
			bufferData[index++] = 3; 
		}
		if(!(*GPIOC_IDR & (1<<7))){
			delay();
//			printf("4 is pressed\n");
			AdditionLogic();
		}

		// making R2 LOW
		*GPIOC_ODR |= (0X0F);
		*GPIOC_ODR &= ~(1<<1);

		if(!(*GPIOC_IDR & (1<<4))){
			delay();
			printf("5 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<5))){
			delay();
			printf("6 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<6))){
			delay();
			printf("7 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<7))){
			delay();
			printf("8 is pressed\n");
		}

		// making R3 LOW
		*GPIOC_ODR |= (0X0F);
		*GPIOC_ODR &= ~(1<<2);

		if(!(*GPIOC_IDR & (1<<4))){
			delay();
			printf("9 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<5))){
			delay();
			printf("10 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<6))){
			delay();
			printf("11 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<7))){
			delay();
			printf("12 is pressed\n");
		}

		// making R1 LOW
		*GPIOC_ODR |= (0X0F);
		*GPIOC_ODR &= ~(1<<3);

		if(!(*GPIOC_IDR & (1<<4))){
			delay();
			printf("13 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<5))){
			delay();
			printf("14 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<6))){
			delay();
			printf("15 is pressed\n");
		}
		if(!(*GPIOC_IDR & (1<<7))){
			delay();
			printf("16 is pressed\n");
		}
	}	// while loop end
}