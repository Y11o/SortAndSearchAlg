#pragma once
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int binarySearch(int* array, int size, int dataToFind) {
    int left = 0;
    int right = size - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (array[mid] == dataToFind) {
            return mid;
        }
        if (array[mid] < dataToFind) left = mid + 1;
        else
        {
            right = mid - 1;
        }
    }
}

void quickSort(int* array, int low, int high)//test
{
    if (low == high) {
        throw invalid_argument("Low and high must have different indexes, ex: low = 0, high = size - 1");
    }
    else
    {
        int left = low;
        int right = high;
        int pivot = array[(left + right) / 2];
        int temp;
        while (left <= right)
        {
            while (array[left] < pivot) left++;
            while (array[right] > pivot) right--;
            if (left <= right)
            {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;
                left++;
                right--;
            }
        }
        if (right > low) quickSort(array, low, right);
        if (left < high) quickSort(array, left, high);
    }
}

void insertionSort(int *array, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void bogoSort(int* array, int size) {
    bool sorted = 0;
    while (!sorted)
    {
        sorted = true;
        for (int i = 1; i < size; i++)
        {
            if (array[i - 1] > array[i]) sorted = false;
        }
        if (sorted) break;
        for (int i = 0; i < size; i++)
        {
            swap(array[i], array[rand() % size]);
        }
    }
}

void countingSort(char* array, int size) { 
    int* countArr = new int[256];
    for (int i = 0; i < 256; i++)
    {
        countArr[i] = 0;
    }
    for (int i = 0; i < size; i++) 
    {
        countArr[array[i]]++;
    }
    int symPos = 0;
    for (int i = 0; i < 256; i++) {
        while (countArr[i]) {
            array[symPos] = i;
            symPos++;
            countArr[i]--;
        }
    }
}

void timeTest() {
    bool flag = true;
    int size, maxVal;
    int count = 0;
    float resQuick = 0;
    float resInsert = 0;
    while (flag) {
        cout << "Input arrays size." << endl;
        cin >> size;
        cout << "Input max possible value for the arrays" << endl;
        cin >> maxVal;

        int* quickArr = new int[size];
        int* insertArr = new int[size];
        for (int i = 0; i < size; i++)
        {
            quickArr[i] = insertArr[i] = rand() % maxVal;
        }

        auto startQuick = high_resolution_clock::now();
        quickSort(quickArr, 0, size - 1);
        auto endQuick = high_resolution_clock::now();
        duration<float> timeQuick = endQuick - startQuick;

        auto startInsert = high_resolution_clock::now();
        insertionSort(insertArr, size);
        auto endInsert = high_resolution_clock::now();
        duration<float> timeInsert = endInsert - startInsert;

        cout << "Quick Sort " << " spend " << timeQuick.count() << " seconds to sort array of " << size << " numbers and max value " << maxVal << endl;
        cout << "Insertion Sort " << " spend " << timeInsert.count() << " seconds to sort array of " << size << " numbers and max value " << maxVal << endl;

        count++;
        resQuick = (resQuick + timeQuick.count()) / count;
        resInsert = (resInsert + timeInsert.count()) / count;

        delete[] quickArr;
        delete[] insertArr;
        cout << "Input 0 to exit or 1 to continue" << endl;
        cin >> flag;
    }
    cout << "According to the results of " << count << "tests, " << "Quick Sort spends" << resQuick << " seconds to sort arrays." << endl;
    cout << "According to the results of " << count << "tests, " << "Insertion Sort spends" << resInsert << " seconds to sort arrays." << endl;
}