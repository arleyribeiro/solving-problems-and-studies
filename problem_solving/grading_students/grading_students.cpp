#include <bits/stdc++.h>

using namespace std;

#define MULTIPLE_5 5
#define MIN_DIFFERENCE 3
#define MIN_GRADE 38

int calculateGradingStudents(int grade) {
    int result = grade;
    int rest = grade % MULTIPLE_5;
    int difference = MULTIPLE_5 - rest;
    if (difference < MIN_DIFFERENCE && grade >= MIN_GRADE) {
        result = grade + difference;
    }
    return result;
}

int main() {

    int numberOfGrades, grade;
    scanf("%d", &numberOfGrades);
    while (numberOfGrades--) {        
        scanf("%d", &grade);
        printf("%d\n", calculateGradingStudents(grade));
    }
    return 0;
}