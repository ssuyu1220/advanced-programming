#include<iostream>
using namespace std;
int main(){
	int f[30]={1,1};
	int n,sum=0;
	cin>>n;
	for(int i=2;i<30;i++){
		f[i]=f[i-2]+f[i-1];
	}
	for(int i=0;i<n;i++){
		sum+=f[i];
	}
	cout<<sum;
		
	return 0;
}
