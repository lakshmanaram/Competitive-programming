#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
struct query {
    long l,r;
    long long k;
    long ind;
};
long sn;
bool q_comp(query a, query b) {
    if(a.l/sn < b.l/sn) return true;
    else if(a.l/sn == b.l/sn)
        if(a.r < b.r) return true;
    return false;
}
bool q_back(query a, query b) {
    if(a.ind < b.ind) return true;
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        long n,q;
        scanf("%ld %ld",&n,&q);
        sn = sqrt(n);
        vector<ll> arr(n);
        for(long i=0;i<n;i++) cin>>arr[i];
        vector<query> qs(q);
        for(long i=0;i<q;i++) {
            scanf("%ld %ld %lld", &qs[i].l, &qs[i].r, &qs[i].k);
            qs[i].l--;
            qs[i].ind = i;
        }
        sort(qs.begin(),qs.end(),q_comp);
        vector<long> ans(q);
        long f = 0;
        long s = 0;
        vector<long> order(n+1,0);
        deque<pair<ll, long> > dp;
        for(long qi=0;qi<q;qi++) {
            query x = qs[qi];
            while(f > x.l) {
                f--;
                if(dp.size() == 0 || dp[0].first != arr[f]) 
                    dp.push_front(mp(arr[f],1));
                else
                    dp[0].second++;
                order[dp[0].second]++;
            }
            while(s < x.r) {
                long siz = dp.size()-1;
                if(dp.size() == 0 || dp[siz].first != arr[s]) {
                    dp.push_back(mp(arr[s],1));
                    siz++;
                }
                else
                    dp[siz].second++;
                order[dp[siz].second]++;
                s++;
            }
            while(f < x.l) {
                order[dp[0].second]--;
                if(dp[0].second == 1)
                    dp.pop_front();
                else
                    dp[0].second--;
                f++;
            }
            while(s > x.r) {
                s--;
                long siz = dp.size()-1;
                order[dp[siz].second]--;
                if(dp[siz].second == 1)
                    dp.pop_back();
                else
                    dp[siz].second--;
            }
            ans[qs[qi].ind] = order[x.k];
        }
        for(long i=0;i<q;i++) {
            printf("%ld\n",ans[i]);
        }
    }
    return 0;
}
