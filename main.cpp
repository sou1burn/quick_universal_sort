#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab_tp.h"

int main() {


    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    if (!in || !out) {
        printf("Error while opening file... Retry\n");
        return 0;
    }

    int n;
    fscanf_s(in, "%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation error for arr\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%d ", &arr[i]) != 1){
            printf("Cannot read elem");
            break;
        }
        //printf("%d", arr[i]);
        
    }

    quicksort(arr, compare_int, 0, n - 1, sizeof(int));

    fprintf(out, "Sorted arr of ints: \n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", arr[i]);
    }
    fprintf(out, "\n");

    int m;
    fscanf_s(in, "%d", &m);
    Person* people = (Person*)malloc(m * sizeof(Person));
    if (!people) {
        printf("Memory allocation error for people\n");
        free(arr);
        fclose(in);
        fclose(out);
        return 0;
    }

    for (int i = 0; i < m; i++) {
        if (fscanf(in, "%99s %2d\n", people[i].name, &people[i].age) !=2) {
            printf("Cannot read elem");
            break;
        }
        //printf("%s %d", people[i].name, people[i].age);
    }

    quicksort(people, compare_person, 0, m - 1, sizeof(Person));

    fprintf(out, "Sorted people: \n");
    for (int i = 0; i < m; i++) {
        fprintf(out, "%s %d\n", people[i].name, people[i].age);
    }

    fclose(in);
    fclose(out);

    free(arr);
    free(people);

    return 0;
}