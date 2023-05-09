#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;
void printArr(vector<int>& arr){
    cout<<"[ ";
    for(auto x:arr)
        cout<<x<<' ';
    cout<<']';
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(vector<int> &arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


void findRunningMedian(vector<int>& arr){
    cout<<left<<setw(20)<<"Sorted"<<"Median"<<endl;
   vector<int> tempArr ;
   for(int i =0 ; i<arr.size() ; i++){
       tempArr.push_back(arr[i]);
       bubbleSort(tempArr,tempArr.size());
       double median;
       if(tempArr.size()%2==0)
           median = (double)(tempArr[tempArr.size()/2] + tempArr[(tempArr.size()/2)-1])/2.0;
       else
           median = (tempArr[tempArr.size()/2]);

       printArr(tempArr);
       cout<<right<<setw(16-2*i)<<median<<endl;


   }
}



int main() {

    vector<int> arr {7,3,5,2};
    findRunningMedian(arr);


    return 0;
}