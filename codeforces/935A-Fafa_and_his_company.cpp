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
	set<long> s;
	for(long i=1;i<=sqrt(t);i++) {
		if(t%i == 0){
			s.insert(i);
			s.insert(t/i);
		}
	}
	cout<<s.size()-1<<endl;
	return 0;
}