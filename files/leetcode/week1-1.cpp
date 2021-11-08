#include <iostream>
#include <string>

using namespace std;

int countValidWords(string sentence)
{
    int cnt = 0;
    int senlen = sentence.length();
    int j = 0;
    for (; j < senlen; ++j)
    {
        while (j < senlen && sentence[j] == ' ')
            ++j;
        int length = 0;
        while (j + length < senlen && sentence[j + length] != ' ')
            ++length;
        int hyphen = 0;
        for (int i = j; i < j + length; ++i)
        {
            if (isdigit(sentence[i]))
            {
                break;
            }
            if (sentence[i] == '-')
            {
                if (hyphen == 0 && i - 1 >= 0 && isalpha(sentence[i - 1]) && i < senlen - 1 && isalpha(sentence[i + 1]))
                    ++hyphen;
                else
                    break;
            }
            if (sentence[i] == '!' || sentence[i] == ',' || sentence[i] == '.')
            {
                if (i == j + length - 1)
                {
                    cnt++;
                    break;
                }
                break;
            }
            if (isalpha(sentence[i]) && i != j + length - 1)
                continue;
            if (isalpha(sentence[i]) && i == j + length - 1)
                cnt++;
        }
        j += length;
    }
    return cnt;
}

int main()
{
    string sentence = "-";
    int cnt = countValidWords(sentence);
    cout << cnt << endl;
    return 0;
}
