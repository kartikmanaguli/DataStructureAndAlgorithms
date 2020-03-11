#include<stdio.h>
void maxheapify(int *,int);
int size; // Total Size of the Array
int large;
void main()
{
   int heapArray[]={-1,89,19,40,17,12,10,2,5,7,11,6,9,70}; //-1 is Dummy because Heap index Starts with 1 (not necessary :) )
   int index;
   size = (sizeof(heapArray)/sizeof(int))-1;

   for(index=size/2;index>1;index--)  // Starting From non-leaf Node which is Start frm floor 1 to floor(n/2)  
       maxheapify(heapArray,index);              

   for(index=1;index<=size;index++)
   printf("%d ",heapArray[index]);
}

void maxheapify(int *heap,int index)
{
   int leftChild=2*index; //leftChild is index of left subtree
   int rightChild=leftChild + 1; //rightChild is index of right subtree
   
   if(leftChild<=size && heap[leftChild]>heap[index])
    large = leftChild;

   else
    large = index;
 
    if(rightChild<=size && heap[rightChild]>heap[index])
    large = rightChild;
   
    if(large!=index){
      heap[index] = heap[index]+heap[large];  //<------<
      heap[large] = heap[index]-heap[large]; // Swapping :)
      heap[index] = heap[index]-heap[large];//<-------<

      maxheapify(heap,large);
    }
}
