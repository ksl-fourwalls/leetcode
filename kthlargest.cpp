#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct llist {
	int val;
	struct llist *next;
};


class Solution {
public:
	struct llist* alloca_mem(index, k) {
		return (struct llist *)&m_list[index % k];
	}

	int findKthLargest(vector<int>& nums, int k) {
		m_list = new struct llist[k];

		for (auto val : nums) {
			for (struct llist* tmp = head; tmp != nullptr; 
					tmp = tmp->next) {
			}
		}
		// free allocated memory
		delete m_list;
		return k;
	}

public:
	struct llist *m_list, *head; 
	int index = 0;
};

int main(int argc, char* argv[]) {
	Solution s;
	vector<int> nums = {
		3, 2, 1, 5, 6, 4
	};
	int k = 2;

	cout << s.findKthLargest(nums, k) << endl;
	return 0;
}
