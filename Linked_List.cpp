//*****************************************
//*	SINGLY LINKED LIST POPULAR PROBLEMS   *
//*****************************************

#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

//Structure Definition
//Alias name for node is n
typedef struct node
{
	int data;
	struct node *next;
}n;

n *head = NULL;
n *tail = NULL;

//Create Node with Data
n* createNode()
{
	n *newnode;
	newnode = new n(); 
	cout<<"Enter data : ";
	cin>>newnode->data;
	newnode->next = NULL;
	return newnode;
}

//To add at the beginning of the list
void addFirst()
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;	
	}
	else
	{
		n *temp = createNode();
		temp->next = head;
		head = temp;
	}	
	cout<<"Inserted at First Successfully"<<endl;	
}

//To add at the middle of the list
void addmid(int pos)
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;
	}
	else
	{
		n *temp = createNode();
		n *th = head;
		int count = 1;
		while(th != NULL)
		{
			if(count == pos-1)
			{
				temp->next = th->next;
				th->next = temp;
				break;
			}
			count++;
			th = th->next;
		}
		cout<<"Inserted at "<<pos<<" Successfully\n";
	}
}

//To add at the last of the list
void addLast()
{
	if(head == NULL)
	{
		head = createNode();
		tail = head;
	}
	else
	{
		n *temp = createNode();
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}
	cout<<"Inserted at Last Successfully"<<endl;
}

//To delete first node from the list
void delfirst()
{
	if(head == NULL)
	{
		cout<<"List is empty\n";
		return;
	}
	if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		n *temp = head;
		head = head->next;
		temp->next = NULL;
		free(temp);
	}
	cout<<"First Element deleted successfully"<<endl;
}

//To delete last node from the list
void dellast()
{
	if(head == NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		n *th1 = head->next;
		n *th2 = head;
		while(th1->next != NULL)
		{
			th1 = th1->next;
			th2 = th2->next;
		}
		th2->next = NULL;
		tail = th2;
		free(th1);
		free(th2);
	}
	cout<<"Deleted last node Successfully"<<endl;
}

//To delete middle element from the list
void delmid(int pos)
{
	if(head == NULL)
	{
		cout<<"List is empty";
		return;
	}
	if(head->next == NULL)
		free(head);
	else
	{
		n *temp = head;
		int count = 1;
		while(temp != NULL)
		{
			if(count == pos-1)
				break;
			temp = temp->next;
			count++;
		}
		n *th = temp->next;
		temp->next = th->next;
		free(th);
	}
	cout<<"Deleted node "<<pos<<" Successfully"<<endl;
	
}

//To check even or odd number of nodes in the list
void checkEven_or_Odd()
{
	int flag = 0;
	n *t = head;
	while(t != NULL)
	{
		flag = !flag;
		t = t->next;
	}
	if(flag == 0 )
		cout<<"List is Even"<<endl;
	else
		cout<<"List is Odd"<<endl;
		
}

//To reverse the entire linked list
void reverse(n *curr)
{
	n *prev=NULL, *temp=NULL;
	while(curr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
	free(prev);
	free(temp);
	
}

//To find the middle node
void middlevalue()
{
	n *temp = head,*fast=head,*slow=head;
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast->next != NULL)
			fast = fast->next;
	}
	cout<<"\nMiddle value "<<slow->data<<endl;
	free(fast);
	free(slow);
	free(temp);
}

//To know number of nodes in the list
int size()
{
	node *t = head;
	int size = 0;
	while(t != NULL)
	{
		++size;
		t = t->next;
	}
	return size;
}

//Check whether list has any loop
bool loop()
{
	if(head == NULL)
		return false;
	if(head->next == NULL)
		return false;
	n *fast=head,*slow=head;
	while(fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast->next != NULL)
			fast = fast->next;
		if(slow == fast)
			return true;
	}
	return false;	
}

//Merging two sorted linked lists
n* sortedMerge(Node* head1,   Node* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    n *head=NULL,*tail=NULL;
    if(head1->data <= head2->data)
    {
        head=tail=head1;
        head1 = head1->next;
    }
    else
    {
        head=tail=head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            tail = tail->next;
            head1 = head1->next;
            
        }
        else
        {
            tail->next = head2;
            tail = tail->next;
            head2 = head2->next;
        }
    }
    if(head1 == NULL)
    {
        tail->next = head2;
    }
    else
    {
        tail->next = head1;
    }
    return head;
}

//Reversing alternate linked list nodes
n * reversekalternatenodes(n *head,int k)
{
	n *curr = head,*prev = NULL,*temp = NULL;
	int count = 0;
	while(curr != NULL && count < k)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		count++;
	}
	if(head != NULL)
		head->next = curr;
	count = 0;
	while(count < k-1 && curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	if(curr != NULL)
		curr->next = reversekalternatenodes(curr->next,k);
	return prev;
}

//To traverse the entire linked list
void display(n *head)
{
	n *t = head;
	while(t != NULL)
	{
		cout<<t->data<<" ";
		t = t->next;
	}
}

//Main Function to call methods
int main()
{
	int count;
	addFirst();
	addFirst();
	addFirst();
	addLast();
	addLast();
	addmid(3);
	//delfirst();
	//delmid(3);
	//dellast();
	display(head);
	checkEven_or_Odd();
	count = size();
	cout<<"Number of Nodes : "<<count<<endl;
	cout<<"List before Reverse : "<<endl;
	display(head);
	reverse(head);
	cout<<"\nList after Reverse : "<<endl;
	display(head);
	middlevalue();
	cout<<"Does loop exist? "<<loop()<<"\n";
	head = reversekalternatenodes(head,2);
	display(head);
	
	return 0;
}
