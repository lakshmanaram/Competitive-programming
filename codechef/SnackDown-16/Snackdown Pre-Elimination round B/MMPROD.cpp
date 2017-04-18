#include <bits/stdc++.h>
using namespace std;
int main(){
    long t;
    cin>>t;
    long long mod = 1000000007;
    while(t--){
        long long n,k,zer = 0;
        cin>>n>>k;
        vector<long long> pos,neg;
        for(long long i = 0;i<n;i++){
            long long x;
            cin>>x;
            if(x>0)
                pos.push_back(x);
            else if(x<0)
                neg.push_back(x);
            else
                zer++;
        }
        if(pos.size()+neg.size()<k)
            cout<<0<<endl;
        else if(pos.size()==0){
            if(k%2!=0 && zer>0)
                cout<<0<<endl;
            else{
                long long p=1;
                sort(neg.begin(),neg.end());
                if(k%2!=0)
                    reverse(neg.begin(),neg.end());
                for(long long i=0;i<k;i++){
                    p *= neg[i];
                    p %= mod; if(p<0) p += mod;
                }
                cout<<p<<endl;
            }
        }
        else if(pos.size()+neg.size()==k){
            if(neg.size()%2!=0 && zer > 0)
                cout<<0<<endl;
            else{
                long long p = 1;
                for(long i = 0;i <pos.size();i++){
                    p *= pos[i];
                    p %= mod; if(p<0) p += mod;
                }
                for(long i = 0;i <neg.size();i++){
                    p *= neg[i];
                    p %= mod; if(p<0) p += mod;
                }
                cout<<p<<endl;
            }
        }
        else{
            sort(pos.begin(),pos.end());
            sort(neg.begin(),neg.end());
            long long p = 1;
            long long posp = pos.size()-1, negp = 0;
            while(k!=0){
                if(negp == neg.size()-1)
                    negp = neg.size();
                if(k==1){
                    if(posp >= 0){
                        p *= pos[posp];
                        posp--;
                    }
                    k--;
                } else if(negp >= neg.size() && posp >= 0){
                    p *= pos[posp];
                    posp--;
                    k--;
                } else if(posp<0 && negp < neg.size()) {
                    p *= neg[negp];
                    p %= mod; if(p<0) p += mod;
                    negp++;
                    p *= neg[negp];
                    negp++;
                    k -= 2;
                } else if(posp == 0 && negp < neg.size()){
                    p *= neg[negp];
                    p %= mod; if(p<0) p += mod;
                    negp++;
                    p *= neg[negp];
                    negp++;
                    k -= 2;
                } else if( posp > 0 && negp < neg.size()){
                    if(pos[posp]*pos[posp-1] > neg[negp]*neg[negp+1]){
                        p *= pos[posp];
                        posp--;
                        k--;
                    } else {
                        p *= neg[negp];
                        p %= mod; if(p<0) p += mod;
                        negp++;
                        p *= neg[negp];
                        negp++;
                        k -= 2;
                    }
                }
                p %= mod; if(p<0) p += mod;
            }
            cout<<p<<endl;
        }
    }
    return 0;
}
