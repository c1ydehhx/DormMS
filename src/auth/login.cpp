#include <iostream>
#include <memory>
#include <unistd.h>

#include "auth/login.hpp"
#include "system/student_manage/student.hpp"
#include "system/student_manage/student_manage.hpp"
#include "user/admin.hpp"
#include "user/user.hpp"

std::shared_ptr<User> LoginPortal::get_user_by_account(std::string account) {
    if (account == "admin") {
        return std::make_shared<User>(Admin::get_instance());
    }

    optional<Student> optional_student =
        StudentManageSystem::get_instance().get_student(account);

    if (optional_student.has_value()) {
        return std::make_shared<User>(optional_student.value());
    } else {
        return NULL;
    }
}

void LoginPortal::login() {
    std::cout << "DormMS v0.1" << std::endl;

    while (true) {
        std::string account;

        std::cout << "Username: ";
        std::cin >> account;

        char *password = getpass("Password: ");

        std::shared_ptr<User> user = get_user_by_account(account);

        if (user != NULL && user->authenticate(password)) {
            std::cout << "Login Success." << std::endl;
            std::cout << std::endl;
            break;
        }

        std::cout << "Try again." << std::endl;
        std::cout << std::endl;
    }
}