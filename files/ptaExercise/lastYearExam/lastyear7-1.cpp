#include <stdio.h>

int main()
{
    float score[10] = {0};
    float sum = 0, result;
    for(int i = 0; i < 7; ++i)
    {
        scanf("%f", &score[i]);
        sum += score[i];
    }
    result = sum/7;
    if (sum >90){
        printf("A");
    }
    else if (sum > 70){
        printf("B");
    }
    else if (sum >50){
        printf("C");
    }
    else{
        printf("D");
    }
    printf(":%.1f\n", result);
    return 0;
}

//10min