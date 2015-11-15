#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int n){
	int n_left = m - l + 1;
	int n_right = n - m;
	int i,j,k=l;
	int left[n_left], right[n_right];
	for(i=0;i<n_left;i++){
		left[i] = arr[l+i];
	}
	for(j=0;j<n_right;j++){
		right[j] = arr[m+1+j];
	}
	for(i=0,j=0;i<n_left&&j<n_right;){
		if(left[i]<right[j]){
			arr[k++] = left[i++];
		}
		else
			arr[k++] = right[j++];
	}
	while(i<n_left){
		arr[k++] = left[i++];
	}
	while(j<n_right){
		arr[k++] = right[j++];
	}
}
void mergesort(int arr[],int l, int r){
	if(l<r){
		int m = (l+r)/2;
		cout<<l<<" "<<m<<" "<<r<<endl;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
int main()
{
	int i=0;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array is \n";
 	for (i=0; i < arr_size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    mergesort(arr, 0, arr_size - 1);
 
    cout<<"\nSorted array is \n";
    for (i=0; i < arr_size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}