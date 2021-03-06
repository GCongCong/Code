6.2020.3.10二叉树的直径
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
示例 :
给定二叉树
          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
注意：两结点之间的路径长度是以它们之间边的数目表示。
struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
class Solution {
public:
int z;
int dep(TreeNode* root){
     if(root==NULL)
        {
            return 0;
        }
        int l=dep(root->left);
        int r=dep(root->right);
         z=max(z,l+r);
        return max(l,r)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
        z=0;
        dep(root);
        return z;

    }
};
