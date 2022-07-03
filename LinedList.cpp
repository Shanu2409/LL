#include <iostream>
using namespace std;

class Node {
	
	public:
	int data;
	Node* next;
	
	Node(int n){
		this->data = n;
		this->next = NULL;
	}
};	
	void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << "  ";
        temp = temp -> next;
    }
    cout << endl;
}


void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}


void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void insertInPosition(Node* &head, int p, int d){
	
	if(p==1){
		insertAtHead(head,d);
		return;
	}
	
	Node* curr = head;
	int cnt = 1;
	
	while(cnt < p-1){
		curr = curr->next;
		cnt++;
	}
	
	if(curr == NULL){
		insertAtTail(curr,d);
	}
	
	Node* newInsert = new Node(d);
	newInsert -> next = curr->next;
	curr-> next = newInsert;
}

void del(Node* &head,int p){
	if(p == 1){
		Node* temp = head;
		temp = temp->next;
		delete(temp); 
	}
	else {
		Node* cur = head;
		Node* pri = NULL;
		
		int cnt = 1;
		while(cnt < p){
			pri = cur;
			cur = cur -> next;
			cnt++;
		}
		pri->next = cur->next;
		cout<<"Deleting "<<cur->data<<" which is at position "<<cnt<<endl;
		delete(cur);
	}
}

void delFromData(Node* &head, int k){
	Node* cur = head;
		Node* pri = NULL;
		
		int cnt = 1;
		while(cur->data != k){
			pri = cur;
			cur = cur -> next;
			cnt++;
		}
		pri->next = cur->next;
		cout<<"Deleting "<<cur->data<<" which is found at position "<<cnt<<endl;
		delete(cur);
	
}

int main(){
	
    Node* node1 = new Node(10);    
    Node* head = node1; 
    Node* tail = node1;
    
    insertAtHead(head,3);
    insertAtTail(tail,12);
    insertAtTail(tail,15);
    insertInPosition(head,2,7);
    insertInPosition(head,1,77);  
    print(head);
    delFromData(head,77);
    print(head);
  
	return 0;
}
