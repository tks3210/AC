#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    vector<int> d;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        d.push_back(tmp);
    }

    sort(d.begin(), d.end());

    cout << d[n/2] - d[n/2 - 1] << endl;

}

