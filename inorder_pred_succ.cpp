#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
	int el;
};

node *newnode(int key)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	temp->el=0;
}
node *insert(node *root,int key)
{
	if(root==NULL)
		return newnode(key);

	if(key<root->data)
		root->left=insert(root->left,key);

	else
		root->right=insert(root->right,key);
	if(root->data>key)
		root->el++;

	return root;
}
void predsucc(node *root,int key,node **pred,node **succ)
{
	if(root==NULL)
		return;
	if(key < root->data)
	{
		*succ=root;
		predsucc(root->left,key,pred,succ);
	}
	else if(key > root->data)
	{
		*pred=root;
		predsucc(root->right,key,pred,succ);
	}
	else
	{
		if(root->right!=NULL)
		{
			node *temp=root->right;
			while(temp->left!=NULL)
				temp=temp->left;

			*succ=temp;
		}
		if(root->left!=NULL)
		{
			node *temp=root->left;
			while(temp->right!=NULL)
				temp=temp->right;

			*pred=temp;
		}
	}
}
		

int main()
{
	node *root=NULL;
	int key;
	while(1)
	{
		cin>>key;
		if(key==-1)
			break;
		root=insert(root,key);
	}

	while(1)
	{
		node *pred=NULL,*succ=NULL;
		cin>>key;
		if(key==-1)
			break;
		predsucc(root,key,&pred,&succ);
		cout<<((pred==NULL)?-1:pred->data)<<" ";
		cout<<((succ==NULL)?-1:succ->data)<<endl;
	}

	return 0;
}
	


