#include "Subject.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);

	DWORD start_time = ::GetTickCount();

	vector<int> result = twoSum(nums, 9);

	DWORD end_time = ::GetTickCount();
	cout << "Cost time:" << end_time - start_time << "ms" << endl;

	for (int index = 0; index < result.size(); index++)
	{
		cout << result.at(index) << ",";
	}
	cout << endl;
}