#include <stdio.h>
#include <stdlib.h>

// from: /home/rgregor/OLDHDD/Dropbox/ODPRTO/_C_and_Cpp/c_qsort-in-c_20211007.txt

typedef struct {
    int date;
    const char* fname;
} Movie;

int comparator(const void* a, const void* b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return (movie1->date - movie2->date);
}

/*
 * length of an array has to be passed to function as argument
 * as array is pased to func as pointer, and it can not be 
 * computed with sizeof(array) --> it would give the length
 * of pointer, NOT the length of an array!!
 * NOTE func parameter *array == array[].
 */
void display_array(Movie *array, int array_len) {
    for (int i=0; i < array_len; i++) {
        printf("%-10d%s\n", array[i].date, array[i].fname);
    }
    printf("\n");
}

int main() {
    const int N = 6;
    Movie array[N];

    // populate the array
    array[0].date = 20201231;
    array[0].fname = "a-filename-with-number_20201231.txt";
    array[1].date = 20181231;
    array[1].fname = "a-filename-with-number_20181231.txt";
    array[2].date = 20211231;
    array[2].fname = "a-filename-with-number_20211231.txt";
    array[5].date = 20001231;
    array[5].fname = "a-filename-with-number_20001231.txt";
    array[4].date = 19951231;
    array[4].fname = "a-filename-with-number_19951231.txt";
    array[3].date = 20220222;
    array[3].fname = "a-filename-with-number_20220222.txt";
    
    // calculate array length
    int arr_len = sizeof(array) / sizeof(array[0]);


    printf("BEFORE sorting by date:\n");
    display_array(array, arr_len);


    qsort(array, N, sizeof(Movie), comparator);
    
    printf("AFTER sorting by date:\n");
    display_array(array, arr_len);

    return 0;
}
