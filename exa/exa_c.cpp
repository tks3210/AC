#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<char, int> > command;
string s;
int string_num, com_num; //文字列長,命令数 
//点pが最終的にどの場所にいるか判定
int func_goal(int p)
{
    int overflag = 0;
    //printf("%d:",p);
    for(int i = 0; i < com_num; i++)
    {
        if (s[p] == command[i].first){
            p += command[i].second;
        }
        if (p < 0) {overflag = -1; break;}
        if (p >= string_num) {overflag = 1; break;}
    }
    //printf("%d\n",overflag);
    return overflag;
}

int main()
{
    cin >> string_num >> com_num;
    cin >> s;
    for(int i = 0; i < com_num; i++)
    {
        char t, d;
        int dint;
        cin >> t >> d;
        dint = (d == 'L') ? -1 : 1;
        command.push_back(make_pair(t, dint));
    }

    for(int i = 0; i < string_num; i++)
    {
        func_goal(i);
    }
    

    int left_it = 0;
    int right_it = string_num;
    while(1){
        if (right_it - left_it <= 1) break;
        int tmp_it = (left_it + right_it) /2;
        if(func_goal(tmp_it) ==  -1){
            left_it = tmp_it;
        } else {
            right_it = tmp_it;
        }
    }
    int left_limit = right_it;

    left_it = 0;
    right_it = string_num;
    while(1){
        if (right_it - left_it <= 1) break;
        int tmp_it = (left_it + right_it) /2;
        if(func_goal(tmp_it) !=  1){
            left_it = tmp_it;
        } else {
            right_it = tmp_it;
        }
    }
    int right_limit = right_it;

    int ans = 0;
   //printf("%d %d %d\n", string_num, left_limit, right_limit);
    cout << string_num - (left_limit) - (string_num - right_limit) << endl;
}

