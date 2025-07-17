#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

#include "student_id.hpp"
#include "util/sha256.hpp"

class Student{
private:
    StudentID student_id;
    std::string name;
    std::string password;
    bool gender; // False -> Male, True -> Female
public:
    Student(StudentID student_id, std::string name, bool gender) : student_id(student_id), name(name), gender(gender) {
        
    }

    StudentID get_student_id(){
        return student_id;
    }

    std::string get_name(){
        return name;
    }

    std::string get_password(){
        return password;
    }

    bool get_gender(){
        return gender;
    }

    void set_password(std::string password){
        this->password = sha256(password);
    }
};

#endif