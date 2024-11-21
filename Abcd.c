#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 6
#define NUM_SEMESTERS 3

// Function to calculate the top 4 subject marks for a student
void top_4_subject_marks(int student_marks[NUM_SUBJECTS][NUM_SEMESTERS], int student_id) {
    int marks[NUM_SUBJECTS * NUM_SEMESTERS];
    int k = 0;
    
    // Flatten the student's marks into a single array
    for (int i = 0; i < NUM_SEMESTERS; i++) {
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            marks[k++] = student_marks[j][i];
        }
    }
    
    // Sort the marks in descending order to find top 4
    for (int i = 0; i < NUM_SUBJECTS * NUM_SEMESTERS - 1; i++) {
        for (int j = i + 1; j < NUM_SUBJECTS * NUM_SEMESTERS; j++) {
            if (marks[i] < marks[j]) {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
    
    // Print the top 4 marks
    printf("Top 4 marks for Student %d: ", student_id);
    for (int i = 0; i < 4; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");
}

// Function to find the top 5 scorers in each subject
void top_5_scorers_in_subject(int marks[NUM_STUDENTS][NUM_SUBJECTS][NUM_SEMESTERS], int subject_id) {
    int subject_marks[NUM_STUDENTS];
    
    // Extract marks for the specified subject in all semesters for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        subject_marks[i] = 0;
        for (int j = 0; j < NUM_SEMESTERS; j++) {
            subject_marks[i] += marks[i][subject_id][j];
        }
    }

    // Sort the students based on the subject marks in descending order
    for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = i + 1; j < NUM_STUDENTS; j++) {
            if (subject_marks[i] < subject_marks[j]) {
                int temp = subject_marks[i];
                subject_marks[i] = subject_marks[j];
                subject_marks[j] = temp;
            }
        }
    }

    // Print the top 5 scorers in the subject
    printf("Top 5 scorers in Subject %d: ", subject_id + 1);
    for (int i = 0; i < 5 && i < NUM_STUDENTS; i++) {
        printf("Student %d(%d) ", i + 1, subject_marks[i]);
    }
    printf("\n");
}

// Function to find semester-wise top scorer list
void semester_wise_top_scorer(int marks[NUM_STUDENTS][NUM_SUBJECTS][NUM_SEMESTERS]) {
    int semester_total_marks[NUM_SEMESTERS][NUM_STUDENTS];

    // Calculate total marks per student in each semester
    for (int i = 0; i < NUM_SEMESTERS; i++) {
        for (int j = 0; j < NUM_STUDENTS; j++) {
            semester_total_marks[i][j] = 0;
            for (int k = 0; k < NUM_SUBJECTS; k++) {
                semester_total_marks[i][j] += marks[j][k][i];
            }
        }
    }

    // Find top scorer for each semester
    for (int i = 0; i < NUM_SEMESTERS; i++) {
        int max_marks = -1;
        int top_scorer = -1;
        
        for (int j = 0; j < NUM_STUDENTS; j++) {
            if (semester_total_marks[i][j] > max_marks) {
                max_marks = semester_total_marks[i][j];
                top_scorer = j;
            }
        }
        
        printf("Top scorer in Semester %d: Student %d with total marks %d\n", i + 1, top_scorer + 1, max_marks);
    }
}

int main() {
    // 3 semesters, 6 subjects, 5 students
    int marks[NUM_STUDENTS][NUM_SUBJECTS][NUM_SEMESTERS] = {
        {{85, 90, 78}, {88, 92, 95}, {80, 85, 75}, {90, 95, 98}, {88, 89, 92}, {85, 92, 96}},  // Student 1
        {{78, 84, 88}, {82, 91, 90}, {75, 80, 70}, {85, 88, 92}, {80, 85, 90}, {88, 87, 94}},  // Student 2
        {{92, 85, 76}, {89, 80, 85}, {88, 90, 84}, {91, 93, 97}, {85, 86, 90}, {90, 88, 93}},  // Student 3
        {{75, 80, 65}, {72, 78, 85}, {70, 74, 65}, {80, 82, 85}, {90, 87, 89}, {65, 70, 72}},  // Student 4
        {{65, 75, 80}, {85, 87, 90}, {92, 95, 100}, {85, 80, 85}, {70, 70, 75}, {88, 90, 92}}   // Student 5
    };

    // Part (a) Top 4 subject marks for each student
    for (int i = 0; i < NUM_STUDENTS; i++) {
        top_4_subject_marks(marks[i], i + 1);
    }

    // Part (b) Top 5 scorers in each subject
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        top_5_scorers_in_subject(marks, i);
    }

    // Part (c) Semester-wise top scorer list
    semester_wise_top_scorer(marks);

    return 0;
}
