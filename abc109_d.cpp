#include <iostream>
using namespace std;

int main(){
    int H, W;
    int Num[500][500];

    cin >> H >> W;

    for (int i= 0; i < H; i++){
        for (int j=0; j < W; j++){
            cin >> Num[i][j];
            Num[i][j] = Num[i][j] % 2;
        }
    }

    struct movebox{
        int setflag = 0;
        int oddflag = 0;
        int befgyou, aftgyou;
        int befretu, aftretu;
    };
    struct movebox box[125000];
    int argbox=0;
    for (int i= 0; i < H; i++){
        for (int j=0; j < W; j++){
            if (Num[i][j] == 1){
                if (box[argbox].oddflag == 0){
                    box[argbox].befgyou = i;
                    box[argbox].befretu = j;
                    box[argbox].oddflag = 1;                    
                } else {
                    box[argbox].aftgyou = i;
                    box[argbox].aftretu = j;
                    box[argbox].setflag = 1;
                    argbox++;
                }
            }
        }
    }
    for (int i=0; i <= argbox; i++){
        cout << box[argbox].befgyou << box[argbox].befretu << box[argbox].aftgyou << box[argbox].aftretu << endl;
    }
}