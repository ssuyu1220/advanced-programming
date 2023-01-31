#include <iostream>
using namespace std;

int main( ){

	int data[6] = {43,35,12,9,3,99};
	cout << "插入排序法－－" << endl << "原始資料為：" ;
	for (int k = 0 ; k < 6 ; k++)
		cout << " " << data[k];
	cout << endl;
	
	for(int i = 1 ; i < 6 ; i++){
		int temp;
		temp = data[i];
		int j = i;
		while((j > 0) && (temp > data[j-1])){
			data[j] = data[j-1];
			j--;
		}
		if (j != i)
			data[j] = temp;						
		cout << "第 " << i << " 輪排序結果：" ;
		for (int k = 0 ; k < 6 ; k++)
			cout << " " << data[k];
		cout << endl;
	}
	cout << endl;
	return 0;
}
