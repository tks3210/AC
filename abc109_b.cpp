#include <iostream>
#include <string>
#include <set>
using namespace std;

char w_end;
set<string> M;

bool check(int k, string s){
    int len = s.length();
    if (k == 0){
        w_end = s[len -1];
        M.insert(s);
        return true;
    }
    if (M.count(s) != 0){
        return false;
    }
    M.insert(s);
    char w_top = s[0];
    if (w_top != w_end){
        return false;
    }
    w_end = s[len-1];
    return true;
}

int main(){
    int N;
    bool ans = true;
    cin >> N;
    
    for (int i = 0; i < N ; i++) {
        string sent;
        cin >> sent;
        if (ans && !check(i, sent)){
            ans = false;
        }
    }

    // if (ans == false){
    //     cout << "No" << endl;
    // } else {
    //     cout << "Yes" << endl;
    // }
    cout << (ans ? "Yes\n" :"No\n");
} 