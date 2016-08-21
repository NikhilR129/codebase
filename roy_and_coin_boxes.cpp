
#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
	int key;
	int data;
	node *left;
	node *right;
};

node *newnode(int KEY,int DATA)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=DATA;
	temp->key=KEY;
};
node *insert(node *root,int KEY,int DATA)
{
	if(root==NULL)
		return newnode(KEY,DATA);

	if(KEY < root->key)
		root->left=insert(root->left,KEY,DATA);

	else
		root->right=insert(root->right,KEY,DATA);

	return root;
}
int find(node *root,int KEY)
{
	if(root==NULL)
		return 0;

	if(root->key <  KEY)
		return find(root->right,KEY);

	return root->data+find(root->left,KEY)+find(root->right,KEY);

}


int main()
{
	int n,m,i,q,x,y;
	cin>>n>>m;
	node *root=NULL;
	int *arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--; y--;
		arr[x]++;
		if(y+1 <= n-1)
			arr[y+1]--;

	}
	int total=0;
	for(i=0;i<n;i++)
	{
		total+=arr[i];
		arr[i]=total;
	}
	int coins[n];
	for(i=0;i<n;i++)
		coins[arr[i]]++;

	for(i=0;i<n;i++)
		if(coins[i])
			root=insert(root,i,coins[i]);
	//int coins[n];
	cin>>q;
	while(q--)
	{
		cin>>x;
		cout<<find(root,x)<<endl;
	}

return 0;
}

