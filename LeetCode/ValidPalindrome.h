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

const char SPACE_CH = 32;

bool isPalindrome(string s) 
{
	bool b_status = true;
	int length = s.size();
	int forward_index = 0, backward_index = length - 1;
	while (forward_index < backward_index)
	{
		char forward_ch = s.at(forward_index);
		if (forward_ch == SPACE_CH)
		{
			continue;
		}
		forward_index++;
		char backward_ch = s.at(backward_index);
		if (backward_ch == SPACE_CH)
		{
			continue;
		}
		backward_index--;
		if (forward_ch != backward_ch)
		{
			b_status = false;
			break;
		}
	}
	return b_status;
}

void TestIsPalindrome()
{
	string str = "A man, a plan, a canal: Panama";
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
