//
// Created by ybsxm on 10/28/2025.
//

#ifndef YOU_GET_AN_A_ASSIGNMENT_H
#define YOU_GET_AN_A_ASSIGNMENT_H
#include <string>
using namespace std;

class Assignment {
private:
    string name;
    int grade;
    int max_points;
public:
    Assignment(string name, int max_points);
    void enterGrade(int grade);
    string getName();
    int getGrade();
    int getMaxPoints();
};



#endif //YOU_GET_AN_A_ASSIGNMENT_H