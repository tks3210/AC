#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}




const int keta_max = 100;
int dp[keta_max][2] = {0};

//K以下の数字を探す
int keta_dp(vector<int> &num, int keta){
    dp[0][0] = 1;
    rep(i, keta){
        int D = num[i];
        rep(smaller, 2){
            //smaller=0 => 0~Dまでの推移、smaller=1 => 0~9までの推移
            for(int d = 0; d <= ((smaller)?9:D); d++){
                int ni = i+1; int ns = smaller;
                if(ns==0){
                    if (d < D) ns = 1; //smallerになる場合の推移
                }
                dp[ni][ns] += dp[i][smaller];
            }
        }
    }
}

const int n_zero_max = 10;
int dp2[keta_max][n_zero_max][2] = {0};


//K以下の数字で非0をnonzero個含む物を探す　0の数を管理する値を追加
int keta_dp2(vector<int> &num, int keta, int nonzero){
    dp2[0][0][0] = 1;
    rep(i, keta){
        rep(j, nonzero+1){
            int D = num[i];
            rep(smaller, 2){
                for(int d = 0; d<=(smaller?9:D); d++){
                    int ni = i+1; int nj = j; int ns = smaller; 
                    if (d != 0) nj++;
                    if (nj>nonzero) continue;
                    if (ns == 0){
                        if (d < D) ns = 1;
                    }
                    dp2[ni][nj][ns] += dp2[i][j][smaller];
                }
            }
        }
    }
}


int main(){

    string s;
    int nonzero;
    cin >> s >> nonzero;
    int keta = s.size();
    vector<int> num(keta);
    rep(i, keta) num[i] = s[i]-'0';

    keta_dp(num, keta);
    keta_dp2(num, keta, nonzero);
    rep(smaller, 2){
        rep(i, keta+1){
            cout << dp[i][smaller] << " ";
        }
        cout << endl;
    }

    rep(smaller, 2){
        cout << "smaller=" << smaller << endl;
        rep(i, keta+1){
            rep(j, nonzero+1){
                cout << dp2[i][j][smaller] << " ";

            }
            cout << endl;
        }
        cout << endl ;
    }


}