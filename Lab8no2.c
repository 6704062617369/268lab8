#include <stdio.h>

int hardestQuestion(char ans[][10], int n);

char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

int main() {

    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'},
        {'D','B','A','B','C','A','E','E','A','D'},
        {'E','D','D','A','C','B','E','E','A','D'},
        {'C','B','A','E','D','C','E','E','A','D'},
        {'A','B','D','C','C','D','E','E','A','D'},
        {'B','B','E','C','C','D','E','E','A','D'},
        {'B','B','A','C','C','D','E','E','A','D'},
        {'E','B','E','C','C','D','E','E','A','D'}
    };

    printf("Hardest question = No.%d\n",
           hardestQuestion(ans, 8) + 1);

    return 0;
}

int hardestQuestion(char ans[][10], int n) {

    int correct[10] = {0};
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < 10; j++) {
            if(ans[i][j] == keys[j])
                correct[j]++;
        }
    }

    int min = correct[0];
    int idx = 0;

    for(i = 1; i < 10; i++) {
        if(correct[i] < min) {
            min = correct[i];
            idx = i;
        }
    }

    return idx;
}
