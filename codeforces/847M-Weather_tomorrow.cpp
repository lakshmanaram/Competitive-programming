#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> t(n);
	int diff;
	bool bval = true;
	for(int i=0;i<n;i++){
		cin>>t[i];
		if(i > 1){
			if(t[i] - t[i-1] != diff)
				bval = false;
		} else if(i == 1)
			diff = t[1]-t[0];
	}
	if(bval) cout<<t[n-1]+diff;
	else cout<<t[n-1];
	return 0;
}