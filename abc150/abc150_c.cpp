#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

int n;
vector<string> dic;
void fds(int bitinfo, string s){
    if (s.size() == n){
        dic.push_back(s);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!((bitinfo >> (i-1)) & 1)){
          string t = s + to_string(i);
          int nextbit = bitinfo + (1 << (i-1));
          fds(nextbit, t);
        } 
    }
}

void perm(){
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    do {
        string s;
        for (auto x : v) s += to_string(x);
        dic.push_back(s);
    } while (next_permutation(v.begin(), v.end()) );
}


int main()
{
    cin >> n;
    //fds(0, "");
    perm();
    sort(dic.begin(), dic.end());
    //show(dic);
    string s,t;
    rep(i, n) {int tmp; cin >> tmp; s += to_string(tmp);}
    rep(i, n) {int tmp; cin >> tmp; t += to_string(tmp);}

    int s_itr, t_itr;
    // for (int i = 0; i < dic.size(); i++)
    // {
    //     if (s == dic[i]) s_itr = i;
    //     if (t == dic[i]) t_itr = i;
    // }
    
    s_itr = lower_bound(dic.begin(), dic.end(), s) - dic.begin();
    t_itr = lower_bound(dic.begin(), dic.end(), t) - dic.begin();

    cout << abs(s_itr - t_itr) << endl;

}

