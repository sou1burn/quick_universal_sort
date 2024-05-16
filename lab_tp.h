#pragma once
#include <vector>
#include <fstream>
#ifndef lab_tp_h
#define lab_tp_h
struct Person {
	char name[100];
	int age;
};
void quicksort(void* arr, int (*cmp)(const void*, const void*), int low, int high, size_t size);
int compare_int(const void* a, const void* b);
int compare_person(const void* a, const void* b);
void dfs(std::vector<std::vector<int>> m, int start, std::vector<bool>& visited, std::fstream& out);

#endif