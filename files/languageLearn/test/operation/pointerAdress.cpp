#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int i[2] = {0};
    int *p1 = i;
    printf("%p\n%p\n", i, &i);
    return 0;
    
}