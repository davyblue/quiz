/*Flat Binary Tree to Linked List use iterative method*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
/*define TreeNode*/
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
}TreeNode;
/*define functions*/
void flatten(TreeNode* root);
void creatTree(TreeNode* root);
/*globel variable record the last traced node*/
TreeNode* lastNode = NULL;
int main()
{
    /*initialize root*/
    TreeNode* root=(TreeNode*) malloc(sizeof(TreeNode));
    /*creat tree for testing*/
    creatTree(root);
    /*Tree can't be NULL*/
    assert(root != NULL);
    /*flat function*/
    flatten(root);
    /*print result*/
    while(root != NULL)
    {
        printf("%d\n",root->value);
        root=root->right;
    }
    /*free memory*/
    free(root);
    return 0;
}
void flatten(TreeNode* root) {
    while(root) {
        if(root->left) {
            TreeNode *tmp = root->left;
            while(tmp->right) 
                tmp = tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}
void creatTree(TreeNode* root)
{
    root->value = 1;
    root->right = (TreeNode*) malloc(sizeof(TreeNode));
    root->right->value = 5;
    root->right->right = (TreeNode*) malloc(sizeof(TreeNode));
    root->right->right->value = 6;
    root->left = (TreeNode*) malloc(sizeof(TreeNode));
    root->left->value = 2;
    root->left->left = (TreeNode*) malloc(sizeof(TreeNode));
    root->left->left->value = 3;
    root->left->right = (TreeNode*) malloc(sizeof(TreeNode));
    root->left->right->value = 4;
}
