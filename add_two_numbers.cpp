#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define update_carry(value, carry) do { 		\
	carry = value / 10;							\
	value %= 10;								\
} while (0)

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *myList = nullptr, *tmp;
			int carry = 0;

			if (l1 != nullptr && l2 != nullptr)
			{
				myList = new ListNode;
				tmp = myList;
				for (;;)
				{
					tmp->val = l1->val + l2->val + carry;
					// find carry
					update_carry(tmp->val, carry);

					l1 = l1->next;
					l2 = l2->next;
					if (l1 == nullptr || l2 == nullptr)
						break;

					tmp->next = new ListNode;
					tmp = tmp->next;
				}

				for (ListNode* from = l1 != nullptr ? l1 : l2; from != nullptr; from = from->next)
				{
					tmp->next = new ListNode;
					tmp = tmp->next;

					tmp->val = from->val + carry;
					// find carry
					update_carry(tmp->val, carry);
				}

				if (carry) 
				{
					tmp->next = new ListNode;
					tmp = tmp->next;
					tmp->val = carry;
				}
				tmp->next = nullptr;
			}
			return myList;
		}

};

int main(int argc, char* argv[])
{
	Solution s;
	ListNode* l1 = nullptr, *l2 = nullptr;

	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);
	l1 = s.addNode(l1, 9);

	l2 = s.addNode(l2, 9);
	l2 = s.addNode(l2, 9);
	l2 = s.addNode(l2, 9);
	l2 = s.addNode(l2, 9);

	for (ListNode* to = s.addTwoNumbers(l1, l2); to != nullptr; to = to->next)
		printf("%d\n", to->val);

	return 0;
}
