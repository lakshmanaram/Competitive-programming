#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> t(101,150);
    t[1] = 0;
    int k,m,n,i,j;
    cin>>k>>m>>n;
    int x,y;
    vector<int> pt;
    vector<int> pf;
    vector<int> vt;
    vector<int> vf;
    for(i=0;i<m;i++){
        cin>>x>>y;
        pf.push_back(x);
        pt.push_back(y);
    }
    for(i=0;i<n;i++){
        cin>>x>>y;
        vf.push_back(x);
        vt.push_back(y);
    }
    bool change = true;
    while (change) {
        change = false;
        for(i=2;i<=100;i++){
            j = i-k;
            if(j<=0)
                j = 1;
            while (j<i) {
                if(min(t[j]+1,t[i])!=t[i]){
                    t[i] = t[j]+1;
                    change = true;
                }
                j++;
            }
        }
        for(i=0;i<pf.size();i++){
            if(t[pt[i]]>t[pf[i]]+1){
                t[pt[i]] = t[pf[i]]+1;
                change = true;
            }
        }
        for(i=0;i<vf.size();i++){
            if(t[vt[i]]>t[vf[i]]+1){
                t[vt[i]] = t[vf[i]]+1;
                change = true;
            }
        }
    }
    cout<<t[100];
    return 0;
}
