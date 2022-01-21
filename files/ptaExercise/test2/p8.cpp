
#include<stdio.h>

#define        MAXLEN        500000
void  sortAndOutput(int *data , int size) ;

int main()
{
    int        data[MAXLEN];
    int        n, i;

    scanf( "%d" , &n );
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &data[i] );

    sortAndOutput( data, n ) ;

    return 0;    
}

void  sortAndOutput(int *data , int size)
{
    // struct peopleft
    // {
    //     int num, n;
    //     int *data;
    // };
    int people[1050];
    int count = 0;
    for (int i = 0; i < size ;)
    {
        people[count] = i;
        i += data[people[count] + 1] + 2;
        count++;
    }
    people[count] = size;
    for (int i = 0; i < count ; i++)
    {
        int index = 0;
        while(data[people[index]] == -1){++index;}
        for (int j = 0; j < count; ++j)
        {
            if (data[people[j]] < data[people[index]] && data[people[j]] != -1)
            {
                index = j;
            }
        }
        for (int k = people[index]; k < people[index + 1] - 1; ++k)
        {
            printf("%d ", data[k]);
        }
        printf("%d\n", data[people[index + 1] - 1]);
        people[index];
        data[people[index]] = -1;
    }
}
