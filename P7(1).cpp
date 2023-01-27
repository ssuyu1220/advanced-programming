#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *push(struct Node *head, int node_data);
Node *pop(struct Node *head);
void displaylist (struct Node *node);
int action(){
	int a;
	printf("\n********************************");
	printf("\n** 1.push                     **");
	printf("\n** 2.pop                      **");
	printf("\n** 3.list the stack from top  **");
	printf("\n** 4.quit                     **");
	printf("\n********************************");
	printf("\nPlease input your choice:");
	scanf("%d",&a);
	return a;
}
	
int main(){
	int n,val;
	Node *head = NULL;
	while(1){
		n=action();
		switch(n){
			case 1:
				printf("\nInput the number to insert:");
				scanf("%d",&val);
				head=push(head,val);
				break; 
			case 2:
				head=pop(head); 
				break;
			case 3:
				displaylist(head);
				printf("\n\n");
				break;
			case 4:
				exit(0);
			default:
				printf("\nPlease input 1, 2, 3 or 4!\n");	
		}
	}
	return 0;
}


Node *push(struct Node *head, int node_data){

	struct Node * newNode = new Node;
	newNode->data = node_data;
	newNode->next = head;
	head = newNode;
	return head;
}

Node *pop(struct Node *head){
	if ( head == NULL ){
		cout<<"The stack is empty, nothing to pop.\n"<<endl;
		return NULL;
	}
	Node *tempnode = head;
	head = head->next;
	delete tempnode;
	return head;
}

void displaylist (struct Node *node){
	if ( node == NULL )
		cout << "The stack is empty.\n" << endl;
	while ( node != NULL ){
		cout << node->data << " ";
		node = node->next;
	}
	
}
