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
			printf(" { %d, 0x%016lx } -> ", tmp->val, (long unsigned)tmp->next);
		printf("NULL\n");
	}

};




class Solution {
	public:
		ListNode* swapPairs(ListNode* head) 
		{
			ListNode* tmp = head;
			ListNode* prev[2];

			if (tmp && tmp->next)
			{
				// store tmp and next
				prev[0] = tmp;
				prev[1] = tmp->next;

				tmp->next = prev[1]->next;
				prev[1]->next = tmp;
				head = prev[1];

				while (tmp->next && tmp->next->next)
				{
					prev[0] = tmp->next;
					prev[1] = tmp->next->next;

					// previous next with new next
					tmp->next = tmp->next->next;

					tmp = prev[0];
					tmp->next = prev[1]->next;
					prev[1]->next = tmp;
				}
			}
			return head;
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
	mlist.push(5);
	mlist.push(6);
	mlist.push(7);

	outlist = s.swapPairs(&mlist);
	outlist->print();

	mlist.free();
	return 0;
}
