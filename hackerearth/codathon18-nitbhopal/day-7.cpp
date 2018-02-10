#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<ll, ll>,
null_type,
less<pair<ll, ll> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct comp
{
    bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const
    {
        if(a.first < b.first) return true;
        if(a.first > b.first) return false;
        if(a.second < b.second) return false;
        if(a.second > b.second) return true;
        return false;
    }
};


set<pair<ll, ll>, comp> mos;

int main() {
    long q;
    scanf("%ld", &q);
    map<ll, ll> mc;
    double mean = 0;
    ordered_set os;
    while(q--) {
            // for(auto it = mos.begin(); it != mos.end(); it++){
            //     cout<<it->first<<" "<<it->second<<endl;
            // }
        
        string s;
        cin>>s;
        if(s == "Insert") {
            ll x;
            scanf("%lld", &x);
            mean += x;
            if(mc.find(x) == mc.end()){
                mc[x] = 1;
            } else {
                mos.erase(mp(mc[x], x));
                mc[x]++;
            }
            mos.insert(mp(mc[x], x));
            os.insert(mp(x, mc[x]));
        } else if(s == "Delete") {
            ll x;
            scanf("%lld", &x);
            mean -= x;
            // for (auto it = mos.begin(); it != mos.end(); it++){
            //     cout<<it->first<<" "<<it->second<<endl;
            // }
            // cout<<" = = =  = =  == = = == = = = \n";
            mos.erase(mp(mc[x], x));
            os.erase(mp(x, mc[x]));
            mc[x]--;
            mos.insert(mp(mc[x], x));
            // for (auto it = mos.begin(); it != mos.end(); it++){
            //     cout<<it->first<<" "<<it->second<<endl;
            // }
        } else if(s == "Mode") {
            // cout<<"Mode\n";
            auto it = mos.end();
            it--;
            printf("%lld\n", it->second);
        } else if(s == "Mean") {
            // cout<<"Mean\n";
            double temp = mean;
            temp /= os.size();
            printf("%lld\n", (ll)floor(temp));
        } else if(s == "Median") {
            // cout<<"Median\n";
            double median;
            if(os.size()%2 == 0){
                median = os.find_by_order(os.size()/2)->first;
                median += os.find_by_order((os.size()/2)-1)->first;
                median /= 2;
            } else {
                median = os.find_by_order(os.size()/2)->first;
            }
            printf("%lld\n", (ll)floor(median));
        }
    }
    return 0;
}