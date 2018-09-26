#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    string s="Iwannabetheguy";
    cout << s[0] << s[1] << s[6] <<endl;
    
    
    for(int i = 0; i < s.size(); i++)
    {
        printf("%c ",s[i]);
    }
    //最初と最後を抽出
    cout << s.front() << endl;       
    cout << s.back() << endl;
    //部分抽出(6文字目から2文字抽出)
    cout << s.substr(6,2) << endl;

    //逆順にした。     
    reverse(s.begin(),s.end());

    cout << s << endl;
}