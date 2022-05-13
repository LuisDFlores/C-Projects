#include <iostream>
#include <ctime>

using namespace std;


void heapify(int arr[], int x, int i)
{
    int max = i; // Initialize max as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    
    // If left child is bigger than root
    if (l < x && arr[l] > arr[max])
        max = l;
    
    // If right child is bigger than biggest so far
    if (r < x && arr[r] > arr[max])
        max = r;
    
    // If max is not root
    if (max != i)
    {
        swap(arr[i], arr[max]);
        
        // Recursively heapify
        heapify(arr, x, max);
    }
}


void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        
        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//function to print array of size n
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    int arr[100];
    
    srand((unsigned)time(0));
    
    for(int i=0; i<100; i++){
        arr[i] = (rand()%100)+1;
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    
    heapSort(arr, n);
    
    cout << "min heap is \n";
    printArray(arr, n);
    return 0;
}
