#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k_len = nums.size();
        for (int idx = k_len-1; idx >= 0; idx--)
        {
            if (nums[idx] == val)
                swap(nums[idx], nums[--k_len]);
        }
        return k_len;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> nums;

    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(4);

    int len = s.removeElement(nums, 4);

    for (int i = 0; i < len; i++)
        cout << nums[i] << endl;

    return 0;
}