#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

void sound(int kase)
{
	string pinyin;
	switch (kase)
	{
	case 1: pinyin = "yi"; break;
	case 2: pinyin = "er"; break;
	case 3: pinyin = "san"; break;
	case 4: pinyin = "si"; break;
	case 5: pinyin = "wu"; break;
	case 6: pinyin = "liu"; break;
	case 7: pinyin = "qi"; break;
	case 8: pinyin = "ba"; break;
	case 9: pinyin = "jiu"; break;
	case 0: pinyin = "ling"; break;
	}
	cout << pinyin;
}

int main()
{
	char curNum;
	int sum = 0;
	while (scanf("%c", &curNum) && curNum != '\n')
	{
		sum += curNum - '0';
	}
	int digit = 1 + log10(sum);
	for (int i = digit; i > 0; --i)
	{
		int kase = sum / (pow(10, i-1));
		sound(kase);
		if (i != 1) printf(" ");
		else printf("\n");
		sum = sum - kase * pow(10, i - 1);
	}
	return 0;
}