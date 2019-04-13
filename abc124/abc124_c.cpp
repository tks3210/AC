#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    
    int ans_one = 0; //0101
    int ans_two = 0; //1010
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0'){
            if ((i % 2) == 0){
                ans_two++;
            } else {
                ans_one++;
            }
        } else {
            if ((i % 2) == 0) {
                ans_one++;
            } else {
                ans_two++;
            }
        }
    }
    cout << min(ans_one, ans_two) << endl;
}

