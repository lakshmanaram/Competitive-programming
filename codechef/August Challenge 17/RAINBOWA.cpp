#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		bool flag = true;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<int> ab = arr;
		reverse(ab.begin(),ab.end());
		for(int i=0;i<ab.size();i++){
			if(ab[i] != arr[i])
				flag = false;
		}
		int val = 1;
		bool start = true;
		for(int i=0;i<arr.size();i++){
			if(start){
				if(arr[i] == val) continue;
				else if(arr[i] == val+1)
					val++;
				else
					flag = false;
				if(val == 7) start = false;
			} else {
				if(arr[i] == val) continue;
				else if(arr[i] == val-1) {
					val--;
					continue;
				} else
					flag = false;
			}
		}
		if(start) flag = false;
		if(flag) cout<<"yes\n";
		else cout<<"no\n";
	}
}