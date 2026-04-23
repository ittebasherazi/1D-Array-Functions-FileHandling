/*
 * ============================================================
 *  Assignment: Programming Fundamentals
 *  Topic     : 1D Arrays, Functions & File I/O
 *  Submitted by: SYEDA ITTEBA FATIMA SHERAZI ( G1F25UBSCS335)
 *  Submitted to: prof Hamza Afzal
 * ============================================================
 *
 *  ROLE OF FUNCTIONS:
 *  Functions break a large program into smaller, manageable
 *  pieces. Each function has one specific job, making the
 *  code easier to read, test, and reuse.
 *
 *  ROLE OF PARAMETER PASSING:
 *  - Pass by Reference (&): Allows a function to modify the
 *    original array stored in main(). Used in inputArray()
 *    and readFromFile() so changes are reflected in main.
 *  - Pass by Value (const): Sends a copy; the original cannot
 *    be changed. Used in displayArray() and writeToFile()
 *    because we only need to read the data.
 *
 *  ROLE OF FILE I/O:
 *  File Input/Output lets us save data permanently on disk
 *  so it is not lost when the program closes. We use
 *  <fstream>: ofstream to write, ifstream to read.
 * ============================================================
 */
 #include <iostream>
#include <fstream>
using namespace std;

// Constant value for array size
const int SIZE = 10;
// Function Prototypes
void inputArray(int arr[], int size);
void displayArray(const int arr[], int size);
int calculateSum(const int arr[], int size);
void writeToFile(const int arr[], int size);
void readFromFile(int arr[], int size);

// Function for taking input
void inputArray(int arr[], int size)
{
    cout << "\nEnter " << size << " values:\n";

    for (int i = 0; i <= size - 1; i++)
    {
        cout << "Enter value for index " << i << ": ";
        cin >> arr[i];
    }
}

// Function for displaying array
void displayArray(const int arr[], int size)
{
    cout << "\nArray Values: ";

    for (int i = 0; i <= size - 1; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Function for calculating sum
int calculateSum(const int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i <= size - 1; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

// Function for writing data into file
void writeToFile(const int arr[], int size)
{
    ofstream outFile("data.txt");

    if (outFile.fail())
    {
        cout << "\nFile could not be opened.\n";
        return;
    }

    for (int i = 0; i <= size - 1; i++)
    {
        outFile << arr[i] << endl;
    }

    outFile.close();
    cout << "\nData saved into file successfully.\n";
}

// Function for reading data from file
void readFromFile(int arr[], int size)
{
    ifstream inFile("data.txt");

    if (inFile.fail())
    {
        cout << "\nUnable to open file.\n";
        return;
    }

    for (int i = 0; i <= size - 1; i++)
    {
        inFile >> arr[i];
    }

    inFile.close();

    cout << "\nValues loaded from file:\n";
    displayArray(arr, size);
}

// Main Function
int main()
{
    int arr[SIZE];

    cout << "=====================================\n";
    cout << " 1D Arrays, Functions & File I/O\n";
    cout << "=====================================\n";

    inputArray(arr, SIZE);

    cout << "\nDisplaying Array:";
    displayArray(arr, SIZE);

    int total = calculateSum(arr, SIZE);
    cout << "\nSum of elements = " << total << endl;

    writeToFile(arr, SIZE);

    readFromFile(arr, SIZE);

    cout << "\nProgram Finished.\n";

    return 0;
}

