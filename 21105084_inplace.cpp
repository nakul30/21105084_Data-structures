/*Ques-1. What is the difference between in-place and out-place sorting algorithms?
Ans-1. 
In-place algorithms
a. An in-place algorithm transforms the input without using any extra memory. 
As the algorithm executes, the input is usually overwritten by the output, and 
no additional space is needed for this operation.
b. An in-place algorithm may require a small amount of extra memory for its 
operation. However, the amount of memory required must not be dependent 
on the input size and should be constant.
c. Several sorting algorithms rearrange the input into sorted order in-place, such 
as insertion sort, selection sort, quick sort, bubble sort, heap sort, etc. All these 
algorithms require a constant amount of extra space for rearranging the 
elements in the input array.
d. Usually, an algorithm is categorized as an in-place or an out-of-place 
algorithm based on the explicit storage allocated by the algorithm. However, 
calling a recursive algorithm as in-place is highly debatable since extra space 
is being used by the call stack. Although this space required by the call stack 
technically takes the recursive algorithms out of the in-place algorithms 
category, the algorithms requiring only O(log(n)) additional space is 
considered to be in-place.
e. In-place algorithms are usually used in an embedded system that runs in 
limited memory. They reduce the space requirements to a great extent, but 
the algorithm time complexity increases in some cases.
Out-of-place algorithms
a. An algorithm that is not in-place is called a not-in-place or out-of-place 
algorithm. Unlike an in-place algorithm, the extra space used by an out-place algorithm depends on the input size.
b. The standard merge sort algorithm is an example of out-of-place algorithm as 
it requires O(n) extra space for merging. The merging can be done in-place, 
but it increases the time complexity of the sorting routine.
Ques-2. Implement Insertion sort in both (in-place and out-place) manner.*/

//Insertion Sort Using In-Place Algorithm
#include <iostream>
using namespace std;
//Creating Insertion Sort void function
void insertion_sort_IP(int arr[],int n){
    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OP(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insertion_sort_OP(arr,si+1,ei);
}
//Function to print array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    //Taking Input array
    cout<<"ENTER NUMBER OF ELEMENTS IN THE ARRAY: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"ENTER ELEMENTS OF ARRAY SEPERATED BY SPACE: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"ARRAY BEFORE SORTING : ";pfun(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"ARRAY AFTER SORTING USING IN-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;
    //calling insertiong sort using out-place algorithm.
    insertion_sort_OP(arr2,0,n-1);
    cout<<"ARRAY AFTER SORTING USING OUT-PLACE ALGORITHM : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;

}

/*
/*
Ques-3. Suggest some practical examples of using in-place and out-place techniques.
Ans-3 In-place techniques- Bubble sort is an example of in-place sorting technique. It usually 
also excludes the space used for stack in recursive algorithms. Quick sort, uses only some 
constant number of variables for partitioning purpose. So, is in-place algorithm.
Out-place techniques- In merge sort, merge function requires extra linear space which is not 
constant. So, it is not in-place. Hence, it is called 'out of place' algorithm. Among the 
comparison based techniques discussed, only Insertion Sort qualifies for this because of the 
underlying algorithm it uses i.e. it processes the array (not just elements) from left to right 
and if new elements are added to the right, it doesn’t impact the ongoing operation.*/