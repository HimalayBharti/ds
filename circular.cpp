#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	
	
};

class Circular{
	
	private:
		Node * head=NULL;
		Node * tail=NULL;
	
	public:
		void insert(int data)
		{
			Node * newnode = new Node(data);
			
			if(head==NULL)
			{
				head=newnode;
				head->next=head;
				cout<<head->data<<" is inserted"<<endl;
				
				return;
			}
			Node * temp = head;
			
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			
			cout<<newnode->data<<" is inserted "<<endl;
			
			return;
		}
		
		void remove()
		{
			if(head==NULL)
			{
				cout<<"Empty data"<<endl;
				return;
			}
			
			Node* temp2;
			Node * temp = head;
			
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp2 = head;
			head=head->next;
			temp->next=head;
			
			cout<<temp2->data<<" is removed "<<endl;
			
			delete(temp2);
			
		}
		
		void search(int value)
		{
			if(head==NULL)
			{
				cout<<"Empty list"<<endl;
				
				return;
			}
			
			Node * temp = head;
			
			while((temp->next!=head) or (temp->data==value))
			{
				if(temp->data==value)
				{
					cout<<temp->data<< " is found "<<endl;
					cout<< "Pointer is "<<temp<<endl;
					
					return;
				}
				
				temp=temp->next;
			}
			cout<<value<<" is not present in list"<<endl;
			
			return;
		}
		
		
		void display()
		{
			if (head==NULL)
			{
				cout<<"No data found"<<endl;
				return;
			}
			
			Node * temp=head;
			
			do
			{
				cout<<temp->data<<"->";
				temp=temp->next;
				
			}while(temp!=head);
			
			cout<<"NULL"<<endl;
			return;
			
		}
		
		
};


int main()
{
	Circular c;
	
	c.insert(10);
	c.insert(20);
	c.insert(30);
	c.insert(40);
	c.insert(50);
	
	c.display();
	
	c.remove();
	
	c.search(300);
	c.display();
	
	return 0;
}
