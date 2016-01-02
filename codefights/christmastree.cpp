#include<bits/stdc++.h>
    using namespace std;
vector<string> christmasTree(int ln, int lh) {
    vector<string> ans;
    string temp = "";
    for(int i=0;i<ln + lh;i++)
        temp += " ";
    temp += "*";
    ans.push_back(temp);
    temp = "";
    for(int i=0;i<ln+lh;i++)
        temp += " ";
    temp += "*";
    ans.push_back(temp);
    temp = "";
    for(int i=0;i<ln +lh - 1;i++)
        temp += " ";
    temp += "***";
    ans.push_back(temp);
    for(int i=0,c=5;i<ln;i++,c+=2){
        int b = c;
        for(int j = lh;j>0;j--,b += 2){
            string t = "";
            for(int k=0;k<ln+lh-b/2;k++){
                t += " ";
            }
            for(int k=0;k<b;k++){
                t += "*";
            }
            ans.push_back(t);
        }
    }
    
    int l = lh;
    if(lh%2==1)
        lh = lh+1;
    for(int j =0;j<ln;j++){
    temp =  "";
    for(int i = 0;i<l + ln - lh/2;i++)
        temp += " ";
    for(int i = 0;i<=lh;i++)
        temp += "*";
    ans.push_back(temp);
    }
    return ans;
}
int main(){
vector<string> s = christmasTree(1,3);
    for(int i=0 ;i<s.size();i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
