#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		vector<long> arr(n);
		for(long i=0;i<arr.size();i++){
			if(!(i&1) && i!=arr.size()-1)
				arr[i+1] = i+1;
			else if(i&1){
				arr[i-1] = i+1;
			}
		}
		if(arr.size() == 1)
			arr[0] = 1;
		else if(arr.size()&1){
			arr[arr.size()-1] = arr.size();
			swap(arr[arr.size()-1], arr[arr.size()-2]);
		}
		for(long i=0;i<arr.size();i++) cout<<arr[i]<<" ";
			cout<<endl;
	}
	return 0;
}