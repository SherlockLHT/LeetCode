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