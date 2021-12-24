int getString( char * source , char *strPtr[] )
{
    char *cur = source;
    strPtr[0] = source;
    int count = 1;
    while(*cur != 0)
    {
        while(*cur != ' ')
        {
            ++cur;
        }
        *cur = '\0';
        strPtr[count] = ++cur;
        ++count;
    }
    --count;
    return count;
}