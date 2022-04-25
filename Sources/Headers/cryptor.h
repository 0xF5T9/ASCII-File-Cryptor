#pragma once
class cryptor {
private:

public:
	cryptor() {
		//	Constructor
	}
	~cryptor() {
		//	Destructor
	}
	/*	Khai báo hàm mẫu (Declare function prototypes)	*/
	int ConvertIntoKey(std::string password);
	void Encrypt(std::string filename, std::string password);
	void Decrypt(std::string filename, std::string password);
};

