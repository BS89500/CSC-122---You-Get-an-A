//
// Created by ybsxm on 10/28/2025.
//

#include "Student.h"

Student::Student(string name, string id) {
    this->name = name;
    this->id = id;
}
string Student::getFirstName() {
    string first_name = "";
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == ' ') {
            break;
        }
        first_name += name[i];
    }
    return first_name;
}
string Student::getLastName() {
    int index = name.find(' ');
    string last_name = "";
    for (int i = index + 1; i < name.length(); i++) {
        last_name += name[i];
    }
    return last_name;
}
string Student::getId() {
    return id;
}
