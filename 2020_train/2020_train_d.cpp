#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){ a[i] = i*i; }

    show(a);
    rep(i, 30){
        //i以上の要素のイテレータが返却される。
        auto itr = lower_bound(a.begin(), a.end(), i); 
        //要素番号として取り出す(x <= a.size())
        int x = itr - a.begin();
        // x=a.size()のとき、解なし（a.size()が0のときも含まれる）
        cout << i << ":" << x << endl;
    }

    struct box{
        int x, y, z;
        box(int x, int y, int z): x(x), y(y), z(z){}
        int sum() const{
            return x*y*z;
        }
    };

    //boxのコンストラクタが定義されている場合は初期化が必要
    vector<box> b(n, {0,0,0});
    rep(i, n){
        b[i].x = i+2;
        b[i].y = (5-i)*(5-i)+1;
        b[i].z = i%3 + 1;
    }

    auto cmp = [](const box &a, const box &b){
        // const box型なのでsum()を呼び出す際にconstが必要
        return a.sum() > b.sum();
    };

    rep(i, n) cout << b[i].x << ":" << b[i].y << ":" << b[i].z << ":::" << b[i].sum() << endl;
    sort(b.begin(), b.end(), cmp);
    rep(i, n) cout << b[i].x << ":" << b[i].y << ":" << b[i].z << ":::" << b[i].sum() << endl;

    box bt(3, 4, 5); 
    int x = lower_bound(b.begin(), b.end(), box{2,8,3}, cmp) - b.begin();
    cout << x << endl;

    

}

