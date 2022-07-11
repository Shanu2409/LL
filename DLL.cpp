#include <iostream>

using namespace std;

class Node{

	public:		
    int data;

		Node* next;

		Node* pri;

		

		

	Node(int n){

		this->data = n;

		this->next = NULL;

		this->pri = NULL;

	}

};

void print(Node* &head){

	Node* temp = head;

	

	while(temp != NULL){

		cout<<temp->data<<" ";

		temp = temp->next;

	} cout<<endl;

}

void insterHead(Node* &head, int d){

	Node* temp = new Node(d);

	

	temp->next = head;

	head->pri = temp;

	head = temp;

}

void instertTail(Node* &tail, int d){

	Node* temp = new Node(d);\

	

	temp->pri = tail;

	tail->next = temp;

	tail = temp;

	

	

}

void deleteHead(Node* &head){

	Node* temp = head;

	head = temp->next;

	cout<<"deleting from head"<<temp->data<<endl;

	head->pri = NULL;

	delete(temp);

}

void deleteTail(Node* &tail){

	Node* temp = tail;

	

	tail = temp->pri;

	tail->next = NULL;

	cout<<"deleting from tail"<<temp->data<<endl;

	delete(temp);

	cout<<endl<<"whehd "<<temp->data;

}

void deletePosition(Node* &head,int p){

	int cnt = 1;

	Node* temp = head;

	

	while(cnt != p){

		temp = temp->next;

		cnt++;

	}

	

	temp->next->pri = temp->pri;

	temp->pri->next = temp->next ;

	

	cout<<"deleting "<<temp->data<<" from location "<<p<<" "<<endl;

	delete(temp);

	

}

int main() {

	Node* n1 = new Node(10);

	Node* head = n1;

	Node* tail = n1;

	insterHead(head,11);

	instertTail(tail,77);

	

//	deleteHead(head);

//	deleteTail(tail);

	deletePosition(head,2);

	

//	cout<<endl<<"head : "<<head->data<<" tail = "<<tail->data;

	

	cout<<endl<<"Data in list : ";

	print(head);

	

	

	

	

	return 0;

}
