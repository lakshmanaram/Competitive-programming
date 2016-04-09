#include<bits/stdc++.h>
using namespace std;
int main(){
    int f,i,t;
    cin>>f>>i>>t;
    vector<char> temp(i,'N');
    vector<vector<char> > likes(f,temp);
    for(int j=0;j<f;j++)
    for(int k=0;k<i;k++)
    cin>>likes[j][k];
    int ans = 0;
    for(int j=0;j<i;j++){
        int val = 0;
        for(int k = 0; k<f;k++){
            if(likes[k][j] == 'Y')
                val++;
        }
        if(val>=t)
            ans++;
    }
    cout<<ans;
    return 0;
}
