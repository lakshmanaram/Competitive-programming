#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long n;
	cin>>n;
	while(n--){
		long a = 0;
		long x = 0;
		for(long i=0;i<5;i++){
			cin>>x;
			a += x;
		}
		if(a < 1) cout<<"Beginner";
		else if(a<2) cout<<"Junior Developer";
		else if(a < 3) cout<<"Middle Developer";
		else if(a < 4) cout<<"Senior Developer";
		else if(a < 5) cout<<"Hacker";
		else cout<<"Jeff Dean";
		cout<<endl;
	}
	return 0;
}