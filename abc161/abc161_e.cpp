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
貪欲法

以下の制限に基づいて、N日間のうちK日間労働する。
    - 労働後、C日間は働かない
    - Sのi文字目が'x'のとき、i日目は働かない
確実に働く日にちを出力する。

基本アプローチ
ある日にちを働かないとしたときに、
破綻する（他の日にちでK日間の労働ができない）かどうかを判定する

最速の場合の労働パターンAと最も開始が遅い場合の労働パターンBがあるとすると、
   ooxxoxoxxxoxoxxo  K=4, C=3
A: 1   2     3    4
B:  1    2   3    4 
同じ数字が重なり合っていない5日目や7日目は
働かなくても4日間の労働が可能
逆に同じ数字が重なり合っている日にちは労働が必須

*/

int main()
{
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<int> b_f(n, 0);
    vector<int> b_b(n, 0);

    int k_t = 0;
    rep(i, n){
        if (s[i] == 'o'){
            k_t++;
            b_f[i] = k_t;
            i+=c;
        } 
        if (k_t >= k || i >= n){
            break;
        }
    }
    k_t = k;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == 'o'){
            b_b[i] = k_t;
            i-=c;
            k_t--;
        }
        if (k_t <= 0 || i < 0){
            break;
        }
    }
    
    // show(b_f);
    // show(b_b);

    rep(i, n){
        if (b_f[i] == b_b[i] && b_f[i] != 0){
            cout << i+1 << endl;
        }
    }
    
}

