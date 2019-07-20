#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N_box[200001];

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    // nから0を見ていく
    for (int i = n; i > 0; i--)
    {
        int tmp = 0;
        for (int j = i; j <= n; j+=i)
        {
            tmp += N_box[j];
        }
        //printf("[%d] a_left = %d a_right = %d \n", i, tmp, a[i-1]);
        if (tmp % 2 != a[i - 1]){
            N_box[i] = 1;
            b.push_back(i);
        } else {
            N_box[i] = 0;
        }
        
    }
    
    cout << b.size() << endl;
    for(auto i: b){
        cout << i << " ";
    }
    cout << endl;

}

