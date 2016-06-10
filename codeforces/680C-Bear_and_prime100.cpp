#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {2,3,4,5,7,9,25,49,11,13,17,19,23,29,31,37,41,43,47};
    vector<int> ans;
    for(int i=0;i<19;i++){
        cout<<arr[i]<<endl;
        string s;
        cin>>s;
        if(s=="yes")
            ans.push_back(arr[i]);
    }
    if(ans.size()==0||ans.size()==1)
        cout<<"prime"<<endl;
    else
        cout<<"composite"<<endl;
    return 0;
}
