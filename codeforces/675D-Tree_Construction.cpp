#include<bits/stdc++.h>
using namespace std;
struct node{
	long long val;
	long left, right;
};
int main()
{
	long n;
	cin>>n;
	vector<node> a(n);
	map<long long,long> key_map;
	// vector<long long> par(n);
	set<long long> arr;
	cin>>a[0].val;
	a[0].right = a[0].left = -1;
	arr.insert(a[0].val);
	key_map[a[0].val] = 0;
	set<long long>::iterator low, high;
	for(long i=1;i<n;i++){
		cin>>a[i].val;
		key_map[a[i].val] = i;
		a[i].right = a[i].left = -1;
		high = arr.upper_bound(a[i].val);
		if(high == arr.begin()){
			// par[i] = *high;
			cout<<*high<<" ";
			a[key_map[*high]].left = i;
		}else{
			low = --high;
			++high;
			if(a[key_map[*low]].right==-1){
				a[key_map[*low]].right = i;
				// par[i] = *low;
				cout<<*low<<" ";
			}else{
				// par[i] = *high;
				cout<<*high<<" ";
				a[key_map[*high]].left = i;
			}
		}
		arr.insert(a[i].val);
	}
	// for(long i=1;i<n;i++){
	// 	cout<<par[i]<<" ";
	// }
	return 0;
}
