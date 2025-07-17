#ifndef STUDENT_MANAGE_MENU_HPP
#define STUDENT_MANAGE_MENU_HPP

#include <iostream>
#include <unistd.h>

#include "config/config.hpp"
#include "system/student_manage/student.hpp"
#include "system/student_manage/student_id.hpp"
#include "system/student_manage/student_manage.hpp"

class StudentManageMenu {
  private:
    static void enter_list_student_procedure() {
        StudentManageSystem::get_instance().list_students();
        std::cout << std::endl;

        return;
    }

    static void enter_add_student_procedure() {
        std::string student_id_str;
        std::string student_name;

        std::cout << "<1/4> Please enter student ID: ";
        std::cin >> student_id_str;

        std::cout << "<2/4> Please enter student name: ";
        std::cin >> student_name;

        std::string gender;

        while (gender != "M" && gender != "F") {
            std::cout << "<3/4> Please enter student gender (M/F): ";
            std::cin >> gender;
        }

        char *password =
            getpass("<4/4> Please enter password for this student: ");

        Student student(StudentID(student_id_str), student_name, gender == "F");

        student.set_password(password);

        StudentManageSystem::get_instance().add_student(student);

        std::cout << "Enter student successfully." << std::endl << std::endl;

        return;
    }

    static void enter_delete_student_procedure() {
        std::string student_id_str;
        std::string sure;

        std::cout << "<1/2> Please enter student ID: ";
        std::cin >> student_id_str;

        std::cout << "<2/2> Are you sure? (y/n) ";
        std::cin >> sure;

        if (sure == "y" || sure == "Y") {
            std::cout << "Delete student successfully." << std::endl
                      << std::endl;
        } else {
            std::cout << "Exit procedure." << std::endl << std::endl;
        }

        return;
    }

    static void enter_commit_procedure() {
        std::string sure;

        std::cout << "<1/1> Are you sure? (y/n) ";
        std::cin >> sure;

        if (sure == "y" || sure == "Y") {
            StudentManageSystem::get_instance().commit();
            std::cout << "Commit." << std::endl << std::endl;
        } else {
            std::cout << "Exit procedure." << std::endl << std::endl;
        }
    }

  public:
    static void enter_student_manage_system() {
        int choice = 0;

        while (true) {
            std::cout << "Student Manage System" << std::endl;
            std::cout
                << "------------------------------------------------------"
                << std::endl;
            std::cout << "Please select function:" << std::endl;
            std::cout << " - [1] Add Student" << std::endl;
            std::cout << " - [2] Delete Student" << std::endl;
            std::cout << " - [3] List Student" << std::endl;
            std::cout << " - [4] Commit" << std::endl;
            std::cout << " - [0] Back to Main Menu" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter your choice: ";

            std::cin >> choice;

            switch (choice) {
            case 0:
                return;
            case 1:
                enter_add_student_procedure();
                break;
            case 2:
                enter_delete_student_procedure();
                break;
            case 3:
                enter_list_student_procedure();
                break;
            case 4:
                enter_commit_procedure();
            default:
                std::cout << "Please, select function in the list" << std::endl;
                break;
            }

            choice = 0;
        }
    }
};

#endif