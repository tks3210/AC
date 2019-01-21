#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    string s;
    string ans;
    cin >> s;

    if (s.size() == 2){
        ans = s;
    }else{
        char tmp;
        tmp = s[0];
        s[0] = s[2];
        s[2] = tmp;
        ans = s;
    }
    cout << ans << endl;
}