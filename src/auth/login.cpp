#include <iostream>
#include <optional>
#include <unistd.h>

#include "auth/login.hpp"
#include "system/student_manage/student.hpp"
#include "system/student_manage/student_manage.hpp"

void LoginPortal::authenticate(std::string username, std::string password) {}

void LoginPortal::login() {
    std::cout << "DormMS v0.1" << std::endl;

    while (true) {
        std::string account;

        std::cout << "Username: ";
        std::cin >> account;

        char *password = getpass("Password: ");

        optional<Student> optional_student =
            StudentManageSystem::get_instance().get_student(account);

        if (account == "admin" && std::string(password) == "admin") {
            std::cout << "Login Success." << std::endl;
            std::cout << std::endl;
            break;
        }

        if (optional_student.has_value() &&
            optional_student->authenticate(password)) {
            std::cout << "Login Success." << std::endl;
            std::cout << std::endl;
            break;
        }

        std::cout << "Try again." << std::endl;
        std::cout << std::endl;
    }
}