#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cmp(const void *a1, const void *a2)
{
	register int num1 = *(int*)a1, num2 = *(int*)a2;
	return num1 - num2;
}

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			int temp[r];

			start = 0;
			end = nums.size()-1;
			data = &temp[0];

			makeCombination(nums, 0, 0);
			for (int idx = 0; idx < intvecArray.size(); idx++)
			{
				vector<int>& intvec = intvecArray[idx];
				for (int idy = 0; idy < r; idy++)
					printf("%d ", intvec[idy]);
				printf("\n");
			}
			return intvecArray;
		}

		bool isPresent()
		{
			for (int idx = 0; idx < intvecArray.size(); idx++)
			{
				vector<int>& curvec = intvecArray[idx];
				bool flag = false;

				for (int idy = 0; idy < r; idy++)
					if (data[idy] != curvec[idy])
						flag = true;

				if (!flag) return false;
			}
			return true;
		}


		void makeCombination(vector<int>& nums, int start, int index)
		{
			if (index == r)
			{
				if ((data[0] + data[1] + data[2]) == 0) 
				{
				//	qsort(data, r, sizeof(int), cmp);
					//if (isPresent()) 
						intvecArray.push_back({data[0], data[1], data[2]});
				}
				return;
			}

			for (int i = start; i <= end && end-i+1 >= r-index; i++)
			{
				data[index] = nums[i];
				makeCombination(nums, i+1, index+1);
			}
		}
	private:
		vector<vector<int>> intvecArray;
		int r = 3, start, end;
		int *data;
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {3,0,-2,-1,1,2};

	s.threeSum(nums);
	return 0;
}