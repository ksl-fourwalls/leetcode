// Given the head of a linked list, rotate the list to the right by k places.
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) { }
	ListNode(int x) : val(x), next(nullptr) { }
	ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class Solution {
	public:
		ListNode *rotateRight(ListNode* head, int k) {
			ListNode *tmp = head, *start, *prev, *endptr = head;
			int idx = 0, size = 0;

			if (endptr != NULL)
			{
				idx++;
				while (endptr->next != NULL)
				{
					endptr = endptr->next;
					idx++;
				}

				size = idx - k % idx;
				for (idx = 1, tmp = head; idx < size; idx++)
					tmp = tmp->next;

				endptr->next = head;
				head = tmp->next;
				tmp->next = NULL;
			}
			return head;
		}

		void printList(ListNode* head)
		{
			while (head != NULL)
			{
				printf("%d -> ", head->val);
				head = head->next;
			}
			printf("NULL\n");
		}
};

int main(int argc, char * argv[]) 
{
	Solution s;
	ListNode* head;

	head = new ListNode(40, new ListNode(20, new ListNode(10, new ListNode(4))));
	s.printList(head);
	s.printList(s.rotateRight(head, 1));
	return 0;
}
