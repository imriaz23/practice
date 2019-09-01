#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*left,*right;
    node(int data){
        this->data=data;
        left=right=nullptr;
    }
};
void printRootToLeafRecc(struct node *root,vector<int> &path){
    if(!root)
    return;
    path.push_back(root->data);
    if(!root->left && !root->right){
        for(int i=0;i<path.size();i++)
        cout<<path[i];
        cout<<endl;
    }
    printRootToLeafRecc(root->left,path);
    printRootToLeafRecc(root->right,path);
    path.pop_back();
}
void printRootToLeafPath(struct node*root){
    vector<int>path;
    printRootToLeafRecc(root,path);
}
int main(){
     freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root = new node(55);
    root->left = new node(78);
    root->right = new node(256);
    root->left->left = new node(4);
    root->left->right = new node(52);
    root->right->left = new node(54);
    root->right->right = new node(8956);
    printRootToLeafPath(root);
}