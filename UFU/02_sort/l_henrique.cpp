// #include <bits/stdc++.h>
// using namespace std;

// #define int long long int
// #define vi vector<int>
// #define endl '\n'

// void printPreOrder(vi &v, int node){
//     int n = v.size();
//     int left = 2*(node+1) - 1;
//     int right = 2*(node+1);

//     cout << v[node] << ' ';
//     if (left < n) printPreOrder(v, left);
//     if (right < n) printPreOrder(v, right);
// }

// void printInOrder(vi &v, int node){
//     int n = v.size();
//     int left = 2*(node+1) - 1;
//     int right = 2*(node+1);

//     if (left < n) printInOrder(v, left);
//     cout << v[node] << ' ';
//     if (right < n) printInOrder(v, right);
// }

// void printPostOrder(vi &v, int node){
//     int n = v.size();
//     int left = 2*(node+1) - 1;
//     int right = 2*(node+1);

//     if (left < n) printPostOrder(v, left);
//     if (right < n) printPostOrder(v, right);
//     cout << v[node] << ' ';
// }

// signed main(){
//     cin.tie(0); cout.tie(0);
//     ios_base::sync_with_stdio(0);

//     vi v;
//     int x;
//     while(cin >> x)
//         v.push_back(x);
    
//     printPreOrder(v,0); cout << endl;
//     printInOrder(v,0); cout << endl;
//     printPostOrder(v,0); cout << endl;

//     return 0;
// }

#include<bits/stdc++.h> 
using namespace std;
  
struct bstnode 
{ 
    int data; 
    struct bstnode *left, *right; 
}; 
  
struct bstnode *newNode(int key) { 
    struct bstnode *temp =  new struct bstnode(); 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(struct bstnode *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->data<<" "; 
        inorder(root->right); 
    } 
} 

void preorder(struct bstnode *root) { 
    if (root != NULL) { 
        cout << root->data<<" "; 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

void postorder(struct bstnode *root) { 
    if (root != NULL) { 
        postorder(root->left); 
        postorder(root->right);
        cout << root->data<<" ";  
    } 
} 
   
struct bstnode* insert(struct bstnode* node, int key) { 
    if (node == NULL) return newNode(key); 
    
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
    return node; 
} 

struct bstnode * minValueNode(struct bstnode* node){ 
    struct bstnode* current = node; 
    
    while (current && current->left != NULL) 
    current = current->left; 
    
    return current; 
} 

struct bstnode* deleteNode(struct bstnode* root, int key) { 
    if (root == NULL) return root; 

    if (key << root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else{ 
        if (root->left == NULL){ 
            struct bstnode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL){ 
            struct bstnode *temp = root->left; 
            free(root); 
            return temp; 
        } 
        
        struct bstnode* temp = minValueNode(root->right); 
    
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}   
// main program
int main() 
{ 
    /* Let us create following BST 
              40 
             /  \ 
           30   60 
                    \ 
                   65 
                      \
                     70*/
    struct bstnode *root = NULL; 
    root = insert(root, 93); 
    root = insert(root, 5); 
    root = insert(root, 11); 
    root = insert(root, 15); 
    root = insert(root, 32); 
    root = insert(root, 2); 
    root = insert(root, 4); 
    root = insert(root, 99); 
    root = insert(root, 115); 
    root = insert(root, 110);
    //93 5 11 15 32 2 4 99 115 110
    
    // cout<<"Binary Search Tree created (Inorder traversal):"<<endl; 
    inorder(root); 
    
    // cout<<"\nDelete node 40\n"; 
    root = deleteNode(root, 93); 
    // cout<<"Inorder traversal for the modified Binary Search Tree:"<<endl; 
    // inorder(root); 
    
    return 0; 
}