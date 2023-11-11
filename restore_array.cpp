#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct EdgeInfo{
	vector<int> pairs;
	bool visited = false;
};

class Solution {
public:
    // Convert into graph and then just join all graph edges
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, EdgeInfo> hmap;
	vector<int> result;
	stack<int> m_Stack;
	int first_node;

        for (auto& pairs: adjacentPairs) {
            hmap[pairs[0]].pairs.push_back(pairs[1]);
            hmap[pairs[1]].pairs.push_back(pairs[0]);
        }

	for (auto& v: hmap)
	{
		if (v.second.pairs.size() == 1)
		{
			first_node = v.first;
			break;
		}
	}

	m_Stack.push(first_node);
	hmap[first_node].visited = true;

	while (!m_Stack.empty()) {
		first_node = m_Stack.top();
		m_Stack.pop();
		result.push_back(first_node);

		vector<int>& searchspace = hmap[first_node].pairs;
		for(auto vertex: searchspace) {
			if (hmap[vertex].visited == false)
			{
				hmap[vertex].visited = true;
				m_Stack.push(vertex);
				break;
			}
		}
	}
	return result;
    }
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<vector<int>> adjacentPairs = {
		{2, 1}, {3, 4}, {3, 2}
	};
	vector<int> result = s.restoreArray(adjacentPairs);
	for (auto vl: result) {
		cout << vl << " ";
	}
	cout << endl;
	return 0;
}
