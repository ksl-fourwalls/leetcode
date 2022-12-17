#include <iostream>
#include <vector>
using namespace std;

#define arraysize(array) (sizeof(array) / sizeof(*array))

class Solution {
	public:
		vector<int> findErrorNums(vector<int>& nums) 
		{
			vector<int> result;
			for (int idy = 0; idy < nums.size()-1; idy++)
			{
				for (int idx = idy+1; idx < nums.size(); idx++)
				{
					if (nums[idx] == nums[idy])
					{
						result.push_back(nums[idy]);

						int which[] = { idx, idy };
						for (int i = 0; i < arraysize(which); i++)
						{
							if (
									(which[i]-1 >= 0 && nums[which[i]-1] == (nums[which[i]]-1)) ||
									(which[i]+1 < nums.size() && nums[which[i]+1] == (nums[which[i]]+1))
							   )
							{
								result.push_back(nums[which[i]]);
							}
						}
					}
				}
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> v = {1, 1};
	vector<int> nums = s.findErrorNums(v);

	for (int idx = 0; idx < nums.size(); idx++)
		cout << nums[idx] << endl;
	return 0;
}
