#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int search(vector<int>& nums, int target) 
		{
			return find_pivot(nums);
		}

		// --------------------------------------------------------------
		// 
		// 
		//  -------------------
		//  |		      |
		//  |		      |
		//  |        ---------|
		//  |        |	      |
		//  v        v	      v
		//  4, 5, 6, 7, 0, 1, 2
		//
		//
		//
		// --------------------------------------------------------------

		int find_pivot(vector<int> nums)
		{
			int start = 0,end = nums.size()-1;
			if (nums[start] > nums[start+1])
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1};
	Solution s;

	cout << s.search(nums, 2) << endl; 
	return 0;
}
