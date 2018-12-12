#ifndef VALID_PALINDROME_H
#define VALID_PALINDROME_H

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
#include <iostream>
using namespace std;

bool isAlphanumeric(char ch)
{
	if (ch >= 48 && ch <= 57)
	{
		return true;
	}
	else if (ch >= 65 && ch <= 90)
	{
		return true;
	}
	else if (ch >= 97 && ch <= 122)
	{
		return true;
	}
	return false;
}

char toLower(char ch)
{
	if (ch >= 65 && ch <= 90)
	{
		return ch + 32;
	}
	return ch;
}

bool isPalindrome(string s) 
{
	bool b_status = true;
	int length = s.size();
	int forward_index = 0, backward_index = length - 1;
	while (forward_index < backward_index)
	{
		char forward_ch = s.at(forward_index);
		char backward_ch = s.at(backward_index);

		if (!isAlphanumeric(forward_ch))
		{
			forward_index++;
			continue;
		}
		
		if (!isAlphanumeric(backward_ch))
		{
			backward_index--;
			continue;
		}
		
		if (toLower(forward_ch) != toLower(backward_ch))
		{
			b_status = false;
			break;
		}
		forward_index++;
		backward_index--;
	}
	return b_status;
}

void TestIsPalindrome()
{
	string str = "0P";
	//string str = "abc";
	if (isPalindrome(str))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
}

#endif	//VALID_PALINDROME_H
