#include <iostream>
#include <string>
#include "../Sources/Headers/menu.h"
#include "../Sources/Headers/cryptor.h"
#include "../Sources/Headers/animation.h"


/*	Tạo object từ classes (Create object from classes)	*/
cryptor CryptorMenuObj;
animation AnimationMenuObj;

/*	Định nghĩa các hàm class 'menu' (Define 'menu' class functions)	*/
void menu::ShowMenu() {
	std::cout << "1. Mã hoá file\n";
	std::cout << "2. Giải mã file\n";
	std::cout << "3. Thoát chương trình";
	std::cout << std::endl;
}

int menu::SelectOption() {
	int i;
	bool ValidOption = false;
	while (ValidOption == false) {
		system("cls");
		ShowMenu();
		std::cout << std::endl;
		std::cout << "Nhập lựa chọn: ";
		std::cin >> i;
		if (i > 0 && i < 4) {
			ValidOption = true;
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return i;
}

void menu::ProcessOption(int option) {
	switch (option) {
	case 1: {
		system("cls");
		ShowMenu();
		std::cout << std::endl;
		std::string filename;
		std::string password;
		std::cout << "# Backup file gốc trước khi mã hoá tránh lỗi.\n";
		std::cout << "# Mật khẩu mã hoá cho phép tối đa 100 ký tự.\n";
		std::cout << "# Chấp nhận chữ cái và số latin, các ký tự đặc biệt ~!@#$%^&*()_ và cả khoảng trống.\n";
		std::cout << std::endl;
		std::cout << "Nhập tên file: ";
		std::getline(std::cin, filename);
		while (true) {
			std::cout << "Nhập mật khẩu mã hoá: ";
			std::getline(std::cin, password);
			if (password.length() <= 100) break;
			else std::cout << "Mật khẩu mã hoá cho phép tối đa 100 ký tự." << std::endl;
		}
		CryptorMenuObj.Encrypt(filename, password);
		break; 
	}
	case 2: {
		system("cls");
		ShowMenu();
		std::cout << std::endl;
		std::string filename;
		std::string password;
		std::cout << "# Backup file gốc trước khi giải mã tránh lỗi hoặc để thử lại nếu nhập sai mật khẩu.\n";
		std::cout << "# Nhập sai mật khẫu mã hoá sẽ dẫn tới file hỏng hoàn toàn\n";
		std::cout << std::endl;
		std::cout << "Nhập tên file: ";
		std::getline(std::cin, filename);
		while (true) {
			std::cout << "Nhập mật khẩu mã hoá: ";
			std::getline(std::cin, password);
			if (password.length() <= 100) break;
			else std::cout << "Mật khẩu mã hoá cho phép tối đa 100 ký tự." << std::endl;
		}
		CryptorMenuObj.Decrypt(filename, password);
		break; 
	}
	case 3:
		system("cls");
		ShowMenu();
		std::cout << std::endl;
		std::cout << "> ";
		AnimationMenuObj.DotAnimation(100);
		exit(0);
		break;
	default:
		break;
	}
}
