#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"
#include "../Sources/Headers/timer.h"
#include "../resource.h"


/*	Tạo object từ classes (Create object from classes)	*/
animation AnimationCryptorObj;
timer TimerCryptorObj;

/*	Định nghĩa các hàm class 'cryptor' (Define 'cryptor' class functions)	*/
int cryptor::ConvertIntoKey(std::string password) {
	char cpassword[100];
	int cryptkey = 0;
	strcpy_s(cpassword, password.c_str());
	for (int i = 0; i < password.length(); i++) {
		cryptkey += cpassword[i];
	}
	return cryptkey;
}

void cryptor::Encrypt(std::string filename, std::string password) {
	SetConsoleTitle(L"ASCII File Cryptor - Encrypting");
	TimerCryptorObj.Start();
	char i;
	std::string OriginalFileName = filename;
	std::string TempData;
	std::ifstream InputFile(filename, std::ios::binary);
	std::ofstream CryptFile("crypting", std::ios::binary);
	int cryptkey = ConvertIntoKey(password);
	if (!InputFile) {
		InputFile.close();
		CryptFile.close();
		system("del /f \"crypting\"");
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		goto escape;
	}
	if (!CryptFile) {
		std::cout << "Không thể tạo file tạm thời (Thiếu quyền?) ";
		AnimationCryptorObj.DotAnimation(500);
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i + cryptkey;
		TempData += i;
	}
	CryptFile << TempData;
	std::cout << "Tệp đã được mã hoá với mật khẩu: \"" << password << "\"" << std::endl;
	std::cout << "# Kiểm tra và ghi nhớ trước khi tiếp tục" << std::endl;
	Sleep(1000);
	InputFile.close();
	CryptFile.close();
	system(("del /f \"" + OriginalFileName + "\"").c_str());
	system(("ren \"crypting\" \"" + OriginalFileName + "\"").c_str());
	TimerCryptorObj.End();
	TimerCryptorObj.Calc();
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_SYNC);
	SetConsoleTitle(L"ASCII File Cryptor");
	AnimationCryptorObj.FlashWindows();
	system("pause");
escape:
	std::cout << "";
}

void cryptor::Decrypt(std::string filename, std::string password) {
	SetConsoleTitle(L"ASCII File Cryptor - Decrypting");
	TimerCryptorObj.Start();
	char i;
	std::string OriginalFileName = filename;
	std::string TempData;
	std::ifstream InputFile(filename, std::ios::binary);
	std::ofstream DecryptFile("decrypting", std::ios::binary);
	int cryptkey = ConvertIntoKey(password);
	if (!InputFile) {
		InputFile.close();
		DecryptFile.close();
		system("del /f \"decrypting\"");
		std::cout << "Không tìm thấy hoặc không thể truy cập file ";
		AnimationCryptorObj.DotAnimation(500);
		goto escape;
	}
	if (!DecryptFile) {
		std::cout << "Không thể tạo file tạm thời (Thiếu quyền?) ";
		AnimationCryptorObj.DotAnimation(500);
		goto escape;
	}
	while (InputFile >> std::noskipws >> i) {
		i = i - cryptkey;
		TempData += i;
	}
	DecryptFile << TempData;
	std::cout << "Tệp đã được giải mã với mật khẩu: \"" << password << "\"" << std::endl;
	Sleep(1000);
	InputFile.close();
	DecryptFile.close();
	system(("del /f \"" + OriginalFileName + "\"").c_str());
	system(("ren \"decrypting\" \"" + OriginalFileName + "\"").c_str());
	TimerCryptorObj.End();
	TimerCryptorObj.Calc();
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_SYNC);
	SetConsoleTitle(L"ASCII File Cryptor");
	AnimationCryptorObj.FlashWindows();
	system("pause");
escape:
	std::cout << "";
}