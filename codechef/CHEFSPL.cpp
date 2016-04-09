#include <bits/stdc++.h>
using namespace std;
bool func(string a, string b){
    int corrections = 0;
    for(int i=0,j = 0;i<a.size()&&j<b.size();i++,j++){
        if(a[i] != b[j]){
            corrections++;
            j--;
        }
        if(corrections>1){
        //    cout<<left<<" "<<right<<" false\n";
            return false;
        }
    }
    return true;
}
int main(){
    long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size()==1){
            cout<<"NO"<<endl;
            continue;
        }
        //cout<<s.size();
        if(s.size()%2 == 0){
            if(s.substr(0,s.size()/2) == s.substr(s.size()/2)){
                cout<<"YES"<<endl;
                continue;
            }
        }
        else{
            string left = s.substr(0,s.size()/2);
            string right = s.substr(s.size()/2);
            if(func(right,left)){
                cout<<"YES"<<endl;
                continue;
            }
            left = s.substr(0,(s.size()/2)+1 );
            right = s.substr((s.size()/2) +1);
            if(func(left,right)){
                cout<<"YES"<<endl;
                continue;
            }
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
