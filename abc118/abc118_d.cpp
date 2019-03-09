#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int match_num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int match_enable[10] = {0};

bool more_2nd(pair<int, int> one, pair<int, int> ano)
{
    if (one.second != ano.second)
    {
        return one.second > ano.second;
    }
    else
    {
        return one.first > ano.first;
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(make_pair(match_num[tmp], tmp));        
    }

    sort(a.begin(), a.end());

    for(auto x: a)
    {
        cout << x.second << endl;
    }
    
    int basenum = a[0].second;
    int keta = n / a[0].first;
    int amari = n % a[0].first;
    //sort(a.begin(), a.end(), more_2nd);
    
    for(int i = 1; i < m; i++)
    {
        if (amari == 1){
            
        }

    }
    


}