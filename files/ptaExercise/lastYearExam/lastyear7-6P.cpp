#include <stdio.h>
inline int read()
{
    int f=1,k=0;char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-')f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
int a[20][2];
signed main()
{
    int n=read();
    for (int i=1;i<=5;i++)
        a[i][0]=read(),a[i][1]=read();
    for (int i=5;i<=9;i++)
    {
        int ret=0;
        for (int j=1;j<=5;j++)
            ret+=(a[j][0]==i&&a[j][1])|(a[j][0]!=i&&!a[j][1]);
        if (ret==n)
            return printf("%d",i),0;
    }
}