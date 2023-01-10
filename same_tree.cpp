// Given the roots of two binary trees p and q, write a function to check if they
// are the same or not.
//
// Two binary trees are considered the same if they are structurally identical
// and the nodes have the same value.

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right (nullptr) { }
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
	public:
		bool isSameTree(TreeNode *p, TreeNode *q) {
			return false;
		}


		bool isSameTree(struct TreeNode *node1, struct TreeNode *node2) 
		{

			if (node1 == NULL && node2 == NULL)
				return true;

			// then print the data of node
			if (node1->val != node2->val)
				return false;

			// now recur on right child
			if (isSameTree(node1->left, node2->left) && 
				isSameTree(node1->right, node2->right))
				return true;

			return false;
		}
	public:
		bool flag = false;
};


int main(int argc, char *argv[])
{
	Solution s;
	TreeNode *p, *q;

	TreeNode *mynod = new TreeNode(20, new TreeNode(28), nullptr);
	TreeNode *mynod1 = new TreeNode(21, new TreeNode(28), nullptr);
	s.isSameTree(p, q);

	printf("%s\n", s.printInorder(mynod, mynod1) ? "TRUE" : "FALSE");
	return 0;
}
