#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, p;
    scanf("%d", &N);
    
    int x[500000];
    int y[500000];
    int t[500000];
    int pl[500000] = {0};  // 배열을 0으로 초기화
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &x[i], &y[i], &t[i]);
    }
    
    for (int j = 0; j < N; j++) {
        if (t[j] == 1) {
            if (j >= 1){ //하나의 조합을 찾기 위한 분기점점
                for (int c = 0; c < N; c++){
                    if (x[j] == x[c] && j != c){
                        p = abs(y[j] - y[c]);
                        if(p > pl[j]){
                            pl[j] = p;
                        }
                    }
                }
            }
            else{
                for (int k = 0; k < N; k++) {
                    if (y[j] == y[k] && j != k) {
                        p = abs(x[j] - x[k]); // x 좌표
                        if (p > pl[j]) {
                            pl[j] = p;
                        }
                    }
                }   
            }
        } else { //t[j]가 0인 경우.
            for (int l = 0; l < N; l++) {
                if (x[j] == x[l] && j != l) {
                    p = abs(y[j] - y[l]); // y 좌표
                    if (p > pl[j]) {
                        pl[j] = p;
                    }
                }
            }
        }
    }
    
    for (int z = 0; z < N; z++) {
        printf("%d\n", pl[z]);
    }
    
    return 0;
}
