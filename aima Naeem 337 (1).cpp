/*
 * ============================================================
 *  Assignment: Programming Fundamentals
 *  Topic     : 1D Arrays, Functions & File I/O
 *  Submitted by: Aima Naeem ( G1F25UBSCS337)
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

// ---------- Constant for array size ----------
const int SIZE = 10;

void inputArray(int arr[], int size);
void displayArray(const int arr[], int size);
int  calculateSum(const int arr[], int size);
void writeToFile(const int arr[], int size);
void readFromFile(int arr[], int size);


// ============================================================
//  PART A: inputArray()
//  Purpose : Takes 10 integer values from the user and stores
//            them in the array.
//  Passing : Pass by reference (array decays to pointer) so
//            the values are stored in the original array in main.
// ============================================================
void inputArray(int arr[], int size)
{
    cout << "\n--- Part A: Enter " << size << " integer values ---\n";
    for (int i = 0; i < size; i++)
    {
        cout << "  Element [" << i << "]: ";
        cin  >> arr[i];
    }
}


// ============================================================
//  PART B (i): displayArray()
//  Purpose : Prints all elements of the array to the screen.
//  Passing : const int arr[] - read-only, original is safe.
// ============================================================
void displayArray(const int arr[], int size)
{
    cout << "\n  Array elements: [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]\n";
}


// ============================================================
//  PART B (ii): calculateSum()
//  Purpose : Calculates and RETURNS the sum of all elements.
//  Passing : const int arr[] - read-only copy.
//  Returns : int (the total sum)
// ============================================================
int calculateSum(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;   // value-returning function
}


// ============================================================
//  PART C: writeToFile()
//  Purpose : Opens "data.txt" and writes each array element
//            on a separate line.
//  File I/O: ofstream is used for OUTPUT (writing) to a file.
// ============================================================
void writeToFile(const int arr[], int size)
{
    ofstream outFile("data.txt");   // open file for writing

    if (!outFile)   // check if file opened successfully
    {
        cout << "\n  ERROR: Could not open data.txt for writing!\n";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        outFile << arr[i] << "\n";  // write element then newline
    }

    outFile.close();   // always close the file when done
    cout << "\n  Data successfully written to data.txt\n";
}


// ============================================================
//  PART D: readFromFile()
//  Purpose : Opens "data.txt", reads values back into the
//            array, then displays them on screen.
//  File I/O: ifstream is used for INPUT (reading) from a file.
//  Passing : Pass by reference so main's array is updated.
// ============================================================
void readFromFile(int arr[], int size)
{
    ifstream inFile("data.txt");    
    if (!inFile)   
    {
        cout << "\n  ERROR: Could not open data.txt for reading!\n";
        return;
    }

    cout << "\n--- Part D: Reading data back from data.txt ---\n";
    for (int i = 0; i < size; i++)
    {
        inFile >> arr[i];          
    }
    inFile.close();               
    displayArray(arr, size);
}


// ============================================================
//  MAIN FUNCTION
// ============================================================
int main()
{
    int arr[SIZE];  // Declare a 1D array of size 10

    cout << "========================================\n";
    cout << "   1D Arrays, Functions & File I/O     \n";
    cout << "========================================\n";

    // ----- Part A: Input -----
    inputArray(arr, SIZE);

    // ----- Part B: Display & Sum -----
    cout << "\n--- Part B: Displaying Array ---";
    displayArray(arr, SIZE);

    // Part E: Display sum using value-returning function
    int total = calculateSum(arr, SIZE);
    cout << "  Sum of all elements = " << total << "\n";

    // ----- Part C: Write to File -----
    cout << "\n--- Part C: Writing to File ---";
    writeToFile(arr, SIZE);

    // ----- Part D: Read from File -----
    readFromFile(arr, SIZE);

    cout << "\n========================================\n";
    cout << "           Program Finished             \n";
    cout << "========================================\n";

    return 0;
}