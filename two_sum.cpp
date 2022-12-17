#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> consecutive_idx;

			// loop through array and continuesly check
			// for partner in second array which result into
			// target value.
			for (int i = 0; i < nums.size()-1; i++)
			{
				for (j = i+1; j < nums.size(); j++)
				{
					if (nums[i] + nums[j] == target)
					{
						consecutive_idx.push_back(i);
						consecutive_idx.push_back(j);
					}
				}
			}

			return consecutive_idx;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> testing;
	testing.push_back(4);
	testing.push_back(4);

	vector<int> consective = s.twoSum(testing, 8);
	std::cout << consective[0] << " " << consective[1] << std::endl;
}
