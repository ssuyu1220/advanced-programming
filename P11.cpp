#include <iostream>
using namespace std;

int main( ){	

	int data[6] = {43,35,12,9,3,99};

	cout << "���J�ƧǪk�С�" << endl << "��l��Ƭ��G" ;
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
			
		cout << "�� " << i << " ���Ƨǵ��G�G" ;
		for (int k = 0 ; k < 6 ; k++)
			cout << " " << data[k];
		cout << endl;
	}
	cout << endl;
	return 0;
}
