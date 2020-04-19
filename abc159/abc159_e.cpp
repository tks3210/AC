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


const int COL_MAX = 1010;
int choko[10][COL_MAX] = {0};

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
 
    rep(i, h){
        string s;
        cin >> s;
        rep(j, w){
            choko[i][j] = s[j] - '0';
        }
    }

    int ans_min = MOD;
    rep(i, 1<<(h-1)){
        vector<int> divide;
        int ans = 0;
        divide.push_back(0);
        rep(i2, h-1){
            if ((i>>i2)&1==1){
                //h=10:0010010011 => (0,)1,2,5,8(,10)
                divide.push_back(i2+1);
                ans++;
            }
        }
        divide.push_back(h);
        //show(divide);
        //cout << i << ":";
        vector<int> sum_len(h);
        rep(j, w){
            vector<int> sum_sum_len(h+1, 0);
            vector<int> oneline_sum(h+1, 0);
            rep(i2, h){
                sum_len[i2] += choko[i2][j];
            }
            rep(i2, h){
                sum_sum_len[i2+1] = sum_sum_len[i2] + sum_len[i2];
                oneline_sum[i2+1] = oneline_sum[i2] + choko[i2][j];
            }
            int max_sum = 0;
            int oneline_block_sum = 0;
            rep(div, divide.size()-1){
                int block_sum = sum_sum_len[divide[div+1]] - sum_sum_len[divide[div]]; 
                int oneline_block = oneline_sum[divide[div+1]] - oneline_sum[divide[div]];
                max_sum = max(max_sum, block_sum);
                oneline_block_sum = max(oneline_block_sum, oneline_block);              
            }
            //cout << i << ":" << j << ":"<< max_sum << endl;  

            if (oneline_block_sum > k) {
                ans = MOD;
                break;
            }
            if (max_sum > k){
                //reset
                rep(i2, h){
                    sum_len[i2] = choko[i2][j];
                }
                ans++;
            }
        }
        ans_min = min(ans_min, ans);
    }
    cout << ans_min << endl;
}

