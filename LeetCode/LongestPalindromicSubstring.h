#ifndef LONGEST_PALINDROMIC_SUBSTRING
#define LONGEST_PALINDROMIC_SUBSTRING

#include <iostream>
using namespace std;

/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��
���� : "babad"
��� : "bab"
ע�� : "aba" Ҳ��һ����Ч�𰸡�

ʾ�� 2��
���� : "cbbd"
��� : "bb"
*/

string longestPalindrome(string s) 
{
	int length = s.length();
	string result_str;

	return result_str;
}

void TestLongestPalindrome()
{
	string str = "babad";
	string substring = longestPalindrome(str);
	cout << substring.c_str() << endl;
}

#endif	//LONGEST_PALINDROMIC_SUBSTRING
