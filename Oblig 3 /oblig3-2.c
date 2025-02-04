#include <stdio.h>
#include <stdbool.h>

int totalOblig[4] = {1, 2, 3, 4}; // Array for total required tasks, no point of including 5 and 6
int studentAnswer;  // Stores the number of tasks completed by the student, prompted for in main 

// Function to check if the student is allowed to take the exam
bool kanjaellernei(int *grades, int num_tasks_completed) {
    int count = 0;

    // Count the number of tasks completed (grades[i] == 1 means completed)
    for (int i = 0; i < 6; i++) {
        if (grades[i] == 1) {
            count++;
        }
    }

    // Student must complete at least 4 tasks, and one of them must be either task 3 or task 6
    if (count >= 4 && (grades[2] == 1 || grades[5] == 1)) { // 2 means task 3rd, and 5 means 6th task.
        printf("Ja, studenten får gå opp til eksamen\n");
        return true;
    } else {
        printf("Nei, studenten får IKKE gå opp til eksamen\n");
        return false;
    }
}

int main() {
    // Explain the requirement
    printf("Hvor mange obligatoriske oppgaver trenger man for å få tilgang til eksamen?\n");
    printf("Det trengs %d obligatoriske oppgaver!\n", totalOblig[3]);

    // Ask how many tasks the student completed
    printf("Hvor mange obligatoriske oppgaver har du innlevert? (kun heletall): \n");
    scanf("%d", &studentAnswer);

    // Two sample of students' grades examples. Arrays
    int student1_grades[6] = {1, 1, 0, 0, 1, 1}; // Represents tasks completion status
    int student2_grades[6] = {1, 1, 1, 0, 0, 1}; // 1 = true, 2= false

    // Check for the first student example student grades
    printf("\nStudent 1 status:\n");
    kanjaellernei(student1_grades, studentAnswer);

    // Check for the second set of example student grades
    printf("\nStudent 2 status:\n");
    kanjaellernei(student2_grades, studentAnswer);

    return 0; // success!!
}
// done