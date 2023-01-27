#include<iostream>
using namespace std;
int main(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	int m=a[0],M=a[0];
	for(int i=1;i<3;i++){
		if(m>a[i]){
			m=a[i];
		}
		if(M<a[i]){
			M=a[i];
		}
	}
	cout<<(M-m);
	return 0;
}
