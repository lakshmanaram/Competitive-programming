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
		if(p == 1 || p == 2){
			cout<<"impossible\n";
		} else {
			string s = "";
			s += 'a';
			for(int i=0;i<p-2;i++) s += 'b';
			s += 'a';
			for(int i=0;i<n/p;i++)
				cout<<s;
			cout<<endl;		
		}
	}
	return 0;
}