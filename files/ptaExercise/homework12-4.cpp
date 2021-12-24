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
        
        while(*str != ch && *str != 0){++str;}
        if (*str == 0){break;}
        char *cur = str;
        while(*cur == ch){++cur;}
        if (*(cur-1) == ch)
        {
            while(*cur != 0)
            {
                *str = *cur;
                ++cur;
                ++str;
            }
        }
    }
}