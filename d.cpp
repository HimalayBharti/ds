#include<iostream>
using namespace std;

class Node{

    public:
      int data;
      Node * next;

    Node()
    {
        this->data=0;
        this->next=NULL;

    }

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }


};

class Singly
{
    private:
     Node *head;

    public:
      void tail_insertion(int data)
      {
        Node newnode = new Node(data);
        if(head==NULL)
        {
            head = newnode;
            return;
        }

        Node * temp;
        temp=head;

        while(temp!=NULL)
        {
            temp=temp->next;
        }

        newnode = temp;
      }


      void display()
      {
        Node * temp;
        temp=head;

        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }

        cout<<"NULL";

      }
};

int main()
{
    Singly s;

    s.tail_insertion(10);
    s.tail_insertion(21);
}