#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <iostream>

#include "menu/student_manage_menu.hpp"

class MainMenu {
  public:
    static void enter_main_menu() {
        int choice = 0;

        while (true) {
            std::cout << "Welcome to NTUT Dorm Management System" << std::endl;
            std::cout
                << "------------------------------------------------------"
                << std::endl;
            std::cout << "Please select function:" << std::endl;
            std::cout << " - [1] Student Management" << std::endl;
            std::cout << " - [2] Room Management" << std::endl;
            std::cout << " - [3] Bed Assignment" << std::endl;
            std::cout << " - [4] Show Configuration" << std::endl;
            std::cout << " - [0] Exit System" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter your choice: ";

            std::cin >> choice;

            switch (choice) {
            case 0:
                exit(0);
            case 1:
                StudentManageMenu::enter_student_manage_system();
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
            }

            choice = 0;
        }
    }
};

#endif