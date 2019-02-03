#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 

int main(){
    int n, m;

    cin >> n >> m;


    vector<int> x;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    
    if (n >= m){
        cout << "0" << endl;
        return 0;
    }


    sort(x.begin(), x.end());

    vector<pair<int, int>> dx;

    for(int i = 0; i < m - 1; i++)
    {
        dx.push_back(make_pair(x[i+1]-x[i], i));
    }
    
    sort(dx.begin(),dx.end(),greater<pair<int, int>>());

    /*
    for(auto f: dx)
    {
        cout << f.first << " " << f.second << endl;
    }
    */
    int ans = 0;

    ll minos = 0;
    for(int i = 0; i < n - 1; i++)
    {
        minos += dx[i].first;        
    }
    ans = x[x.size()-1] - x[0] - minos;

    cout << ans << endl;
}