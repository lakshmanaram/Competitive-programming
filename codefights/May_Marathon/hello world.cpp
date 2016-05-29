#include<bits/stdc++.h>
std::string stringof(int a,int n){
    using namespace std;
    string ans = "";
    while(a){
        ans += a%10 + '0';
        a/=10;
    }
    while(ans.size()<n)
        ans += '0';
    reverse(ans.begin(),ans.end());
    return ans;
}
int ansof(std::string a){
    int ans = 0;
    for(int i=0;i<a.size();i++){
        ans*=10;
        ans += a[i]-'0';
    }
    return ans;
}
std::vector<int> alienTime(int H, int M, int S, std::string fr, std::string to) {
    using namespace std;
    string delimiter = ":";
    size_t pos = 0;
    string hour,minute;
    vector<int> ans(10,0);
    while(fr!=to){
        pos = fr.find(delimiter);
        hour = fr.substr(0, pos);
        for(int i=0;i<hour.size();i++){
            ans[hour[i]-'0']++;
        }
        fr.erase(0, pos + 1);
        pos = fr.find(delimiter);
        minute = fr.substr(0, pos);
        for(int i=0;i<minute.size();i++){
            ans[minute[i]-'0']++;
        }
        fr.erase(0, pos + 1);
        for(int i=0;i<minute.size();i++){
            ans[minute[i]-'0']++;
        }
        for(int i=0;i<fr.size();i++){
            ans[fr[i]-'0']++;
        }
        if(stringof(ansof(fr)+1,fr.size())==stringof(S,fr.size())){
            fr = stringof(0,fr.size());
            if(stringof(ansof(minute)+1,minute.size())==stringof(M,minute.size())){
                minute = stringof(0,minute.size());
                if(stringof(ansof(hour)+1,hour.size())==stringof(H,hour.size())){
                    hour = stringof(0,hour.size());
                } else{
                    hour = stringof(ansof(hour)+1,hour.size());
                }
            } else{
                minute = stringof(ansof(minute)+1,minute.size());
            }
        }else{
            fr = stringof(ansof(fr)+1,fr.size());
        }
        fr = hour+":"+minute+":"+fr;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        cout<<fr<<endl;
    }
    pos = fr.find(delimiter);
    hour = fr.substr(0, pos);
    for(int i=0;i<hour.size();i++){
        ans[hour[i]-'0']++;
    }
    fr.erase(0, pos + 1);
    pos = fr.find(delimiter);
    minute = fr.substr(0, pos);
    for(int i=0;i<minute.size();i++){
        ans[minute[i]-'0']++;
    }
    fr.erase(0, pos + 1);
    for(int i=0;i<minute.size();i++){
        ans[minute[i]-'0']++;
    }
    for(int i=0;i<fr.size();i++){
        ans[fr[i]-'0']++;
    }
    return ans;
}

int main(){
    using namespace std;

    vector<int> ans = alienTime(25,50,120,"00:00:000","00:00:002");
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
