#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include <vector>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);

    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal

    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);

private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    // insert helper function
    void insertHelper(Node<T>*, T);
    //search helper function
    void searchHelper(Node<T>*, T);
    //remove helper fuction
    void removeHelper(Node<T>*, T);
    //get size helper function
    void get_size(Node<T>*, T);
    //inorder helper
    void inorderHelper(Node<T>*);
    //preorder helper
    void preorderHelper(Node<T>*);
    //post order helper
    void postorderHelper(Node<T>*);
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>

 std::vector<T> *BST<T>::inorder() {
std::vector<T> *vec = new std::vector<T>;
        inorderHelper(root);

}

template<class T>

void BST<T>::inorderHelper(Node<T>* node){
    std::vector<T> *vec = new std::vector<T>;


        if(node != NULL) {
        if(node->left) inorderHelper(node->left);
        std::cout << " " << node->val << " ";
        if(node->right)
        inorderHelper(node->right);
    }
}



/*pseudocode for preorder traversal
         print the node
         recurse the left subtree
         recurse the right subtree
    */
template<class T>
 std::vector<T>* BST<T>::preorder(){
    std::vector<T> *vec = new std::vector<T>;

    preorderHelper(root);

 }
template<class T>
    void BST<T>::preorderHelper(Node<T>* node){
        std::vector<T> *vec = new std::vector<T>;
        if(node != NULL) {
        std::cout << " " << node->val << " ";
        if(node->left) prederHelper(node->left);
        if(node->right) preorderHelper(node->right);
    }
    }


template<class T>
    std::vector<T>* BST<T>::postorder(){
    std::vector<T> *vec = new std::vector<T>;
    postorderHelper(root);
 }

template<class T>
    void BST<T>::postorderHelper(Node<T>* node){
    std::vector<T> *vec = new std::vector<T>;
    if(node != NULL) {
        if(node->left) postorderHelper(node->left);
        if(node->right) postorderHelper(node->right);
        std::cout << " " << node->val << " ";
    }
    }

template<class T>
void BST<T>::insert(T val)
{
        insertHelper(root, val);
}
template<class T>
void BST<T>::insertHelper(Node<T>* root, T val) {
        if (root == NULL) { root= Node<T>* (val);}
        if (val < root->new_data) root->left = insertHelper(root->left, val);
        if (val > root->new_data) root->right = insertHelper(root->right, val);
        return root;
    }

template<class T>
Node<T> *BST<T>::search(T val)
{
    return search(Node* root, T val);
}

template<class T>
Node<T> *BST<T>::search(Node* root, T val)
{
    if (root == nullptr) return -1;
    if (root->val == val) return root;
    return val > root->val ? search(root->right, val) : search(root->left, val);

}



template<class T>
void BST<T>::remove(Node *root, T val)
{
    root=remove(root, val);
}
Node* BST<T>::remove(Node *root, T val)
{

if (root == NULL) {
     return NULL;
  }
  if (val < root->val) {  // data is in the left sub tree.
      root->left = Delete(root->left, val);
  } else if (data > root->val) { // val is in the right sub tree.
      root->right = Delete(root->right, val);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->right;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->left;
        delete temp;
     }
     // case 4: two children
     else {
        struct Node *temp = FindMin(root->right); // find minimal value of right sub tree
        root->val = temp->val; // duplicate the node
        root->right = Delete(root->right, temp->val); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}





template<class T>
Node* BST<T>::int get_size(Node*root)//helper function for get_size
{
	if (node == NULL)
        return 0;
    else
        return(size(node->left) + 1 + size(node->right));  //+1 is for root
}
template<class T>
int BST<T>::get_size()
{
    n=0;
    if (root != NULL) {
    n = get_size(root);
    }
    return n;
}

