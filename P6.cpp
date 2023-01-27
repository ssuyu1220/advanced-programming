#include <iostream>
#include <string>
using namespace std;

struct Node{
	int data;
	string name;
	int score;
	Node *next;
};

Node *push(struct Node *head, int node_data);
Node *append(struct Node *head, int node_number,string node_name,int node_score);
Node *insert(struct Node *head, int num, int node_data);
Node *deletefirstnode(struct Node *head);
Node *deletelastnode(struct Node *head);
Node *deletemiddlenode(struct Node *head, int num);
void displaylist (struct Node *node);

int main(){
	char k;
	int sum=0,cnt=0;
	Node *head=NULL;
	do{
		cout<<"請依序輸入學生之座號、姓名及數學成績（以空白區隔）"<<endl; 
		int n_number,n_score;
		string n_name;
		cin>>n_number>>n_name>>n_score;
		sum+=n_score;
		cnt+=1;
		head=append(head,n_number,n_name,n_score);
		cout<<"還有其他學生要輸入嗎？";
		cin>>k;
	}while(k=='y');
	cout<<endl<<"你輸入的所有學生資料如下："<<endl;
	cout<<"座號\t姓名\t數學成績"<<endl;
	displaylist(head); 
	printf("所有學生的數學成績平均為：%.1f",float(sum)/float(cnt));
	
	
	return 0;
}


Node *push(struct Node *head, int node_data){

	struct Node * newNode = new Node;	//新增節點運算子
	newNode->data = node_data;	//->抓取某物件裡的某成員
	newNode->next = head;
	head = newNode;
	return head;
}

Node *append(struct Node *head, int node_number,string node_name,int node_score){
	
	Node * newNode = new Node;
	Node *current = head;			//宣告current變數找尋串列結尾
	newNode->data = node_number;
	newNode->name = node_name;
	newNode->score = node_score;
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
		cout << node->data <<'\t'<<node->name<<'\t'<<node->score<<endl;
		node = node->next;
	}
	if ( node == NULL )
		cout << endl;
}
