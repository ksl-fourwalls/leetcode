#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct soldier_struct {
    int index, soldiers;
};

bool compare(soldier_struct i1, soldier_struct i2) {
    if (i1.soldiers < i2.soldiers || (i1.soldiers == i2.soldiers && i1.index < i2.index))
        return true;
    return false;
}

class Solution {
public:
    // the number of soldiers in row i is less than number of 
    // soldiers in row j
    // Both rows have the same number of soldiers and i < j
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        
        vector<soldier_struct> v_soldier;
        vector<int> result;
        int count, idy, idx;
        
        for (idy = 0; idy < mat.size(); idy++) {
            count = 0;
            for (idx = 0; idx < mat[idy].size(); idx++) {
                if (mat[idy][idx]) count++;
                else break;
            }
            v_soldier.push_back({idy, count});
        }
        sort(v_soldier.begin(), v_soldier.end(), compare);
        for (idx = 0; idx < k; idx++)
            result.push_back(v_soldier[idx].index);
        return result;
    }
};

int main(int argc, char* argv[])
{
	Solution s;
	vector<vector<int>> mat = {
		{1, 1, 0, 0, 0}, {1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0}, {1, 1, 0, 0, 0},
		{1, 1, 1, 1, 1}
	};
	vector<int> result = s.kWeakestRows(mat, 3);

	for (auto val: result)
		cout << val << ", ";
	cout << endl;

	return 0;
}
