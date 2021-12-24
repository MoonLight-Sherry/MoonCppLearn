#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[30];
    char name[30];
    int scores[5];
} STUDENT;

int main()
{
    int n;
    scanf("%d", &n);
    while (getchar() != '\n')
    {
        continue;
    }
    STUDENT **students = (STUDENT **)malloc(n * sizeof(STUDENT *));
    for (int i = 0; i < n; ++i)
    {
        students[i] = (STUDENT *)malloc(sizeof(STUDENT));
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int kase;
        scanf("%d", &kase);
        getchar();
        switch (kase)
        {
            char temp[30];
        case 1:
        {
            scanf("%s", &temp);
            int found1 = 0;
            for (int j = 0; j < count; ++j)
            {
                if (strcmp(students[j]->id, temp) == 0)
                {
                    printf("Students already exist\n");
                    found1 = 1;
                    break;
                }
            }
            if (found1 == 0)
            {
                strcpy(students[count]->id, temp);
                scanf("%s", &(students[count]->name));
                for (int j = 0; j < 3; ++j)
                {
                    scanf("%d", &(students[count]->scores[j]));
                }
                printf("Add success\n");
                count++;
            }
            break;
        }
        case 2:
        {
            scanf("%s", &temp);
            int found = 0;
            for (int j = 0; j < count; ++j)
            {
                if (strcmp(students[j]->id, temp) == 0)
                {
                    for (int k = j; j < count - 1; ++j)
                    {
                        strcpy(students[j]->id, students[j+1]->id);
                        strcpy(students[j]->name, students[j+1]->name);
                        memcpy(students[j]->scores, students[j+1]->scores, 5*sizeof(int));
                    }
                    count--;
                    printf("Delete success\n");
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("Students do not exist\n");
            }
            break;
        }
        case 3:
        {
            scanf("%s", &temp);
            int found2 = 0;
            for (int j = 0; j < count; ++j)
            {
                if (strcmp(students[j]->id, temp) == 0)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        scanf("%d", &(students[j]->scores[k]));
                    }
                    printf("Update success\n");
                    found2 = 1;
                    break;
                }
            }
            if (found2 == 0)
            {
                printf("Students do not exist\n");
            }
            break;
        }
        case 4:
        {
            scanf("%s", &temp);
            int found3 = 0;
            for (int j = 0; j < count; ++j)
            {
                if (strcmp(students[j]->id, temp) == 0)
                {
                    int sum = (students[j])->scores[0] + (students[j])->scores[1] + (students[j])->scores[2];
                    double average = (double)sum / 3;
                    printf("Student ID:%s\nName:%s\nAverage Score:%.1lf\n", students[j]->id, students[j]->name, average);
                    found3 = 1;
                    break;
                }
            }
            if (found3 == 0)
            {
                printf("Students do not exist\n");
            }
            break;
        }
        }
        while (getchar() != '\n')
        {
            continue;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        free(students[i]);
    }
    free(students);
    return 0;
}