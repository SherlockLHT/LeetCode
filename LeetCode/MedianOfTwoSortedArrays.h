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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	double median_num = 0.00;

	PrintNums(nums1);

	return median_num;
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
	vector<int> nums1;
	vector<int> nums2;

	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(4);
	nums1.push_back(5);

	nums2.push_back(7);
	nums2.push_back(8);

	double result = findMedianSortedArrays(nums1, nums2);

	cout << "Result: " << result << endl;
}

#endif	//MEDIAN_OF_TWO_SORTED_ARRAYS