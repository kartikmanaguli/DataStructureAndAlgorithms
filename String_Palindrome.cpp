#include <iostream>
using namespace std;
string checkPalin(auto str){
    int end = str.length()-1;
    int start = 0 ;
    while(start < end-start){
        if(str[start]!=str[end-start])
        return "Not a Palindraome";
        start++;
    }
    return "Palindraome";
}

int main()
{
    string str ;
    cin>>str ;
    cout <<checkPalin(str);
}
