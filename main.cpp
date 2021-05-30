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
    void stringSorter(string* ptr_arrayToSort, int lengthOfArrayToSort)
    {
        for(int i = 0; i < lengthOfArrayToSort; i++)
        {
            string* ptr_lesserElement = ptr_arrayToSort +i;
            int lesserElementsFirstCharAsciiValue = int(ptr_lesserElement->at(0));
            for(int j = i +1; j < lengthOfArrayToSort; j++)
            {
                int currentElementsFirstCharAsciiValue = int((ptr_arrayToSort +j)->at(0));
                if(currentElementsFirstCharAsciiValue < lesserElementsFirstCharAsciiValue)
                    ptr_lesserElement = ptr_arrayToSort +j;
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
    string arr1[lengthOfArray] = {"b","A","d","c","z","a"};

    arraySorters myObjct;
    myObjct.stringSorter(arr1, lengthOfArray);

    for(int i = 0; i < lengthOfArray; i ++)
        cout << arr1[i] << " ";

    return 0;
}
