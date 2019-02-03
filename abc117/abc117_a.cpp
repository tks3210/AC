#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 

int main(){
    int n;

    cin >> n;
    vector<int> x;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());
    
    int sum = 0;
    for(int i = 0; i < n - 1; i++)
    {
        sum += x[i];
    }
    if (sum > x[x.size() - 1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}