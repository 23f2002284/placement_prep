#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
Given a string S of distinct character of size N and 
their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. 
Your task is to build the Huffman tree 
print all the huffman codes in preorder traversal of the tree.
Note: While merging if two nodes have the same value, 
then the node which occurs at first will be taken on the left of Binary Tree and 
the other one to the right, 
otherwise Node with less value will be taken on the left of the subtree and 
other one to the right.

Preorder traversal
- root
- left
- right
means 
- 1st root will be the node with highest frequency
- then left subtree
- then right subtree

*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void traverse(Node* root, vector<string> &ans, string temp){
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp);
        return;
    }

    traverse(root->left, ans, temp + '0');
    traverse(root->right, ans, temp + '1');

}

vector<string> huffman_encoding(string s, vector<int> freq, int N){
    
    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    for(int i=0; i<N; i++){
        pq.push(new Node(freq[i]));
    }
    
    while(pq.size() > 1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* newNode = new Node(left->data + right->data);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    
    Node* root = pq.top();
    vector<string> ans;
    traverse(root, ans, "");
    return ans;
}


int main(){
    string s ="abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    int N = 6;
    vector<string> ans = huffman_encoding(s, freq, N);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}