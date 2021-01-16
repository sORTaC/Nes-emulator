#ifndef  BUS_H
#define  BUS_H

#include <vector>
#include "cpu.h"
#include "ppu.h"

class Bus
{
private:
	cpu6502* cpu;
	NesPPU* ppu;
	uint8_t ram[65536];
	bool strobe;
	uint8_t controller, controller_index;
public:
	Bus();
	void ConnectBus(cpu6502*, NesPPU*);
	uint16_t BusRead(uint16_t);
	void BusWrite(uint16_t, uint8_t);
	uint8_t ask_cpu(uint16_t data);
	void write_controller(uint8_t*);
	uint8_t read_controller(int index);
	void init();
	void run();
};

#endif // ! BUS_H


