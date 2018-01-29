#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	string yes = "YES", no = "NO";
	while(t--) {
		ll k, d0, d1;
		scanf("%lld %lld %lld", &k, &d0, &d1);
		k -= 2;
		long start = -1;
		long long valsum = d0 + d1;
		ll sumd = (d0+d1)%10;
		if(sumd == 0 || sumd == 5){
			cout<<no<<endl;
			continue;
		}
		while(k > 0 && start == -1){
			if(sumd == 2){
				start = 1;
				break;
			}
			valsum += sumd;
			k--;
			sumd = (sumd*2)%10;
		}
		if(k > 0){
			valsum += (k/4)*2;
			switch(k%4){
				case 1:
				valsum += 2;
				break;
				case 2:
				valsum += 6;
				break;
				case 3:
				valsum += 14;
				break;
			}
		}
		if(valsum %3 ==0) cout<<yes<<endl;
		else cout<<no<<endl;
	}
	return 0;
}		