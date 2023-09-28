#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		vector<int> result;
		int swap_idx = 0;

		if (nums[0] % 2 == 0)
			result.push_back(nums[swap_idx++]);
		else {
			result.push_back(nums[0]);
		}

		
		for (int idx = 1; idx < nums.size(); idx++)
		{
			if (val % 2 != 0) {
				result.push_back(nums[idx]);
			}
			else {
				if (swap_idx < result.size()) {
					result.push_back(result[swap_idx]);
					result[swap_idx++] = nums[idx];
				} else {
					result.push_back(nums[idx]);
				}
			}
		}
		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = { 0, 2 };

	vector<int> result = s.sortArrayByParity(nums);
	for (int in: result) 
		cout << in << endl;
	return 0;
}
