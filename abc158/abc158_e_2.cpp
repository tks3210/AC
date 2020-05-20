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
部分文字列　剰余


長さNの0~9からなる文字列
部分文字列のうち、十進表記の整数と見なした際にPで割り切れる個数をカウント
部分文字列は先頭0を許容
1<=N<=2*10^5
2<=P<=10000

p = 2, 5でもないとき、

「ある数XXX0000がpで割れるなら、XXXもpで割り切れる。」性質を使うと、

下a桁目までのmod p下の値Aと、下b(<a)桁目のmod p下での値が一致していたとき、
a-bの間の数字はpで割り切れることになる。
よってこのような組み合わせ数を探せばよく、
下x桁目からmapで剰余を管理しながら今まで出た剰余の数を足していくと答えがでる。

abc164_eで類題登場


*/

ll calc_num25(string& s, int n, int p){
    int score = 0;
    ll ans = 0; 
    rep(i, n){
        int num = s[n-1-i]-'0';
        if (num%p==0) {
            score++;
            ans += score;
        }
    }

    return ans;
}


int main()
{
    int n, p;
    cin >> n >> p;
    string s; cin >> s;


    vector<int> mod10(n);
    mod10[0] = 1;
    for (int i = 1; i < n; i++)
    {
        mod10[i] = mod10[i-1]*10;
        mod10[i] %= p;
    }
    //show(mod10);
    if (p == 2 || p == 5){
        ll ans = calc_num25(s, n, p);
        cout << ans << endl;
        return 0;
    }

    int modp = 0;
    map<int, int> modset;
    modset.insert({0,1});
    ll ans = 0; 
    rep(i, n){
        int num = s[n-1-i]-'0';
        modp += num * mod10[i];
        modp %= p;
        if (modset.find(modp) == modset.end()){
            modset.insert({modp, 1});
        } else {
            ans+=modset[modp];
            modset[modp]++;
        }
    }
    cout << ans << endl;


}
