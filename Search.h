#include <iostream>
#include <string>

using namespace std;

// write a function to print the contents of your array
//   bonus! try to implement your function so that it can accept
//     many types of data (int, char, string, etc.)
template <typename flexibleType> // ???
void printArray(flexibleType arr[], int length) {
    for(int i = 0; i < length; i++){
        cout << arr[i] << " "; 
    }
}

// Implement a sequential search algorithm
// your function should search for a target value (target)
//    within the indices of "start" to "end"
// return true if target exists in the array within this range,
//    return false otherwise
bool seqSearch(string target, string arr[], int start, int end){

    
    for(int i = start; i <= end; i++){
        if(arr[i] == target){
            return true; 
        }
    }

    //else 
    return false; 
}


// Implement an iterative binary search 
// Return true if target exists in the array with size n,
//    return false otherwise 
bool binSearch(float target, float arr[], int n) {

    int low = 0; 
    int high = n -1; //setting the intial bounds low-high

    while(low <= high){ //loop till the search space is exhausted 
                            //till array size is like 1 

    int mid = (low + high) / 2; //find the mid value in the search space 

    if(target == arr[mid]){
        return true; //auto true if the mid value IS the target
    }

    else if(target < arr[mid]){ //if out target is less than middle index...
        high = mid -1; //then just changiung new high (visualize intuitive elim of array, given binary cut)
    }
    else { //else our target is greater than middle value...
        low = mid + 1; //new low is after mid
    }
    }

    //if not found in exhaaustive logic return false 
    return false;	
}

// Implement a recursive binary search 
// Return true if target exists in the array with size n
//   return false otherwise
bool binSearchR(char target, char charray[], int n) {
    // base

    int mid = n/2; 

    if(charray[mid] == target){
        return true; 
    }

    else if(n <= 0){
        return false; 
    }
    

    if(target > charray[mid]){
        return binSearchR(target, &charray[mid + 1], n/2); //--------------------------------------------------------------
    }

    else{ 
        return binSearchR(target, charray, n/2);
    }
}

// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int x, int y) {
    double temp; 

    temp = darray[x]; 
    darray[x] = darray[y]; 
    darray[y] = temp; 
}

int minFind(double darray[], int size) {
    double min = darray[0]; 
    int index = 0;
    for(int i = 0; i < size; i++){
        if(darray[i] < min){ 
            min = darray[i]; 
            index = i;
        }
    }

    return index; 
}

void newSort(double darray[], int n) {
    for(int i = 0; i < n -1; i++){ //last one will be swapped by the time we reach it so, n -1
        int mindex = i + minFind(&darray[i], n -i); //getting the min index
        swap(darray, mindex, i); //swapping values with current 
        //we loop this, adding text to new commit
    }
}