#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		long p, n;
		cin>>n>>p;
		int val = 0;
		string s = "";
		if(p == 1){
			val = n;
			for(int i=0;i<n;i++) s += 'a';
		} else if (p > 2){
			val = 1;
			char x = 'a';
			for(int i=0;i<n;i++){
				s += x;
				x++;
				if(x == 'd') x = 'a';
			}
		} else {
			switch(n){
				case 1: s = "b";val = 1;
				break;
				case 2: s = "ab";val = 1;
				break;
				case 3: s = "abb";val = 2;
				break;
				case 4: s = "aabb";val = 2;
				break;
				case 5: s = "ababb";val = 3;
				break;
				case 6: s = "aababb";val = 3;
				break;
				case 7: s = "aababbb";val = 3;
				break;
				case 8: s = "aaababbb";val = 3;
				break;
				default:
				string x = "babbaa";
				long rem = n;
				while(rem != 0){
					if(rem >= 6){
						s += x;
						rem -= 6;
					} else {
						s += x.substr(0,rem);
						break;
					}
				}
				val = 4;
			}
		}
		cout<<val<<" "<<s;
		printf("\n");
	}
	return 0;
}