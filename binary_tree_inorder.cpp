struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> treenode;
		// I want my program to be fast as fuck
		// I can do anything for it.
		// for example can allocate global memory
		//


void treeTraversal(TreeNode *root)
{
	if (root == NULL)
		return;

	treeTraversal(root->left);
	treenode.push_back(root->val);
	treeTraversal(root->right);
}

class Solution {
	public:
		vector<int> inorderTraversal(TreeNode *root) 
		{
			// this is fucking hack which
			// will make our progam fucking fast
			treenode.resize(0);

			treeTraversal(root);
			return treenode;
		}
};
