#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tmp;

class Solution {
public:
	void permutation(int left) {
		if (left == right)
		{
			tmp.push_back(vector<int>(int_struct.m_Ptr, int_struct.m_Ptr+int_struct.size));
			return;
		}
		else {
			for (int i = left; i <= right; i++)
			{
				swap(int_struct.m_Ptr[left], int_struct.m_Ptr[i]);
				permutation(left+1);
				swap(int_struct.m_Ptr[left], int_struct.m_Ptr[i]);
			}
		}

	}

	vector<vector<int>> permute(vector<int>& nums) {

		tmp.resize(0);
		right = nums.size()-1;

		// initialize struct
		int_struct.m_Ptr = &nums[0];
		int_struct.size = nums.size();

		permutation(0);

		return tmp;
	}

	struct {
		int *m_Ptr;
		size_t size;
	} int_struct;
	int right;
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {
		1, 3, 4
	};
	vector<vector<int>> m_value = s.permute(nums);
	for (auto& ptr : m_value) {
		for (int value: ptr)
			printf("%d, ", value);
		printf("\n");
	}
	return 0;
}
