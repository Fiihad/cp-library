#include <bits/stdc++.h>
using namespace std;

int h, w, **out;
char **ara;

void marking(int x, int y, int mode=0)
{
    if (ara[x][y]=='#' || x>=h || y>=w || x<0 || y<0) return;
    out[x][y]=1;

    if (mode != 2 || out[x][y+1] == 0) marking(x, y+1, 1);
    if (mode != 1 || out[x][y-1] == 0) marking(x, y-1, 2);
    if (mode != 4 || out[x-1][y] == 0) marking(x-1, y, 3);
    if (mode != 3 || out[x+1][y] == 0) marking(x+1, y, 4);
}

int main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int ini, inj, count=0;
        cin >> w >> h;
        ara = (char**)malloc(h*sizeof(char*));
        out = (int**)malloc(h*sizeof(int*));
        for(int i=0; i<h; i++){
            ara[i] = (char*)malloc(w*sizeof(char));
            out[i] = (int*)calloc(w, sizeof(int));
        }

        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                scanf(" %c", &ara[i][j]);
                if (ara[i][j] == '@'){
                    ini = i;
                    ini = j;
                }
            }
        }
        
        marking(ini, inj);

        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++)
                if (out[i][j]) count++;
        }
        
        for (int i=0; i<h; i++){
            free(ara[i]);
            free(out[i]);
        }
        free(ara);
        free(out);
        
        cout << "Case " << cases << ": " << count << endl;
    }
    return 0;
}