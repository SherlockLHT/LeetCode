#ifndef PALINDROME_NUMBER_H
#define PALINDROME_NUMBER_H

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
	if (x == 0)
	{
		return true;
	}
	if (x < 0 || x % 10 == 0)
	{
		return false;
	}
	int pre_forward = x;
	int forward = x;
	int backward = 0;
	while (forward >= backward * 10)
	{
		int n = forward % 10;
		backward = backward * 10 + n;
		pre_forward = forward;
		forward = forward / 10;
	}

	if (pre_forward == backward || forward == backward)
	{
		return true;
	}

	return false;
}

void TestIsPalindrome(){

	int num = 101;

	if (isPalindrome(num))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
#endif	//PALINDROME_NUMBER_H
