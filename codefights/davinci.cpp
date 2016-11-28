#include <bits/stdc++.h>
#include <string>
using namespace std;
std::string humanFigureProportions(std::string text) {
    using namespace std;
    string x = "The whole figure is ";
    string ans = "";
    int total,crh,plf,cth,pstb,bbh,ctn,temp;
    bool tots = false;
    text = text.substr(x.size());
    size_t pos = text.find("inches");
    if(text.substr(0,pos) != "... "){
    	if(!tots){
    		total = atoi(text.substr(0,pos).c_str());
    		tots = true;
    	} else {
    		temp = atoi(text.substr(0,pos).c_str());
    		if(total != temp)
    			return "Error";
    	}
	}
	text = text.substr(text.find("inches"));
	x = "inches. From the chin to the roots of the hair is ";
	text = text.substr(x.size());
    pos = text.find("inches");
    if(text.substr(0,pos) != "... "){
    	if(!tots){
    		total = 10*atoi(text.substr(0,pos).c_str());
    		tots = true;
    	} else {
    		temp = atoi(text.substr(0,pos).c_str());
    		if(total != 10*temp)
    			return "Error";
    	}
	}
	text = text.substr(text.find("inches"));


	crh = total/10;
	plf = total/10;
	cth = total/8;
	pstb = total/6;
	bbh = total/4;
	ctn = total/3;
	ans = "The whole figure is "
	+ std::to_string(total) +" inches. From the chin to the roots of the hair is "
	+ to_string(crh) +" inches. From the joint of the palm of the hand to the tip of the longest finger is "
	+ to_string(plf) +" inches. From the chin to the top of the head "
	+ to_string(cth) +" inches; and from the pit of the stomach to the top of the breast is "
	+ to_string(pstb) +" inches, and from the pit below the breast bone to the top of the head "
	+ to_string(bbh) +" inches. From the chin to the nostrils "
	+ to_string(ctn) +" inches...";
	return ans;
}
int main(){
	string a = "The whole figure is ... inches. From the chin to the roots of the hair is 12 inches. From the joint of the palm of the hand to the tip of  the longest finger is ... inches. From the chin to the top of the head 15 inches; and from the pit of the stomach to the top of the breast is ... inches, and from the pit below the breast bone to the top of the head ... inches. From the chin to the nostrils 40 inches...";
	cout<<humanFigureProportions(a);
	return 0;
}