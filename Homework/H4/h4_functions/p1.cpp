#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (int val) : val(val), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void levelorder(TreeNode* root) {
    if (root == nullptr) return;
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            
            cout << front->val << " ";
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }
    }
}

TreeNode* buildMinCostTree(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    queue<TreeNode*> q;
    q.push(new TreeNode(arr[(int)arr.size() - 1]));
    TreeNode* root = q.front();
    
    int index = (int)arr.size() - 2;
    while (index >= 0 && !q.empty()) {
        int size = (int)q.size();
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            
            if (index < 0) break;
            front->left = new TreeNode(arr[index--]);
            q.push(front->left);
            
            if (index < 0) break;
            front->right = new TreeNode(arr[index--]);
            q.push(front->right);
        }
    }
    
    return root;
}

TreeNode* buildMinTree(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    if (arr.size() == 1) return new TreeNode(arr[0]);
    
    TreeNode* root = new TreeNode(-1);
    TreeNode* curr = root;
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        if (i >= 2) {
            curr->right = new TreeNode(arr[i]);
            curr->left = new TreeNode(-1);
            curr = curr->left;
        }
        else {
            curr->right = new TreeNode(arr[i]);
            curr->left = new TreeNode(arr[i - 1]);
            break;
        }
    }
    
    return root;
}

int main() {
    vector<int> a = {1, 3, 5, 7}, b = {1, 3, 5, 7, 9};
    
    auto rs1 = buildMinCostTree(a), rs2 = buildMinTree(b);
    levelorder(rs1);
    cout << endl;
    inorder(rs2);
    cout << endl;
    
//    TreeNode* root = new TreeNode(2);
//    root->left = new TreeNode(1);
//    root->right = new TreeNode(3);
//    levelorder(root);
}
