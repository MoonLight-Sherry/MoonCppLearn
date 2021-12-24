#include <stdio.h>

void testfun2(int* i)
{
    (*i)++;
}

void testfun3(int *ptr)
{
    int i = 0;
    testfun2(ptr);
    printf("%d\n", i);
}

int main()
{
    int i = 0;
    int *ptr = &i;
    testfun3(&i);
    printf("%d\n", i);
    testfun2(ptr);
}

void testfun1()
{
    void testfun2(int*);
}



