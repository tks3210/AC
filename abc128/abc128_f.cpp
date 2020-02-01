#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n;
    cin >> n;
    vector<int> s;
    rep(i, n-1){ int tmp; cin >> tmp; s.push_back(tmp);}

    // c-1
    ll max_score = 0;
    for (int c = 1; c < n; c++)
    {
        ll score = 0;
        set<int> hasu;
        for (int x = 1; c*x < n; x++)
        {
            if ((n-1-(x*c)) <= c) break;
            int first = c*x;
            int second = n-1-first;
            if (hasu.find(first) != hasu.end()) break;
            score += s[first];       
            hasu.insert(first);
            if (hasu.find(second) != hasu.end()) break;
            score += s[second];
            hasu.insert(second);
            max_score = max(max_score, score);
        }
        
    }
    
    cout << max_score << endl;
}

