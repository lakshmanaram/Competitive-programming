// dfs template - everything is 0 indexed
#include <bits/stdc++.h>
#define mp make_pair 
#define pb push_back
#define ll long long 
#define sll set<ll> 
using namespace std;
ll gcd(ll a, ll b) {
    if(a == 0 && b == 0)
        return 0;
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
string s;
int n,m,x,y;
ll get_digit(int start, int no){
    ll ans = 0;
    for(int i=start;i<start+no;i++){
        ans *= 10;
        ans += s[i]-'0';
    }
    return ans;
}
sll none;
vector<vector<sll > > ans;
void func(int start, int sep_placed, sll &maxgcd, int seps) {
    if(sep_placed == seps) {
        if(n-start <= m) {
            long long g = get_digit(start,n-start);
            maxgcd.insert(g);
        }
        return;
    }
    if((seps-sep_placed+1)*m < n-start)
        return;
    for(int i=1;i<=m && start + i < n;i++){
        long long g = get_digit(start,i);
        sll tempgcd = ans[start+i][seps-sep_placed-1];
        for(sll::iterator it = tempgcd.begin();it!=tempgcd.end();it++){
            maxgcd.insert(gcd(g,*it));
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ans.clear();
        cin>>n>>s>>m>>x>>y;
        vector<sll > temp(y+1);
        ans.resize(n,temp);
        for(int i=n-1;i>=0;i--) {
            for(int j = 0;j<=y;j++) {
                sll maxgcd;
                func(i,0,maxgcd,j);
                ans[i][j] = maxgcd;
            }
        }
        ll ans_final = 0;
        for(int i=x;i<=y;i++) {
            sll maxgcd = ans[0][i];
            if(maxgcd.size()!=0){
                sll::iterator it = maxgcd.end();
                it--;    
                if(*it > ans_final)
                    ans_final = *it;
            }
        }
        cout<<ans_final<<endl;
    }
}