#include <iostream>
using namespace std;

int main( ){	

	int data[6] = {43,35,12,9,3,99};

	cout << "選擇排序法－－" << endl << "原始資料為：" ;
	for (int k = 0 ; k < 6 ; k++)
		cout << " " << data[k];
	cout << endl;
	
	for(int i = 0 ; i < 5 ; i++){
		
		int pos = i;
		for(int j = i+1 ; j < 6 ; j++){
			
			if (data[pos] < data[j])
				pos = j;			
		}
		int temp;
		temp = data[i];
		data[i] = data[pos];
		data[pos] = temp;
	
		cout << "第 " << i+1 << " 輪排序結果：" ;
		for (int k = 0 ; k < 6 ; k++)
			cout << " " << data[k];
		cout << endl;
	}
	cout << endl;
	return 0;
}

