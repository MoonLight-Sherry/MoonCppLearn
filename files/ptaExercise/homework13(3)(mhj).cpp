#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(suppress : 4996)
//define this as universal constant to avoid "30" in many places. 
//If it needs to change, just change here, instead of changing in many places, even some place missed.
#define maxNameLen 30
typedef struct
{
	char id[30];
	char name[maxNameLen];
	int scores[5];
} STUDENT;

//subtract below function for re-use in every case
int search(STUDENT** students, int size, char* idToSearch) {
	for (int j = 0; j < size; ++j)
	{
		if (strcmp(students[j]->id, idToSearch) == 0)
		{
			return j;
		}
	}
	return -1;
}

#pragma warning(disable : 4996)
int main()
{
	int n;
	scanf("%d", &n);
	while (getchar() != '\n')
	{
		continue;
	}
	STUDENT** students = (STUDENT**)malloc(n * sizeof(STUDENT*));
	//for (int i = 0; i < n; ++i)
	//{
	//	students[i] = (STUDENT*)malloc(sizeof(STUDENT));
	//}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		int kase;
		scanf("%d", &kase);
		getchar();

		//put these lines here to avoid repetitive code in every case
		char inputId[maxNameLen];
		scanf("%s", &inputId, maxNameLen);
		int idPos = search(students, count, inputId);

		switch (kase)
		{

		case 1:
		{
			if (idPos < 0) {
				students[count] = (STUDENT*)malloc(sizeof(STUDENT));

				strcpy(students[count]->id, inputId);
				scanf("%s", &(students[count]->name), maxNameLen);
				for (int j = 0; j < 3; ++j)
				{
					scanf("%d", &(students[count]->scores[j]));
				}
				printf("Add success\n");
				count++;
			}
			else {
				printf("Students already exist\n");
			}
			break;
		}

		case 2:
		{
			if (idPos < 0) {
				printf("Students do not exist\n");
			}
			else {
				free(students[idPos]); //Important!!
				for (int k = idPos; k < count - 1; ++k)
				{
					students[k] = students[k + 1];
				}
				students[count - 1] = 0; //need to set this last pointer as null
				count--;

				printf("Delete success\n");
			}
			break;
		}

		case 3:
		{
			if (idPos < 0)
			{
				printf("Students do not exist\n");
			}
			else {
				for (int k = 0; k < 3; ++k)
				{
					scanf("%d", &(students[idPos]->scores[k]), maxNameLen);
				}
				printf("Update success\n");
			}
			break;
		}

		case 4:
		{
			if (idPos < 0)
			{
				printf("Students do not exist\n");
			}
			else
			{
				int sum = (students[idPos])->scores[0] + (students[idPos])->scores[1] + (students[idPos])->scores[2];
				double average = (double)sum / 3;
				printf("Student ID:%s\nName:%s\nAverage Score:%.1lf\n", students[idPos]->id, students[idPos]->name, average);
			}
			break;
		}

		}

		while (getchar() != '\n')
		{
			continue;
		}
	}

	for (int i = 0; i < count; ++i) //must use count instead of n
	{
		free(students[i]);
	}
	free(students);
	return 0;
}