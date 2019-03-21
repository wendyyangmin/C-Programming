#include <stdio.h>
#include <stdlib.h>

#define FILE_IN "sales.in"
#define FILE_OUT "sales.out"
#define RECORDS 25 
#define ELEMENTS 13 

int main(void)
{

  int i = 0, j = 0, k = 0;
  double sales[RECORDS][ELEMENTS];
  
  
  double maxMonth = 0, minMonth = 0;
  double totalAnnualSales[RECORDS];
  double quarterlySales[RECORDS][4];
  double monthlyDiff[RECORDS][11];
  double monthlyPercentChange[RECORDS][11];
  
/******************************************************************/
/* This section creates two streams for input and output files */
/******************************************************************/
 FILE  *input_stream;
 FILE *output_stream;

  input_stream = fopen(FILE_IN,  "r"); // read only 
 output_stream = fopen(FILE_OUT, "w"); // write only 
          
   //error checking to make sure input input_stream is not null         
   if ( input_stream == NULL) 
   {   
      printf("Error! Could not open input_stream\n"); 
      exit(-1);  
   } 
          
   //error checking to make sure input output_stream is not null         
   if ( output_stream == NULL) 
   {   
      printf("Error! Could not open output_stream\n"); 
      exit(-1);  
   } 
/*****************************************************************/

  printf("\n\n    Begin  program \n\n");

  // This for loop scans in the array values
  printf("\n");
  for(i = 0; i < RECORDS; i++ )
  {
     for( j = 0; j < ELEMENTS; j++)
     {
        fscanf(input_stream, "%lf", &sales[i][j]); 
     }
     //printf("\n");
  }


  // This for loop displays the array indices 
  printf("\n");
  fprintf(output_stream,"\n");
  for(i = 0; i < RECORDS; i++ )
  {
     for( j = 0; j < ELEMENTS; j++)
     {
         printf(" [%2d][%2d]", i, j);
        fprintf(output_stream," [%2d][%2d]", i, j);
     }
  printf("\n");
  fprintf(output_stream,"\n");
  }
  fprintf(output_stream,"\n");

  // This for loop displays the array values 
  printf("\n");
  fprintf(output_stream,"\n");
  for(i = 0; i < RECORDS; i++ )
  {
     for( j = 0; j < ELEMENTS; j++)
     {
         printf(" %7.0lf", sales[i][j]);
        fprintf(output_stream," %7.0lf", sales[i][j]);
     }
  printf("\n");
  fprintf(output_stream,"\n");
  }
  fprintf(output_stream,"\n");

// Find the max sales value
printf("\n");
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
  for(j=0;j<ELEMENTS;j++)
  {
  if(sales[i][j]>maxMonth){
   maxMonth=sales[i][j];
    }
  }
}
 fprintf(output_stream,"maximum sales value:%7.0lf", maxMonth);

// Find the minimum sales value
printf("\n");
minMonth=sales[0][1];
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
  for(j=1;j<ELEMENTS;j++)
  {
  if(minMonth > sales[i][j] && sales[i][j] > 0.0000001){
   minMonth=sales[i][j];
    }
  }
}
 fprintf(output_stream,"minimum sales value:%7.0lf\n", minMonth);

// Find the total annual sales value
printf("\n");
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
  for(j=1;j<ELEMENTS;j++)
  {
 totalAnnualSales[i] += sales[i][j];
}
 fprintf(output_stream,"total annual sale:%7.0lf\n", totalAnnualSales[i]);
}

// Find the quarterly sales value
printf("\n");
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
fprintf(output_stream,"quarterly sale:");

//first quarter
 quarterlySales[i][k]=0;
 for(j=1;j<4;j++){ 

 quarterlySales[i][k] += sales[i][j];
}
fprintf(output_stream,"%7.0lf", quarterlySales[i][k]);

//second quarter
 quarterlySales[i][k]=0;
  for(j=4;j<7;j++)
  {
 quarterlySales[i][k] += sales[i][j];
}
 fprintf(output_stream," %7.0lf", quarterlySales[i][k]);

//third quarter
 quarterlySales[i][k]=0;
  for(j=7;j<10;j++)
  {
 quarterlySales[i][k] += sales[i][j];
}
 fprintf(output_stream," %7.0lf", quarterlySales[i][k]);

//fourth quarter 
 quarterlySales[i][k]=0;
 for(j=10;j<13;j++)
  {
 quarterlySales[i][k] += sales[i][j];
}
 fprintf(output_stream," %7.0lf\n", quarterlySales[i][k]);
}

// Find the monthly difference in computed
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
  fprintf(output_stream,"monthly difference:");
  for(j=1;j<ELEMENTS-1;j++)
  {
 if(sales[i][j]>0.00001){//to avoid the last four months which does not have data
 monthlyDiff[i][j]=sales[i][j+1]-sales[i][j];//calculate monthly difference

 fprintf(output_stream,"%7.0lf", monthlyDiff[i][j]);
}
else{
    fprintf(output_stream,"no data ");//print out month with no data as 'no data'
      }
  }
 fprintf(output_stream,"\n");
}


// Find the monthly percentage change in sales computed
fprintf(output_stream,"\n");
 for(i=0;i<RECORDS;i++)
 {
 fprintf(output_stream,"monthly percentage change:");
  for(j=1;j<ELEMENTS-1;j++)
  {
 if(sales[i][j]>0.00001){//to avoid the last four months which does not have data
 monthlyPercentChange[i][j]=(sales[i][j+1]-sales[i][j])/sales[i][j]*100;
 
 fprintf(output_stream," %7.3lf", monthlyPercentChange[i][j]);
}
  else{
    fprintf(output_stream,"no data ");//print out month with no data as 'no data'
      }
  }
fprintf(output_stream,"\n");
  
 }

/* Close the file streams when finished                            */
  /******************************************************************/
  fclose(input_stream);
  fclose(output_stream);

  printf("\n   End of program \n\n");
  return(0);
}
