#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int alpha[26];
int bet[26];
int main(){
    string s;
    string t;

    cin >> s >> t;
    int ng_flg = 0;
    for (int i = 0; i < s.size(); i++){
        int tmp = (int)t[i] - (int)'a';
        if (alpha[tmp] == 0){
            alpha[tmp] = (int)s[i];
        } else {
            //printf("%d:%c, %c\n",i, (char)alpha[tmp], (char)s[i]);
            if (alpha[tmp] != (int)s[i]){
                ng_flg = 1;
            }
        }
    }
    for (int i = 0; i < s.size(); i++){
        int tmp = (int)s[i] - (int)'a';
        if (bet[tmp] == 0){
            bet[tmp] = (int)t[i];
        } else {
            //printf("%d:%c, %c\n",i, (char)alpha[tmp], (char)s[i]);
            if (bet[tmp] != (int)t[i]){
                ng_flg = 1;
            }
        }
    }
    if (ng_flg == 0){
        printf("Yes");
    }else{
        printf("No");
    }
}