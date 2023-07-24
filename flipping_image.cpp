#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
		vector<vector<int>> flipped_image;
		int idx;

		for (auto& m_Vec : image)
		{
			vector<int> tmp_vec;
			for (idx = m_Vec.size()-1; idx >= 0; idx--)
				tmp_vec.push_back(!m_Vec[idx]);
			flipped_image.push_back(tmp_vec);
		}

		return flipped_image;
	}

};

int main(int argc, char *argv[])
{
	vector<vector<int>> flipped_image, image = {
		{1, 1, 0},
		{1, 0, 1},
		{0, 0, 0}
	};
	Solution s;

	flipped_image = s.flipAndInvertImage(image);
	for (auto& m_Vec : flipped_image)
	{
		for (auto value : m_Vec)
			cout << value << endl;
		cout << endl;
	}
	return 0;
}
