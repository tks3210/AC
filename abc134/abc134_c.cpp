#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a_tmp, a;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a_tmp.push_back(tmp);
        a.push_back(tmp);
    }
    sort(a_tmp.begin(), a_tmp.end(), greater<int>());

    int onlyOneFlag = 1;
    if (a_tmp[0] == a_tmp[1]){
        onlyOneFlag = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if ((onlyOneFlag == 1) && a[i] == a_tmp[0]){
            cout << a_tmp[1] << endl;
        } else {
            cout << a_tmp[0] << endl;
        }
    }

}

