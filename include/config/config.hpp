#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

class Configuration {
private:
    std::string student_data_path;
    std::string dorm_data_path;
    Configuration() {
        
    }
public:
    static Configuration& get_instance(){
        static Configuration configuration;
        return configuration;
    }
    
    std::string get_student_data_path(){
        return student_data_path;
    }
    
    std::string get_dorm_data_path(){
        return dorm_data_path;
    }

    void load_configuration(std::string path){
        std::ifstream f(path);
        nlohmann::json data = nlohmann::json::parse(f);

        student_data_path = data["student_data"];

        std::cout << "Load student data by path: " << student_data_path << std::endl;

        dorm_data_path = data["dorm_data"];

        std::cout << "Load dorm data by path: " << dorm_data_path << std::endl;
    }
};

#endif