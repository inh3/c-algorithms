#include <stdio.h>

void maxSum(int numArray[], int length);

int arrayLength = 9;
int numArray[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

int negLength = 3;
int negArray[3] = { -1, -2, -3 };

int valleyLength = 3;
int valleyArray[3] = { 6, -7, 5 };

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

    for(int i = 0; i < valleyLength; i++) {
        printf("%d ", valleyArray[i]);
    }
    printf("\n");
    maxSum(valleyArray, valleyLength);

    return 0;
}

void maxSum(int numArray[], int length) {

    int tempStartIndex = -1;
    int startIndex = -1;
    int endIndex = -1;

    int maxSum = 0;
    int thisSum = 0;

    for(int i = 0; i < length; i++) {

        // this could be the start of a new subarray because
        // the sum is at 0 and the value is above 0
        if(thisSum == 0 && numArray[i] >= 0) {
            tempStartIndex = i;
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
            startIndex = tempStartIndex;
            maxSum = thisSum;
            endIndex = i;
        }
    }

    printf("Max Sum: %d [%d, %d]\n", maxSum, startIndex, endIndex);
}
