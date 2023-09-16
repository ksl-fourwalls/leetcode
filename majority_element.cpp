#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
	public:
		int majorityElement(vector<int>& nums) {
			map<int, int> hmap;
			pair<int, int> result;

			for (int idx = 0; idx < nums.size(); idx++)
				hmap[nums[idx]]++;

			result.second = 0;
			for (auto& val: hmap)
			{
				if (val.second > result.second)
					result = val;
			}
			return result.first;
		}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums = {
		3, 2, 3
	};
	cout << s.majorityElement(nums) << endl;
	return 0;
}
