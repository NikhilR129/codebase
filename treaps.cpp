#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
struct node
{
	int data;
	int priority;
	node *left;
	node *right;
};

node *search(node *root,int key)
{
	if(root==NULL || root->data==key)
		return root;

	if(key<root->data)
		return search(root->left,key);
	else
		return search(root->right,key);
}
int height(node *root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
node *newnode(int key)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=key;
	temp->left=temp->right=NULL;
	temp->priority=rand()%1007;

	return temp;
}
node*  more_priority(node *a,node *b)
{
	if(a==NULL)
		return b;

	if(b==NULL)
		return a;

	return (a->priority>=b->priority?a:b);

}	

node *insert(node *root,int key)
{
	if(root==NULL)
		return newnode(key);

	if(key < root->data)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);

	node *temp=more_priority(root->left,root->right);
	if(root->priority>=temp->priority)
		return root;

	if(temp==root->left)
	{
		node *rot_helper=temp->right;
		temp->right=root;
		root->left=rot_helper;
		return temp;
	}
	else if(temp==root->right)
	{
		node *rot_helper=temp->left;
		temp->left=root;
		root->right=rot_helper;
		return temp;
	}
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

int main()
{
	char ch;
	int x;
	node *root=NULL;
	while(true)
	{
		cin>>x;
		if(x==-1)
			break;
		root=insert(root,x);
	}
	while(true)
	{
		cin>>ch;
		if(ch=='i')
		{
			cin>>x;
			root=insert(root,x);
		}
		if(ch=='d')
		{
			inorder(root);
		}
		if(ch=='s')
		{
			cin>>x;
			if(search(root,x)!=NULL) cout<<"found"<<endl;
			else cout<<"Not found"<<endl;
		}
		if(ch=='h')
			cout<<height(root)<<endl;
	}
	return 0;
}
