#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n,k;
        long long m;
        int e;
        cin>>n>>k>>e>>m;
        vector<long long> marks;
        for(long i=1;i<n;i++){
            long long ans = 0;
            for(long j =0; j<e;j++){
                long long x;
                cin>>x;
                ans += x;
            }
            marks.push_back(ans);
        }
        long long ans = 0;
        for(long j =1; j<e;j++){
            long long x;
            cin>>x;
            ans += x;
        }
        sort(marks.begin(),marks.end());
        reverse(marks.begin(),marks.end());
        ans = marks[k-1] - ans + 1;
        if(ans < 0) ans = 0;
        if(ans > m)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
