#include<stdio.h>
#define STUDENTS 5
#define SUBJECT 6
#define SEMESTER 3
void top_4_Subject_Marks(int student_marks[SUBJECT][SEMESTER],int roll){
    int marks[SUBJECT*SEMESTER];
    int k=0;
    //Merge the each student all subject all marks
    for(int i=0;i<SEMESTER;i++){
        for(int j=0;j<SUBJECT;j++){
            marks[k]=student_marks[j][i];
            k++;
        }
    }
     for (int i = 0; i <(SUBJECT*SEMESTER)- 1; i++) {
        for (int j = i + 1; j <SUBJECT*SEMESTER; j++) {
            if (marks[i] < marks[j]) {
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
    printf("Student %d top 4 marks: ",roll);
    for(int i=0;i<4;i++){
        printf("%d ",marks[i]);
    }
    
}



void top_5_scorers_in_each_subject(int marks[STUDENTS][SUBJECT][SEMESTER], int subject_id) {
    int subject_marks[STUDENTS];
    // Extract marks for the specified subject in all semesters for each student
    for (int i = 0; i < STUDENTS; i++) {
         subject_marks[i]= 0;
        for ( int j = 0; j <SEMESTER; j++) {
           
            subject_marks[i] += marks[i][subject_id][j];
        }
    }

    // Sorting the students based on the subject marks
    for (int i = 0; i <STUDENTS - 1; i++) {
        for (int j = i + 1; j <STUDENTS; j++) {
            if (subject_marks[i] < subject_marks[j]) {
                int temp = subject_marks[i];
                subject_marks[i] = subject_marks[j];
                subject_marks[j] = temp;
            }
        }
    }


    printf("Top 5 scorers in Subject %d: ", subject_id + 1);
    for (int i = 0; i < 5 && i <STUDENTS; i++) {
        printf("Student %d(%d) ", i + 1, subject_marks[i]);
    }
    printf("\n");
}

void semester_wise_top_scorer(int marks[STUDENTS][SUBJECT][SEMESTER]) {
    int semester_total_marks[SEMESTER][STUDENTS];

    // Calculate total marks per student in each semester
    for (int i = 0; i < SEMESTER; i++) {
        for (int j = 0; j < STUDENTS; j++) {
            semester_total_marks[i][j] = 0;
            for (int k = 0; k < SUBJECT; k++) {
                semester_total_marks[i][j] += marks[j][k][i];
            }
        }
    }

    // Find top scorer for each semester
    for (int i = 0; i < SEMESTER; i++) {
        int max_marks = -1;
        int top_scorer = -1;
        
        for (int j = 0; j < STUDENTS; j++) {
            if (semester_total_marks[i][j] > max_marks) {
                max_marks = semester_total_marks[i][j];
                top_scorer = j;
            }
        }
        
        printf("Top scorer in Semester %d: Student %d with total marks %d\n", i + 1, top_scorer + 1, max_marks);
    }
}

int main(){
    int marks[STUDENTS][SUBJECT][SEMESTER]={
        {{92, 90, 78}, {88, 92, 95}, {90, 85, 75}, {90, 95, 98}, {88, 89, 92}, {85, 82, 96}},  // roll 1
        {{72, 95, 88}, {82, 91, 90}, {75, 80, 70}, {85, 88, 92}, {80, 85, 90}, {88, 87, 94}},  // roll 2
        {{92, 85, 76}, {89, 80, 85}, {88, 90, 84}, {91, 93, 97}, {85, 86, 90}, {90, 88, 93}},  // roll 3
        {{85, 81, 65}, {72, 78, 85}, {70, 74, 65}, {80, 82, 85}, {90, 87, 79}, {65, 70, 72}},  // roll 4
        {{77, 75, 80}, {85, 87, 90}, {92, 95, 100}, {85, 80, 85}, {70, 70, 75}, {88, 90, 92}}   // roll 5
    };
    for(int i=0;i<STUDENTS;i++){
        top_4_Subject_Marks(marks[i],i+1);
        printf("\n");
    }
    for (int i = 0; i <SUBJECT; i++) {
        top_5_scorers_in_each_subject(marks, i);
    }
    semester_wise_top_scorer(marks);
    return 0;
}