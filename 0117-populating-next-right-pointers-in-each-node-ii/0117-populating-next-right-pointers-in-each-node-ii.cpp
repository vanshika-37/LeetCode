/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> levelOrder(Node *root)
    {
        vector<vector<Node*>> ans;
        queue<Node *> q;
        if (root == NULL)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            vector<Node*> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *v = q.front();
                q.pop();
                if (v->left)
                    q.push(v->left);
                if (v->right)
                    q.push(v->right);
                level.push_back(v);
            }
            ans.push_back(level);
        }
        return ans;
    }
    
    Node* connect(Node* root) {
        vector<vector<Node*>>ans = levelOrder(root);
        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < ans[i].size() - 1; j++){
                ans[i][j]->next = ans[i][j+1];
            }
        }
        return root;
    }
};