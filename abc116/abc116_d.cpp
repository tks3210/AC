#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;

int K[100001] = {0}; //各寿司の数
unsigned long long sum[100001] = {0};
int var = 0;
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
    int n, k;
    vector<pair<int, int>> p;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        //std:make_pair
        p.push_back(make_pair(tmp1, tmp2));
    }

    sort(p.begin(), p.end(), more_2nd);

    //初期評価値を導出

    vector<pair<int, int>> pp; //部分列を作成
    for (int i = 0; i < k; i++)
    {
        pp.push_back(make_pair(p[i].first, p[i].second));
    }

    unsigned long long firstsum = 0;
    for (int i = 0; i < pp.size(); i++)
    {
        if (K[pp[i].first] == 0)
            var++;
        K[pp[i].first]++;
        firstsum += (unsigned long long)pp[i].second;
    }
    sum[var] = firstsum + var * var;

    //変更
    unsigned long long ans = sum[var];
    for (int i = k; i < n; i++)
    {
        //cout << sum[var] << endl;

        //cout << pp.size();
        //cout << p[i].first << " " << p[i].second << " sum:" << sum[var] << " var:" << var <<  " K[p[i].first]:" << K[p[i].first] <<endl;
        int tmp = -1;
        sort(pp.begin(), pp.end(), more_2nd);
        for (int j = pp.size() - 1; j >= 0; j--)
        {
            //cout << "r" << j;
            //重複を検知
            if (K[pp[j].first] >= 2)
            {
                tmp = j;
            }
        }
        //重複ない場合、終わり
        if (tmp == -1)
        {
            //cout << "break" << endl;
            break;
        }

        //寿司が新種であること
        if (K[p[i].first] == 0)
        {
            //cout << "change" << endl;
            pp.erase(pp.begin() + tmp);
            pp.push_back(make_pair(p[i].first, p[i].second));
            K[tmp]--;
            K[p[i].first]++;
            var++;
            sum[var] += sum[var - 1] + (var * 2 - 1) - (pp[tmp].second - p[i].second);
            ans = max(sum[var], ans);
        }

    }

    cout << ans << endl;
}