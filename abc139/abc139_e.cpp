#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    rep(i, n){
        rep(j, n-1){
            int tmp; cin >> tmp; 
            a[i].push_back(tmp);
        }
    }


    int day = 0; 
    while(1){
        int isgameflag = 0;
        vector<int> isgame(n, 0);
        day++;

        rep(i, n){
            if (isgame[i] == 0 && a[i].size() != 0){
                int aite = a[i][0] - 1;
                if (a[aite].size() != 0 && (a[aite][0] - 1) == i && isgame[aite] == 0){
                    a[i].erase(a[i].begin());
                    isgame[i] = 1;
                    a[aite].erase(a[aite].begin());
                    isgame[aite] = 1;
                    isgameflag = 1;
                }
            }
        }
        if (isgameflag == 0){day = -1; break;}
        int remain = 0;
        rep(i, n){remain += a[i].size();}
        if (remain == 0) break;
    }

    cout << day << endl;

}

/*

int day = 0; 
while(1){
    int isgameflag = 0;
    vector<int> isgame(n, 0);
    day++;

    rep(i, n){
        if (isgame[i] == 0){
            int aite = a[i][0];
            if (a[aite - 1][0] == i && isgame[aite - 1]){
                a[i].erase(a[i].begin());
                isgame[i] = 1;
                a[aite - 1].erase(a[aite - 1].begin());
                isgame[aite - 1] = 1;
                isgameflag = 1;
            }
        }
    }
    if (isgameflag == 0){
        day = -1;
        break;
    }

    int remain = 0;
    rep(i, n){remain += a[i].size();}
    if (remain == 0) break;
}





*/