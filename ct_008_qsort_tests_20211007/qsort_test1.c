#include <stdio.h>
#include <stdlib.h>

// from: /home/rgregor/OLDHDD/Dropbox/ODPRTO/_C_and_Cpp/c_qsort-in-c_20211007.txt

int comparator(const void* a, const void* b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2) {
        return -1;
    } else if (num1 == num2) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * length of an array has to be passed to function as argument
 * as array is pased to func as pointer, and it can not be 
 * computed with sizeof(array) --> it would give the length
 * of pointer, NOT the length of an array!!
 * NOTE func parameter *array = array[].
 */
void display_array(int *array, int array_len) {

    for (int i=0; i < array_len; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 6, 12, 4, 3, 5, 2, 30, 7, 9};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    printf("Arraj elements before sorting: ");
    display_array(arr, arr_len);

    /* sorting ...*/
    qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), comparator);
    printf("Array elements AFTER sorting: ");
    display_array(arr, arr_len);

    return 0;
}
