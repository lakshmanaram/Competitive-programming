#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main(){
    int q;
    cin>>q;
    long long maxval = 0;
    int maxk = 0;
    vector<long> x(q);
    vector<long> k(q);
    for(int i=0;i<q;i++){
        cin>>x[i]>>k[i];
        if(x[i] > maxval)
            maxval = x[i];
        if(k[i] > maxk)
            maxk = k[i];
    }
    vector<map<long long ,long long> > ans(maxk);
    vector<long long> f;
    f.push_back(1);
    f.push_back(2);
    ans[0][1] = 1;
    ans[0][2] = 1;
    long long temp = 3;
    while(temp<=maxval){
        ans[0][temp] = 1;
        f.push_back(temp);
        temp += f[f.size()-2];
    }
    for(int j=0;j<f.size();j++){
        for(int i=1;i<maxk;i++){
            cout<<"iteration "<<i<<endl;
            map<long long, long long>::iterator it;
            for(it = ans[i-1].begin();it != ans[i-1].end();++it){
                if(it->first + f[j] <= maxval){
                    cout<<it->first<<" "<<f[j]<<" "<<it->second<<" "<<maxval<<endl;
                    if(ans[i].find(it->first + f[j]) != ans[i].end()){
                        ans[i][it->first + f[j]] += it->second;
                        ans[i][it->first + f[j]] %= mod;
                    } else {
                        ans[i][it->first + f[j]] = it->second;
                    }
                } else{
                    break;
                }
            }
        }
        cout<<endl;
    }
    for(int i=0;i<q;i++){
        if(ans[k[i]-1].find(x[i])!=ans[k[i]-1].end()){
            cout<<ans[k[i]-1][x[i]]<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
