#pragma once
#include <string>
using namespace std;


class Solution
{
public:
	int countValidWords(string sentence)
	{
		printSentence(sentence);

		int cnt = 0;
		int senlen = sentence.length();
		int start = 0;
		int end = start + 1;
		while (start < senlen) //always not modify for-loop variables inside loop
		{
			while (start < senlen && sentence[start] == ' ')
				++start;
			int end = start + 1;//So end is NOT included in word!!!
			while (end < senlen && sentence[end] != ' ')
				++end;

			int hyphen = 0;
			for (int i = start; i < end; ++i)
			{
				if (isdigit(sentence[i]))
				{
					break;
					printIsntWord(sentence, start, end);
				}
				if (sentence[i] == '-')
				{
					//break below different if-conditions in different lines
					if (hyphen == 0 
						&& i - 1 >= 0 && isalpha(sentence[i - 1]) 
						&& i + 1 < senlen && isalpha(sentence[i + 1]))
						++hyphen;
					else {
						printIsntWord(sentence, start, end);
						break;
					}
				}
				if (sentence[i] == '!' || sentence[i] == ',' || sentence[i] == '.')
				{
					if (i == end - 1)
					{
						cnt++;
						//break;// why here?
						printIsWord(sentence, start, end);
					}
					else {
						printIsntWord(sentence, start, end);
					}
					break;
				}
				if (isalpha(sentence[i]) && i != end - 1) {
					continue;
				}
				else if (isalpha(sentence[i]) && i == end - 1) {
					printIsWord(sentence, start, end);
					cnt++;
					break;
				}
				else if (i == end - 1){
					printIsntWord(sentence, start, end);
				}
			}
			start = end;
		}
		return cnt;
	}

private:
	//Always has debug info output, and you can comment out them when submitting code
	void printIsntWord(string sentence, int start, int end) {
		printf("Isn't Word: %s. start:%d, end:%d\n\r", sentence.substr(start, end - start).c_str(), start, end);
	};
	void printIsWord(string sentence, int start, int end) {
		printf("Word: %s. start:%d, end:%d\n\r", sentence.substr(start, end - start).c_str(), start, end);
	};
	void printSentence(string sentence) {
		printf("sentence is: %s", sentence.c_str());
	};
};