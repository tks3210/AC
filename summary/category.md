# graph
## 木の探索
* 幅優先探索ならqueue、深さ優先探索なら再起関数(or stack)を使う
* queueの場合開始点を入れてwhileで回す
* 再起関数の場合は下記を注意して作成する
    * 葉に到達したとき終端すること
        * visited[N]を使って、visited[next] = trueの場合弾く
        * parentを引数(orグローバル変数)に持ち、next = parentであれば弾く
            * 閉路がある場合無限ループに陥るので注意
    * 親要素との関連で値を書き換える必要があるとき
        * 親側の関数内で子側(next)の要素を書き換えるのが良い
        * 子側の関数内で行おうとすると、親が誰かを参照する必要
## 有向グラフの探索

## 無向グラフの探索

## 重み付きグラフの探索
* 辺を表す隣接リスト表現の際に、下記のように二要素で表すのがポイント
```c++
vector<P> root[N_OVERSIZE];
```
* 混乱しそうなときは、構造体で管理するのもbetter(abc152_f)
```c++
struct Edge{
    int to, id;
    Edge(int to, int id): to(to), id(id){} 
};

rep(i, n-1){
    int tmpa, tmpb; cin >> tmpa >> tmpb;
    tmpa--; tmpb--;
    edge[tmpa].emplace_back(tmpb, i);
    edge[tmpb].emplace_back(tmpa, i);
}    
```


# dp
## 問題
* abc129_e(桁dp)
## 基本
* 状態を定める
* 推移条件を定める
* 初期値を定める

### 桁dp
* A ^ B = A + B <= L となるA,Bの組み合わせ列挙
* Example: 上位bitから見ていき、A+B < L となることが確定するか否かで分離
    * dp[i][0]: 上位ibit目における二種の組み合わせの数(ibit目までの比較でA+B < L)
    * dp[i][1]: 上位ibit目における二種の組み合わせの数(ibit目までの比較でA+B=L)
* xor 系の比較問題系は、前の数が比較値を下回っていたか否かでdp組むパターンが多い


# Union Found Tree
## 問題
* abc126_e
* abc097_d

## 用途(検討中)
* 単純なグルーピングがしたいとき
* 制限が与えられる問題に対して応用ができる(abc126_e)

## code
```c++
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
```

## 基本
* 宣言(UnionFind tree(n))
* 結合(tree.unite(a,b))
* 根の取得(tree.root(a))
* 同一グループの判定(tree.same(a,b))
* グループ数の判定
    * tree.root(a)をset型配列に入れる(abc126_e)
* グループ内の人数の判定

# xor
## 問題
* abc126_f
* abc129_e
## 基本
* [0, 2^M) の排他的論理和は0
* 逆元が同一
    * cを足すという処理と、cを引くという処理が同一
    * [0, 2^M) の順列からcをひいた排他的論理和はcとなる
* A xor B = A + B < l となる場合の数
    * 各bitが双方1でない


# しゃくとり法
長さnの数列において、
* 「条件」を満たす区間のうち、最小・最大の長さを求める
* 「条件」を満たす区間を数え上げよ
## 問題
* abc130_d
## 基本
* 数列の区間考えるときは半開区間をイメージする
    * [0, 3) = a[0] + a[1] + a[2]
    * [0, 3) = sum[3] - sum[0]
        * sum[i] = a[0] + ... + a[i-1]
        * sum[0] = 0
* 数列がa1から始まる場合もa0で考え直すほうが良い

https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
```c++
    /* 区間の左端 left で場合分け */
    int right = 0;     // 毎回 right を使い回すようにする
    long long sum = 0; // sum も使い回す
    for (int left = 0; left < n; ++left) {
        /* sum に a[right] を加えても大丈夫なら right を動かす */
        while (right < n && sum + a[right] <= x) {
            sum += a[right];
            ++right;
        }

        /* break した状態で right は条件を満たす最大 */
        res += (right - left);

        /* left をインクリメントする準備 */
        if (right == left) ++right; // right が left に重なったら right も動かす
        else sum -= a[left]; // left のみがインクリメントされるので sum から a[left] を引く
    }
```
### ユースシーン

　
### 方法
* 区間の開始地点を固定し、終了地点を条件を満たす範囲で動かす
* 区間の開始地点を1増やす。

# 総和計算
## 問題
* abc127_e : マンハッタン距離の座標分解


# データ構造応用
## 問題
* abc127_f
## 中央値のO(logn)参照
* priority_queueの昇順、降順を二個遣い
* 昇順側の最小値と降順側の最大値を比較して後者が大きければ入れ替える
## priority_queueの優先順位付け
* 
```c++
auto compare = [](const info_0s& a, const info_0s& b){ 
    if (a.time == b.time){
        return a.point < b.point;
    } else {
        return a.time > b.time;
    }
};
priority_queue<info_0s, vector<info_0s>, decltype(compare)> info(compare);
```
## set型で数字が既に存在するかを確認
```c++
set<int> s;
if (s.find(key) != s.end()){
    //exist
}
```
# bit
## 問題
* abc128_c
## 基本
* 各bitで状態を表すときは下記のようなloop文を作る
    * 3状態あるとややこしい(kadomatsu)
```c++
    rep(i, 1<<n){
        rep(j, m){
            for(auto sw: s[j]){
                if (i>>sw & 1) right += 1;
            }
        }
    }
```