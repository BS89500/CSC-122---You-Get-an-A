#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/Gradebook.h"

TEST_CASE( "Gradebook Test" ) {
    Gradebook gradebook;

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
    // The outputted report might look something like this:

    // Last_Name,First_Name,Student_Id,Quiz_1,Lab_1
    // Bobberson,Bob,ABC123,85,0
    // Jesserson,Jess,HIJ789,93,49
    // Sammerson,Sam,DEF456,95,none
    REQUIRE( gradebook.report() == "Bobberson, Bob, ABC123, 85, 0\nJesserson, Jess, HIJ789, 93, 49\nSammerson, Sam, DEF456, 95, none\n" );
}

TEST_CASE("No Students") {
    Gradebook gradebook;
    REQUIRE(gradebook.report() == "Error: No Students in Gradebook");
}
