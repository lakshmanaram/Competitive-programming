#include <bits/stdc++.h>
#define mp make_pair 
#define ll long long 
#define pb push_back
using namespace std;
ll mod = 1000000007;
vector<long long> factorial;
ll findfac(ll a){
    if(factorial.size() > a)
        return factorial[a];
    if(factorial.size() == 0)
        factorial.push_back(1);
    for(ll i = factorial.size(); i <= a;i++)
        factorial.push_back((factorial[i-1]*i)%mod);
    return factorial[a];
}
int main() {
    long n, m;
    cin>>n>>m;
    vector<long long> comp(m+1,0);
    ll curno = 1;
    vector<long> hash(1,m);
    while(n--) {
        map<long long, long long> change;
        long x;
        cin>>x;
        map<long, long> valz;
        while(x--) {
            long y;
            cin>>y;
            if(valz.find(y)!=valz.end())
                valz[y]++;
            else
                valz[y] = 1;
        }
        map<long,long>::iterator mit;
        vector<pair<long, long> > vect;
        for(mit = valz.begin();mit!=valz.end();mit++) {
            vect.pb(mp(mit->second,mit->first));
        }
        sort(vect.begin(),vect.end());
        long cur = vect[0].first;
        for(long i=0;i<vect.size();i++) {
            if(cur == vect[i].first) {
                if(change.find(comp[vect[i].second])==change.end()){
                    change[comp[vect[i].second]] = curno;
                    hash[comp[vect[i].second]]--;
                    hash.push_back(1);
                    comp[vect[i].second] = curno;
                    curno++;
                } else {
                    // cout<<"hash added"<<endl;
                    hash[comp[vect[i].second]]--;
                    hash[change[comp[vect[i].second]]]++;
                    comp[vect[i].second] = change[comp[vect[i].second]];
                }
            } else {
                cur = vect[i].first;
                change.clear();
                change[comp[vect[i].second]] = curno;
                hash[comp[vect[i].second]]--;
                hash.push_back(1);
                comp[vect[i].second] = curno;
                curno++;
            }
        }
    }
    ll ans = 1;
    for(long i=0;i<hash.size();i++){
        ans *= findfac(hash[i]);
        ans %= mod;
    }
    cout<<ans;
    return 0;
}