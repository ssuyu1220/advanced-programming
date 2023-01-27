#include<iostream>
using namespace std;
int score[4][4]={0};
int total[4]={0};
int Hwin=0;
int main(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>score[i][j];
			total[i]+=score[i][j];
		}
	}
	for(int i=0;i<4;i+=2){
		cout<<total[i]<<':'<<total[i+1]<<endl;
		if(total[i]>total[i+1]) Hwin+=1;
	}
	if(Hwin==2) cout<<"Win"<<endl;
	else if(Hwin==0) cout<<"Lose"<<endl;
	else cout<<"Tie";
}

