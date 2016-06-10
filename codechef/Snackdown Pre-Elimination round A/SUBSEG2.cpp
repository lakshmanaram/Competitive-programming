#include "bits/stdc++.h"
using namespace std;
struct node{
    vector<set<long> > before;
    long val;
};
int main(){
    long n,q;
    cin>>n>>q;
    vector<pair<long,long> > inps;
    long rangemax = 0;
    for(long i=0;i<n;i++){
        long a,b;
        cin>>a>>b;
        rangemax = max(rangemax,b);
        inps.push_back(make_pair(a,b));
    }
    sort(inps.begin(),inps.end());
    node initial;
    initial.val = 0;
    vector<node> precomps(rangemax+1,initial);
    vector<set<long> > maxbefore;
    long maxval = 0;
    long inp_ptr = 0;
    for(long i=1;i<=rangemax;i++){
        vector<set<long> > temp = maxbefore;
        if(temp.size()==0){
            set<long> t;
            temp.push_back(t);
        }
        while(inp_ptr<inps.size() && inps[inp_ptr].first==i){
            if(precomps[inps[inp_ptr].second].val < maxval+1){
                precomps[inps[inp_ptr].second].val = maxval+1;
                precomps[inps[inp_ptr].second].before = temp;
            }else if(precomps[inps[inp_ptr].second].val == maxval+1){
                for(long mp=0;mp<temp.size();mp++){
                    precomps[inps[inp_ptr].second].before.push_back(temp[mp]);
                }
            }
            inp_ptr++;
        }
        if(precomps[i].val>maxval){
            maxval = precomps[i].val;
            temp = precomps[i].before;
            for(long mp=0;mp<temp.size();mp++){
                temp[mp].insert(i);
            }
            precomps[i].before = temp;
            maxbefore = temp;
        }else if(precomps[i].val == maxval){
            temp = precomps[i].before;
            for(long mp=0;mp<temp.size();mp++){
                temp[mp].insert(i);
                maxbefore.push_back(temp[mp]);
            }
            precomps[i].before = maxbefore;
        }else{
            precomps[i].before = maxbefore;
            precomps[i].val = maxval;
        }
    }
    // for(long i=0;i<=rangemax;i++){
    //     cout<<i<<endl;
    //     cout<<"val = "<<precomps[i].val<<endl;
    //     cout<<"before = "<<endl;
    //     for(long j = 0; j< precomps[i].before.size();j++){
    //         for(set<long>::iterator k = precomps[i].before[j].begin(); k!= precomps[i].before[j].end();k++){
    //             cout<<*k<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<" ------- ----- ----- "<<endl;
    // }
    for(long j=0;j<q;j++){
        long a,b;
        cin>>a>>b;
        if(a>rangemax){
            cout<<0<<endl;
            continue;
        }
        a = min(a,rangemax);
        b = min(b,rangemax);
        vector<set<long> > temp = precomps[b].before;
        set<long>::iterator itup;
        long tempans = precomps[b].val;
        long ans = 0;
        for(long i=0;i<temp.size();i++){
            itup = temp[i].upper_bound(a-1);
            long val = distance(temp[i].begin(),itup);
            if(itup == temp[i].end())
                continue;
            if(itup == temp[i].begin()){
                ans = max(ans,tempans);
                continue;
            }
            itup--;
            ans = max(ans, tempans-precomps[*itup].val);
        }
        cout<<ans<<endl;
    }
    return 0;
}
