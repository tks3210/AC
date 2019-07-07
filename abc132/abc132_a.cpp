#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;

    if(((s[0] == s[1]) && (s[2] == s[3]) && (s[0] != s[2]))||
    ((s[0] == s[2]) && (s[1] == s[3]) && (s[0] != s[1]))||
    ((s[0] == s[3]) && (s[1] == s[2]) && (s[0] != s[1]))){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

