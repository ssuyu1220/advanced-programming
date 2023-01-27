#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *push(struct Node *head, int node_data){

	struct Node * newNode = new Node;	//新增節點運算子
	newNode->data = node_data;	//->抓取某物件裡的某成員
	newNode->next = head;
	head = newNode;
	return head;
}

Node *append(struct Node *head, int node_data){
	
	Node * newNode = new Node;
	Node *current = head;			//宣告current變數找尋串列結尾
	newNode->data = node_data;
	newNode->next = NULL;
	if ( head == NULL ){			//若一開始為空串列，新加入的節點即是head
		head = newNode;
		return head;
	}
	while ( current->next != NULL)	//表示current非串列結尾
		current = current->next;
	current->next = newNode;		//完成新增節點於串列尾端
	return head;
}

Node *insert(struct Node *head, int num, int node_data){
	if ( head == NULL ){
	 	cout << "不能是空串列" << endl;
		return NULL;
	}
	struct Node *newNode = new Node;
	struct Node *count_list = head;
	struct Node *current = head;
	newNode->data = node_data;
	
	int listlen = 0;
	while ( count_list != NULL ){	//計算串列長度
		listlen++;
		count_list = count_list->next;
	}
	
	if (num==0 || num >= listlen)
		cout << "插入位置超出串列範圍" <<endl;
	else{
		for ( int i = 1; i < num ; i++ )
			current = current->next;
		newNode->next = current->next;
		current->next = newNode;
	}
	return head;
}

Node *deletefirstnode(struct Node *head){
	if ( head == NULL )
		return NULL;
	Node *tempnode = head;	//使用tempnode暫存要被刪除的head
	head = head->next;
	delete tempnode;		//刪除節點運算子
	return head;
}

Node *deletelastnode(struct Node *head){
	if ( head == NULL )
		return NULL;
	if ( head->next == NULL ){
		delete head;
		return NULL;
	}
	Node *second_last = head;				//從head開始找尋倒數第2個節點
	while ( second_last->next->next != NULL )
		second_last = second_last->next;
	delete (second_last->next);
	second_last->next = NULL;
	return head;
}

Node *deletemiddlenode(struct Node *head, int num){
	if ( head == NULL ){
		cout << "不能是空串列" << endl;
		return NULL;
	}
	struct Node *remove_pre = head;
	struct Node *count_list = head;
	struct Node *remove;
	
	int listlen = 0;
	while ( count_list != NULL ){	//計算串列長度
		listlen++;
		count_list = count_list->next;
	}
	if (num==0 || num >= listlen)
		cout << "刪除位置超出串列範圍" <<endl;
	else{
		for ( int i = 1; i < num ; i++ )
			remove_pre = remove_pre->next;
		remove = remove_pre->next;
		remove_pre->next = remove->next;
	}
	delete remove;
	return head;
}

void displaylist (struct Node *node){
	while ( node != NULL ){
		cout << node->data << "-->";
		node = node->next;
	}
	if ( node == NULL )
		cout << "NULL" << endl;
}

int main(){
	/*
	struct Node*node=new Node;
	node->data=20;
	node->next=NULL;
	struct Node*head=node;
	*/
	Node *head=NULL;
	head=append(head,20);
	//displaylist(head);
	head=push(head,25);
	//displaylist(head);
	head=append(head,18);
	//displaylist(head);
	head=insert(head,1,17);
	displaylist(head);
	head=deletemiddlenode(head,2);
	//displaylist(head);
	head=deletemiddlenode(head,2);
	displaylist(head);
	return 0;
}
