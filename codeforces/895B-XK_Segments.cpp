#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;
int main()
{
    ll n, x, k;
    cin>>n>>x>>k;
    vector<ll> arr(n);
    for(long i=0;i<n;i++) cin>>arr[i];
    map<ll, ll> m;
    set<ll> sarr;
    for(long i=0;i<n;i++){
        sarr.insert(arr[i]);
        if(m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else m[arr[i]] = 1;
    }
    map<ll, ll>::iterator mit = m.begin();
    map<ll, ll>::iterator temp = m.begin();
    mit++;
    ll last_val = temp->second;
    while(mit != m.end()) {
        // cout<<temp->second<<" ";
        mit->second += temp->second;
        last_val = mit->second;
        mit++;
        temp++;
    }
    // cout<<temp->second<<endl;
    ll initial = 0;
    ll ans = 0;
    for(mit = m.begin(); mit!= m.end();mit++) {
        ll val = mit->first;
        ll nos = mit->second - initial;
        ll times = (val-1) / x;
        times += k;
        times++;
        ll second_val = times*x;
        set<ll>::iterator sit = sarr.lower_bound(second_val);
        ll count_sec_val;
        if(sit == sarr.end()) count_sec_val = last_val;
        else if(sit == sarr.begin()) count_sec_val = 0;
        else {
            sit--;
            count_sec_val = m[*sit];
        }
        times--;
        second_val = times*x;
        sit = sarr.lower_bound(second_val);
        if(sit == sarr.end()) count_sec_val -= max(last_val, initial);
        else if(sit == sarr.begin()) count_sec_val -= max((ll)0, initial);
        else {
            sit--;
            count_sec_val -= max(m[*sit], initial);
        }
        ans += count_sec_val*nos;
        initial = mit->second;
    }
    cout<<ans<<endl;

    return 0;
}