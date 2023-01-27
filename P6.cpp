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
		cout<<"�Ш̧ǿ�J�ǥͤ��y���B�m�W�μƾǦ��Z�]�H�ťհϹj�^"<<endl; 
		int n_number,n_score;
		string n_name;
		cin>>n_number>>n_name>>n_score;
		sum+=n_score;
		cnt+=1;
		head=append(head,n_number,n_name,n_score);
		cout<<"�٦���L�ǥͭn��J�ܡH";
		cin>>k;
	}while(k=='y');
	cout<<endl<<"�A��J���Ҧ��ǥ͸�Ʀp�U�G"<<endl;
	cout<<"�y��\t�m�W\t�ƾǦ��Z"<<endl;
	displaylist(head); 
	printf("�Ҧ��ǥͪ��ƾǦ��Z�������G%.1f",float(sum)/float(cnt));
	
	
	return 0;
}


Node *push(struct Node *head, int node_data){

	struct Node * newNode = new Node;	//�s�W�`�I�B��l
	newNode->data = node_data;	//->����Y����̪��Y����
	newNode->next = head;
	head = newNode;
	return head;
}

Node *append(struct Node *head, int node_number,string node_name,int node_score){
	
	Node * newNode = new Node;
	Node *current = head;			//�ŧicurrent�ܼƧ�M��C����
	newNode->data = node_number;
	newNode->name = node_name;
	newNode->score = node_score;
	newNode->next = NULL;
	if ( head == NULL ){			//�Y�@�}�l���Ŧ�C�A�s�[�J���`�I�Y�Ohead
		head = newNode;
		return head;
	}
	while ( current->next != NULL)	//���current�D��C����
		current = current->next;
	current->next = newNode;		//�����s�W�`�I���C����
	return head;
}

Node *insert(struct Node *head, int num, int node_data){
	if ( head == NULL ){
	 	cout << "����O�Ŧ�C" << endl;
		return NULL;
	}
	struct Node *newNode = new Node;
	struct Node *count_list = head;
	struct Node *current = head;
	newNode->data = node_data;
	
	int listlen = 0;
	while ( count_list != NULL ){	//�p���C����
		listlen++;
		count_list = count_list->next;
	}
	
	if (num==0 || num >= listlen)
		cout << "���J��m�W�X��C�d��" <<endl;
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
	Node *tempnode = head;	//�ϥ�tempnode�Ȧs�n�Q�R����head
	head = head->next;
	delete tempnode;		//�R���`�I�B��l
	return head;
}

Node *deletelastnode(struct Node *head){
	if ( head == NULL )
		return NULL;
	if ( head->next == NULL ){
		delete head;
		return NULL;
	}
	Node *second_last = head;				//�qhead�}�l��M�˼Ʋ�2�Ӹ`�I
	while ( second_last->next->next != NULL )
		second_last = second_last->next;
	delete (second_last->next);
	second_last->next = NULL;
	return head;
}

Node *deletemiddlenode(struct Node *head, int num){
	if ( head == NULL ){
		cout << "����O�Ŧ�C" << endl;
		return NULL;
	}
	struct Node *remove_pre = head;
	struct Node *count_list = head;
	struct Node *remove;
	
	int listlen = 0;
	while ( count_list != NULL ){	//�p���C����
		listlen++;
		count_list = count_list->next;
	}
	if (num==0 || num >= listlen)
		cout << "�R����m�W�X��C�d��" <<endl;
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
