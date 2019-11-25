#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define S 20
#define T 20
int dp_1[S][T] = {0};
int dp_2[S][T][2] = {0};
int dp_3[S][T] = {0};

int dp_sumCommonPartString(string s , string t){
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j]){
                dp_3[i + 1][j + 1] = dp_3[i][j + 1] + dp_3[i + 1][j] + 1;
            } else {
                dp_3[i + 1][j + 1] = dp_3[i][j + 1] + dp_3[i + 1][j] - dp_3[i][j];
            }
            printf("[%d][%d]:%d ", i, j, dp_3[i + 1][j + 1]);
        }
        printf("\n");
    }
    return dp_3[s.size()][t.size()];
}



//input 二つの文字列, output 一致部分列の長さ(飛び飛びの部分列を許容する。)
int dp_commonPartString(string s, string t){
    //dp[0][*], dp[*][0]は値0の空間として使用
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j]){
                dp_1[i + 1][j + 1] = dp_1[i][j] + 1;
            } else {
                dp_1[i + 1][j + 1] = max(dp_1[i][j + 1], dp_1[i + 1][j]);
            }
            printf("[%d][%d]:%d ", i, j, dp_1[i + 1][j + 1]);
        }
        printf("\n");
    }
    return dp_1[s.size()][t.size()];
}

//input 二つの文字列, output 一致部分列の長さ(飛び飛びの部分列を許容しない。)
int dp_commonAreaString(string s, string t){
    //dp[0][*], dp[*][0]は値0の空間として使用
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if(s[i] == t[j]){
                if (dp_2[i][j][1] == 0){
                    dp_2[i + 1][j + 1][0] = dp_2[i][j][0] + 1;
                } else {
                    dp_2[i + 1][j + 1][0] = 1;
                }
            } else {
                dp_2[i + 1][j + 1][1] = 1;
                dp_2[i + 1][j + 1][0] = max(dp_2[i][j + 1][0], dp_2[i + 1][j][0]);
            }
            ans = max(ans, dp_2[i + 1][j + 1][0]);
            printf("[%d][%d]:%d ", i, j, dp_2[i + 1][j + 1][0]);
        }
        printf("\n");
    }
    return ans;
}


int main(){
    //s:125643
    //t:24638
    string s = "23456";
    string t = "24546";
//    cin >> t;
    
    cout << "s: "<< s << ",t: "<< t << endl;
    cout << dp_commonPartString(s, t) << endl;    
    cout << dp_commonAreaString(s, t) << endl;    
    cout << dp_sumCommonPartString(s, t) + 1 << endl;  
}