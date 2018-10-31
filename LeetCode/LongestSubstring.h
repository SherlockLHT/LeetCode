#ifndef LONGEST_SUBSTRING_H
#define LONGEST_SUBSTRING_H

#include <iostream>
using namespace std;

/*
给定一个字符串，找出不含有重复字符的最长子串的长度。
示例 1:
输入: "abcabcbb"
输出: 3
解释: 无重复字符的最长子串是 "abc"，其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/
int lengthOfLongestSubstring(string s)	//暴力遍历
{
	if (s.empty())
	{
		return 0;
	}
	
	int max_length = 1;
	for (int out_index = 0; out_index < s.length() - 1; out_index++)
	{
		string current_max_str = s.substr(out_index, 1);
		for (int in_index = out_index + 1; in_index < s.length(); in_index++)
		{
			char c = s.at(in_index);
			if (string::npos != current_max_str.find(c))
			{
				break;
			}
			current_max_str = current_max_str + c;
		}
		max_length = (max_length >= current_max_str.length()) ? max_length : current_max_str.length();
	}
	return max_length;
}
//和法一的区别在于，遍历发现重复不必要再加1继续，而是可以跳过重复的那一段
int lengthOfLongestSubstring2(string s)
{
	if (s.empty())
	{
		return 0;
	}

	int max_length = 1;
	for (int out_index = 0; out_index < s.length() - 1; out_index++)
	{
		string current_max_str = s.substr(out_index, 1);
		for (int in_index = out_index + 1; in_index < s.length(); in_index++)
		{
			char c = s.at(in_index);
			int find_index = current_max_str.find(c);
			if (string::npos != find_index)
			{
				int next_index = s.find(current_max_str) + current_max_str.find(c);
				out_index = (out_index < next_index) ? next_index : out_index;
				break;
			}
			current_max_str = current_max_str + c;
		}
		max_length = (max_length >= current_max_str.length()) ? max_length : current_max_str.length();
	}
	return max_length;
}

void TestLongestSubstring()
{
	string str = "pwwkew";
	/*char c = 'a';
	cout << Contain(str, c);
	return;*/
	cout << "Longest substring length: " << lengthOfLongestSubstring2(str) << endl;
}

#endif	//LONGEST_SUBSTRING_H
