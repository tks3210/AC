#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> num;
 
//素因数分解は不要で、単にMの約数を求めれば良い。
//Mの約数のうち、
int main()
{
    int N, M;
 
    cin >> N >> M;
 
    int ans = 0;
    for (int i = 1; i * i <= M; i++)
    {
        if (M % i == 0)
        {
            num.push_back(i);
            num.push_back(M/i);
        }
    }
    sort(num.begin(),num.end());
    
    for(int i = 0; i < num.size(); i++)
    {
       // printf("%d",num[i]);
        if (num[i] >= N) {
            ans = M / num[i];
            break;
        }
    }
    
    cout << ans << endl;
}