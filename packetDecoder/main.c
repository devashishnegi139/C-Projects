#include <stdint.h>
#include <stdio.h>

struct Packet{
	uint8_t CRC;
	uint8_t STATUS;
	uint16_t PAYLOAD;
	uint8_t BAT;
	uint8_t SENSOR;
	uint8_t LONG_ADDR;
	uint8_t SHORT_ADDR;
	uint8_t ADDR_MODE;
};

int main(void){
	uint32_t PacketData;
	printf("Enter the Packet Data: ");
	fflush(stdout);

	scanf("%x", &PacketData);

	struct Packet frame;
	frame.CRC = (uint8_t)(PacketData & 0X4);
	frame.STATUS = (uint8_t)( (PacketData>>2) & 0X1);
	frame.PAYLOAD = (uint16_t)( (PacketData>>3) & 0XFFF);
	frame.BAT = (uint8_t)( (PacketData>>15) & 0X7);
	frame.SENSOR = (uint8_t)( (PacketData>>18) & 0X7);
	frame.LONG_ADDR = (uint8_t)( (PacketData>>21) & 0XFF);
	frame.SHORT_ADDR = (uint8_t)( (PacketData>>29) & 0X3);
	frame.ADDR_MODE = (uint8_t)( (PacketData>>31) & 0X1);

	printf("CRC: %x\n", frame.CRC);
	fflush(stdout);
	printf("STATUS: %x\n", frame.STATUS);
	fflush(stdout);
	printf("PAYLOAD: %x\n", frame.PAYLOAD);
	fflush(stdout);
	printf("BAT: %x\n", frame.BAT);
	fflush(stdout);
	printf("SENSOR: %x\n", frame.SENSOR);
	fflush(stdout);
	printf("LONG_ADDR: %x\n", frame.LONG_ADDR);
	fflush(stdout);
	printf("SHORT_ADDR: %x\n", frame.SHORT_ADDR);
	fflush(stdout);
	printf("ADDR_MODE: %x\n", frame.ADDR_MODE);
	fflush(stdout);
}