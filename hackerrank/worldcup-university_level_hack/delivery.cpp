#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    vector<long> children;
}ns[100001];
bool vis[100001];
vector<long> tovis;
vector<long> tv;
vector<long> doin;

bool funcd(long a){
    //cout<<"**"<<a<<"**";
    if(vis[a]==true){
        if(tv.empty()){
            sort(tovis.begin(),tovis.end());
            vector<long>::iterator it = tovis.begin();
            while(it!=tovis.end()){
                cout<<*it<<" ";
                it++;
            }
            cout<<endl;
            vis[a] = false;
            return true;
        }
        vis[a]=false;
        return false;
    }
    vis[a]=true;
    vector<long>::iterator it1 = find(tv.begin(),tv.end(),a);
    vector<long>::iterator ittemp = it1;
    if(it1!=tv.end()){
        doin.push_back(a);
        tv.erase(it1);
    }
    bool d=false;
    if(ns[a].children.empty()){
        if(tv.empty()){
            vector<long>::iterator it = doin.begin();
            while(it!=doin.end()){
                cout<<*it<<" ";
                it++;
            }
            cout<<endl;
            vis[a] = false;
            return true;
        }
        vis[a]=false;
        if(ittemp!=tv.end()){
            doin.pop_back();
            tv.insert(ittemp,a);
        }
        return false;
    }
    else{
        for(it1=ns[a].children.begin();it1!=ns[a].children.end();it1++){
            d = funcd(*it1);
            if(d==true){
                vis[a]=false;
                return true;   
            }
        }
    }
    vis[a]=false;
    if(ittemp!=tv.end()){
        doin.pop_back();
        tv.insert(ittemp,a);
    }
    return false;
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        tovis.clear();
        long m,n,k,i=0,temp;
        cin>>n>>m>>k;
        fill(vis,vis+n+1,false);
        for(;i<k;i++){
            cin>>temp;
            tovis.push_back(temp);
        }
        long x,y;
        for(i=1;i<=n;i++){
            ns[i].children.clear();
        }
        for(i=0;i<m;i++){
            cin>>x>>y;
            if(x!=y)
                ns[x].children.push_back(y);
        }
        for(i=1;i<=n;i++){
            doin.clear();
            tv=tovis;
            if(funcd(i))
                break;
        }
        if(i==n+1)
            cout<<"-1"<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
