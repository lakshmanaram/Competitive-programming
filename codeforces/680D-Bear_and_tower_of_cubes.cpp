#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m;
    set<long long> arr;
    set<long long>::iterator lit;
    vector<long long> extra;
    cin>>m;
    if(m<=7){
        cout<<m<<" "<<m;
    }else{
        long long n=7;
        arr.insert(0);
        arr.insert(7);
        extra.push_back(0);
        extra.push_back(7);
        for(int i=2;;i++){
            long long temp = pow(i,3);
            if(temp >= m){
                break;
            }else{
                // for(lit=arr.begin();lit!=arr.end();lit++)
                //     cout<<*lit<<" ";
                // cout<<endl;
                temp = min((long long)pow(i+1,3) - temp,m-temp);
                // cout<<temp<<" outside"<<endl;
                lit = arr.upper_bound(temp);
                // if(lit==arr.end())
                    lit--;
                // cout<<*lit<<" all outside"<<endl;
                if(extra[distance(arr.begin(),lit)]+1 >= extra[extra.size()-1]){
                    arr.insert(pow(i,3)+*lit);
                    extra.push_back(extra[distance(arr.begin(),lit)]+1);
                    // cout<<pow(i,3) + *lit<<" "<<extra[extra.size()-1]<<" added in if"<<endl;
                }else{
                    lit = arr.end();
                    lit--;
                    arr.insert(*lit);
                    extra.push_back(extra[extra.size()-1]);
                    // cout<<*lit<<" "<<extra[extra.size()-1]<<" added in else"<<endl;
                }
            }
        }
        lit = arr.end();
        lit--;
        cout<<extra[extra.size()-1]<<" "<<*lit<<endl;
    }
    return 0;
}
