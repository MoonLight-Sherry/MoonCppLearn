#include<stdio.h>

void delcharfun(char *str,char ch);

int main()
{
    char    ch,str[110];

    scanf("%s",str);    //读入字符串 
    getchar();            //读取回车符号 
    scanf("%c",&ch);    //读入字符 
    delcharfun(str,ch);    //删除 
    printf("%s\n",str);    //输出删除后结果 
    return 0;    
}

void delcharfun(char *str,char ch)
{
    while(*str != 0)
    {
        if (*str == ch)
        {
            char* cur = str;
            while(*cur != 0)
            {
                *cur = *(cur + 1);
                ++cur;
            }
        }
        while(*str != 0 && *str != ch)
        {
            ++str;
        }
    }
}