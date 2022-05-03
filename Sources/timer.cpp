#include <iostream>
#include <Windows.h>
#include "../Sources/Headers/timer.h"

/*	Define 'timer' class functions	*/
void timer::Start() {
	start = GetTickCount64();
}

void timer::End() {
	end = GetTickCount64();
}

void timer::Calc() {
	calc = end - start;
	calc = calc / 1000;
	std::cout << "Quá trình mã hoá tốn " << calc << " giây." << std::endl;
	Reset();
}

void timer::Reset() {
	start = 0;
	end = 0;
	calc = 0.0;
}