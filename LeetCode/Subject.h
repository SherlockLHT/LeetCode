#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <map>
using namespace std;

/*
����һ�����������һ��Ŀ��ֵ���ҳ������к�ΪĿ��ֵ����������
����Լ���ÿ������ֻ��Ӧһ�ִ𰸣���ͬ����Ԫ�ز��ܱ��ظ����á�
ʾ��:
���� nums = [2, 7, 11, 15], target = 9
��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
*/

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	map<int, int> nums_map;
	vector<int>::iterator iter = nums.begin();
	int index = 0;
	for (; iter != nums.end(); ++iter, index++)
	{
		nums_map.insert(make_pair(*iter, index));
	}
	index = 0;
	for (iter = nums.begin(); iter != nums.end(); ++iter, index++)
	{
		int search_target = target - *iter;
		map<int, int>::iterator map_iterator = nums_map.find(search_target);
		if (map_iterator != nums_map.end() && map_iterator->second != index)
		{
			result.push_back(index);
			result.push_back(map_iterator->second);
			break;
		}
	}
	return result;
}

#endif	//SUBJECT_H