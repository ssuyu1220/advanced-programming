#include <iostream>
#include <vector>
#include <fstream>
#include<map>
using namespace std;

map<string,string> words;

struct node{
    string title;
    string content;
    vector<node*> childen;
};

node* insert(node *parent,string node_title,string node_content){
    node *new_node = new node;
	node *current = parent;
    new_node->title = node_title;
	new_node->content = node_content;
	new_node->childen;
	current->childen.push_back(new_node);
    parent=new_node;
    return parent;
}

void dfs(node *cur_node){
    int l=cur_node->childen.size();
    cout<<"["<<cur_node->title<<"]"<<"\n"<<cur_node->content<<endl;
    for(int i=0;i<l;i++){
        node *new_node=cur_node->childen[i];
        dfs(new_node);
    }
}

//讀檔+建map
void readf() {
    fstream f;
    string title="",content="",line;
    int tmp=0;
    f.open("words.txt");
    while (getline(f, line)) {
        if(tmp==0 && line.find("<title>=")!=-1){
            title=line.erase(0,9);
            title.pop_back();
            tmp=1;
        }
        else if(tmp==1 && line.find("<content>=")!=-1){
            tmp=2;
        }
        else if(tmp==2){
            if(line=="\""){
                words.insert(pair<string, string>(title, content));
                tmp=0;
                title="";
                content="";
                continue;
            }
            content.append(line);
            content.append("\n");  
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readf();
    node Node;
    Node.title="advanced programming";
    Node.content=words["advanced programming"];
    node *root_node=&Node;
    node *tmp_node1, *tmp_node2, *tmp_node3;
    tmp_node1=insert(root_node,"data structure",words["data structure"]);
    tmp_node2=insert(tmp_node1,"linked list",words["linked list"]);
    tmp_node2=insert(tmp_node1,"stack",words["stack"]);
    tmp_node2=insert(tmp_node1,"queue",words["queue"]);
    tmp_node1=insert(root_node,"algorithms",words["algorithms"]);
    tmp_node2=insert(tmp_node1,"sort",words["sort"]);
    tmp_node1=insert(tmp_node2,"bubble sort",words["bubble sort"]);
    tmp_node1=insert(tmp_node2,"selection sort",words["selection sort"]);
    tmp_node1=insert(tmp_node2,"insertion sort",words["insertion sort"]);
    tmp_node2=insert(tmp_node1,"search",words["search"]);
    tmp_node1=insert(tmp_node2,"sequential search",words["sequential search"]);
    tmp_node1=insert(tmp_node2,"binary search",words["binary search"]);
    tmp_node2=insert(tmp_node1,"others",words["others"]);
    tmp_node1=insert(tmp_node2,"greedy",words["greedy"]);
    tmp_node1=insert(tmp_node2,"divide and conquer",words["divide and conquer"]);
    dfs(root_node);
    return 0;
}