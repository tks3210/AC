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



vector<int> step(2010, 0);

void bfs(int st,  vector<vector<int>>& line){

    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int now = q.front();
        for (auto next: line[now])
        {
            if (step[next] != 0) continue;
            q.push(next);
            step[next] = step[now] + 1;
        }
        q.pop();
    }

}


int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> k(n);
    vector<vector<int>> line(n);
    rep(i, n-1){ 
        line[i].push_back(i+1);
        line[i+1].push_back(i);
    }
    line[x-1].push_back(y-1);
    line[y-1].push_back(x-1);

    rep(i, n){
        step = vector<int>(n, 0);
        bfs(i, line);
        for (int j = i+1; j < n; j++)
        {
            k[step[j]]++;
        }
    }

    rep(i, n-1){
        cout << k[i+1] << endl;
    }
}

