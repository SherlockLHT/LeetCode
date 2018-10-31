#ifndef LONGEST_SUBSTRING_H
#define LONGEST_SUBSTRING_H

#include <iostream>
using namespace std;

/*
����һ���ַ������ҳ��������ظ��ַ�����Ӵ��ĳ��ȡ�
ʾ�� 1:
����: "abcabcbb"
���: 3
����: ���ظ��ַ�����Ӵ��� "abc"���䳤��Ϊ 3��
ʾ�� 2:
����: "bbbbb"
���: 1
����: ���ظ��ַ�����Ӵ��� "b"���䳤��Ϊ 1��
ʾ�� 3:
����: "pwwkew"
���: 3
����: ���ظ��ַ�����Ӵ��� "wke"���䳤��Ϊ 3��
��ע�⣬�𰸱�����һ���Ӵ���"pwke" ��һ�������� �������Ӵ���
*/
int lengthOfLongestSubstring(string s)	//��������
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
//�ͷ�һ���������ڣ����������ظ�����Ҫ�ټ�1���������ǿ��������ظ�����һ��
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
