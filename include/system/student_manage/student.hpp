#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

#include "student_id.hpp"

class Student{
private:
    StudentID student_id;
    std::string name;
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

    bool get_gender(){
        return gender;
    }
};

#endif