#include <iostream>
using namespace std;

int main( ){

	int data[6] = {43,35,12,9,3,99};
	cout << "��w�ƧǪk�С�" << endl << "��l��Ƭ��G" ;
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
		cout << "�� " << 5-i+1 << " ���Ƨǵ��G�G" ;
		for (int k = 0 ; k < 6 ; k++)
			cout << " " << data[k];
		cout << endl;
	}
	cout << endl;
	return 0;
}

