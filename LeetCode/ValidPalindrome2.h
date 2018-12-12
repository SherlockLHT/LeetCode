#ifndef VALID_PALINDROME2_H
#define VALID_PALINDROME2_H

#include <iostream>
using namespace std;

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

bool isPalindrome(string s)
{
	int length = s.size();
	int forward_index = 0, backward_index = length - 1;
	while (forward_index < backward_index)
	{
		if (s.at(forward_index) != s.at(backward_index))
		{
			return false;
		}
		forward_index++;
		backward_index--;
	}
	return true;
}

bool validPalindrome(string s) {
	if (isPalindrome(s))
	{
		return true;
	}
	
	for (int index = 0; index < s.size(); index++)
	{
		string str = s;
		str.erase(index, 1);
		if (isPalindrome(str))
		{
			return true;
		}
	}
	
	return false;
}

void TestIsPalindrome()
{
	string str = "abca";
	if (validPalindrome(str))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
}

#endif //VALID_PALINDROME2_H
