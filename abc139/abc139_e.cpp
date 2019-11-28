#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 1005;
const int MAXV = MAXN * MAXN /2;
vector<int> to[MAXV];

int id[MAXN][MAXN];
int toId(int i, int j){
    if (i > j) swap(i, j);
    return id[i][j];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1));
    rep(i, n){
        rep(j, n-1){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int V = 0;
    rep(i, n)rep(j ,n){
        if (i < j){
            id[i][j] = V++;
        }
    }

    rep(i , n){
        rep(j, n-1){
            a[i][j] = toId(i, a[i][j]); 
        }
        rep(j, n-2){
            to[a[i][j+1]].push_back(a[i][j]);    
        }
    }

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