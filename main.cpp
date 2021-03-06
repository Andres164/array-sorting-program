#include<iostream>
#include<cstring>
#include <string>

using namespace std;

class arraySorters
{
public:
    void selectionSort(int* ptr_arrayToSort, int lengthOfArrayToSort)
    {
        for(int i = 0; i < lengthOfArrayToSort; i++)
        {
            int* ptr_lesserNumber = ptr_arrayToSort;
            int* ptr_elementArrayToSortInJIndex = ptr_arrayToSort + 1;
            for(int j = i + 1; j < lengthOfArrayToSort; j++)
            {
                if(*ptr_elementArrayToSortInJIndex < *ptr_lesserNumber)
                    ptr_lesserNumber = ptr_elementArrayToSortInJIndex;
                ptr_elementArrayToSortInJIndex++;
            }
            swapElementsOfArray(ptr_arrayToSort, ptr_lesserNumber);
            ptr_arrayToSort++;
        }
    }
    void insertionSort(int* ptr_arrayToSort, int lengthOfArrayToSort)
    {
        int* ptr_indexZeroArrayToSort = ptr_arrayToSort;
        for(int i = 1; i < lengthOfArrayToSort; i++)
        {
            ptr_arrayToSort++;
            int* ptr_elementBeingCompared = ptr_arrayToSort;
            while(ptr_elementBeingCompared > ptr_indexZeroArrayToSort && *ptr_elementBeingCompared < *(ptr_elementBeingCompared - 1))
            {
                swapElementsOfArray(ptr_elementBeingCompared, ptr_elementBeingCompared - 1);
                ptr_elementBeingCompared--;
            }
        }
    }
    void mySorter(int* ptr_arrayToSort, int lengthOfArrayToSort)
    {
        for(int i = 0; i < int(lengthOfArrayToSort/2); i++)
        {
            int* ptr_lesserNumber = ptr_arrayToSort +i;
            int* ptr_greaterNumber = ptr_lesserNumber;
            for(int j = i +1; j < lengthOfArrayToSort -i; j++)
            {
                int* ptr_currentNumber = ptr_arrayToSort +j;
                if(*ptr_currentNumber < *ptr_lesserNumber)
                    ptr_lesserNumber = ptr_currentNumber;
                else if(*ptr_currentNumber > *ptr_greaterNumber)
                    ptr_greaterNumber = ptr_currentNumber;
            }
            int* ptr_greaterSideBoundary = ptr_arrayToSort +(lengthOfArrayToSort -1 -i);
            if(ptr_lesserNumber == ptr_greaterSideBoundary && ptr_greaterNumber == ptr_arrayToSort +i)
                swapElementsOfArray(ptr_greaterNumber, ptr_greaterSideBoundary);
            else if(ptr_greaterNumber == ptr_arrayToSort +i)
            {
                swapElementsOfArray(ptr_greaterNumber, ptr_greaterSideBoundary);
                swapElementsOfArray(ptr_lesserNumber, ptr_arrayToSort +i);
            } else {
                swapElementsOfArray(ptr_lesserNumber, ptr_arrayToSort +i);
                swapElementsOfArray(ptr_greaterNumber, ptr_greaterSideBoundary);
            }
        }
    }
    void stringSorter(string* ptr_arrayToSort, int lengthOfArrayToSort)
    {
        for(int i = 0; i < lengthOfArrayToSort; i++)
        {
            string* ptr_lesserElement = ptr_arrayToSort +i;
            for(int j = i +1; j < lengthOfArrayToSort; j++)
            {
                string* ptr_currentElement = ptr_arrayToSort +j;
                if(*ptr_currentElement < *ptr_lesserElement)
                    ptr_lesserElement = ptr_currentElement;
            }
            string temp = *ptr_lesserElement;
            *ptr_lesserElement = *(ptr_arrayToSort +i);
            *(ptr_arrayToSort +i) = temp;
        }
    }

private:
    void swapElementsOfArray(int* ptr_element1, int* ptr_element2)
    {
        int temp = *ptr_element1;
        *ptr_element1 = *ptr_element2;
        *ptr_element2 = temp;
    }
};

int main()
{
    int lengthOfArray = 6;
    int arr1[lengthOfArray] = {6,2,1,4,5,3}; // 3,5,4,1,2,6

    arraySorters myObjct;
    myObjct.mySorter(arr1, lengthOfArray);

    for(int i = 0; i < lengthOfArray; i ++)
        cout << arr1[i] << " ";

    return 0;
}
