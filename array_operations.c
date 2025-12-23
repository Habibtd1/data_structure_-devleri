#include <stdio.h>
 
int main() {
    int arr[100] = {1,2,3,4,5};
    int size = 5; 
    int i;
      
    //Traversal
    printf("Array: ");
    for(i= 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Reverse
    for(i=0; i < size / 2; i++){
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i]= temp;
    }
    printf("After Reverse: ");
    for(i=0; i  < size; i++)
    printf("%d ",arr[i]);
    printf("\n");

    //Insertion 
    for(i = size;i > 2; i--){
        arr[i] = arr[i-1];
    }
    arr[2] =10;
    size++;

    printf("After Insertion: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

     //Deletion
     for(i = 3; i < size - 1; i++){
        arr[i] = arr[i + 1];
     }
     size--;
      
     printf("After deletion: ");
     for(i = 0;i < size; i++){
        printf("%d ", arr[i]);
     }
     printf("\n");

     return 0;


}