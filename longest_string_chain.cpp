#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compar(string& a1, string& a2) {
	if (a1.size() < a2.size())
		return true;
	return false;
}

bool ispredecessor(string dest, string src) {
	if (dest.compare(src) != 1)
		return false;

	for (int idx = 0, idy = 0; idx < src.size(); idy++)
	{
		if (src[idx] == dest[idy])
			idx++;
		if (dest.size() >= idy)
			return false;
	}
	return true;
}

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		map<int, vector<int>> m_lstr;
		for (int idx = 0; idx < words.size(); idx++) {
			m_lstr[words[idx].size()].push_back(idx);
		}

		for (auto& vc: m_lstr) {

			for (auto v: vc.second)
				cout << v <<  " , ";
			cout << endl;
		}
		return -1; 
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<string> words = {
		"a", "b", "ba", "bca", "bda", "bdca"
	};
	s.longestStrChain(words);
	return 0;
}
