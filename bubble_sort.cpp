#include <iostream>
using namespace std;

int main( ){

	int data[6] = {43,35,12,9,3,99};
	cout << "氣泡排序法－－" << endl << "原始資料為：" ;
	for (int k = 0 ; k < 6 ; k++)
		cout << " " << data[k];
	cout << endl;
	
	for(int i = 5 ; i > 0 ; i--){
		for(int j = 0 ; j < i ; j++){
			if (data[j] < data[j+1]){
				int temp;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}							
		}
		cout << "第 " << 5-i+1 << " 輪排序結果：" ;
		for (int k = 0 ; k < 6 ; k++)
			cout << " " << data[k];
		cout << endl;
	}
	cout << endl;
	return 0;
}

