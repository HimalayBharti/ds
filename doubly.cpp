#include<iostream>

using namespace std;

class Node{
	
	public:
		
		int data;
		Node * next;
		Node *prev;
		
		Node(int data)
		{
			this->data= data;
			this->prev=NULL;
			this->next=NULL;
			
		}
};

class Doubly{
	
	
	private:
		Node *head = NULL;
		
	public:
		
		void head_insertion(int data)
		{
			Node * newnode = new Node(data);
			if (head==NULL)
			{
				head=newnode;
				cout<<head->data<<" is inserted at the begenning "<<endl;
				return;
			}
			
			Node* temp = head;
			newnode->next=temp;
			temp->prev=newnode;
			head=newnode;
			
			cout<<head->data<<" is inserted at the head of list"<<endl;
			return ;
			
		}
		
		void tail_insertion(int data)
		{
			Node * newnode = new Node(data);
			
			if (head==NULL)
			{
				head=newnode;
				cout<<head->data<<" is inserted at the tail insertion"<<endl;
				return;
				
			}
			 Node * temp = head;
			 
			 while(temp->next)
			 {
			 	temp=temp->next;
			 }
			 temp->next=newnode;
			 newnode->prev=temp;
			 cout<<newnode->data<<" is inserted at the end of the list"<<endl;
			 
			 return ;
			
		}
		
		void insertion(int data,int index)
		{
			Node * newnode = new Node(data);
			
			
			if(head==NULL)
			{
				head=newnode;
				cout<<head->data<< " 1st element"<<endl;
				return;
			}
			
			if (index==0)
			{
				newnode->next=head;
				head->prev=newnode;
				cout<<newnode->data<< " is inserted at the 0 index"<<endl;
				return;
			}
			
			
			int count=0;
			Node * pre;
			Node * pos;	
			Node * temp = head;
					
			while(count<=index-1)
			{
				if(count==index-1)
				{
					pre=temp;
					pos=temp->next;
					
					newnode->next=pos;
					newnode->prev=pre;
					
					pre->next=newnode;
					pos->prev=newnode;
						
					cout<<newnode->data<< " is inderted at the index: "<<index<<endl;
					
					return;						
				}
					
				count++;
				temp=temp->next;
			}
		}
		
		void  head_remove()
		{
			if(head==NULL)
			{
				cout<<"No element"<<endl;
				
				return;
			}
			Node* temp =head;
			
			head=head->next;
			cout<<temp->data<<" is deleted from the begening"<<endl;
			
			delete(temp);
			return ;
		}
		
		void end_remove()
		{
			if(head==NULL)
			{
				cout<<"Empty list"<<endl;
				return;
			}
			
			Node * temp = head;
			Node * pre;
			while(temp->next!=NULL)
			{
				pre=temp;
				temp=temp->next;
				
			}
			
			pre->next=NULL;
			
			cout<<temp->data<<" is deleted from the end of the list"<<endl;
			
			delete(temp);
			return;
			
			
		}
		
		
		void display()
		{
			Node* temp = head;

			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL";
		}
		
};
int main()
{
    Doubly d;
    
    d.head_insertion(100);
    d.head_insertion(10);
    
    d.tail_insertion(30);
    d.tail_insertion(20);
    
    
    d.insertion(25,2);
    
    d.head_remove();
    
    
    d.end_remove();
    
    d.display();
    return 0;
}
