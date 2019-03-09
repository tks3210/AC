#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;


int take_box[8] = {0};
int sum_take[3] = {0};

int main(){
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> l;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        l.push_back(tmp);
    }
    

    int loop = 1 << (n*2);
    //cout << loop << endl;

    
    int ans = 1 << 16;
    for(int i = 0; i < loop; i++)
    {
        int unused_cnt = 0;
        int score = 0;
        int tmp = i;
        sum_take[0] = 0;
        sum_take[1] = 0;
        sum_take[2] = 0;
        for(int j = 0; j < n; j++)
        {
            take_box[j] = (tmp >> (j*2)) % 4;
        }
        for(int j = 0; j < n; j++)
        {
            if (take_box[j] == 3){
                unused_cnt++;
                continue;    
            }    
            sum_take[take_box[j]] += l[j];
        }
        if (sum_take[0] == 0 || sum_take[1] == 0 || sum_take[2] == 0){
            continue;
        }
        score += sum_take[0] > a ? sum_take[0] - a : a - sum_take[0];
        score += sum_take[1] > b ? sum_take[1] - b : b - sum_take[1];
        score += sum_take[2] > c ? sum_take[2] - c : c - sum_take[2];
        score += (n - unused_cnt - 3 ) * 10;
        ans = min(score, ans);
    }

    cout << ans << endl;
}