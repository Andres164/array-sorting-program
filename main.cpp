#include<iostream>

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
    int arr1[lengthOfArray] = {2,1,3,4,6,5};

    arraySorters myObjct;
    myObjct.selectionSort(arr1, lengthOfArray);

    for(int i = 0; i < lengthOfArray; i ++)
        cout << arr1[i] << " ";

    return 0;
}
