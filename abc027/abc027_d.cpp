#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
#define abs(a) ((a) < 0 ? -(a) : (a))
int HP = 0;
void calcHp(int It, int Rpos, int Mzan, int Hpoint){
    if (It == s.size()) { 
        //printf("point:%d, Rpos:%d\n", Hpoint,Rpos);
        if (HP <= Hpoint){
            HP = Hpoint;
        }
        return;
    } 
    //printf("It%d,Rp%d,Mz%d,Hp%d,Ssize%d\n",It,Rpos,Mzan,Hpoint,s.size());
    if (s[It] == '+') {
        calcHp(It + 1, Rpos, Mzan, Hpoint + Rpos);
    } else if (s[It] == '-'){
        calcHp(It + 1, Rpos, Mzan, Hpoint - Rpos);
    } else {
        if (Mzan - 1 <= abs(Rpos)){
            if (Rpos > 0){
                calcHp(It + 1, Rpos - 1, Mzan - 1, Hpoint);
            } else {
                calcHp(It + 1, Rpos + 1, Mzan - 1, Hpoint);
            }
        }else{
            calcHp(It + 1, Rpos + 1, Mzan - 1, Hpoint);
            calcHp(It + 1, Rpos - 1, Mzan - 1, Hpoint);
        }
    }

}


int main(){
    cin >> s;

    int Mcnt = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'M') Mcnt++;
    }

    calcHp(0, 0, Mcnt, 0);

    cout << HP << endl;
}

