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
    int maxVal, multiplier, testsCount;
    int size = 1;
    float resQuick = 0;
    float resInsert = 0;
    cout << "Input quantity of tests you want to run" << endl;
    cin >> testsCount;
    testsCount++;
    cout << "Input max possible value for the arrays" << endl;
    cin >> maxVal;
    cout << "Input the multiplier for the array dimension for each test" << endl;
    cin >> multiplier;
    cout << endl;
    for (int i = 1; i < testsCount; i++)
    {
        for (int j = 0; j < i; j++)
        {
            size *= multiplier;
        }
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
        cout << "Insertion Sort " << " spend " << timeInsert.count() << " seconds to sort array of " << size << " numbers and max value " << maxVal << endl << endl;

        testsCount--;
        resQuick = (resQuick + timeQuick.count()) / testsCount;
        resInsert = (resInsert + timeInsert.count()) / testsCount;
        testsCount++;

        delete[] quickArr;
        delete[] insertArr;
        size = 1;
    } 
    testsCount--;
    cout << "According to the results of " << testsCount << " tests, " << "Quick Sort spends " << resQuick << " seconds to sort arrays." << endl;
    cout << "According to the results of " << testsCount << " tests, " << "Insertion Sort spends " << resInsert << " seconds to sort arrays." << endl;
}
