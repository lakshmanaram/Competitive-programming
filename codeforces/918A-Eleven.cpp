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
	S(n);
	long a = 3;
	long b = 5;
	string s = "OOOo";
	long i = 5;
	while(i <= 1010){
		if(i == b){
			s += "O";
			long c = a;
			a = b;
			b = c+b;
		} else {
			s += "o";
		}
		i++;
	}
	cout<<s.substr(0, n);
	return 0;
}