#ifndef STUDENT_MANAGE_SYSTEM_HPP
#define STUDENT_MANAGE_SYSTEM_HPP

#include <iostream>
#include <vector>
#include <tabulate/table.hpp>

#include "student.hpp"

class StudentManageSystem{
private:
    std::vector<Student> students;
    StudentManageSystem(){
        
    }
public:
    static StudentManageSystem& get_instance(){
        static StudentManageSystem instance;
        return instance;
    }

    void add_student(Student student){
        students.push_back(student);
    }

    void delete_student(std::string ID){
        auto it = students.begin();

        for(int i = 0; it != students.end(); it++){
            if(it->get_student_id().to_string() == ID){
                break;
            }
        }

        if(it != students.end()){
            students.erase(it);
        }
    }

    void list_students(){
        tabulate::Table table;
        table.format().multi_byte_characters(true);

        table.add_row({"ID", "Name", "Gender", "Room", "Bed", "Password"});

        for(Student student : students){
            table.add_row({student.get_student_id().to_string(), student.get_name(), student.get_gender() == true ? "Female" : "Male", "21013", "2", student.get_password()});
        }

        table.print(std::cout);
        std::cout << std::endl;
    }
};

#endif