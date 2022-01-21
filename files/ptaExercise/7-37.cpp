#include<stdio.h>

int N;

int s[31]; // 存放划分结果，这里用了比较简单地容器，数组，比我想象的要简单 
int top = -1; // 数组指针 
int count = 0; // 统计输出的次数 
int sum = 0; // 拆分项累加和 

void division (int i);

int main (){
    scanf ("%d", &N);
    division (1);
    return 0; 
}

void division (int i) {//拆分 
    if (sum == N) {
        count ++;
        printf("%d=", N);
        int k;
        for (k=0; k<top; k++) {
            printf("%d+", s[k]);
        }
        if (count%4 == 0 || s[top] == N) {
            printf("%d\n", s[top]);
        } else {
            printf("%d;", s[top]);
        }
        return;
    } // 输出部分 
    if (sum > N) {
        return;
    }
    for (int j=i; j<=N; j++) { 
        s[++top] = j;
        sum += j; 
        division (j);
        sum -= j;
        top --;
    } // 算法主体 
}
