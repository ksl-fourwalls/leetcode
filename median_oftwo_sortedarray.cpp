#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// sorted means binary search
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		int i, j;

		for (i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
			if (nums1[i] > nums2[j])
				result.push_back(nums2[j++]);
			else result.push_back(nums1[i++]);
		}

		if (i < nums1.size()) {
			do { 
				result.push_back(nums1[i++]);
			} while (i < nums1.size());
		} else {
			do {
				result.push_back(nums2[j++]);
			} while (j < nums2.size());
		}

		if (result.size() % 2 == 1)
			return double(result[result.size() / 2]);
		return double(result[result.size()/2-1] + result[result.size()/2+1]) / 2;
	}
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<int> nums1 = {
		1, 2
	}, nums2 = {
		3, 4
	};

	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}
