6.2020.3.10��������ֱ��
����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ�������㡣
ʾ�� :
����������
          1
         / \
        2   3
       / \     
      4   5    
���� 3, ���ĳ�����·�� [4,2,1,3] ���� [5,2,1,3]��
ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��
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
