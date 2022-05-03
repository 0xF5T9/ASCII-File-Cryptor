#pragma once
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/cryptor.h"

class menu {
private:
	animation* Animation;
	cryptor* Cryptor;
public:
	menu(): Animation(NULL), Cryptor(NULL) {	// Constructor
		
	}
	menu(animation* _Animation, cryptor* _Cryptor) {
		this->Animation = _Animation;
		this->Cryptor = _Cryptor;
	}
	menu(const menu& _copy): Animation(NULL), Cryptor(NULL) {	//	Copy Constructor

	}
	~menu() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void ShowMenu() const;
	int SelectOption();
	bool ProcessOption(int _option);
};

