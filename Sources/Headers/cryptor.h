#pragma once
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/timer.h"

class cryptor {
private:
	animation* Animation;
	timer* Timer;
public:
	cryptor(): Animation(NULL), Timer(NULL) {	//	Constructor
		
	}
	cryptor(animation* _Animation, timer* _Timer) {	//	Constructor (w/ Animation & Timer Object)
		this->Animation = _Animation;
		this->Timer = _Timer;
	}
	cryptor(const cryptor& _copy): Animation(NULL), Timer(NULL) {	//	Copy Constructor

	}
	~cryptor() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	int ConvertIntoKey(std::string _password);
	void Encrypt(std::string _filename, std::string _password);
	void Decrypt(std::string _filename, std::string _password);
};

