//**************************************
//*	Interview Problems on Binary Trees *
//**************************************

#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

//Tree Structure
struct node
{
	int data,hd;
	struct node *left,*right;
};

//To create new node
node * newnode(int d)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/*
	Traversal Time and Space Complexity:
	
	In recursion : Time Complexity - O(n)
				   Space Complexity - O(logn) for complete tree! In case of skew tree, O(n)
				   
	In Iterative : Time Complexity - O(n)
				   Space Complexity - O(n)

*/


//Inorder Traversal using Recursive Approach
void inorder(struct node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

//Inorder Traversal using Iterative Approach
void inorderiterate(struct node *root)
{
	struct node *th = root;
	stack<struct node *> s;
	while(true)
	{
		while(th)
		{
			s.push(th);
			th = th->left;
		}
		if(s.empty())
			break;
		struct node *temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		th = temp->right;
	}
}

//Preorder Traversal using Recursive Approach
void preorder(struct node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

//Preorder Traversal using Iterative Approach
void preorderiterate(struct node *root)
{
	struct node *th = root;
	stack<struct node *> s;
	while(true)
	{
		while(th)
		{
			s.push(th);
			cout<<th->data<<" ";
			th = th->left;
		}
		if(s.empty())
			break;
		struct node *temp = s.top();
		s.pop();
		th = temp->right;
	}
}

//Postorder Traversal using Recursive Approach
void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

//Postorder Traversal using Iterative Approach
void postorderiterate(struct node *root)
{
	stack<struct node*> temp;
	stack<int> s; 
	temp.push(root);
	while(!temp.empty())
	{
		struct node *curr = temp.top();
		temp.pop();
		s.push(curr->data);
		if(curr->left != NULL)
			temp.push(curr->left);
		if(curr->right != NULL)
			temp.push(curr->right);
	}
	while(s.empty() != 1)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

//Level order Traversal
void levelorder(struct node *root)
{
	if(root != NULL)
	{
		queue<node *> box;
		box.push(root);
		
		while(box.empty() == false)
		{
			struct node *val = box.front();
			cout<<val->data<<" ";
			box.pop();
			
			if(val->left != NULL)
				box.push(val->left);
			
			if(val->right != NULL)
				box.push(val->right);
		}
	}	
}

//Level order Traversal line by line
void levelorderline(struct node* root)
{
	if(root == NULL) return;
	
	queue<node *> q;
	q.push(root);
	while(q.empty() == false)
	{
		int level = q.size();
		
		while(level > 0)
		{
			struct node *val = q.front();
			cout<<val->data<<" ";
			q.pop();
		
			if(val->left != NULL)
				q.push(val->left);
			
			if(val->right != NULL)
				q.push(val->right);
			level--;		
		}
		cout<<"\n";
	}
}

//Spiral Traversal
void spiral(struct node *root)
{
	if(root == NULL) return;
	stack<node *> s1;
	stack<node *> s2;
	
	s1.push(root);
	
	while(s1.empty() == false  || s2.empty() == false)
	{
		while(!s1.empty())
		{
			struct node *n = s1.top();
			cout<<n->data<<" ";
			s1.pop();
		
			if(n->left != NULL)
				s2.push(n->left);
		
			if(n->right != NULL)
				s2.push(n->right);
		}
		
		while(!s2.empty())
		{
			struct node *n1 = s2.top();
			cout<<n1->data<<" ";
			s2.pop();
		
			if(n1->right != NULL)
				s1.push(n1->right);
		
			if(n1->left != NULL)
				s1.push(n1->left);
		}
	}
}

//Left View of the Binary Tree
void leftview(struct node* root)
{
	queue<struct node*> q;
	stack<int> s;
	q.push(root);
	while(!q.empty())
	{
		int count = q.size();
		while(count > 0)
		{
			struct node *temp  = q.front();
			q.pop();
			s.push(temp->data);
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			--count;	
		}
		while(s.size() != 1)
			s.pop();
		cout<<s.top()<<" ";
		s.pop();
	}
}

//Ordered Left View of Binary Tree
void orderleftview(struct node *root)
{
	queue<struct node*> q;
	stack<int> s,rs;
	q.push(root);
	while(!q.empty())
	{
		int count = q.size();
		while(count > 0)
		{
			struct node *temp  = q.front();
			q.pop();
			s.push(temp->data);
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			--count;	
		}
		while(s.size() != 1)
			s.pop();
		rs.push(s.top());
		s.pop();
	}	
	while(!rs.empty())
	{
		cout<<rs.top()<<" ";
		rs.pop();
	}
}

//Right View of the Binary Tree
void rightview(struct node *root)
{
	queue<struct node *> q;
	stack<int> s;
	q.push(root);
	while(!q.empty())
	{
		int count = q.size();
		while(count > 0)
		{
			struct node *temp = q.front();
			q.pop();
			s.push(temp->data);
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			--count;
		}
		cout<<s.top()<<" ";
		while(!s.empty())
		{
			s.pop();
		}
	}
}

//Ordered right view of the binary tree
void orderrightview(struct node *root)
{
	queue<struct node *> q;
	stack<int> s,rs;
	q.push(root);
	while(!q.empty())
	{
		int count = q.size();
		while(count > 0)
		{
			struct node *temp = q.front();
			q.pop();
			s.push(temp->data);
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			--count;
		}
		rs.push(s.top());
		while(!s.empty())
		{
			s.pop();
		}
	}
	while(!rs.empty())
	{
		cout<<rs.top()<<" ";
		rs.pop();
	}
}

//Vertical Traversal
void vertical(struct node *root)
{
    queue<pair<struct node*,int> > q;
    multimap <int,int> m;
    q.push(make_pair(root,0));
    while(q.empty() == false)
    {
        pair <struct node *,int> temp = q.front();
        m.insert(make_pair(temp.second,temp.first->data));
        q.pop();
        
        if(temp.first->left != NULL)
        {
            q.push(make_pair(temp.first->left,temp.second-1));
        }
        if(temp.first->right != NULL)
        {
            q.push(make_pair(temp.first->right,temp.second+1));
        }
    }
    multimap <int,int> :: iterator it;
    for(it = m.begin();it != m.end();++it)
    	cout<<it->second<<" ";
}

//Bottom View of the Binary Tree
void bottomview(struct node *root)
{
	struct node *th = root;
	int hd = 0;
	queue<struct node *> q;
	map<int,int> m;
	root->hd = hd;
	q.push(root);
	while(!q.empty())
	{
		struct node *temp = q.front();
		m[temp->hd] = temp->data;
		q.pop();
		if(temp->left != NULL)
		{
			temp->left->hd = temp->hd-1;
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			temp->right->hd = temp->hd+1;
			q.push(temp->right);
		}
	}
	map<int,int> :: iterator i;
	for(i = m.begin();i != m.end();++i)
	{
		cout<<i->second<<" ";
	}	
}

//Top View of the Binary Tree
void topview(struct node *root)
{
	queue<struct node *> q;
	map<int,int> m;
	root->hd = 0;
	q.push(root);
	while(!q.empty())
	{
		struct node *temp = q.front();
		if(m.find(temp->hd) == m.end())
		{
			m[temp->hd] = temp->data;
		}
		q.pop();
		
		if(temp->left != NULL)
		{
			temp->left->hd = temp->hd-1;
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			temp->right->hd = temp->hd+1;
			q.push(temp->right);
		}
	}
	map<int,int> :: iterator it;
	for(it = m.begin();it != m.end();++it)
		cout<<it->second<<" ";
}

//Reverse Level order Traversal
void revlevel(struct node *root)
{
	if(root == NULL) return;
	
	queue<node *> q;
	stack<node *> s;
	
	q.push(root);
	
	while(q.empty() == false)
	{
		struct node *n = q.front();
		s.push(n);
		q.pop();
		
		if(n->left != NULL)
			q.push(n->left);
		
		if(n->right != NULL)
			q.push(n->right);
	}
	
	while(s.empty() == false)
	{
		struct node *n1 = s.top();
		cout<<n1->data<<" ";
		s.pop();
	}
}

//Sum of all nodes in the Binary Tree
int sum(struct node *root)
{
	if(root == NULL)	return 0;
	else
		return root->data+(sum(root->left)+sum(root->right));
}


void replace(struct node *root)
{
	queue<struct node *> q;
	int level = 0;
	q.push(root);
	while(!q.empty())
	{
		int count = q.size();
		while(count>0)
		{
			struct node *th = q.front();
			q.pop();
			th->data = level;
			cout<<th->data<<" ";
			count--;
			if(th->left != NULL)
				q.push(th->left);
			if(th->right != NULL)
				q.push(th->right);
		}
		cout<<"\n";
		level++;
	}
}

//Height of the Binary Tree
int height(struct node* root)
{
	if(root == NULL) return 0;
	
	if(root->left == NULL && root->right == NULL) return 0;
	
	if(root != NULL)
	{
		int l = height(root->left);
		int r = height(root->right);
		return(1+((l>r)?l:r));
	}
}

//Check Tree is balanced or not
int balanced(struct node *root)
{
	if(root == NULL)	return 1;
	int l = height(root->left);
	int r = height(root->right);
	if(abs(l-r) <= 1)
		return 1;
	else
		return 0;
}

//Get sum of leaf nodes
int leaf(struct node* root)
{
	if(root == NULL) return 0;
	
	if(root->left == NULL && root->right == NULL)	return 1;
		
	return (leaf(root->left)+leaf(root->right));
}

//Get sum of non leaf nodes
int nonleaf(struct node* root)
{
	if(root == NULL) return 0;
	
	if(root->left == NULL && root->right == NULL) return 0;
	
	return (1+(nonleaf(root->left) + nonleaf(root->right)));
}

//Main Function
int main()
{
	int h,l,nl,bal;
	struct node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->left->left->left = newnode(8);
	root->left->left->right = newnode(9);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(11);
	root->right->left->left = newnode(12);
	root->right->left->right = newnode(13);
	root->right->right->left = newnode(14);
	root->right->right->right = newnode(15);
	cout<<"Inorder Traversal - Recursion\n";
	inorder(root);
	cout<<"\nInorder Traversal - Iteration\n";
	inorderiterate(root);
	cout<<"\n\nPreorder Traversal - Recursion\n";
	preorder(root);
	cout<<"\nPreorder Traversal - Iteration\n";
	preorderiterate(root);
	cout<<"\n\nPostorder Traversal - Recursion\n";
	postorder(root);
	cout<<"\nPostorder Traversal - Iteration\n";
	postorderiterate(root);
	cout<<"\n\nLevelorder Traversal\n";
	levelorder(root);
	cout<<"\n\nLevelorder Traversal (Line by Line)\n";
	levelorderline(root);
	cout<<"\nLevel order Traversal (spiral form or Zig-Zag form)\n";
	spiral(root);
	cout<<"\n\nLeft View of a Tree\n";
	leftview(root);
	cout<<"\n\nFrom Bottom to top Left View\n";
	orderleftview(root);
	cout<<"\n\nRight View of a Tree\n";
	rightview(root);
	cout<<"\n\nFrom Bottom to top Right View\n";
	orderrightview(root);
	cout<<"\n\nVertical Order\n";
	vertical(root);
	cout<<"\n\nBottom View of a Tree\n";
	bottomview(root);
	cout<<"\n\nTop View of a Tree\n";
	topview(root);
	cout<<"\n\nReverse Level order Traversal\n";
	revlevel(root);
	cout<<"\n\nSum of all the nodes : "<<sum(root)<<"\n";
	cout<<"\n\nReplace level value on each node in Level order Traversal\n";
	replace(root);
	h = height(root);
	cout<<"\n\nHeight of the tree : "<<h;
	l = leaf(root);
	bal = balanced(root);
	cout<<"\n\nTree is Balanced or not : "<<bal<<"\n";
	cout<<"\nCount the number of leaf nodes : "<<l<<"\n";
	nl = nonleaf(root);
	cout<<"\nCount the number of non-leaf nodes : "<<nl<<"\n";
	return 0;
}
