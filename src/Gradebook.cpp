//
// Created by ybsxm on 10/28/2025.
//

#include "Gradebook.h"
#include <sstream>
#include <cmath>
#include <iostream>

Gradebook::Gradebook() {
    //no-op
    cout << "successful" << endl;
}
void Gradebook::add_student(string name, string id) {
    Student s(name, id);
    vector<Assignment> assignments;
    gradebook.insert(make_pair(name, make_tuple(s, assignments)));
}
void Gradebook::add_assignment(string name, int max_grade) {
    Assignment ass(name, max_grade);
    for (auto it = gradebook.begin();it != gradebook.end(); it++) {
        std::get<1>(it->second).push_back(ass);
    }
}

void Gradebook::enter_grade(string name, string assignmentName, int grade) {
    vector<Assignment>& ass = std::get<1>(gradebook.find(name)->second);
    vector<Assignment>::iterator it;
    for (it = ass.begin(); it != ass.end(); it++) {
        if (it->getName() == assignmentName) {
            it->enterGrade(grade);
            break;
        }
    }
}

string Gradebook::report() {
    string report = "";
    try {
        if (gradebook.size() == 0) {
            throw "Error: No Students in Gradebook";
        }

        for (auto it = gradebook.begin();it != gradebook.end(); it++) {
            Student& student = std::get<0>(it->second);
            vector<Assignment> assignments = std::get<1>(it->second);
            report += student.getLastName() + ", " + student.getFirstName() + ", " + student.getId() + ", ";
            for (auto iter = assignments.begin();iter != assignments.end(); iter++) {
                if (iter->getGrade() == -1) {
                    report += "none\n";
                }
                else if (iter == assignments.end() - 1) {
                    report += to_string(iter->getGrade()) + "\n";
                }
                else {
                    report += to_string(iter->getGrade()) + ", ";
                }
            }
        }
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    catch(...) {
        cout << "Error" << endl;
    }

    return report;
}


string Gradebook::assignment_report(string ass) {
    string report = "";
    int max;
    float grade = 0;
    int counter = 0;

    for (auto it = gradebook.begin();it != gradebook.end(); it++) {
        Student& student = std::get<0>(it->second);
        vector<Assignment> assignments = std::get<1>(it->second);
        report += student.getLastName() + ", " + student.getFirstName() + ", " + student.getId() + ", ";
        for (auto iter = assignments.begin();iter != assignments.end(); iter++) {
            if (iter->getName() == ass) {
                if (iter->getGrade() == -1) {
                    report += "none\n";
                }
                else {
                    report += to_string(iter->getGrade()) + "\n";
                    max = iter->getMaxPoints();
                    grade += iter->getGrade();
                    counter++;
                }
            }
        }
    }
    std::ostringstream out;
    float avg = (grade) / counter;
    out.precision(1);
    out << std::fixed << report <<"\nAverage Score: " << avg << " / " << max << endl;
    return std::move(out).str();
}

