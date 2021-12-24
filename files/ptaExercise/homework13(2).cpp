#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[25];
    int total;
}STUDENT;

void input(STUDENT *student)
{
    scanf("%s", &(student->name));
    getchar();
    scanf("%d", &(student->total));
}

int main()
{
    int n;
    scanf("%d", &n);
    STUDENT ** students = (STUDENT**)malloc(n*sizeof(STUDENT*));
    for (int i = 0; i < n; ++i)
    {
        students[i] = (STUDENT*)malloc(sizeof(STUDENT));
    }
    for (int i = 0; i < n; ++i)
    {
        getchar();
        input(students[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (students[i]->total < students[j]->total)
            {
                STUDENT *temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
            else if (students[i]->total == students[j]->total)
            {
                if (strcmp(students[i]->name, students[j]->name) > 0)
                {
                    STUDENT *temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("Name:%s\ntotal:%d\n", students[i]->name, students[i]->total);
        printf("\n");
    }
    return 0;
}