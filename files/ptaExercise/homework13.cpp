#include <stdio.h>

typedef struct
{
    char name[25];
    char id[25];
    int scores[5];
    double avarage;
    int total;
}STUDENT;

int main()
{
    STUDENT stu;
    gets(stu.name);
    gets(stu.id);
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", stu.scores+i);
        sum += stu.scores[i];
        getchar();
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = i; j < 5; ++j)
        {
            if (stu.scores[i] < stu.scores[j])
            {
                int temp = stu.scores[i];
                stu.scores[i] = stu.scores[j];
                stu.scores[j] = temp;
            }
        }
    }
    stu.avarage = (double)sum/5;
    stu.total = sum;
    STUDENT *student = &stu;
    printf("Name:%s\nID:%s\nScore:%d %d %d %d %d\naverage:%.2lf total:%d\n", student->name, student->id, student->scores[0], student->scores[1], student->scores[2], student->scores[3],student->scores[4], student->avarage, student->total);
    return 0;
}