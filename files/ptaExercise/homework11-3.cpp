int getVowel(char str[],char vowel[])
{
    int count = 0;
    for (int i = 0; i < sizeof(str)/sizeof(str[0]); ++i)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowel[count] = str[i];
            count++;
        }
    }
    return count;
} 