#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *newnode(int key)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=key;
	temp->left=temp->right=NULL;
	return temp;
}
node *insert(int key,node *root)
{
	if(root==NULL)
		return newnode(key);

	if(root->data > key)
		root->left=insert(key,root->left);

	else
		root->right=insert(key,root->right);

	return root;
}
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

node *delete_node(node *root,int key)
{
	if(root==NULL)
		return root;

	if(key< root->data)
		root->left= delete_node(root->left,key);

	if(key> root->data)
		root->right= delete_node(root->right,key);

	else
	{
		if(root->left==NULL)
		{
			node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root->left;
			free(root);
			return temp;
		}
		else
		{
			node *temp=root->right;
			while(temp->left!=NULL)
				temp=temp->left;

			root->data=temp->data;

			free(temp);

			return root;
		}
	}
	return root;
}


int main()
{
	node *root=NULL;
	root=insert(10,root);
	root=insert(5,root);
	root=insert(15,root);
	root=insert(20,root);

	root=delete_node(root,15);

	inorder(root);

	return 0;
}



