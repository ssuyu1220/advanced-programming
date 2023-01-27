#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *enqueue(struct Node *head, int node_data);
Node *dequeue(struct Node *head);
void displaylist (struct Node *node);

int action(){
	int a;
	printf("\n**********************************");
	printf("\n** 1.enqueue                    **");
	printf("\n** 2.dequeue                    **");
	printf("\n** 3.list the queue from front  **");
	printf("\n** 4.quit                       **");
	printf("\n**********************************");
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
				head=enqueue(head,val);
				break; 
			case 2:
				head=dequeue(head); 
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



Node *enqueue(struct Node *head, int node_data){
	
	Node * newNode = new Node;
	Node *current = head;
	newNode->data = node_data;
	newNode->next = NULL;
	if ( head == NULL ){
		head = newNode;
		return head;
	}
	while ( current->next != NULL)
		current = current->next;
	current->next = newNode;
	return head;
}

Node *dequeue(struct Node *head){
	if ( head == NULL ){
		cout<<"The queue is empty, nothing to delete.\n"<<endl;
		return NULL;
	}
	Node *tempnode = head;	//使用tempnode暫存要被刪除的head
	head = head->next;
	delete tempnode;		//刪除節點運算子
	return head;
}

void displaylist (struct Node *node){
	if ( node == NULL )
		cout << "The queue is empty.\n" << endl;
	while ( node != NULL ){
		cout << node->data << " ";
		node = node->next;
	}
	
}
