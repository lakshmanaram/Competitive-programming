#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    vector<int> w;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        w.push_back(x);
    }
    vector<int>person(n,2);
    int x = 0, y = 0, ch = 0;
    vector<int> t = w;
    sort(t.begin(),t.end());
    i = t.size()-1;
    x++;
    vector<int>::iterator p;
    p = find(w.begin(),w.end(),t[i]);
    person[p-w.begin()] = ch;
    int dif = t[i];
    for(i = t.size()-2;i>=0;i--){
        p = find(w.begin(),w.end(),t[i]);
        if(dif>=0){
            ch = 1;
            person[p-w.begin()] = ch;
            dif -= t[i];
            x++;
        }else{
            ch = 0;
            person[p-w.begin()] = ch;
            dif += t[i];
            y++;

        }
        if(x==(n+1)/2 || y==(n+1)/2)
            break;
    }
    if(x==(n+1)/2){
        for(i=0;i<person.size();i++){
            if(person[i]==2)
                person[i] = 0;
        }
    }
    for(i=0;i<person.size();i++){
        if(person[i]==2)
            person[i] = 1;
    }
    ch = person[0];
    for(i=0;i<person.size();i++){
        if(person[i]==ch)
            cout<<w[i]<<" ";
    }
    cout<<endl;
    ch = 1-ch;
    for(i=0;i<person.size();i++){
        if(person[i]==ch)
            cout<<w[i]<<" ";
    }
    return 0;
}
