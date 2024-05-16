#include <iostream>

#include "lab_tp.h"

void swap(void* a, void* b, size_t size) {

    char* tmp = (char*)malloc(size);
    if (tmp == NULL) {
        fprintf(stderr, "Memory allocation error in swap\n");
        return;
    }
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);

}

int partition(void* arr, int (*cmp)(const void*, const void*), int low, int high, size_t size) {

    void* pivot = (char*)arr + high * size;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (cmp((char*)arr + j * size, pivot) < 0) {
            i++;
            swap((char*)arr + i * size, (char*)arr + j * size, size);
        }
    }
    swap((char*)arr + (i + 1) * size, (char*)arr + high * size, size);
    return i + 1;

}

void quicksort(void* arr, int (*cmp)(const void*, const void*), int low, int high, size_t size) {

    if (low < high) {
        int pi = partition(arr, cmp, low, high, size);
        quicksort(arr, cmp, low, pi - 1, size);
        quicksort(arr, cmp, pi + 1, high, size);
    }
}


int compare_int(const void* a, const void* b) {

    return (*(int*)a - *(int*)b);
}

int compare_person(const void* a, const void* b) {

    Person* person1 = (Person*)a;
    Person* person2 = (Person*)b;

    int name_cmp = strcmp(person1->name, person2->name);

    if (name_cmp == 0) {
        return person1->age - person2->age;
    }

    return name_cmp;
}

void dfs(std::vector<std::vector<int>> m, int start, std::vector<bool>& visited, std::fstream& out) {

    std::cout << start << " ";
    visited[start] = true;
    out << start << " ";
    for (int i = 0; i < m[start].size(); i++) {

        if (m[start][i] == 1 && (!visited[i])) {
            dfs(m, i, visited, out);
        }
    }

}
