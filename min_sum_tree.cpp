// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <climits>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
void fun(struct node *root,int sum,int *mnm)
{
	if(root==NULL)
		return;
	if(root->right==NULL && root->left==NULL)
	{
		if(sum+root->data<*mnm)
			*mnm=sum+root->data;
		return;
	}
	fun(root->left,sum+root->data,mnm);
	fun(root->right,sum+root->data,mnm);
}
int main()
{
	struct node *root  = newNode(1);
	root->left             = newNode(2);
	root->right           = newNode(3);
	root->left->left     = newNode(4);
	root->left->right   = newNode(5); 
	root->right->left=newNode(100);
	//printf("\nPreorder traversal of binary tree is \n");
	//printPreorder(root);

	//printf("\nInorder traversal of binary tree is \n");
	//printInorder(root);  

	//printf("\nPostorder traversal of binary tree is \n");
	//printPostorder(root);

	//getchar();
	int mn=INT_MAX;
	fun(root,0,&mn);
	cout<<mn;
}
