#pragma once
#include <Windows.h>

class timer {
private:

public:
	/*	Class Properties	*/
	DWORD start;
	DWORD end;
	double calc;
	timer(): start(0), end(0), calc(0.0) {	//	Constructor

	}
	timer(const timer& _copy) : start(0), end(0), calc(0.0) {	//	Copy Constructor

	}
	~timer() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void Start();
	void End();
	void Calc();
	void Reset();
};

