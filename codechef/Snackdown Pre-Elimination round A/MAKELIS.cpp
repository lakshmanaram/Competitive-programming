#include <bits/stdc++.h>
using namespace std;
int main(){
    long t;
    cin>>t;
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    vector<int> primes(p, p + sizeof p / sizeof p[0]);
    while(t--){
        long long k;
        cin>>k;
        if(k==1){
            cout<<1<<endl<<1<<endl;
            continue;
        }
        vector<int> ans;
        int ans_p = 1;
        for(int i=0;k!=1;i++){
            if(k%primes[i]==0){
                stack<int> temp;
                for(int j=0;j<primes[i];j++){
                    temp.push(ans_p++);
                }
                while(!temp.empty()){
                    ans.push_back(temp.top());
                    temp.pop();
                }
                k /= primes[i];
                i--;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
