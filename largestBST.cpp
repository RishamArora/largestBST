/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <queue>
#include<climits>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int largestBSTSubtree(BinaryTreeNode<int> *root);
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
bool isBST(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;}
     if(root->data<min || root->data>max){
         return false;
     }
    bool lout=isBST(root->left,min,root->data-1);
    bool rout=isBST(root->right,root->data,max);
    return lout&&rout;
}

int height(BinaryTreeNode<int> *root){
    int a=0;
    if(root==NULL){
        return 0;
    }
    else{
        a++;
    }
    int lh=0,rh=0;
    if(root->left!=NULL){
        lh=height(root->left);
    }
    if(root->right!=NULL){
        rh=height(root->right);
    }
    return a+max(lh,rh);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {

    bool isbst=isBST(root,INT_MIN,INT_MAX);
    if(isbst){
        return height(root);
    }
    else{
        int a=largestBSTSubtree(root->left);
        int b=largestBSTSubtree(root->right);
        return max(a,b);
    }

}
