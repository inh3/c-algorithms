#include <stdio.h>
#include <stack>

typedef struct {
    int x;
    int y;
} GridPos;

void floodFill(bool[5][5], int xSize, int ySize, int xStart, int yStart);

bool gridToFill[5][5] = {
    { false,  false,  false,  false,  false },
    { true,   true,   false,  true,   true  },
    { true,   false,  true,   false,  true  },
    { true,   false,  false,  false,  true  },
    { true,   true,   true,   false,  true  }
};

int main() {

    printf("POLYFILL BEFORE:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%u ", gridToFill[i][j]);
        }
        printf("\n");
    }

    int xStart = 0;
    int yStart = 0;
    printf("START: x(%d), y(%d) %u\n", xStart, yStart, gridToFill[yStart][xStart]);
    floodFill(gridToFill, 5, 5, xStart, yStart);

    printf("POLYFILL AFTER:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%u ", gridToFill[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void floodFill(bool[5][5], int xSize, int ySize, int xStart, int yStart) {

    std::stack<GridPos> gridPosStack;

    gridPosStack.push((GridPos){ xStart, yStart });

    while(!gridPosStack.empty()) {

        GridPos gridPos = gridPosStack.top();
        gridPosStack.pop();

        if(gridToFill[gridPos.y][gridPos.x] == false) {

            // fill the position
            gridToFill[gridPos.y][gridPos.x] = true;

            // east
            if(gridPos.x + 1 < xSize) {
                gridPosStack.push((GridPos){ gridPos.x + 1, gridPos.y });
            }
            // west
            if(gridPos.x - 1 >= 0) {
                gridPosStack.push((GridPos){ gridPos.x - 1, gridPos.y });
            }
            // north
            if(gridPos.y + 1 < ySize) {
                gridPosStack.push((GridPos){ gridPos.x, gridPos.y + 1});
            }
            if(gridPos.y - 1 >= 0) {
                gridPosStack.push((GridPos){ gridPos.x, gridPos.y - 1});
            }
        }
    }
}
