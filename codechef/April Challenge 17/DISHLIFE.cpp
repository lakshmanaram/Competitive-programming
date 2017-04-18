#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		 long n,k;
		 cin>>n>>k;
		 vector<long> arr(k+1,0);
		 arr[0] = 1;
		 vector<vector<long> > q;
		 while(n--) {
		 	long x;
		 	cin>>x;
		 	vector<long> temp(x);
		 	for(int i=0;i<temp.size();i++){
		 		cin>>temp[i];
		 		arr[temp[i]]++;
		 	}
		 	q.push_back(temp);
		 }
		 bool yes = true;
		 for(int i = 0; i<arr.size();i++) {
		 	if(arr[i] == 0)
		 		yes = false;
		 }
		 if(!yes)
		 	cout<<"sad"<<endl;
		 else {
		 	yes = false;
		 	for(int i=0;i<q.size();i++){
		 		bool possible = true;
		 		for(int j=0;j<q[i].size();j++) {
		 			if(arr[q[i][j]] == 1)
		 				possible = false;
		 		}
		 		if(possible)
		 			yes = true;
		 	}
		 	if(yes)
		 		cout<<"some"<<endl;
		 	else
		 		cout<<"all\n";
		 }
	}
	return 0;
}