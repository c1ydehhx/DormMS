#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

#include "student_id.hpp"
#include "user/user.hpp"

class Student : public User {
  private:
    StudentID student_id;
    std::string name;
    std::string password;
    bool gender; // False -> Male, True -> Female
  public:
    Student(StudentID student_id, std::string name, bool gender,
            std::string password = "")
        : User(student_id.to_string(), password, RoleType::STUDENT),
          student_id(student_id), name(name), gender(gender) {}

    StudentID get_student_id() { return student_id; }

    std::string get_name() { return name; }

    bool get_gender() { return gender; }
};

#endif