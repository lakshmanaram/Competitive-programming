#include <bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		long long minele = -1, minind = 0;
		vector<long long> arr(n);
		for(long i=0;i<n;i++){
			cin>>arr[i];
			if(i!=0){
				if(arr[i]-arr[i-1] == minele)
					minind++;
				else{
					if(minind == 0){
						minind = 1;
						minele = arr[i]-arr[i-1];
					} else 
						minind--;
				}
			}
		}
		if(n <= 3)
			cout<<*min_element(arr.begin(),arr.end())<<endl;
		else {
			long long d = minele;
			bool excuse = false;
			bool flag = true;
			long ansind = -1;
			long i=0;
			for(i=0;i<arr.size()-2;i++) {
				if(arr[i+1] - arr[i] != d){
					if(arr[i+2] - arr[i] == d && !excuse){
						excuse = true;
						ansind = i+1;
						i++;
					} else if(arr[i+2] - arr[i+1] == d && !excuse){
						excuse = true;
						ansind = i;
					} else{
						flag = false;
					}
				}
			}
			if(flag){
				if(excuse){
					if(ansind == arr.size()-2 || arr[i+1] - arr[i] == d){
						cout<<arr[ansind]<<endl;
					} else 
						cout<<-1<<endl;
				} else {
					if(arr[i+1] - arr[i] == d){
						cout<<*min_element(arr.begin(),arr.end())<<endl;
					} else 
						cout<<arr[arr.size()-1]<<endl;
				}
			} else
				cout<<-1<<endl;
		}
	}
}