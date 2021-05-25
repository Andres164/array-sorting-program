#include<iostream>

using namespace std;

class arraySorters
{
public:
    void selectionSort(int arrayToSort[], int lengthOfArrayToSort)
    {
        for(int i = 0; i < lengthOfArrayToSort; i++)
        {
            int lesserNumberIndex = i;
            for(int j = i + 1; j < lengthOfArrayToSort; j++)
            {
                if(arrayToSort[j] < arrayToSort[lesserNumberIndex])
                    lesserNumberIndex = j;
            }
            swapElementsOfArray(&arrayToSort[i], &arrayToSort[lesserNumberIndex]);
        }

        for(int i = 0; i < lengthOfArrayToSort; i++)
            cout << arrayToSort[i] << " ";
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

    return 0;
}
