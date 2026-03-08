#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random1to100();
int searchNum(int numAr[], int numArSize, int target);
int checkNum(int numAr[], int numArSize);
void printAr(int numAr[], int numArSize);
void best3_by_select(int score[], int best3[]);
void best3_by_sort(int score[], int best3[]);

int main() {
    srand(time(NULL));

    int score1[4] = {65, 80, 75, 90};
    int score2[4] = {65, 80, 75, 90};
    int best3[3];
    int i;

    best3_by_select(score1, best3);
    printf("Best 3 (select):");
    for (i = 0; i < 3; i++)
        printf(" %d ", best3[i]);

    printf("\n");

    best3_by_sort(score2, best3);
    printf("Best 3 (sort):  ");
    for (i = 0; i < 3; i++)
        printf(" %d ", best3[i]);

    return 0;
}

void best3_by_select(int score[], int best3[]) {
    int i, j, max, idx;
    for (i = 0; i < 3; i++) {
        max = -1;
        idx = -1;
        for (j = 0; j < 4; j++) {
            if (score[j] > max) {
                max = score[j];
                idx = j;
            }
        }
        best3[i] = max;
        if (idx != -1) score[idx] = -1;
    }
}
void best3_by_sort(int score[], int best3[]) {
    int i, j, temp;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4 - 1 - i; j++) {
            if (score[j] < score[j + 1]) {
                temp = score[j];
                score[j] = score[j + 1];
                score[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 3; i++)
        best3[i] = score[i];
}

int searchNum(int numAr[], int numArSize, int target) {
    for (int i = 0; i < numArSize; i++) {
        if (numAr[i] == target) return 1;
    }
    return 0;
}

int random1to100() {
    return (rand() % 100) + 1;
}

int checkNum(int numAr[], int numArSize) {
    int rnum = random1to100();
    while (searchNum(numAr, numArSize, rnum)) {
        rnum = random1to100();
    }
    return rnum;
}

void printAr(int numAr[], int numArSize) {
    for (int i = 0; i < numArSize; i++)
        printf("%d ", numAr[i]);
}
