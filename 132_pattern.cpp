#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int>& nums, int left, int right) 
{
	if (left == right)
		return;


}

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int i, j, k;

		for (i = 0; i < nums.size(); i++)
		{
			for (j=i+1; j < nums.size()-1; j++)
			{
				if (nums[i] < nums[j])
				{
					for (k=j+1; k < nums.size(); k++)
					{
						if (nums[j] > nums[k] && nums[i] < nums[k])
							return true;
					}
				}
			}
		}
		return false;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = { 1, 0, 1, -4, -3 };
	printf("%s\n", s.find132pattern(nums) ? "TRUE" : "FALSE");
	return 0;
}
