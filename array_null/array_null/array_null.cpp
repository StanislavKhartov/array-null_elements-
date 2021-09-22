#include <iostream>
#include <ctime>

using namespace std;

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
    int state = 0;
    cout << "If you want to fill array with random numbers, enter 1, else enter 2\n";
    cin >> state;
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
            array[i] = (rand() % (upper_bound - lower_bound + 1) + lower_bound);
        }
        break;
    case 2:
        cout << "PLease enter members of array\n";
        for (int i = 0; i < length; i++)
        {
            cin >> array[i];
        }
        break;
    default:
        return 1;
    }
    printArray(array, length);
    int pointer = 0;
    int pointerLastNull = 0;
    while (pointer != length)
    {
        if (array[pointer] == 0)
        {
            swap(array[pointer], array[pointerLastNull]);
            pointerLastNull++;
        }
        pointer++;
    }
    printArray(array, length);
    delete(array);
    return 0;
}