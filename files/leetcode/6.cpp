//remain to be solved

#include <stdlib.h>

char * convert(char * s, int numRows){
    if (numRows == 1) return s;
    char rows[1000][1000] = {'0'};
    int curRow = 0, curCol = 0;
    bool goingDown = false;
    for (int i = 0; i < numRows; ++i)
    {
        rows[curRow][curCol] = s[i];
        if (curRow == 0 || curRow == numRows - 1)
        {
            goingDown = !goingDown;
        }
        curRow += goingDown? 1:-1;
        curCol += goingDown? 0:1;
    }
    char *ret = (char*)malloc(sizeof(int)*sizeof(s));
    int count = 0;
    for (int i = 0; i < numRows; ++i)
    {
        int j = 0;
        while(rows[i][j] != '0')
        {
            ret[count] = rows[i][j];
            ++j;
            ++count;
        }
    }
    return ret;
}