#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int key, i, j;
    for (i = 1; i < arr.size(); i++) {
        key = arr[i];
        for (j = i-1; j >= 0 && arr[j] > key; --j) {
            arr[j+1] = arr[j];
        }      
        arr[j+1] = key;
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<vector<int>> df;
        vector<int> result;
        int idx, idy; 
        
        df.resize(nums.size());
        
        for (idx = 0; idx < nums.size(); idx++) {
            df[nums[idx]].push_back(nums[idx]);
        }
        
        for (idx = 0; idx < nums.size(); idx++) {
            insertionSort(df[idx]);
        }
        
        for (idx = 0; idx < nums.size(); idx++) {
            for (idy = 0; idy < df[idx].size(); idy++) {
                result.push_back(df[idx][idy]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> m_arr = { 5, 1, 1, 2, 0, 0 };
	vector<int> result = s.sortArray(m_arr);

	cout << "[ ";
	for (auto vl: result)
		cout << vl << " ";
	cout << "]\n";
	return 0;
}
