#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        long long zera = 0,zerb = 0;
        for(long i=0;i<a.size();i++){
            if(a[i]=='0')
                zera++;
            if(b[i]=='0')
                zerb++;
        }
        long long ans = abs(zera-zerb);
        if((zera==0||zera==a.size()) && ans!=0)
            cout<<"Unlucky Chef"<<endl;
        else{
            if(zera>zerb){
                long i=0;
                while(i<a.size() && zera!=zerb){
                    if(a[i]=='0' && b[i]=='1'){
                        a[i] = '1';
                        zera--;
                    }
                    i++;
                }
                i=0;
                while(i<a.size() && zera!=zerb){
                    if(a[i]=='0'){
                        a[i] = '1';
                        zera--;
                    }
                    i++;
                }
            }else{
                long i=0;
                while(i<a.size() && zera!=zerb){
                    if(a[i]=='1' && b[i]=='0'){
                        a[i] = '0';
                        zera++;
                    }
                    i++;
                }
                i=0;
                while(i<a.size() && zera!=zerb){
                    if(a[i]=='1'){
                        a[i] = '0';
                        zera++;
                    }
                    i++;
                }
            }
            long long tempans = 0;
            for(long i=0;i<a.size();i++){
                if(a[i]!=b[i])
                    tempans++;
            }
            ans += tempans/2;
            cout<<"Lucky Chef"<<endl<<ans<<endl;
        }
    }
    return 0;
}
