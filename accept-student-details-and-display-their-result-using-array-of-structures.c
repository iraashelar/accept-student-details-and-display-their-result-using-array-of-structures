#include <stdio.h>

#define SUBJECTS 3
#define PASS_MARKS 40

struct Student {
    int roll;
    char name[50];
    int marks[SUBJECTS];
    int total;
    float percentage;
    char result[5];
};

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Accept details
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        int passed = 1;

        for (int j = 0; j < SUBJECTS; j++) {
            printf("Enter marks of subject %d (out of 100): ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
            if (s[i].marks[j] < PASS_MARKS) {
                passed = 0;
            }
        }

        s[i].percentage = (float)s[i].total / SUBJECTS;

        if (passed) {
            sprintf(s[i].result, "Pass");
        } else {
            sprintf(s[i].result, "Fail");
        }
    }

    // Display results
    printf("\n================ STUDENT RESULTS ================\n");
    for (int i = 0; i < n; i++) {
        printf("\nRoll No    : %d\n", s[i].roll);
        printf("Name       : %s\n", s[i].name);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d  : %d\n", j + 1, s[i].marks[j]);
        }
        printf("Total      : %d / %d\n", s[i].total, SUBJECTS * 100);
        printf("Percentage : %.2f%%\n", s[i].percentage);
        printf("Result     : %s\n", s[i].result);
    }

    return 0;
}
