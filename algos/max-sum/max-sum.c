#include <stdio.h>

void maxSum(int numArray[], int length);

int arrayLength = 9;
int numArray[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

int negLength = 3;
int negArray[3] = { -1, -2, -3 };

int main() {
    printf("MAX SUBSEQUENT SUM:\n");

    for(int i = 0; i < arrayLength; i++) {
        printf("%d ", numArray[i]);
    }
    printf("\n");
    maxSum(numArray, arrayLength);

    printf("\n");

    for(int i = 0; i < negLength; i++) {
        printf("%d ", negArray[i]);
    }
    printf("\n");
    maxSum(negArray, negLength);

    return 0;
}

void maxSum(int numArray[], int length) {

    int startIndex = -1;
    int endIndex = -1;

    int maxSum = 0;
    int thisSum = 0;

    for(int i = 0; i < length; i++) {

        // set the start and end if this is a new subarray
        if(thisSum == 0 && numArray[i] >= 0) {
            startIndex = i;
            endIndex = i;
        }

        // update the total sum
        thisSum += numArray[i];

        // the sum has gone negative so this is not a valid
        // subarray
        if(thisSum < 0) {
            thisSum = 0;
        }
        // the sum is positive and bigger so update the end index
        else if(thisSum > maxSum) {
            maxSum = thisSum;
            endIndex = i;
        }
    }

    printf("Max Sum: %d [%d, %d]\n", maxSum, startIndex, endIndex);
}
