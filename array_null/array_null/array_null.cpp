#include <iostream>
#include <ctime>

using namespace std;

int* mergeArrays(int* firstArray, int* secondArray, int firstLength, int secondLength)
{
    int* array = new int[firstLength + secondLength];
    for (int i = 0; i < firstLength; i++)
    {
        array[i] = firstArray[i];
    }
    for (int i = 0; i < secondLength; i++)
    {
        array[i + firstLength] = secondArray[i];
    }
    delete[]firstArray;
    delete[]secondArray;
    return array;
}

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cout << "Please, enter size of array\n";
    int length = 0;
    cin >> length;
    int* array = new int[length];
    int* nullArray = new int[length];
    int state = 0;
    cout << "If you want to fill array with random numbers, enter 1, else enter 2\n";
    cin >> state;
    int nullLength = 0;
    int pointer1 = 0;
    int pointer2 = 0;
    switch (state)
    {
    case 1:
        cout << "Please enter the lower bound and upper bound of random numbers\n";
        int lower_bound;
        int upper_bound;
        cin >> lower_bound;
        cin >> upper_bound;
        if (upper_bound < lower_bound)
        {
            cout << "wrong data\n";
            return 1;
        }
        srand(NULL);
        for (int i = 0; i < length; i++)
        {
            int tmp = (rand() % (upper_bound - lower_bound + 1) + lower_bound);
            if (tmp == 0)
            {
                nullArray[pointer1] = 0;
                pointer1++;
                nullLength++;
            }
            else
            {
                array[pointer2] = tmp;
                pointer2++;
            }
        }
        break;
    case 2:
        cout << "PLease enter members of array\n";

        for (int i = 0; i < length; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
            {
                nullArray[pointer1] = 0;
                pointer1++;
            }
            else
            {
                array[pointer2] = tmp;
                pointer2++;
            }
        }
        break;
    default:
        return 1;
    }
    int* answer = mergeArrays(nullArray,array , pointer1, pointer2);
    printArray(answer, length);
    delete[]answer;
    return 0;
}