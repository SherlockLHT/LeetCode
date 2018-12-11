#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS
#define MEDIAN_OF_TWO_SORTED_ARRAYS

/*����������СΪ m �� n ���������� nums1 �� nums2��
�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��
����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�

ʾ�� 1:
nums1 = [1, 3]
nums2 = [2]
����λ���� 2.0

ʾ�� 2:
nums1 = [1, 2]
nums2 = [3, 4]

����λ����(2 + 3) / 2 = 2.5

��һ�����������������λ����Ȼ���������λ��ȡƽ��ֵ
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
	//����1������2��ѭ������ʱ������һ��ȡ�꣬һ��δȡ��
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
	if (index1 < nums1.size())//����1û��ȡ�꣬����ʣ�µ�����ȡ������������
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
	if (length % 2 == 0)	//ż��
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