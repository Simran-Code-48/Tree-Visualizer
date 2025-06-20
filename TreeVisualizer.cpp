#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int idx;
    int level;
    int leftwidth;
    int rightwidth;
    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};
TreeNode* buildTree(vector<int> &levelorder, int null){
    queue<TreeNode*> q;
    TreeNode *root=new TreeNode(levelorder[0]);
    int idx=0;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        ++idx;
        if(idx<levelorder.size() && levelorder[idx]!=null){
            node->left=new TreeNode(levelorder[idx]);
            q.push(node->left);
        }
        ++idx;
        if(idx<levelorder.size() && levelorder[idx]!=null){
            node->right=new TreeNode(levelorder[idx]);
            q.push(node->right);
        }
    }
    return root;
}
int widthSubTree(TreeNode *root){
    if(!root)   return 0;
    root->leftwidth=widthSubTree(root->left);
    root->rightwidth=widthSubTree(root->right);
    return 1+root->leftwidth+root->rightwidth;
}
int maxlevel=0;
int maxIdx=0;
void setIndex(TreeNode *root,int parentIdx, int level, bool rightchild){
    if(!root)   return ;
    if(rightchild){
        root->idx=parentIdx+root->leftwidth+1;
    }else{
        root->idx=parentIdx-root->rightwidth-1;
    }
    maxlevel=max(maxlevel, level);
    maxIdx=max(maxIdx, root->idx);
    root->level=level;
    setIndex(root->left, root->idx, level+1, false);
    setIndex(root->right, root->idx, level+1, true);
}

void fillLevels(TreeNode*root, vector<vector<string>> &levels){
    if(!root)   return ;
    levels[root->level][root->idx-1]=to_string(root->val);
    fillLevels(root->left, levels);
    fillLevels(root->right, levels);
}
int main(){
    int null=INT_MIN;
    vector<int> levelorder={50, 25, 75, 2, null, 55, null, null, 5, null, 59, 4, 6, 58, null, null, null, null, 7, 57, null};
    TreeNode *root=buildTree(levelorder,null);
    widthSubTree(root);
    setIndex(root, 0, 0, true);
    vector<vector<string>> levels(maxlevel+1,vector<string>(maxIdx,"  "));
    fillLevels(root, levels);
    for(int i=0;i<=maxlevel;i++){
        for(int j=0;j<maxIdx;j++){
            cout<<setw(3)<<levels[i][j];
        }
        cout<<"\n";
    }
    
    
    return 0;
}