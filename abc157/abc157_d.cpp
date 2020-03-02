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

struct UnionFind{

	std::vector<int> data;
	// dataの各要素について
	// 負の値:その集合のルートであること示す。また、その絶対値は集合の要素数となっている。
	// 正の値:親ノードの番号(dataのインデックス)。root()を呼び出すたびに集合のルートを指すように書きなおされるので木はそんなに深くならない

	//初期化 size:最大要素数
	UnionFind(int size): data(size, -1) {}
	
	// 集合を併合する
	// すでに同じ集合だった場合は、falseが返る
	bool unite(int x, int y){
		x=root(x);
		y=root(y);
		if( x != y ){
			// 要素数の大きな方へ合併するためのswap
			if( data[y] < data[x] ) std::swap(x, y);
			// 要素数を加算する
			data[x] += data[y];
			// yの属する集合のルートをxに変更
			data[y] = x;
		}
		return x!=y;
	}

	// 同じ集合かどうか判定
	bool find(int x, int y){
		return root(x) == root(y);
	}

	// 集合の識別番号を返す
	int root(int x){
		// 負の値を持つものがその集合のルート
		// 正の値は同じ集合に属するものを指す(辿ればいずれルートへ着く)
		return (data[x] < 0)? x : data[x]=root(data[x]);
	}

	// 集合の要素数を返す
	int size(int x){
		return -data[ root(x) ];
	}
};

#define NUM_MAX  100050
int node_minus[NUM_MAX] = {0}; //引く数を規定

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<P> ab(m);
    vector<P> cd(k);

    rep(i, m) {cin >> ab[i].first >>ab[i].second;}
    rep(i, k) {cin >> cd[i].first >>cd[i].second;}

    UnionFind uf(n+1);

    rep(i, m){
        uf.unite(ab[i].first, ab[i].second);
        node_minus[ab[i].first]++;
        node_minus[ab[i].second]++;
    }

    rep(i, k){
        if (uf.root(cd[i].first) == uf.root(cd[i].second)){
            node_minus[cd[i].first]++;
            node_minus[cd[i].second]++;
        }
    }

    rep(i, n){
        int id = i+1;
        cout << uf.size(id) - node_minus[id] - 1 << " ";
    }

}

