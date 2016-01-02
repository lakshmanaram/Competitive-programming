int func1(std::string s){
    for(int i=0;i<s.size()/2;i++){
        if((s[i]!=s[s.size()-i-1])&&((s[i]+1)%10!=s[s.size()-i-1])&&(s[i]!=(s[s.size()-i-1]+1)%10))
            return 0;
    }
    return 1;
}
std::vector<int> Inv_all(std::vector<std::string> Numbers) {
    std::vector<int> ans;
    
    for(int i=0;i<Numbers.size();i++){
        std::string a = Numbers[i];
        if(a=="1"){
            ans.push_back(0);
            continue;
        }
        if(func1(a)){
            if(a=="2"||a=="4"||a=="6"||a=="8")
                ans.push_back(1);
            else if(a=="3"||a=="5"||a=="7"||a=="9")
                ans.push_back(0);
            else
                ans.push_back(1);
        }
        else if ((a[0]=='1')&&(a.size()>2)){
            a.erase(a.begin());
            if(func1(a)){
                ans.push_back(1);
            }
            else
                ans.push_back(0);
        }
        else
            ans.push_back(0);
    }
    return ans;
}

