#include <iostream>

#include "src/Gradebook.h"
#include "src/hello.hpp"

int main() {
  std::cout << hello() << std::endl;
  Gradebook gradebook;
  cout << gradebook.report();

  gradebook.add_student("Bob Bobberson", "ABC123");
  gradebook.add_student("Sam Sammerson", "DEF456");
  gradebook.add_student("Jess Jesserson", "HIJ789");

  gradebook.add_assignment("Quiz 1", 100);
  gradebook.add_assignment("Lab 1", 50);

  gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
  gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
  gradebook.enter_grade("Jess Jesserson", "Lab 1", 49);
  gradebook.enter_grade("Jess Jesserson", "Quiz 1", 93);
  gradebook.enter_grade("Bob Bobberson", "Lab 1", 0);

  cout << gradebook.report();
  //cout << gradebook.assignment_report("Lab 1");
}
