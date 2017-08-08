/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> item;
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        TreeNode* temp;
        
        if(!root) return ans;
        else 
        {
            q.push(root);
            q.push(NULL);
        }
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            if(temp!=0)
            {
                item.push_back(temp->val);
                if(temp->left) q.push(temp->left);//remove null in the tree to avoid mistaken null mark.
                if(temp->right) q.push(temp->right);
            }
            else
            {
                ans.push_back(item);
                item={};
                if(q.size()) q.push(NULL);// take null as marker of level!//use judge to avoid dead loop.
            }
        }
        
        return ans;
        
    }
};

//no mark used!!
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> item;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        TreeNode* temp;
        
        if(!root) return ans;
        else 
        {
            q.push(root);
        }
        
        while(!q.empty())
        {

            
            for(int i = 0, n = q.size(); i < n; i++)
            {   
                temp = q.front();
                q.pop();
                item.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            ans.push_back(item);
            item={};
        }
        
        return ans;
        
    }
};
