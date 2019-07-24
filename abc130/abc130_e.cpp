#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

#define S 2005
#define T 2005
ll dp_3[S][T] = {0};

int dp_sumCommonPartString(vector<int> s, vector<int> t){
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j]){
                dp_3[i + 1][j + 1] = (dp_3[i][j + 1] + dp_3[i + 1][j] + 1);
            } else {
                dp_3[i + 1][j + 1] = (dp_3[i][j + 1] + dp_3[i + 1][j] - dp_3[i][j]);
            }
            dp_3[i + 1][j + 1] %= MOD;
            if (dp_3[i + 1][j + 1] < 0) dp_3[i + 1][j + 1] += MOD;
            //printf("[%d][%d]:%d ", i, j, dp_3[i + 1][j + 1]);
        }
        //printf("\n");
    }
    return (int)dp_3[s.size()][t.size()];
}


int main(){
    vector<int> s, t;
    int n, m;
    cin >> n >> m;
    rep(i, n){ int tmp; cin >> tmp; s.push_back(tmp);}
    rep(i, m){ int tmp; cin >> tmp; t.push_back(tmp);}
    cout << (dp_sumCommonPartString(s, t) + 1) % MOD << endl;  
}