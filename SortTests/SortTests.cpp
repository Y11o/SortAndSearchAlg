#include "pch.h"
#include "CppUnitTest.h"
#include "../SearchAndSort/SortAndTimeTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortTests
{
	TEST_CLASS(SortTests)
	{
	public:
		
		TEST_METHOD(BinarySearchTest)
		{
			int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			Assert::IsTrue(binarySearch(arr, 10, 7) == 6);
		}

		TEST_METHOD(QuickSort)
		{
			int arr[] = { 145, 33, 21, 67, 12, 5, -7 };
			quickSort(arr, 0, 6);
			Assert::IsTrue(arr[0] == -7);
			Assert::IsTrue(arr[1] == 5);
			Assert::IsTrue(arr[2] == 12);
			Assert::IsTrue(arr[3] == 21);
			Assert::IsTrue(arr[4] == 33);
			Assert::IsTrue(arr[5] == 67);
			Assert::IsTrue(arr[6] == 145);
		}

		TEST_METHOD(InsertionSortTest)
		{
			int arr[] = { 145, 33, 21, 67, 12, 5, -7 };
			insertionSort(arr, 7);
			Assert::IsTrue(arr[0] == -7);
			Assert::IsTrue(arr[1] == 5);
			Assert::IsTrue(arr[2] == 12);
			Assert::IsTrue(arr[3] == 21);
			Assert::IsTrue(arr[4] == 33);
			Assert::IsTrue(arr[5] == 67);
			Assert::IsTrue(arr[6] == 145);
		}

		TEST_METHOD(BogoSortTest)
		{
			int arr[] = {-100, 21, 2, 11, 1007, 993, 13};
			bogoSort(arr, 7);
			Assert::IsTrue(arr[0] == -100);
			Assert::IsTrue(arr[1] == 2);
			Assert::IsTrue(arr[2] == 11);
			Assert::IsTrue(arr[3] == 13);
			Assert::IsTrue(arr[4] == 21);
			Assert::IsTrue(arr[5] == 993);
			Assert::IsTrue(arr[6] == 1007);
		}
		
		TEST_METHOD(CountingSortTest)
		{
			char arr[] = {'a', 'h', 'J', 'e', 'W', 'W', 'h', 'a', 'F'};
			countingSort(arr, 9);
			Assert::IsTrue(arr[0] == 'F');
			Assert::IsTrue(arr[1] == 'J');
			Assert::IsTrue(arr[2] == 'W');
			Assert::IsTrue(arr[3] == 'W');
			Assert::IsTrue(arr[4] == 'a');
			Assert::IsTrue(arr[5] == 'a');
			Assert::IsTrue(arr[6] == 'e');
			Assert::IsTrue(arr[7] == 'h');
			Assert::IsTrue(arr[8] == 'h');

		}
	};
}
