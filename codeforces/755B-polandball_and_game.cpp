#include <bits/stdc++.h>
using namespace std;
int main() {
	long n,m;
	cin>>n>>m;
    long a, b, c;
    set<string> x;
    while(n--){
        string t;
        cin>>t;
        x.insert(t);
    }
    a = 0, b = 0, c = 0;
    while(m--) {
        string t;
        cin>>t;
        if (x.find(t) == x.end())
            b++;
        else
            c++;
    }
    a = x.size()-c;
    if(a>b)
        cout<<"YES";
    else if(a<b)
        cout<<"NO";
    else {
        if(c&1)
            cout<<"YES";
        else
            cout<<"NO";
    }
	return 0;
}