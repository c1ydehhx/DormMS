#ifndef STUDENT_MENU_HPP
#define STUDENT_MENU_HPP

#include "system/student_info/student_info.hpp"
#include "user/current_user.hpp"
#include "user/user.hpp"
#include <iostream>
class StudentMenu {
  private:
    static void enter_show_information_procedure() {
        StudentInfoSystem::get_instance().show();
        std::cout << std::endl;
    }

  public:
    static void enter_student_menu() {
        int choice = 0;

        while (true) {
            std::shared_ptr<User> user =
                CurrentLoginUser::get_instance().get_user();

            std::cout << "Hi, " << user->get_account() << ". Welcome to DormMS."
                      << std::endl;
            std::cout
                << "------------------------------------------------------"
                << std::endl;
            std::cout << "Please select function:" << std::endl;
            std::cout << " - [1] Show my information" << std::endl;
            std::cout << " - [0] Exit System" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter your choice: ";

            std::cin >> choice;

            std::cout << std::endl;

            switch (choice) {
            case 0:
                return;
            case 1:
                enter_show_information_procedure();
                break;
            default:
                std::cout << "Please, select function in the list" << std::endl;
            }

            choice = 0;
        }
    }
};

#endif