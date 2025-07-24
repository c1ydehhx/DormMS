#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <cstddef>
#include <memory>
#include <string>

#include "student_id.hpp"
#include "user/user.hpp"

enum class GenderType { MALE, FEMALE };

class Bed;

class Student : public User {
  private:
    StudentID student_id;
    std::string name;
    GenderType gender;

    std::shared_ptr<Bed> bed = nullptr;

  public:
    Student(StudentID student_id, std::string name, GenderType gender,
            std::string password = "")
        : User(student_id.to_string(), password, RoleType::STUDENT),
          student_id(student_id), name(name), gender(gender) {}

    StudentID get_student_id() { return student_id; }

    std::string get_name() { return name; }

    GenderType get_gender() { return gender; }

    std::shared_ptr<Bed> get_bed() { return this->bed; }

    void set_bed(std::shared_ptr<Bed> bed) { this->bed = bed; }
};

#endif