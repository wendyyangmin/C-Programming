#include<stdio.h>
//Funtion SwapArrayEnds
void SwapArrayEnds(int sortArray[],int SORT_ARR_SIZE){
  int i;
  int j;
  for (i=0; i<SORT_ARR_SIZE;i++){
      if ((sortArray[i]%2) == 1){
        for(j=i+1;j<SORT_ARR_SIZE;j++){
        int temp;
           if ((sortArray[j]%2) == 0){
           temp = sortArray[i];
           sortArray[i] = sortArray[j];
           sortArray[j] = temp;
           break;
           }
         }
       }
   }
}

int main(){
  const int SORT_ARR_SIZE = 10;
  int sortArray[SORT_ARR_SIZE];
  int i=0;
  
printf("Enter ten integers:\n");
  for(i=0;i<SORT_ARR_SIZE;i++){
    scanf("%d",&sortArray[i]);
 }
 
  SwapArrayEnds(sortArray, SORT_ARR_SIZE);

 for (i=0;i< SORT_ARR_SIZE;++i) {
   printf("%d ", sortArray[i]);
}
printf("\n");

return 0;

}
