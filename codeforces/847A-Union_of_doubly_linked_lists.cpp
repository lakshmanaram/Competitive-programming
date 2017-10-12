#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> starts;
	vector<int> left(n+1), right(n+1);
	for(int i=1;i<=n;i++){
		cin>>left[i]>>right[i];
		if(left[i] == 0) starts.pb(i);
	}
	vector<vector<int> > lists;
	for(int i=0;i<starts.size();i++){
		vector<int> slist;
		slist.pb(starts[i]);
		int val = starts[i];
		while(right[val] != 0){
			val = right[val];
			slist.pb(val);
		}
		lists.pb(slist);
	}
	for(int i=0;i<lists.size()-1;i++){
		right[lists[i][lists[i].size()-1]] = lists[i+1][0];
		left[lists[i+1][0]] = lists[i][lists[i].size()-1];
	}
	for(int i=1;i<n+1;i++) cout<<left[i]<<" "<<right[i]<<endl;
	return 0;
}