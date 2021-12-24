#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    char* test1 = (char*)malloc(sizeof(char)*2);
    int m =  test1 < test1 + 1;
    int n = test1 < test1 + 1;
    printf("%d\n%d\n", m, n);//数组后项比前项地址大
    printf("%d", &m > &n);
    cout << endl;
    int a1;
    int a2;
    printf("%p %p\n", &a1, &a2);
    cout << (&a1 > &a2) << endl;//先定义的内存地址大
    return 0;
}