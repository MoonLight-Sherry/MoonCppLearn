#include <stdio.h>
#include <cstdio>
#include <iostream>

#include "SolutionWordCount.h"

using namespace std;

void countWord(string sentence);

int main()
{
	
	string sentence = "a word-count, only valid words, not invalid! 8wo 8-a !not etc.";
	countWord(sentence);

	sentence = "-a word-count, ";
	countWord(sentence);

	sentence = ",! ";
	countWord(sentence);

	sentence = "a,!";
	countWord(sentence);

	sentence = "a,! ";
	countWord(sentence);
}
void countWord(string sentence) {
	Solution wordCount;
	int count = wordCount.countValidWords(sentence);
	cout << "Sentence: " << sentence << ". WordCount: " << count << endl << endl;
}

int main1()
{
	float score[10] = { 0 };
	float sum =0, result;
	for (int i = 0; i < 7; ++i)
	{
		scanf("%f", &score[i]);
		sum += score[i];
	}
	result = sum / 7;
	if (sum > 90) {
		printf("A");
	}
	else if (sum > 70) {
		printf("B");
	}
	else if (sum > 50) {
		printf("C");
	}
	else {
		printf("D");
	}
	printf(":%.2f\n", result);
	return 0;
}