#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			if (list1 != nullptr || list2 != nullptr)
			{
				ListNode *resultlist = new ListNode, *tmp = resultlist;
				if (list1 != nullptr && list2 != nullptr) 
				{

					while (1)
					{
						if (list1->val > list2->val)
						{
							tmp->val = list2->val;
							list2 = list2->next;
						}
						else 
						{
							tmp->val = list1->val;
							list1 = list1->next;
						}

						if (list1 != nullptr && list2 != nullptr) 
						{
							tmp->next = new ListNode;
							tmp = tmp->next;
						}
						else break;
					}

					while (list1 != nullptr)
					{
						tmp->next = new ListNode;
						tmp = tmp->next;
						tmp->val = list1->val;

						list1 = list1->next;
					}

					while (list2 != nullptr)
					{
						tmp->next = new ListNode;
						tmp = tmp->next;
						tmp->val = list2->val;

						list2 = list2->next;
					}
					tmp->next = nullptr;
					return resultlist;
				}
				else
					return (list1 != nullptr) ? list1 : list2;
			}
			return nullptr;
		}
};

void printList(ListNode* list) 
{
	for (;list != nullptr; list = list->next)
	{
		cout << list->val << " ";
	}
	cout << endl;
}
	

int main(int argc, char *argv[])
{
	Solution s;
	/*
	ListNode* list1 = new ListNode(20), *list2 = new ListNode(40), *tmp;

	tmp = list1;
	tmp->next = new ListNode(40);

	tmp = tmp->next;
	tmp->next = new ListNode(80);

	tmp = tmp->next;
	tmp->next = nullptr;

	tmp = list2;
	tmp->next = new ListNode(40);

	tmp = tmp->next;
	tmp->next = new ListNode(80);

	tmp = tmp->next;
	tmp->next = nullptr;
	*/

	ListNode* list1 = nullptr, *list2 = new ListNode(0, nullptr);

	printList(list1);
	printList(list2);
	printList(s.mergeTwoLists(list1, list2));
	
	return 0;
}
