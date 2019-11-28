#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    vector<int> ans;

    int itr = 0;
    while(1){
        //cout << itr << endl;
        if ((itr + m) >= n){
            ans.push_back(n - itr);
            break;
        } 
        bool gameover = true;
        for (int i = m; i > 0; i--)
        {
            if (s[itr + i] == '0'){
                ans.push_back(i);
                itr += i;
                gameover = false;
                break;
            }
        }
        
        if (gameover == true){
            cout << "-1" << endl;
            break;
        }

    }

    reverse(ans.begin(), ans.end());

    show(ans);
}

