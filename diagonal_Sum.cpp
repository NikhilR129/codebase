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
	temp->left=temp->right=NULL;
	temp->data=key;

	return temp;
}
node *insert(node *root,int key)
{
	if(root==NULL)
		return newnode(key);
}
void fill_diagonal_array(int level,int a[],node *root)
{
	if(root==NULL)
		return;

	a[level]+=root->data;

	fill_diagonal_array(level,a,root->right);
	fill_diagonal_array(level+1,a,root->left);
}

int find_max_level(node *root)
{
	int level=1;
	while(root->left!=NULL)
		level++,root=root->left;

	return level;
}
int main()
{
	int i;
	node *root=NULL;
	root=newnode(5);
	root->left=newnode(6);
	root->left->left=newnode(7);
	root->right=newnode(5);
	int n=find_max_level(root);

	int a[n];
	for(i=0;i<n;i++)
		a[i]=0;
	fill_diagonal_array(0,a,root);

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}



