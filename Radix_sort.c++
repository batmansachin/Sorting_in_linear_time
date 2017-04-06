#include <bits/stdc++.h>

using namespace std;

int find_max(int arr[],int n){
	int p = 0;
	for(int i=0;i<n;i++)
		p = max(p,arr[i]);
	return p;
}
void print(int arr[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
void count_sort(int arr[],int n,int exp){
	int output[n];
	int i,count[10] = {0};
	for(i=0;i<n;i++){
		count[(arr[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
		count[i] += count[i-1];
	for(i = n-1;i>=0;i--){
		output[count[(arr[i]/exp)%10]-1]=arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
		arr[i] = output[i];
}

void radixsort(int arr[],int n){
	int max_val = find_max(arr,n);
	for(int i =  1;max_val/i > 0 ; i *=10){
		count_sort(arr,n,i);
	}
}

int main(void){

	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    

	return 0;
}