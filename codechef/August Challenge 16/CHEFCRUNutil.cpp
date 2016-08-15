#include <bits/stdc++.h>
using namespace std;
long long utilfunc(vector<long long> arr){
	bool sign;
	vector<long long> tarr;
	if(arr.size()!=0){
		long long val = arr[0];
		if(val >= 0)
			sign = true;
		else
			sign = false;
		for(long i=1;i<arr.size();i++){
			if(arr[i]==0)
				continue;
			else if(arr[i]>0){
				if(sign)
					val += arr[i];
				else{
					tarr.push_back(val);
					cout<<val<<" ";
					val = arr[i];
					sign = true;
				}
			} else {
				if(sign){
					tarr.push_back(val);
					cout<<val<<" ";
					val = arr[i];
					sign = false;
				} else {
					val += arr[i];
				}
			}
		}
		tarr.push_back(val);
		cout<<val<<" "<<endl;
	}
	long long ans = 0;
	if(tarr.size()!=0) {
		long index = distance(tarr.begin(),max_element(tarr.begin(),tarr.end()));
		if(tarr[index] <= 0){
			ans += 2*accumulate(tarr.begin(),tarr.end(),0);
		} else {
			vector<bool> abool(tarr.size(),true);
			abool[index] = false;
			long long tempans = 0;
			long pos = index;
			for(long i = index+1; i<tarr.size();i++){
				tempans += tarr[i];
				if(tempans > 0){
					tempans = 0;
					pos = i;
				}
			}
			for(long i = pos+1; i<tarr.size();i++)
				ans += tarr[i]+tarr[i];
			tempans = 0;
			pos = index;
			for(long i = index-1; i>=0;i--){
				tempans += tarr[i];
				if(tempans > 0){
					tempans = 0;
					pos = i;
				}
			}
			for(long i = pos-1; i>=0;i--)
				ans += tarr[i]*2;
		}
	}
	return ans;
}
int main(){
	vector<long long> arr;
	arr.push_back(-5);
	arr.push_back(1000);
	arr.push_back(-500);
	arr.push_back(70);
	arr.push_back(700);
	arr.push_back(70);
	arr.push_back(-40);
	arr.push_back(30);
	cout<<endl<<utilfunc(arr)<<endl;
	return 0;
}