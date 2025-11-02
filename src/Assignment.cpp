//
// Created by ybsxm on 10/28/2025.
//

#include "Assignment.h"

#include "Gradebook.h"

Assignment::Assignment(string name, int max_points) {
    this->name = name;
    this->max_points = max_points;
    this->grade = -1;
}

void Assignment::enterGrade(int grade) {
   this->grade = grade;
}
string Assignment::getName() {
    return this->name;
}
int Assignment::getGrade() {
    return this->grade;
}
int Assignment::getMaxPoints() {
    return this->max_points;
}