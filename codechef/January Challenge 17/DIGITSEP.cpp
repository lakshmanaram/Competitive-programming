// dfs template - everything is 0 indexed
#include <bits/stdc++.h>
#define mp make_pair 
#define pb push_back
#define ll long long 
using namespace std;
ll gcd(ll a, ll b) {
    if(a <= 0)
        return b;
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
string s;
int n,m,x,y;
ll maxgcd = 1;
ll get_digit(int start, int no){
    ll ans = 0;
    for(int i=start;i<start+no;i++){
        ans *= 10;
        ans += s[i]-'0';
    }
    return ans;
}
void func(int start, int sep_placed, long long gcdn) {
    // cout<<"start = "<<start<<endl;
    if(start == n) {
        if(sep_placed >= x) {
            maxgcd = max(maxgcd,gcdn);
        }
        return;
    }
    if(sep_placed == y) {
        if(n-start <= m) {
            long long g = get_digit(start,n-start);
            maxgcd = max(maxgcd,gcd(gcdn,g));
        }
        return;
    }
    if((y-sep_placed+1)*m < n-start || (gcdn!=-1 && gcdn <= maxgcd))
        return;
    for(int i=1;i<=m && start + i <= n;i++){
        long long g = get_digit(start,i);
        // cout<<"using "<<i<<" g = "<<g<<endl;
        // cout<<"calling start = "<<start+i<<endl;
        func(start+i,sep_placed+1,gcd(gcdn,g));
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        maxgcd = 1;
        cin>>n>>s>>m>>x>>y;
        func(0,0,-1);
        cout<<maxgcd<<endl;
    }
}