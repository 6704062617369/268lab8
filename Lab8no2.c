#include <stdio.h>

int countNo1Correct(char ans[][10], int n);

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

    printf("No.1 correct = %d people\n", countNo1Correct(ans, 8));

    return 0;
}

int countNo1Correct(char ans[][10], int n) {

    int i, count = 0;

    for(i = 0; i < n; i++) {
        if(ans[i][0] == keys[0])
            count++;
    }

    return count;
}
