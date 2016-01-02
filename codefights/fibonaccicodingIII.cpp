#include <bits/stdc++.h>
std::string FibonacciCodingIII(std::string a, std::string b) {
    if(a.length()<b.length()){
        std::string temp = a;
        a = b;
        b = temp;
    }
    int i,j;
    for(i=b.length()-1,j = a.length()-1;i>=0;i--,j--){
    	if(a[i]=='1'&&b[i]=='1')
    		a[i]='2';
    	else if(a[i]!='1')
    		a[i] = b[i];        
    }
    std::reverse(a.begin(),a.end());
    bool val = false;
    i=0;
	while(i<a.length()-1){
		if(a[i]=='2')
			val = true;
		else if(a[i]>'0'&&a[i+1]>'0')
			val = true;
		i++;
	}
	if(a[i]=='2')
		val = true;
    while(val){
    	while(a[a.length()-1]>'1'){
    		a+='1';
    		a[a.length()-2] -= 2;
    		a[a.length()-4] ++;
    	}
    	while(a[a.length()-1]>'0' && a[a.length()-2]>'0'){
	    	a[a.length()-1]--;
	    	a[a.length()-2]--;
	    	a += '1';
    	}
    	for(i=a.length()-2;i>=2;i--){
    		if(a[i]>'1'){
    			a[i] -= 2;
    			a[i+1]++;
    			a[i-2]++;
    		}
    	}
    	if(a[0]>'0'){
    		a[1] += a[0] - '0';
    		a[0] = '0';
    	}
    	if(a[1] > '0'){
    		a[2] += (a[1]-'0')/2;
    		a[1] = (a[1] - '0')%2;
    	}
    	for(i=a.length()-2;i>=2;i--){
    		if(a[i]>'1'){
    			a[i] -= 2;
    			a[i+1] += 1;
    			a[i-2] += 1;
    		}
    	}
    	for(i=a.length()-2;i>=1;i--){
    		if(a[i]>'0'&&a[i-1]>'0'){
    			a[i+1] ++;
    			a[i] --;
    			a[i-1] --;
    		}
    	}
    	val = false;
    i=0;
	while(i<a.length()-1){
		if(a[i]=='2')
			val = true;
		else if(a[i]>'0'&&a[i+1]>'0')
			val = true;
		i++;
	}
	if(a[i]=='2')
		val = true;
    }
    std::reverse(a.begin(),a.end());
    return a;
}

int main(){
	std::string a = "110", b = "100";
	std::cout<<FibonacciCodingIII(a,b);
	return 0;
}
