#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
    
    Node() {
        this->data = 0;
        this->next = NULL;
    }
};

class LinkedList {
	
private:
    Node* head = NULL;

public:
    // Node insertion at tail back
    void tail_insertion(int value) {
        Node* newnode = new Node(value);
        
        if (head == NULL) {
            head = newnode;
        } 
		else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Node insertion at head or front 
    void head_insertion(int value) {
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
    }
    
    //Node insertation at any position
    void insertion(int value,int position){
    	
    	Node* newNode=new Node(value);
    	Node* temp=head;
    	Node*prev=NULL;
    	int count=0;
    	
    	while (temp && count<position){
    		prev=temp;
			temp=temp->next;
			count++;
			
		}
		if(count == position){
			newNode->next=temp;
			prev->next=newNode;	
		}
		else 
		    cout<<"Position is out of range"<<endl;	
	}
	
	//Deletion from head	
	void head_deletion()
	{    
		Node *temp = head;
		head = head->next;
		delete temp;
		
	}
	
	//Deletion from tail
	void tail_deletion()
	{
		
		Node* temp = head;
		Node* prev = NULL;
		while(temp->next!=NULL){
			
			prev=temp;
			temp=temp->next;
			
		}
		delete temp;
		prev->next=NULL;
		
	}
	
	//Deletion from any position
	void deletion_at_any_position(int position){
         if (!head || position<0)
         {
              cout<<"list is empty"<<endl;
              
         }
         
         if(position==0)
         {
           Node*temp=head;
           head=head->next;
           delete temp;
         }
		 Node* temp=head;
		 Node* temp2=NULL;
		 int count=0;
		 
		 while(temp&&count<position)
		 {
            temp2=temp;
            temp=temp->next;
            count++;
   
        }
         if(count==position&&temp)
         {
         temp2->next=temp->next;
         delete temp;
                                   }
   
		else
		{
            cout<<"position out of range"<<endl;
        
        }
            
	}
	
	
	// search element
	
	void search(int value)
	{
		if(head==NULL)
		{
			cout<<"Empty list"<<endl;
			return;
		}
		
		Node *temp=head;
		while((temp==NULL) or (temp->data == value))
		{
			if(temp->data==value)
			{
				cout<<"Search element: "<<temp->data<<endl;
				cout<<"Pointer: "<<temp<<endl;
				
				return;
			}
			
			temp=temp->next;
			
		}
	
		cout<<value<< " is not present"<<endl;
		
		return;
		
		
	}

    // Function to print node info
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
        
    }
};

int main() {
    LinkedList list;
    list.head_insertion(10);
    list.head_insertion(20);
    list.head_insertion(30);
    list.head_insertion(40);
    
    list.display();
    list.tail_insertion(300);
    //list.insertion(40,2);
    list.display();
    
    list.head_deletion();
    list.display();
    
    list.tail_deletion();
    list.display();
    
    list.search(3000);
    
    return 0;
}

