#include<iostream>
#include<vector>
struct  TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		return g(1, n);
	}
	vector<TreeNode*> g(int start, int end) {
		if (end < start)
		{
			vector<TreeNode*>a;
		
			return a;
		}
		if (end == start) {
			vector<TreeNode*>answer;
			TreeNode* node = new TreeNode(start);//创建一个结点，子节点都为空
			answer.push_back(node);
			return answer;
		}
		else {
			vector<TreeNode*> res_vec;
			for (int i = start; i <= end; i++) {
				vector<TreeNode*> l_vec = g(start, i - 1);
				vector<TreeNode*> r_vec = g(i + 1, end);
				for (int k = 0; k < l_vec.size(); k++) {
					for (int j = 0; j < r_vec.size(); j++) {
						TreeNode* root = new TreeNode(i);
						root->left = l_vec[k];
						root->right = r_vec[j];
						res_vec.push_back(root);
					}
				}
			}
			return res_vec;
		}
	}
};
