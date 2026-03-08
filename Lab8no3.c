#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes (Declarations)
int random1to100();
int searchNum(int numAr[], int numArSize, int target);
int checkNum(int numAr[], int numArSize);
void printAr(int numAr[], int numArSize);
void best3_by_select(int score[], int best3[]);
void best3_by_sort(int score[], int best3[]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int score1[4] = {65, 80, 75, 90};
    int score2[4] = {65, 80, 75, 90};
    int best3[3];
    int i;

    // Selection method
    best3_by_select(score1, best3);
    printf("Best 3 (select):");
    for (i = 0; i < 3; i++)
        printf(" %d ", best3[i]);

    printf("\n");

    // Sorting method
    best3_by_sort(score2, best3);
    printf("Best 3 (sort):  ");
    for (i = 0; i < 3; i++)
        printf(" %d ", best3[i]);

    return 0;
}

// --- Logic Functions ---

void best3_by_select(int score[], int best3[]) {
    int i, j, max, idx;
    for (i = 0; i < 3; i++) {
        max = -1; // Initialize with a value lower than any possible score
        idx = -1;
        for (j = 0; j < 4; j++) {
            if (score[j] > max) {
                max = score[j];
                idx = j;
            }
        }
        best3[i] = max;
        if (idx != -1) score[idx] = -1; // Mark as used
    }
}

void best3_by_sort(int score[], int best3[]) {
    int i, j, temp;
    // Bubble sort to sort in descending order (highest to lowest)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4 - 1 - i; j++) {
            if (score[j] < score[j+1]) { // Use < for descending order
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
    // Pick the first 3 (which are now the highest)
    for (i = 0; i < 3; i++)
        best3[i] = score[i];
}

// --- Utility Functions ---

void printAr(int numAr[], int numArSize) {
    for (int i = 0; i < numArSize; i++)
        printf("%d ", numAr[i]);
}

int searchNum(int numAr[], int numArSize, int target) {
    for (int i = 0; i < numArSize; i++) {
        if (numAr[i] == target) return 1;
    }
    return 0;
}
