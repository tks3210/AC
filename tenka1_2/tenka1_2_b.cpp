#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    for(int i = 0; i < n; i++)
    {
        if(s[i] != s[k - 1]){
            s[i] = '*';
        }
    }
    
    cout << s << endl;
}

