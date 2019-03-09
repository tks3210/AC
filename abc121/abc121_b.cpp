#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
 
int main(){
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b;
    vector<int> a[21]; 
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        b.push_back(tmp);       
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            a[i].push_back(tmp);       
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int score = 0;
        for(int j = 0; j < m; j++)
        {
            score += a[i][j]*b[j];
        }
 
        score += c;
        if (score > 0) ans++;
    }
    
    cout << ans;
}