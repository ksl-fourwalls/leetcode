#include <iostream>
#include <vector>

using namespace std;
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int prev, idx = 0, size = nums.size(), count,
			    indx, indy;

			if (nums.size() > 0)
			{
				prev = nums[idx++];
				count = 1;
			}

			while (idx < size)
			{
				if (prev == nums[idx])
					count++;
				else {
					count -= 2;
					if ( count > 0 ) {
						for (indx = idx-count, indy = idx; indy < size; indx++, indy++)
							nums[indx] = nums[indy];
						size -= count;
						idx -= count;
					}
					prev = nums[idx];
					count = 1;
				}
				idx++;
			}

			count -= 2;
			if ( count > 0 ) size -= count;
			return size;
		}

};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums = {
		1, 1, 1, 2
	};
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}
