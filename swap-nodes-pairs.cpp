#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

	void push(int x)
	{
		ListNode* tmp = this;

		for (tmp = this; tmp->next != nullptr; tmp = tmp->next) { }
		tmp->next = new ListNode(x);
	}

	void free()
	{
		ListNode* tmp = this->next, *prev;

		while ( tmp )
		{
			prev = tmp;
			tmp = tmp->next;
			delete prev;
		}

		this->next = nullptr;
	}

	void print()
	{
		for (ListNode* tmp = this; tmp != nullptr; tmp = tmp->next)
			printf(" %d -> ", tmp->val);
		printf("NULL\n");
	}
};


class Solution {
	public:
		ListNode* swapPairs(ListNode* head) {
			ListNode* tmp = head, *prev, *start = head->next, *remind_prev;

			if (tmp && tmp->next)
			{
				// store next to next 
				prev = tmp->next->next;
				tmp->next->next = tmp;
				tmp->next->next->next = prev;
				remind_prev = prev;

				tmp = prev;
				printf("0x%016x, 0x%016x\n", tmp, tmp->next);
				printf("%d %d\n", tmp->val, tmp->next->val);

				while (tmp && tmp->next)
				{
					// store next to next 
					prev = tmp->next->next; // store null
					tmp->next->next = tmp;	// set null to something
					tmp->next->next->next = prev;

					remind_prev->next = tmp->next;
					remind_prev = prev;
					tmp = prev;
				}
			}
			return start;
		}
};

int main(int argc, char* argv[])
{
	ListNode mlist, *outlist;
	Solution s;

	mlist.val = 1;
	mlist.next = nullptr;

	mlist.push(2);
	mlist.push(3);
	mlist.push(4);

	outlist = s.swapPairs(&mlist);
	outlist->print();

	mlist.free();
	return 0;
}
