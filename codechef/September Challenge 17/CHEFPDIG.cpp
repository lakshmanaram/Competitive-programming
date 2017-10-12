#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string nos;
		cin>>nos;
		vector<long> arr(10,0);
		for(long i=0;i<nos.size();i++){
			arr[nos[i]-'0']++;
		}
		string ans ="";
		char a = 'A';
		for(long i = 65; a <= 'Z'; a++, i++){
			int x = i/10;
			int y = i%10;
			if(arr[x] >= 1){
				arr[x]--;
				if(arr[y] >= 1){
					ans += a;
				}
				arr[x]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}