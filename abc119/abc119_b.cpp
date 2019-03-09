#include <bits/stdc++.h>
#include <string>
using namespace std;
 
typedef long long ll;
 
int like_cnt[31] = {0};




int main(){
    int n;

    cin >> n;
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        string tmp1;
        string tmp2;

        cin >> tmp1 >> tmp2;

        if (tmp2 == "JPY"){
            ans += stoi(tmp1);
        } else {
            ans += stod(tmp1) * 380000.0;
        }


    }
    cout << ans << endl;

}