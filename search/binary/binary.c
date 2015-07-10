#include <queue>
#include <stdio.h>
using namespace std;

vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8 };

int binaryIterative(int numberToFind);

int main() {
    printf("Binary Search!\n");

    for(int i = 0; i < numbers.size(); i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    printf("Find '3': %d\n", binaryIterative(3));
    printf("Find '6': %d\n", binaryIterative(6));
    printf("Find '11': %d\n", binaryIterative(11));
    printf("Find '0': %d\n", binaryIterative(0));

    return 0;
}

int binaryIterative(int numberToFind) {

    int start = 0;
    int end = numbers.size();

    while(start <= end) {

        int mid = (end + start) / 2;
        //printf("value: %d (%d)\n", numbers[mid], mid);

        if(numbers[mid] == numberToFind) {
            return mid;
        }

        if(numbers[mid] > numberToFind) {
            end = mid - 1;
        }
        else if(numbers[mid] < numberToFind) {
            start = mid + 1;
        }

        //printf("s: %d e: %d\n", start, end);
    }

    return -1;
}
