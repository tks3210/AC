#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> x;
    for(int i = 0; i < 5; i++)
    {
        ll tmp;
        cin >> tmp;
        x.push_back((n - 1)/tmp + 1);
    }
    
    cout << *max_element(x.begin(), x.end()) + 4 << endl;
}

