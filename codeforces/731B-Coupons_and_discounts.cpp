#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bool carry = false, flag = true;
	for(int i=0;i<n;i++){
		if(carry) {
			if(arr[i] > 0) {
				if(arr[i]%2 != 0)
					carry = false;
			} else {
				flag = false;
				break;
			}
		}
		else if(arr[i]%2!=0)
			carry = true;

	}
	if(flag && !carry)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}