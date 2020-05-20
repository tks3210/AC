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

class SegTree {
    vector<int> a;
    int trsize = 0;
    int lvsize = 0;
public:
    SegTree(vector<int> &in){
        int n = in.size();
        int bit = 0;
        while(1){
            if ((1<<bit) >= n){
                break;
            }
            bit++;
        }
        lvsize = 1<<bit;
        trsize = lvsize*2-1;
        a = vector<int>(trsize);
        rep(i, in.size()) a[(trsize/2)+i] = in[i];
        for (int i = (trsize/2)-1; i >= 0; i--)
        {
            a[i] = min(a[i*2+1], a[i*2+2]);
        }        
    }

    void update(int node, int val){
        if (node < 0) return;
        int targ = node + (trsize/2);
        if (targ >= trsize) return;
        a[targ] = val;
        do{
            targ--;
            targ/=2;
            a[targ] = min(a[targ*2+1], a[targ*2+2]);
        }while(targ > 0);
 
    }

    int search(int sl, int sr){
        cout << sl << sr << endl;
        return search_query(0, lvsize, sl, sr, 0);
    }

    int search_query(int l, int r, int sl, int sr, int k){
        if (r <= sl || sr <= l){
            return MOD;
        } else if (sl <= l && r <= sr) {
            return a[k];
        } 
        int h_1 = search_query(l, (l+r)/2, sl, sr, k*2+1);
        int h_2 = search_query((l+r)/2, r, sl, sr, k*2+2);
        return min(h_1, h_2);
    }

    void Show(){
        cout << trsize << endl;
        rep(i, trsize) cout << a[i] << " ";
        cout << endl;
    }

private:


};

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    SegTree st(a);

    st.Show();
    cout << st.search(0,3) << endl;
    cout << st.search(1,2) << endl;
    cout << st.search(6,8) << endl;
    cout << st.search(0,8) << endl;

    return 0;
}

/*
init
data列のサイズを調べる
2の累乗でギリギリこえるとこまで確保
size/2 からpushする。
size/2-1から0まで順番に求めていく

update
子、親をたどって更新する

search
区間を指定する



*/