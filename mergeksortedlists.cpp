#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
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

// You are given an arrayy of k linked-lists lists each linked-list is sorted in ascending order
// merge all the linked list into one sorted linked list return it
class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) 
		{
			ListNode mlist, *tmp, **kptrs, *swapptr;
			size_t idx, idy, kptrsize = 0, minidx;

			mlist.next = nullptr;
			tmp = &mlist;
			kptrs = (ListNode**)calloc(sizeof(struct ListNode *), lists.size());

			for (idx = 0; idx < lists.size(); idx++)
			{
				if (lists[idx] != nullptr)
					kptrs[kptrsize++] = lists[idx];
			}

			while (kptrsize != 0)
			{
				minidx = 0;
				for (idx = 1; idx < kptrsize; idx++)
				{
					if (kptrs[idx]->val < kptrs[minidx]->val)
						minidx = idx;
				}

				tmp->next = new ListNode(kptrs[minidx]->val);
				tmp = tmp->next;

				kptrs[minidx] = kptrs[minidx]->next;
				if (kptrs[minidx] == nullptr)
				{
					swapptr = kptrs[kptrsize-1];
					kptrs[--kptrsize] = kptrs[minidx];
					kptrs[minidx] = swapptr;
				}


			}
			tmp->next = NULL;
			free(kptrs);

			return ((ListNode*)&mlist)->next;
		}
};

int main(int argc, char* argv[])
{
	vector<ListNode*> lists;
	Solution s;

	lists.push_back(new ListNode(1));
	lists.push_back(new ListNode(1));
	lists.push_back(new ListNode(2));

	lists[0]->push(4);
	lists[0]->push(5);

	lists[1]->push(3);
	lists[1]->push(4);

	lists[2]->push(6);



	s.mergeKLists(lists)->print();
	return 0;
}
