#include <bits/stdc++.h>
using namespace std;
long long x;
void reduce(long &n) {
    n -= x;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n,m;
        cin>>n>>m;
        vector<long> temp(m);
        vector<vector<long> > a(n,temp);
        for(long i=0;i<n;i++)
            for(long j=0;j<m;j++)
                cin>>a[i][j];
        for(long i=0;i<n;i++)
            for(long j=0;j<m;j++){
            	long long x;
            	cin>>x;
                a[i][j] -= x;
            }
        long long ans = 0;
        x = ceil((double)accumulate(a[0].begin(),a[0].end(),0)/(double)a[0].size());
        cout<<x<<endl;
        ans += abs(x);
        for_each(a[0].begin(),a[0].end(),reduce);
        vector<long> ttemp(n);
        vector<vector<long> > c(m,ttemp);
        for(long i=0;i<n;i++)
            for(long j=0;j<m;j++)
                c[j][i] = a[i][j];
        for(long i=0;i<m;i++) {
            x = c[i][0];
            for_each(c[i].begin(),c[i].end(),reduce);
            ans += abs(x);
        }
		for(long i=0;i<n;i++)
            for(long j=0;j<m;j++)
                a[i][j] = c[j][i];
        for(long i=1;i<n;i++) {
            x = a[i][0];
            for_each(a[i].begin(),a[i].end(),reduce);
            ans += abs(x);
        }
        bool flag = true;
        for(long i=0;i<a.size();i++)
            for(long j=0;j<a[i].size();j++)
                if(a[i][j] != 0) flag = false;
        if(flag)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
