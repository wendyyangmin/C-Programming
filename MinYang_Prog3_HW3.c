#include <stdio.h>
#include <stdlib.h>

// Function prompts user to enter postiive non-zero number denominator
int GetPositivedenNumber(void) {
   int userNum = 0;
   
   while (userNum <= 0) {
      printf("Enter a positive number (>0): \n");
      scanf("%d", &userNum);
      
      if (userNum <= 0) {
         printf("Invalid number.\n");
      }
   }
   
   return userNum;
}

// Function prompts user to enter postiive non-zero number numerator
int GetPositivenumNumber(void) {
   int numNum = 0;
   
   while (numNum <= 0) {
      printf("Enter a positive number (>0): \n");
      scanf("%d", &numNum);
      
      if (numNum <= 0) {
         printf("Invalid number.\n");
      }
   }
   
   return numNum;
}


//Function FindGCD: Function returns greatest common divisor of two inputs
int FindGCD(int aVal, int bVal) {
   int numA = aVal;
   int numB = bVal;
   
   while (numA != numB) { // Euclid's algorithm
      if (numB > numA) {
         numB = numB - numA;
      }
      else {
         numA = numA - numB;
      }
   }
   
   return numA;
}

// Function FindLCM: Function returns least common multiple of two inputs denominator
int FindLCM(int aVal, int bVal) {
   int lcmVal = 0;
   
   lcmVal = abs(aVal * bVal) / FindGCD(aVal, bVal);
   
   return lcmVal;
}

//Funtion Findnum: Find sum of numerator
double Findnum(int aVal, int bVal, int cVal, int dVal){
   double numSum=0.0;
  numSum=(aVal*dVal)+(bVal*cVal);

   return numSum;
}

//Function FindSum: Find sum of two fractions
double FindSum(int array1[], int array2[]){
   double aVal,bVal,cVal,dVal;
   double sumResult=0.0;
   
   aVal=array1[0];
   bVal=array1[1];
   cVal=array2[0];
   dVal=array2[1];
   if(FindLCM(bVal,dVal)<bVal*dVal){
  sumResult=(FindLCM(bVal, dVal)/bVal*aVal+FindLCM(bVal,dVal)/dVal*cVal)/FindLCM(bVal, dVal);
   }
   else{
   sumResult = Findnum(aVal, bVal, cVal, dVal)/FindLCM(bVal, dVal);
   }
   return sumResult;
}  

int main(void) {
   int array1[1];
   int array2[1];
   int i;
   double finalResult = 0.0;
   
   printf("Enter value for first input:\n");
   for(i=0;i<2;i++){
    array1[i]= GetPositivenumNumber();
    }
   
   printf("\nEnter value for second input:\n");
   for(i=0;i<2;i++){ 
   array2[i] = GetPositivenumNumber();
   }

   finalResult=FindSum(array1,array2);

   printf("\nSum of two fractions [%d,%d] and [%d,%d] is %5.1lf\n",
         array1[0],array1[1],array2[0],array2[1],finalResult);
   
   return 0;
}
