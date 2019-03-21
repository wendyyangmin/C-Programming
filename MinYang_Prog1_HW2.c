#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FILE_IN "in.txt"
#define FILE_OUT "out.txt"
#define INPUTS 10 
#define RESULTS 8 

int main(void)
{
  int i = 0;
  double array_in[INPUTS];
  double array_out[RESULTS];
/******************************************************************/
/* This section creates two streams for input and output files */
/******************************************************************/
 FILE  *input_stream;
 FILE *output_stream;

  input_stream = fopen(FILE_IN,  "r"); // read only 
 output_stream = fopen(FILE_OUT, "w"); // write only 
          
   //error checking to make sure input input_stream is not null         
   if ( input_stream == NULL){ 
      printf("Error! Could not open input_stream\n"); 
      exit(-1);  
   } 
          
   //error checking to make sure input output_stream is not null         
   if ( output_stream == NULL){ 
      printf("Error! Could not open output_stream\n"); 
      exit(-1);  
   } 
/*****************************************************************/

  printf("\n\n    Begin  program \n\n");

  // This for loop scans in the array values
  printf("\n");
  for(i = 0; i < INPUTS; i++ ){
     fscanf(input_stream, "%lf", &array_in[i]); 
     printf("\n");
  }


  // This for loop displays the array  
  printf("\n");
  fprintf(output_stream,"\n");
  for(i = 0; i < INPUTS; i++ ){
     printf(" %5.3lf\n", array_in[i] );
     fprintf(output_stream," %5.3lf\n", array_in[i] );
  }
  fprintf(output_stream,"\n");

  // This part  displays the area of a triangle  
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[0]=array_in[0]*array_in[1]/2;
  fprintf(output_stream," area of a triangle: %5.3lf", array_out[0]);
  
// This part displays the area of a sphere
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[1]= array_in[2]*array_in[2]*4*M_PI;
  fprintf(output_stream," area of a sphere: %5.3lf", array_out[1]);

  // This part displays the area of a sector
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[2]= array_in[2]*array_in[2]*array_in[3]*M_PI/360;
  fprintf(output_stream," area of a sector: %5.3lf", array_out[2]);

  // This part displays the area of an ellipse
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[3]= array_in[4]*array_in[5]*M_PI;  
  fprintf(output_stream," area of an ellipse: %5.3lf", array_out[3]);

  // This part displays the miles
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[4]= array_in[6]*1.609;
  fprintf(output_stream," Miles from Kilometers:  %5.3lf", array_out[4]);

  // This part displays the pounds
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[5]=array_in[7]*2.205;
  fprintf(output_stream," Pounds from Kilograms:  %5.3lf", array_out[5]);

  // This part displays the fahrenheit
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[6]=array_in[8]*9/5-459.67;
  fprintf(output_stream," Fahrenheit from Kelvin Temperature:  %5.3lf", array_out[6]);
  
// This part displays the megabyte
  printf("\n");
  fprintf(output_stream,"\n");
  array_out[7]= array_in[9]*0.0000001; 
  fprintf(output_stream," Megabyte from terabytes:  %5.3lf", array_out[7]); 
  fprintf(output_stream,"\n");
  
 
/******************************************************************/
  /* Close the file streams when finished                            */
  /******************************************************************/
  fclose(input_stream);
  fclose(output_stream);

  return(0);
}
