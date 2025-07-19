#ifndef STUDENT_ID_HPP
#define STUDENT_ID_HPP

#include <string>

class StudentID {
private:
    std::string ID;
public:
    StudentID(std::string ID){
        this->ID = ID;
    }

    std::string to_string(){
        return ID;
    }
};

#endif