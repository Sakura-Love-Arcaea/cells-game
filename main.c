#include <stdio.h>
#include <ctype.h>
#define N 10

int table[N][N] = {
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 1, 0, 0, 0, 1, 1}
};
int newtable[N][N];
int generation;//第幾代

void init() {
    // for (int row = 0; row < N; row++) {
    //     for (int column = 0; column < N; column++) {
    //         table[row][column] = 0;
    //     }
    // }

}

int neighbors(int row, int column) {
    int count = 0;
    for (int rowShift = -1; rowShift <= 1; rowShift++) {
        for (int columnShift = -1; columnShift <= 1; columnShift++) {
            if (row + rowShift < 0 || row + rowShift > N || column + columnShift < 0 || column + columnShift > N ) {
                continue;
                }
            if (table[row + rowShift][column + columnShift] == 1) {
                count++;
            }
        }
    }
    if (table[row][column] == 1) {
        count--;
    }
    return count;
}
void outputMap() {
    printf("----------%d-----------\n", generation);
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
        if (table[row][column] == 0) {
            printf("⬜️");
        }else {
            printf("🟪");
        }
        // printf("%d", table[row][column]);
        // if (column == N-1) {
        //     printf("\n");
        // }else {
        //     printf(" ");
        // }
        // }
    }
    printf("\n");
    }
}
void overWrite() {
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            table[row][column] = newtable[row][column];
        }
    }
    generation++;
}
int main() {
    init();
    outputMap();
    
    for (int i = 0; i < 20; i++) {
        for (int row = 0; row < N; row++) {
            for (int column = 0; column < N; column++) {
                int p = neighbors(row, column);
                if (p <= 1) {
                    newtable[row][column] = 0;
                } else {
                    if (p >= 4) {
                    newtable[row][column] = 0;
                    } else {
                        if (p == 2) {
                            newtable[row][column] = table[row][column];
                        }else {
                            newtable[row][column] = 1;
                        }
                    }
                }
                
                
                
        }
    }
    overWrite();
    outputMap();
    }
    
    return 0;
}