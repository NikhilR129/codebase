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

int nthsmallest(node *root,int n)
{
	if(root->el == n-1)
		return root->data;

	if(n-1 < root->el)
		return nthsmallest(root->left,n);

	return nthsmallest(root->right,n);

}
	
int main()
{
	node *root=NULL;

	int key,nth,ch;
	while(true)
	{
		cin>>ch;
		if(ch==1)
		{
			cin>>key;
			root=insert(root,key);
		}
		if(ch==2)
		{
			cin>>nth;
			cout<<nthsmallest(root,nth)<<endl;
		}
	}


	return 0;
}



