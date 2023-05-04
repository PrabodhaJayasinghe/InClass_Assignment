#include <iostream>

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int temp;
    int maximum = root;
    int left = 2*root + 1;
    int right = 2*root +2;

    if ((n>left) && (arr[left]>arr[maximum])){
        maximum = left;
    }
    if ((n>right) && (arr[right]>arr[maximum])){
        maximum = right;
    }
    if (maximum != root){
        temp = arr[root];
        arr[root]=arr[maximum];
        arr[maximum] = temp;
        heapify(arr,n,maximum);
    }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
    int temp;
    // build heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements from heap one by one
    for (int k = n-1; k >= 0; k--) {

        temp = arr[0];
        arr[0]=arr[k];
        arr[k] = temp;
        heapify(arr, k, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{

    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int heap_arr[num];

    cout << "Enter " << num << " elements: ";
    for (int i = 0; i < num; i++) {
        cin >> heap_arr[i];
    }
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
