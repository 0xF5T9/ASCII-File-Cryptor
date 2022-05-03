#pragma once
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/timer.h"
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/menu.h"

/*	Define create object functions	*/
animation* CreateObjectAnimation() {
	animation* CreateObject = new animation();
	return CreateObject;
}

timer* CreateObjectTimer() {
	timer* CreateObject = new timer();
	return CreateObject;
}

cryptor* CreateObjectCryptor(animation* _Animation, timer* _Timer) {
	cryptor* CreateObject = new cryptor(_Animation, _Timer);
	return CreateObject;
}

menu* CreateObjectMenu(animation* _Animation, cryptor* _Cryptor) {
	menu* CreateObject = new menu(_Animation, _Cryptor);
	return CreateObject;
}

/*	Define free object memory functions	*/
void FreeMemory(animation* _Ptr) {
	delete _Ptr;
}

void FreeMemory(timer* _Ptr) {
	delete _Ptr;
}

void FreeMemory(cryptor* _Ptr) {
	delete _Ptr;
}

void FreeMemory(menu* _Ptr) {
	delete _Ptr;
}