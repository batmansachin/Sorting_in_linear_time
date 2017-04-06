#include <bits/stdc++.h>

using namespace std;

void count_sort(int arr[],int k){
		int c[k+5];

		int n = 9;
		int output[n];
		memset(c,0,sizeof(c));
		for(int i = 0;i<n;i++){
			c[arr[i]]++;
		}
		for(int i=1;i<=k;i++)
			c[i] += c[i-1];
		for(int i=0;i<n;i++){
			output[c[arr[i]]-1] = arr[i];
		}
		for(int i=0;i<n;i++){
			printf("%d ",output[i]);
		}
		printf("\n");
}

int main(void){
	int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 0;
    for(int i=0;i<n;i++){
    	k = max(k,arr[i]);
    }
    count_sort(arr, k+1);
    
    return 0;
}