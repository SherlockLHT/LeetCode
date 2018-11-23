#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>
#include <iostream>
using namespace std;

//归并
void Merge(vector<int>& in_nums, int start_index, int middle_index, int end_index)
{
	int pre_index = start_index;
	int after_index = middle_index + 1;
	int out_index = start_index;
	vector<int> origin_nums(in_nums);	//保存原数组数据，留作取数据用
	while (pre_index <= middle_index && after_index <= end_index)
	{
		int pre_num = origin_nums.at(pre_index);
		int after_num = origin_nums.at(after_index);
		if (pre_num < after_num)
		{
			in_nums[out_index++] = pre_num;
			pre_index++;
		}
		else
		{
			in_nums[out_index++] = after_num;
			after_index++;
		}
	}
	//将剩下的数据填入数组
	if (pre_index <= middle_index)//后一个数组取完，前一个未取完
	{
		while (pre_index <= middle_index)
		{
			in_nums[out_index++] = origin_nums.at(pre_index++);
		}
	}
	else
	{
		while (after_index <= end_index)
		{
			in_nums[out_index++] = origin_nums.at(after_index++);
		}
	}
}

void Sort(vector<int>& nums, int start_index, int end_index)
{
	if (start_index < end_index)
	{
		int middle_index = (start_index + end_index) / 2;
		Sort(nums, start_index, middle_index);
		Sort(nums, middle_index + 1, end_index);
		Merge(nums, start_index, middle_index, end_index);
	}
}

//对外标准接口
void MergeSort(const vector<int>& in_nums, vector<int>& out_nums)
{
	out_nums = in_nums;
	Sort(out_nums, 0, in_nums.size() - 1);
}
//打印数组
void Print(const vector<int>& nums)
{
	for (int index = 0; index < nums.size(); index++)
	{
		cout << nums.at(index) << " ";
	}
	cout << endl;
}

void TestMergeSort()
{
	vector<int> in = {8,4,5,7,1,3,6,2};
	vector<int> out;

	MergeSort(in, out);
	Print(out);
}


#endif	//MERGE_SORT
