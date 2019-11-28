#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;




int cldnum[100001] = {0};


int main()
{
    string s;
    cin >> s;

    int rflag = 1;
    int lflag = 0;
    int blocknum = 0;
    int lpos;
    s.push_back('R');
    for (int i = 1; i < s.size(); i++)
    {
        if (rflag > 0){
            if (s[i] == 'R'){
                rflag++;
            } else {
                blocknum += rflag;
                rflag = 0;
                lflag = 1;
                lpos = i;
            }
        } else {
            if (s[i] == 'R'){
                blocknum += lflag;
                lflag = 0;
                rflag = 1;
                if (blocknum % 2 == 0){
                    cldnum[lpos] = blocknum / 2;
                    cldnum[lpos - 1] = blocknum / 2;
                } else {
                    if (((lpos - i) % 2) == 0){                        
                        cldnum[lpos] = blocknum / 2;
                        cldnum[lpos - 1] = blocknum / 2 + 1;
                    } else {        
                        cldnum[lpos] = blocknum / 2 + 1;
                        cldnum[lpos - 1] = blocknum / 2;
                    }
                }
                blocknum = 0;
            } else {
                lflag++;
            }
        }
    }

    for (int i = 0; i < s.size() - 1; i++){
            cout << cldnum[i] << " ";
    }
    cout << endl;
}

