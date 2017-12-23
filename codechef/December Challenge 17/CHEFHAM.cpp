#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long n;
		scanf("%ld",&n);
		vector<long> arr(n);
		for(long i=0;i<arr.size();i++){
			scanf("%ld",&arr[i]);
		}
		map<long, long> m;
		for(long i=0;i<arr.size();i++){
			m[arr[i]]++;
		}
		vector<long> even, odd;
		map<long, long> e,o;
		map<long, long>::iterator mit = m.begin();
		while(mit != m.end()){
			if(mit->second == 2) even.pb(mit->first);
			else odd.pb(mit->first);
			mit++;
		}
		if(even.size() > 0){
			long temp = even[even.size()-1];
			for(long i=0;i<even.size();i++){
				e[even[i]] = temp;
				temp = even[i];
			}
		}
		if(odd.size() > 0){
			long temp = odd[odd.size()-1];
			for(long i=0;i<odd.size();i++){
				o[odd[i]] = temp;
				temp = odd[i];
			}
		}
		if(odd.size() == 1 && even.size() == 1){
			if(arr[0] != arr[1]) swap(arr[0],arr[1]);
			else swap(arr[0],arr[2]);
			printf("2\n");
		} else if (even.size() == 1 && odd.size() == 0 || even.size() == 0 && odd.size() == 1) {
			printf("0\n");
		} else if (even.size()==1){
			vector<long> temp, temp1;
			for(long i=0;i<arr.size();i++){
				if(even[0] == arr[i]){
					temp.pb(i);
					continue;
				} else 
					temp1.pb(i);
				arr[i] = o[arr[i]];
			}
			swap(arr[temp[0]],arr[temp1[0]]);
			swap(arr[temp[1]],arr[temp1[1]]);
			printf("%ld\n", arr.size());
		} else if(odd.size() == 1){
			vector<long> temp;
			for(long i=0;i<arr.size();i++){
				if(odd[0] == arr[i]){
					temp.pb(i);
					continue;
				}
				arr[i] = e[arr[i]];
			}
			long i=0;
			if(i == temp[0]) i++;
			swap(arr[temp[i]], arr[i]);
			printf("%ld\n", arr.size());
		} else {
			for(long i=0;i<arr.size();i++){
				if(e.find(arr[i]) != e.end())
					arr[i] = e[arr[i]];
				else 
					arr[i] = o[arr[i]];
			}
			printf("%ld\n", arr.size());
		}
		for(long i=0;i<arr.size();i++) printf("%ld ",arr[i]);
		printf("\n");
	}
	return 0;
}