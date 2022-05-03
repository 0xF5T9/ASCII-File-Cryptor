#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/timer.h"
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/func.h"

int main() {

	/*	Initialize program parameters	*/
	animation* Animation = CreateObjectAnimation();
	timer* Timer = CreateObjectTimer();
	cryptor* Cryptor = CreateObjectCryptor(Animation, Timer);
	menu* Menu = CreateObjectMenu(Animation, Cryptor);
	SetConsoleOutputCP(65001);	//	Set code page utf-8
	Animation->DisableSelection();	//	Disable console selection
	
	/*	Start the program	*/
	while (true) {
		SetConsoleTitle(L"ASCII File Cryptor");
		bool EXITPROGRAM = Menu->ProcessOption(Menu->SelectOption());
		if (EXITPROGRAM == true) break;
	}

	/*	End the program	*/
	FreeMemory(Animation);
	FreeMemory(Timer);
	FreeMemory(Cryptor);
	FreeMemory(Menu);
	return 0;
}