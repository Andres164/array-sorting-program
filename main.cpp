#include<iostream>

using namespace std;

class arraySorters
{
public:
    arraySorters();
    void selectionSort(int arrayToSort[])
    {
        int lengthOfArrayToSort = lengthOfArray(arrayToSort);
        for(int i = 0; i < lengthOfArrayToSort; i++)
        {
            int lesserNumber = arrayToSort[i];
            for(int j = i + 1; j < lengthOfArrayToSort; j++)
            {
                if(arrayToSort[j] < lesserNumber)
                    lesserNumber = arrayToSort[j];
            }

        }
    }

private:
    int lengthOfArray(int arr[])
    {
        return (sizeof(arr)/sizeof(arr[0]));
    }

    void swapElementsOfArray(int index1, int index2, int* arr[])
    {
        int temp;
        temp = *arr[index1];
        arr[index1] = arr[index2];
        arr[index2]* = temp;
    }
};

int main()
{


    return 0;
}
