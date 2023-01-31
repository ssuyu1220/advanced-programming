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
	printf("\n請選擇你想使用的搜尋演算法 1.循序搜尋法 2.二元搜尋法：");
	scanf("%d",&mode);
	if(mode>2 || mode<1){
		printf("你輸入的選擇有誤，請重新輸入！\n");
		system("pause");
	}
	printf("\n你選擇的是循序搜尋法，請輸入欲搜尋的資料（1 ~ 100 )：");
	scanf("%d",&find);
	printf("\n隨機產生的資料群為：");
	srand(time(NULL));
	for(int i=0;i<20;i++){
		nums[i]=1+rand()%100;
		printf(" %d",nums[i]);
	}
	printf("\n\n");
	if(mode==1){
		ans=sequentialsearch(nums,20,find);
		if(ans==-1) printf("隨機產生的資料群中，沒有你搜尋的資料 %d\n",find);
		else printf("在隨機產生的資料群中第 %d 筆資料找到你搜尋的資料 %d\n",ans,find);
	}
	else{
		printf("排序後的資料群為：");
		selectionsort(nums,20);
		for(int j=0;j<20;j++) printf(" %d",nums[j]);
		printf("\n\n");
		ans=binarysearch(nums,20,find);
		if(ans==-1) printf("隨機產生的資料群中，沒有你搜尋的資料 %d\n",find);
		else printf("在排序後的資料群中第 %d 筆資料找到你搜尋的資料 %d\n",ans,find);
	}
	return 0;
}
