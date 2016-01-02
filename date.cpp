#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;
int day, month, year;
bool leap(){                                                                                   //determines whether the year is a leap year
    return (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
}
bool isDateValid(){                                                     //validate date entered
	if(leap()){
        if ((month == 2) && (day > 29)){
            cout<<"There are no more than 29 days even in a leap year february"<<endl;
            return false;
        }
    }
    else {
        if ((month == 2) && (day > 28)){
            cout<<"There are no more than 28 days even in a non-leap year february"<<endl;
            return false;
        }
    }    
    if(year < 1 ){
        cout<<"The given year isn't valid, Enter a positive year."<<endl;
        return false;
    }   
    if(month < 1 ){
        cout<<"The given month isn't valid, Enter a positive month."<<endl;
        return false;
    }
    else if(day < 1){
        cout<<"The given day isn't valid, Give a positive day as input."<<endl;
        return false;
    }
    else if(month > 12){
        cout<<"The given month isn't valid. Months are indexed from 1 to 12."<<endl;
        return false;
    }
    if(((month == 1) || (month ==3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))&& (day > 31)){
        cout<<"There are no more than 31 days in the given month"<<endl;
        return false;
    }
    else if (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30)){
        cout<<"There are no more than 30 days in the given month"<<endl;
        return false;
    }
    else
        return true;
    }
bool getdate(){                                                                                      //function to get date
    char a;
    int i,n;
    string date;
    cin>>date;
    if(date.size()!=10)
        return false;
    for(i=0,n=0;i<2;i++){                                                                            //checks date
    	a = date[i];
        if(!isdigit(a)){
    		return false;
		}
		n*=10;
		n += int(a)-int('0');
	}
    day = n;
    a = date[i++];
	if(a!='-')
		return false;
	for(n=0;i<5;i++){                                                                               //checks month
        a = date[i];
        if(!isdigit(a)){
    		return false;
		}
		n*=10;
		n += int(a)-int('0');
	}
    month = n;
    a = date[i++];
	if(a!='-')
		return false;
	for(n=0;i<10;i++){                                                                              //checks year
    	a = date[i];
    	if(!isdigit(a)){
    		return false;
		}
		n*=10;
		n += int(a)-int('0');
	}
    year = n;
    return true;
}
string getday(){
    string d = "";
    switch(day/10){
        case 3:
            if(day%10 == 0){
                d += "Thirtieth";
                return d;
            }
            else 
                d += "Thirty ";
            break;
        case 2:
            if(day%10 == 0){
                d += "Twentieth";
                return d;
            }
            else 
                d += "Twenty ";
            break;
        case 1:
            switch(day%10){
                case 0:
                    d += "Tenth";
                    break;
                case 1:
                    d += "Eleventh";
                    break;
                case 2:
                    d += "Twelfth";
                    break;
                case 3:
                    d += "Thirteenth";
                    break;
                case 4:
                    d += "Fourteenth";
                    break;
                case 5:
                    d += "Fifteenth";
                    break;
                case 6:
                    d += "Sixteenth";
                    break;
                case 7:
                    d += "Seventeenth";
                    break;
                case 8:
                    d += "Eighteenth";
                    break;
                case 9:
                    d += "Nineteenth";
                    break;
            }
            return d;
    }
    switch(day%10){
        case 1:
            d += "First";
            break;
        case 2:
            d += "Second";
            break;
        case 3:
            d += "Third";
            break;
        case 4:
            d += "Fourth";
            break;
        case 5:
            d += "Fifth";
            break;
        case 6:
            d += "Sixth";
            break;
        case 7:
            d += "Seventh";
            break;
        case 8:
            d += "Eighth";
            break;
        case 9:
            d += "Ninth";
            break;
    }
    return d;
}
string getmonth(){
    switch(month){
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
    }
}
string getyday(int n){
    string d = "";
    switch(n/10){
        case 9:
            d += "Ninety ";
            break;
        case 8:
            d += "Eighty ";
            break;
        case 7:
            d += "Seventy ";
            break;
        case 6:
            d += "Sixty ";
            break;
        case 5:
            d += "Fifty ";
            break;
        case 4:
            d += "Forty ";
            break;
        case 3:
            d += "Thirty ";
            break;
        case 2:
            d += "Twenty ";
            break;
        case 1:
            switch(n%10){
                case 0:
                    d += "Ten";
                    return d;
                case 1:
                    d += "Eleven";
                    return d;
                case 2:
                    d += "Twelve";
                    return d;
                case 3:
                    d += "Thirteen";
                    return d;
                case 4:
                    d += "Fourteen";
                    return d;
                case 5:
                    d += "Fifteen";
                    return d;
                case 6:
                    d += "Sixteen";
                    return d;
                case 7:
                    d += "Seventeen";
                    return d;
                case 8:
                    d += "Eighteen";
                    return d;
                case 9:
                    d += "Nineteen";
                    return d;                    
            }
    }
    switch(n%10){
    	case 0:
    		if(d.size()>0)
    			d.erase(d.end()-1);
    		break;
        case 1:
            d += "One";
            break;
        case 2:
            d += "Two";
            break;
        case 3:
            d += "Three";
            break;
        case 4:
            d += "Four";
            break;
        case 5:
            d += "Five";
            break;
        case 6:
            d += "Six";
            break;
        case 7:
            d += "Seven";
            break;
        case 8:
            d += "Eight";
            break;
        case 9:
            d += "Nine";
            break;
    }
    return d;
}
string getyear(){
    string y = "";
    if(year/100 != 0){
        y += getyday(year/100);
        y += " ";
    }
    if(year%100 == 0)
    	y += "Hundred";
    else
	    y += getyday(year%100);
    return y;
}
int main(){
    cout<<endl<<"PROGRAM TO CONVERT A GIVEN DATE TO IT'S WORD FORMAT"<<endl<<endl;
    cout<<setw(60)<<setfill('*')<<"*"<<endl<<setw(60)<<setfill('*')<<"*"<<endl<<endl<<endl;
    bool choice = true;
    while(choice){
        choice = false;
        cout<<"Enter Date in the format (dd-mm-yyyy): (Do not forget the '-')"<<endl;
        if(!getdate()){
            cout<<"The date entered is in an incorrect format"<<endl<<"Please enter a date in this format (dd-mm-yyyy)"<<endl<<endl;
            day = 0;
            month = 0;
            year = 0;
            choice = true;
            continue;
        }
        cout<<"The entered date is: "<<day<<"-"<<month<<"-"<<year<<endl;
        if(!isDateValid()){
            cout<<"The entered date is invalid. Please try again."<<endl<<endl;;
            day = 0;
            month = 0;
            year = 0;
            choice = true;
            continue;
        }
        else{
            cout<<"The given date is valid"<<endl;
        }
        cout<<getday()<<" of "<<getmonth()<<". "<<getyear()<<endl;
        day = 0;
        month = 0;
        year = 0;
        cout<<"Do you want to continue: (Y/N) ";
        char ch;
        cin>>ch;
        if(ch=='N'||ch=='n')
        	choice = false;
        else
        	choice = true;
    }
}
