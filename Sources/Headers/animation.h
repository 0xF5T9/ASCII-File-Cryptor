#pragma once

class animation {
private:

public:
	animation() {	//	Constructor
		
	}
	animation(const animation& _copy) {	//	Copy Constructor

	}
	~animation() {	//	Destructor
		
	}

	/*	Class function prototypes	*/
	void DotAnimation(int _milliseconds);
	void FlashWindows();
	void DisableSelection();
};

