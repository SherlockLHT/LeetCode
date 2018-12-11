#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS
#define MEDIAN_OF_TWO_SORTED_ARRAYS

/*给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是(2 + 3) / 2 = 2.5

法一：计算两组数组的中位数，然后对两个中位数取平均值
*/



#include <iostream>
#include <vector>
using namespace std;

void PrintNums(const vector<int>& nums);
double GetMedian(const vector<int>& nums);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> new_nums;
	int index1 = 0, index2 = 0;
	//数组1和数组2在循环结束时，必是一个取完，一个未取完
	while (index1 < nums1.size() && index2 < nums2.size())
	{
		if (nums1.at(index1) < nums2.at(index2))
		{
			new_nums.push_back(nums1.at(index1++));
		}
		else
		{
			new_nums.push_back(nums2.at(index2++));
		}
	}
	if (index1 < nums1.size())//数组1没有取完，将其剩下的数据取出放入新数组
	{
		for (; index1 < nums1.size(); index1++)
		{
			new_nums.push_back(nums1.at(index1));
		}
	}
	else
	{
		for (; index2 < nums2.size(); index2++)
		{
			new_nums.push_back(nums2.at(index2));
		}
	}
	PrintNums(new_nums);

	return GetMedian(new_nums);
}

double GetMedian(const vector<int>& nums)
{
	int length = nums.size();
	if (length % 2 == 0)	//偶数
	{
		int sum = nums.at(length / 2 - 1) + nums.at(length / 2);
		return ((double)sum) / 2;
	}
	else
	{
		return (double)nums.at(length / 2);
	}
}

void PrintNums(const vector<int>& nums)
{
	for (int index = 0; index < nums.size(); index++)
	{
		cout << nums.at(index) << " ";
	}
	cout << endl;
}

void TestMedianOfTwoSortedArrays()
{
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {4};


	//double result = findMedianSortedArrays(nums1, nums2);
	double result = (GetMedian(nums1) + GetMedian(nums2)) / 2;

	cout << "Result: " << result << endl;
}

#endif	//MEDIAN_OF_TWO_SORTED_ARRAYS