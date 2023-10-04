//RA2211003010129 Assignment-3 Question-7

#include <stdio.h>

// Define a structure called Date to represent the date of birth
typedef struct {
    int day;
    int month;
    int year;
} Date_10129;

// Define a structure called Student that includes student's ID, name, and date of birth
typedef struct {
    int studentID_10129;
    char name_10129[100];
    Date_10129 dob_10129;
} Student_10129;

// Define a structure called Course that includes course code, course name, and instructor's name
typedef struct {
    char courseCode_10129[10];
    char courseName_10129[100];
    char instructorName_10129[100];
} Course_10129;

// Function to enter information about a student
void enterStudentInfo_10129(Student_10129 *students_10129, int index) {
    printf("Enter student ID: ");
    scanf("%d", &students_10129[index].studentID_10129);
    printf("Enter student name: ");
    scanf("%s", students_10129[index].name_10129);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &students_10129[index].dob_10129.day, &students_10129[index].dob_10129.month, &students_10129[index].dob_10129.year);
}

// Function to enter information about a course
void enterCourseInfo_10129(Course_10129 *courses_10129, int index) {
    printf("Enter course code: ");
    scanf("%s", courses_10129[index].courseCode_10129);
    printf("Enter course name: ");
    scanf("%s", courses_10129[index].courseName_10129);
    printf("Enter instructor's name: ");
    scanf("%s", courses_10129[index].instructorName_10129);
}

// Function to display information of all students
void displayStudentInfo_10129(Student_10129 *students_10129, int numStudents_10129) {
    printf("Student Information:\n");
    for (int i = 0; i < numStudents_10129; i++) {
        printf("Student ID: %d, Name: %s, Date of Birth: %d/%d/%d\n", students_10129[i].studentID_10129, students_10129[i].name_10129, students_10129[i].dob_10129.day, students_10129[i].dob_10129.month, students_10129[i].dob_10129.year);
    }
}

// Function to display information of all courses
void displayCourseInfo_10129(Course_10129 *courses_10129, int numCourses_10129) {
    printf("Course Information:\n");
    for (int i = 0; i < numCourses_10129; i++) {
        printf("Course Code: %s, Course Name: %s, Instructor: %s\n", courses_10129[i].courseCode_10129, courses_10129[i].courseName_10129, courses_10129[i].instructorName_10129);
    }
}

int main() {
    Student_10129 students_10129[10]; // Array of Student structures to store information for multiple students
    Course_10129 courses_10129[5];    // Array of Course structures to store information for multiple courses

    int numStudents_10129, numCourses_10129;

    printf("Enter the number of students (up to 10): ");
    scanf("%d", &numStudents_10129);

    // Input student information
    for (int i = 0; i < numStudents_10129; i++) {
        enterStudentInfo_10129(students_10129, i);
    }

    printf("Enter the number of courses (up to 5): ");
    scanf("%d", &numCourses_10129);

    // Input course information
    for (int i = 0; i < numCourses_10129; i++) {
        enterCourseInfo_10129(courses_10129, i);
    }

    // Display student and course information
    displayStudentInfo_10129(students_10129, numStudents_10129);
    displayCourseInfo_10129(courses_10129, numCourses_10129);

    return 0;
}
