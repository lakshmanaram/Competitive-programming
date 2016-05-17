#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        int n;
        string temp;
        cin>>n>>temp;
        int divisor;
        if(temp == "INDIAN")
            divisor = 200;
        else
            divisor = 400;
        while(n--){
            int x;
            cin>>temp;
            if(temp == "CONTEST_WON"){
                ans += 300;
                cin>>x;
                if(x<=20)
                    ans += 20-x;
            } else if(temp == "TOP_CONTRIBUTOR")
                ans += 300;
            else if(temp == "CONTEST_HOSTED")
                ans += 50;
            else{
                cin>>x;
                ans += x;
            }
        }
        cout<<ans/divisor<<endl;
    }
    return 0;
}
