#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	string s;
	cin>>s;
	long ans = 0;
	for(long i=0;i<s.size();i++){
		ll noq, no, nc, mnoq, ano;
		noq = no = nc = mnoq = ano = 0;
		for(long j=i;j<s.size();j++){
			if(s[j] == '('){
				no++;
				ano++;
			} else if(s[j] == ')') { 
				nc++;
				ano--;
			} else {
				noq++;
				ano--;
				if(ano > mnoq)
					mnoq++;
			}
			if(ano < 0) ano = 0; 
			if(nc > no + noq) break;
			if(nc > no){
				noq -= nc-no;
				no = nc;
				if(mnoq > noq) mnoq = noq;
			}
			if(nc == no){
				if(noq%2 == 0){
					ans++;
				}
			} else if (no > nc){
				if(ano == 0 && (j-i+1)%2 ==0){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}