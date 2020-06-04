#include <bits/stdc++.h>
using namespace std;

#define MAX_LENGTH 99999999
vector<int> problems;

int main () {
    int chapters = 0, limitProblems, aux, countProblems = 0;
    
    scanf("%d %d", &chapters, &limitProblems);

    problems.push_back(0);
    for (int i = 0; i < chapters; i++) {
        scanf("%d ", &aux);
        problems.push_back(aux);
    }

    int pageBook = 1;
    for (int chapter = 1; chapter <= chapters; chapter++) {
        int problemsPerChapter = problems[chapter];
        int pages = ceil((problemsPerChapter * 1.0) / (limitProblems * 1.0));
        
        int startProblem = 1, 
        endProblem = limitProblems < problemsPerChapter ? limitProblems : problemsPerChapter;
        
        for(int page = 1; page <= pages; page++) {
            if (pageBook >= startProblem && pageBook <= endProblem) {
                countProblems++;
            }

            if (endProblem + 1 <= problemsPerChapter)
                startProblem = endProblem + 1;
            else
                startProblem = endProblem;

            if ((endProblem + limitProblems) < problemsPerChapter)
                endProblem += limitProblems;
            else
                endProblem = problemsPerChapter;
            pageBook++;
        }
    }

    printf("%d\n", countProblems);

    return 0;
}