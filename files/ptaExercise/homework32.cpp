#include <stdio.h>

int main()
{
    char cur;
    while(scanf("%c", &cur))
    {
        char changed;
        if(cur < 'x' || cur < 'X')
        {
            changed = cur + 3;
        }
        else{
            changed = cur - 23;
        }
        printf("%c", changed);
    }
    return 0;
}