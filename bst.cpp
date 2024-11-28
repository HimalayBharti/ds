#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        parent = NULL;  
        left = NULL;    
        right = NULL;   
    }
};

class Binary_Tree {
private:
    Node* root;
    
    
    Node* build(Node* node, int value) {
        if (node == NULL) {  
            return new Node(value);
        }

        if (value < node->data) {
            node->left = build(node->left, value);
            node->left->parent = node; 
        }
        else {
            node->right = build(node->right, value);
            node->right->parent = node; 
        }

        return node;
    }
    
    
    Node* deleteNode(Node* root, int value) {
        if (root == NULL) {  
            return root;
        }

        
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        }
        
        else {
            
            if (root->left == NULL) {  
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {  
                Node* temp = root->left;
                delete root;
                return temp;
            }

            
            Node* temp = root->right;
            while (temp != NULL && temp->left != NULL) {  
                temp = temp->left;
            }

            
            root->data = temp->data;

            
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    
    void inorderTraversal(Node* node) {
        if (node == NULL) {  
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
    
    void preorderTraversal(Node* node){
    	
    	if(node==NULL)
    	{
    		return;
    		
		}
		cout<<node->data<<" ";
		preorderTraversal(node->left);
		
		preorderTraversal(node->right);
	}
	
	void postorderTraversal(Node * node){
		
		if(node==NULL)
		{
			return;
		}
		
		postorderTraversal(node->left);
		postorderTraversal(node->right);
		cout<<node->data<<" ";
	}
	
public:
    Binary_Tree() {
        root = NULL;  
    }

   
    void build(int value) {
        root = build(root, value);
        cout << value << " is inserted" << endl;
    }

    
    void deletion(int value) {
        root = deleteNode(root, value);
        cout << value << " is deleted" << endl;
    }

    
    void inorder() {
        cout << "In-order traversal of the tree: ";
        inorderTraversal(root);
        cout << endl;
    }
    
    void preorder()
    {
    	cout<<"Pre-order traversal of the tree: ";
    	preorderTraversal(root);
    	cout<<endl;	
	}
	
	void postorder(){
		cout<<"Post-order traversal of tree: ";
		postorderTraversal(root);
		cout<<endl;
		
	}
};

int main() {
    Binary_Tree b;

    b.build(10);
    b.build(20);
    b.build(30);
    b.build(5);
    b.build(15);

    b.inorder();

    b.deletion(20);
    b.inorder();
    
    b.deletion(5);
    
    b.inorder();
    b.preorder();
    b.postorder();

    return 0;
}

