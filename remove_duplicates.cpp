#include <iostream>
#include <vector>
using namespace std;

//
// Given an integer array nums sorted in non-decreasing order remove the duplicates in-place
// such that each unique element appears only once. The relative order of the elements should be
// kept the same
//
// Since it is impossible to change the length of the array in some language you must
// instead have the result by placed in the first part of the array nums. More formally
// if there are k elements after remvoeing the duplicates the first k element of nums
// should hold the final result. It does not matter what you leave beyond the first k elements
//
// Return k after placing the final result in the first k slots of nums
//
// Do not allocate extra space for another array. You must do this by modifying the input arrayy
// in-place with O(1) extra memory
//
class Solution {
	public:
		int removeDuplicates(vector<int>& nums)
		{
			int curidx = 0, idx, prev;

			prev = nums[0];
			curidx = 0;
			for (idx = 1; idx < nums.size(); idx++)
			{
				if (prev == nums[idx]) 
					continue;

				prev = nums[idx];
				nums[++curidx] = nums[idx];
			}
			return ++curidx;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };

	cout << s.removeDuplicates(nums) << endl;
	return 0;
}
