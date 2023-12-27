#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {
		int prev=0, i, result = 0;
		for (i = 1; i < colors.size(); i++) {
			if (colors[prev] == colors[i]) {
				if (neededTime[prev] < neededTime[i]) {
					result += neededTime[prev];
				}
				else {
					result += neededTime[i];
					continue;
				}
			}
			prev = i;
		}
		return result;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	string colors = "aaabbbabbbb";
	vector<int> neededTime = {3,5,10,7,5,3,5,5,4,8,1};
	cout << s.minCost(colors, neededTime) << endl;
	return 0;
}
