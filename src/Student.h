//
// Created by ybsxm on 10/28/2025.
//

#ifndef YOU_GET_AN_A_STUDENT_H
#define YOU_GET_AN_A_STUDENT_H
#include <string>
using namespace std;

class Student {
    private:
    string name;
    string firstName;
    string lastName;
    string id;
public:
    Student(string name, string id);
    string getFirstName();
    string getLastName();
    string getId();
};


#endif //YOU_GET_AN_A_STUDENT_H