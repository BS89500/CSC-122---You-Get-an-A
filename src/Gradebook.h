//
// Created by ybsxm on 10/28/2025.
//

#ifndef YOU_GET_AN_A_GRADEBOOK_H
#define YOU_GET_AN_A_GRADEBOOK_H
#include <vector>

#include "Assignment.h"
#include "Student.h"
#include <map>
#include <tuple>

using namespace std;

class Gradebook {
    private:
    std::map<std::string, std::tuple<Student, vector<Assignment>>> gradebook;
    public:
    Gradebook();
    void add_student(string name, string id);
    void add_assignment(string name, int max_grade);
    void enter_grade(string name, string assignmentName, int grade);
    string assignment_report(string);
    string report();
    Assignment get_assignment(string name);
};


#endif //YOU_GET_AN_A_GRADEBOOK_H