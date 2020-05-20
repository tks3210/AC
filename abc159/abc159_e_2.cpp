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


/*
重実装　n全探索　GRID

GRID構造の0と1からなるデータがあり、
このGRIDを端から端まで分割することで、1が含まれるものをKマス以下にしたい。
分割の操作の最小数をもとめたい。
ただし、このGRIDは横1~1000マス、縦1~10マスとなる。

GRIDの縦が10マスであることがポイント。
縦方向の分割は全パターンを試しても、2^9で抑えられる。

縦方向の分割が確定した状態で、
横方向の分割の最小数を求めたい。


貪欲法で解く。
縦方向の累積和を取っておき、
各列ごとに、各分割のホワイトチョコの数を足していく。

(1)ホワイトチョコが累積でK個を超えた場合、横の分割を行う。
(2)ホワイトチョコがその列のみでK個を超えた場合、縦の分割の時点で誤りなので未評価。

重実装のため、もう一回解いて慣らしたい。

*/

const int COL_MAX = 1010;
int choko[10][COL_MAX] = {0};
int choko_rowsum[11][COL_MAX] = {0};

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    rep(i,h){
        string s; cin >> s;
        rep(j,w){
            choko[i][j] = s[j]-'0';
        }
    }
    rep(i,h)rep(j,w){
        choko_rowsum[i+1][j] = choko_rowsum[i][j] + choko[i][j];
    }


    int ans = MOD;
    rep(i, 1<<(h-1)){
        int tans = 0;
        bool isok = true;
        vector<int> div; 
        div.push_back(0);
        for (int j = 0; j < h-1; j++)
        {
            if ((i>>j)&1==1){
                div.push_back(j+1);
                tans++;
            }
        }
        div.push_back(h);
        vector<int> block(div.size()-1, 0);
        vector<int> blockOneRow(div.size()-1, 0);
        //show(div);
        for(int row = 0; row < w; row++){
            bool isbreak = false;
            for (int d = 0; d < div.size()-1; d++)
            {
                blockOneRow[d] = choko_rowsum[div[d+1]][row] - choko_rowsum[div[d]][row];
                //cout << block[d] << ":" << d << ":"<<row <<"::";
                if (blockOneRow[d] > k){
                    isok = false; break;
                }
                if (block[d]+blockOneRow[d] > k){
                    isbreak = true;
                } else {
                    block[d] += blockOneRow[d];
                }
            }
            if (isbreak){
                copy(blockOneRow.begin(), blockOneRow.end(), block.begin());
                //cout << row << endl;
                tans++;
            }     
        }
        //cout  << i << " " << tans << endl;
        if (isok) ans = min(tans, ans);
    }
    cout << ans << endl;

}