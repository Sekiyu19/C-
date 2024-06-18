#include <iostream>
#include <string>

int main() {
    std::cout << "Please input your first name" << std::endl;
    std::string first_name;
    std::cin >> first_name;

    std::cout << "Please input your middle name" << std::endl;
    std::string middle_name;
    std::cin >> middle_name;

    std::cout << "Please input your last name" << std::endl;
    std::string last_name;
    std::cin >> last_name;

    for(int i = 0; i < first_name.size() + middle_name.size() + last_name.size() + 14; i++) {
      std::cout << "*";
    }
    std::cout << std::endl << "* ";
    for(int i = 0; i < first_name.size() + middle_name.size() + last_name.size() + 10; i++) {
      std::cout << " ";
    }
    std::cout << " *" << std::endl;
    std::cout << "* Hello, " << first_name << " " << middle_name << " " << last_name << "! *" << std::endl;
    std::cout << "* ";
    for(int i = 0; i < first_name.size() + middle_name.size() + last_name.size() + 10; i++) {
      std::cout << " ";
    }
    std::cout << " *" << std::endl;
    for(int i = 0; i < first_name.size() + middle_name.size() + last_name.size() + 14; i++) {
      std::cout << "*";
    }
    std::cout << std::endl;
    
    return 0;
}

// 5. 正常に動作するが、表示の幅があるので長すぎると改行されてしまい綺麗に表示されない。

// 6. 英語以外の場合、stringのsizeが1ではなくなることがある。
//    日本語はそのまま表示される。
