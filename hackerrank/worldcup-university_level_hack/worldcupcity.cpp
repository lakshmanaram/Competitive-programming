#include <bits/stdc++.h>
using namespace std;
bool vis[100001];
long vval = 0;
struct itnode{
    long parent;
    long pval;
    long value;
    vector<long> children;
    vector<int> cval;
}s[100001];
long indices[100001];
map<string,long long> m;
map<string,long long>::iterator it;
void dfs(long a,long parent,long pval){
    //cout<<"---"<<a<<"--"<<parent<<endl;
    s[a].parent = parent;
    s[a].pval = pval;
    string s1;
    if(a<parent)
        s1 = to_string(a)+" "+to_string(parent);
    else
        s1 = to_string(parent)+" "+to_string(a);
    m[s1] = pval;
    long i=0;
    if(parent!=0){
        vector<long>::iterator it = find(s[a].children.begin(),s[a].children.end(),parent);
        long long temp  = it-s[a].children.begin();
        vector<int>::iterator it1 = temp + s[a].cval.begin() ;
        s[a].children.erase(it);
        s[a].cval.erase(it1);        
    }
    while(i<s[a].children.size())
        {
        long t = s[a].children[i];
        dfs(t,a,s[a].cval[i]);
        i++;
    }
    s[a].value = ++vval;
    indices[vval] = a;
    return;
}
long long dist(long a, long b){
    if(a==b)
        return 0;
    string s1;
    if(a<=b)
        s1 = to_string(a)+" "+to_string(b);
    else
        s1 = to_string(b)+" "+to_string(a);
    it = m.find(s1);
    if(it!=m.end()){
        return it->second;
    }
    long long d=0;
    long av, bv;
    av = s[a].value;
    bv = s[b].value;
    long p;
    if(av<bv){
        long temppar = a;
        long tempv = s[temppar].value;
        while(!(av<=tempv&&bv<=tempv)){
            d += s[temppar].pval;
            temppar = s[temppar].parent;
            tempv = s[temppar].value;
            string s2;
            s2 = to_string(a)+" "+to_string(temppar);
            it = m.find(s2);
            if(it==m.end()){
                it[s2] = d;
            }
        }
        p = temppar;
        temppar = b;
        long k=0;
        tempv = s[temppar].value;
        while(p!=temppar){
            string s2;
            s2 = to_string(temppar)+" "+to_string(p);
            it = m.find(s2);
            if(it!=m.end()){
                d+=it[s2];
                break;
            }
            d += s[temppar].pval;
            k += s[temppar].pval;
            temppar = s[temppar].parent;
            s2 = to_string(b)+" "+to_string(temppar);
            it = m.find(s2);
            if(it!=m.end()){
                it[s2]=k;
            }
        }
    }
    else{
        long temppar = b;
        long tempv = s[temppar].value;
        while(!(av<=tempv&&bv<=tempv)){
            d += s[temppar].pval;
            temppar = s[temppar].parent;
            tempv = s[temppar].value;
            string s2;
            s2 = to_string(b)+" "+to_string(temppar);
            it = m.find(s2);
            if(it==m.end()){
                it[s2] = d;
            }
        }
        p = temppar;
        temppar = a;
        tempv = s[temppar].value;
        while(p!=temppar){
            d += s[temppar].pval;
            temppar = s[temppar].parent;
        }
    }
    m[s1] = d;
    //cout<<a<<"-"<<b<<"-"<<d<<endl;
    return d;
}
int main() {
    long n,t;
    cin>>n>>t;
    long i=0;
    for(;i<n-1;i++){
        long a,b;
        int c;
        cin>>a>>b>>c;
        s[a].children.push_back(b);
        s[b].children.push_back(a);
        s[a].cval.push_back(c);
        s[b].cval.push_back(c);
    }
    dfs(1,0,0);
    while(t--){
        long long ans=0;
        long n1;
        cin>>n1;
        vector<long> query;
        for(i=0;i<n1;i++){
            long temp;
            cin>>temp;
            query.push_back(temp);
        }
        vector<long>::iterator it,it1;
        for(it=query.begin();it<query.end()-1;it++){
            for(it1 = it+1;it1<query.end();it1++)
                ans=0;
                ans += dist(*it,*it1);
        }
        cout<<ans<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
