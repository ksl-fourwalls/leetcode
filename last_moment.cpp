#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 1 for left 
// 0 for right
// -1 for none

class Solution {
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		vector<int> plank;

		plank.resize(n, -1);
		for (int vl: left) {plank[vl] = 1;}
		for (int vl: right) {plank[vl] = 0;}
	}
};

int main(int argc, char* argv[]) {
	return 0;
}
