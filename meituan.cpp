#include<iostream>
#include<string>
#include<vector>

using namespace std;



int main(){
    int year;
    cin >> year;
    if(year % 400 == 0){
        cout << "yes";
        return 0;
    }
    else if(year % 100 == 0){
        cout << "no";
        return 0;
    }else if(year % 4 == 0){
        cout << "yes";
        return 0;
    }else{
        cout << "no";
        return 0; 
    }
    return 0;
}
