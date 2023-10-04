//RA2211003010129 Assignment-3 Question-7

#include <stdio.h>

typedef union {
    int subject1_10129;
    int subject2_10129;
} SubjectMarks_10129;

typedef struct {
    SubjectMarks_10129 marks_10129[2];
} StudentMarks_10129;

int main() {
    StudentMarks_10129 students_10129[3];  // Mark lists for 3 students and 2 subjects

    // Input marks for each student and each subject
    for (int i = 0; i < 3; i++) {
        printf("Enter marks for student %d, subject 1: ", i + 1);
        scanf("%d", &students_10129[i].marks_10129[0].subject1_10129);

        printf("Enter marks for student %d, subject 2: ", i + 1);
        scanf("%d", &students_10129[i].marks_10129[1].subject2_10129);
    }

    // Display the mark lists for each student and each subject
    for (int i = 0; i < 3; i++) {
        printf("Student %d, Subject 1 marks: %d\n", i + 1, students_10129[i].marks_10129[0].subject1_10129);
        printf("Student %d, Subject 2 marks: %d\n", i + 1, students_10129[i].marks_10129[1].subject2_10129);
    }

    return 0;
}
