#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
class Solution {
public:
        int peakIndexInMountainArray(vector<int>& arr) {
                if (arr.size() < 3)
                        return 0;

                // we need a fucking binary search
                int left = 0, right = arr.size()-1, m;

                while (left <= right) {
                        m = floor((left + right) / 2);

                        // first condition
                        //
                        if (arr[m+1] > arr[m])
                                left = m + 1;
                        // second condition
                        //
                        else if (arr[m-1] > arr[m])
                                right = m - 1;
                        else {
                                return m;
                        }
                }
                return -1;
        }
};


int main(int argc, char *argv[])
{
        Solution s;
        vector<int> array = { 0, 2, 1, 0 };

        cout << s.peakIndexInMountainArray(array) << endl;
        return 0;
}
