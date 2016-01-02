//COSH1503
#include <bits/stdc++.h>
using namespace std;
long m;
bool wayToSort(int i, int j) { return i > j; }
void func(vector<int> w,int i, long want,long sum){
    if(m==0)
        return;
    if(i!=w.size() && want>=0 && want <= sum){
        func(w,i+1,want-w[i],sum - w[i]);
        func(w,i+1,want,sum - w[i]);
        m = min(want,m);
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        vector<int> w;
        long sum = 0;
        for(i=0;i<n;i++){
            int x;
            cin>>x;
            sum += x;
            w.push_back(x);
        }
        long want = sum/2;
        m = sum;
        sort(w.begin(),w.end(),wayToSort);
        i = 0;
        func(w,i,want,sum);
        cout<<(sum+1)/2 - sum/2 + m<<endl;
    }
    return 0;
}
 
