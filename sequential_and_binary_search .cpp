#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdlib.h> 
using namespace std;

void selectionsort (int data[],int n){

	for(int i = 0 ; i < n-1 ; i++){
		
		int pos = i;
		for(int j = i+1 ; j < n ; j++){
			
			if (data[pos] > data[j])
				pos = j;			
		}
		int temp;
		temp = data[i];
		data[i] = data[pos];
		data[pos] = temp;
	}
}

int binarysearch (int data[], int n, int key){

	int low = 0, high = n-1;
	
	while (low <= high) {
		
		int mid = (low + high)	/ 2;
		if (data[mid] == key)
			return mid+1;
		else if (data[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return (-1);
}


int sequentialsearch (int data[], int n, int key){

	int i;
	
	for (i = 0; i < n; i++){
		
		if (data[i] == key)
			return i+1;
    }
	
	return (-1);
}

int main(){
	int mode,find,ans;
	int nums[20];
	printf("\n�п�ܧA�Q�ϥΪ��j�M�t��k 1.�`�Ƿj�M�k 2.�G���j�M�k�G");
	scanf("%d",&mode);
	if(mode>2 || mode<1){
		printf("�A��J����ܦ��~�A�Э��s��J�I\n");
		system("pause");
	}
	printf("\n�A��ܪ��O�`�Ƿj�M�k�A�п�J���j�M����ơ]1 ~ 100 )�G");
	scanf("%d",&find);
	printf("\n�H�����ͪ���Ƹs���G");
	srand(time(NULL));
	for(int i=0;i<20;i++){
		nums[i]=1+rand()%100;
		printf(" %d",nums[i]);
	}
	printf("\n\n");
	if(mode==1){
		ans=sequentialsearch(nums,20,find);
		if(ans==-1) printf("�H�����ͪ���Ƹs���A�S���A�j�M����� %d\n",find);
		else printf("�b�H�����ͪ���Ƹs���� %d ����Ƨ��A�j�M����� %d\n",ans,find);
	}
	else{
		printf("�Ƨǫ᪺��Ƹs���G");
		selectionsort(nums,20);
		for(int j=0;j<20;j++) printf(" %d",nums[j]);
		printf("\n\n");
		ans=binarysearch(nums,20,find);
		if(ans==-1) printf("�H�����ͪ���Ƹs���A�S���A�j�M����� %d\n",find);
		else printf("�b�Ƨǫ᪺��Ƹs���� %d ����Ƨ��A�j�M����� %d\n",ans,find);
	}
	return 0;
}
