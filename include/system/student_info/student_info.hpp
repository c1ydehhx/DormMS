#ifndef STUDENT_INFO_HPP
#define STUDENT_INFO_HPP

#include "system/student_manage/student_manage.hpp"
#include "user/current_user.hpp"
#include "user/student.hpp"
#include "user/user.hpp"
#include <memory>
class StudentInfoSystem {
  private:
    StudentInfoSystem() {}

  public:
    static StudentInfoSystem &get_instance() {
        static StudentInfoSystem student_info_system;
        return student_info_system;
    }
    static void show() {
        std::shared_ptr<User> user =
            CurrentLoginUser::get_instance().get_user();

        std::shared_ptr<Student> student =
            StudentManageSystem::get_instance().get_student(
                user->get_account());

        if (student != nullptr) {
            std::cout << "Here is your information:" << std::endl;
            std::cout << "- Student ID: " << student->get_account()
                      << std::endl;
            std::cout << "- Name: " << student->get_name() << std::endl;
            std::cout << "- Gender: "
                      << (student->get_gender() == GenderType::FEMALE ? "FEMALE"
                                                                      : "MALE")
                      << std::endl;
            std::cout << "- Role: "
                      << (student->get_role() == RoleType::ADMIN ? "ADMIN"
                                                                 : "STUDENT")
                      << std::endl;
        } else {
            std::cerr << "Unexcpeted Error: Student is absent." << std::endl;
        }
    }
};

#endif