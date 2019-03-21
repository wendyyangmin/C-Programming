#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FILE_IN "in.txt"
#define FILE_OUT "out.txt"
#define INPUTS 10 
#define RESULTS 8 


  // Function findTriangleArea:This part  displays the area of a triangle  
  double findTriangleArea(double base,double height){
         double areaTri = 0.0;
         areaTri=base*height/2;
         return areaTri;
}

  // Function findSphereArea:This part displays the area of a sphere
  double findSphereArea(double radius){
         double areaSphere = 0.0;
         areaSphere=4*radius*radius*M_PI;
         return areaSphere;        
}

  // Function findSectorArea: This part displays the area of a sector
  double findSectorArea(double radius,double theta){
         double areaSector = 0.0;
         areaSector=radius*radius*theta*M_PI/360;
         return areaSector;
}

  // Function findEllipseArea: This part displays the area of an ellipse
  double findEllipseArea(double axis1, double axis2){
         double areaEllipse = 0.0;
         areaEllipse=axis1*axis2*M_PI;
         return areaEllipse;  
}

  // Function findKilometer: This part displays the miles
  double findKilometer(double miles){
         double kilometers = 0.0;
         kilometers=1.609*miles;
         return kilometers;
}

  // Function findkilograms: This part displays the kilograms
  double findkilograms(double pounds){
         double kilograms = 0.0;
         kilograms=pounds*2.205; 
         return kilograms;
}

  // Function findFahrenheit: This part displays the fahrenheit
  double findFahrenheit(double kelvin){
         double fahrenheit = 0.0;
         fahrenheit= kelvin*9/5-459.67;
         return fahrenheit;
}
 
 // Function findMegabyte: This part displays the megabyte
  double findMegabyte(double terabyte){
         double megabyte = 0.0;
         megabyte=terabyte*0.0000001;
         return megabyte;
}

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
  array_out[0] = findTriangleArea(array_in[0],array_in[1]);
  fprintf(output_stream," area of a triangle: %5.3lf\n", array_out[0]);
  
  // This part displays the area of a sphere 
  array_out[1] = findSphereArea(array_in[2]);
  fprintf(output_stream," area of a sphere: %5.3lf\n", array_out[1]);

  // This part displays the area of a sector
  array_out[2] = findSectorArea(array_in[2],array_in[3]);
  fprintf(output_stream," area of a sector: %5.3lf\n", array_out[2]);

  // This part displays the area of an ellipse
  array_out[3] = findEllipseArea(array_in[4],array_in[5]);
  fprintf(output_stream," area of an ellipse: %5.3lf\n", array_out[3]);

  // This part displays the miles
  array_out[4] = findKilometer(array_in[6]);
  fprintf(output_stream," Kilometers from miles:  %5.3lf\n", array_out[4]);

  // This part displays the kilograms
  array_out[5] = findkilograms(array_in[7]);
  fprintf(output_stream," Kilograms from Pounds:  %5.3lf\n", array_out[5]);

  // This part displays the fahrenheit
  array_out[6] = findFahrenheit(array_in[8]);
  fprintf(output_stream," Fahrenheit from Kelvin Temperature:  %5.3lf\n", array_out[6]);
  
  // This part displays the megabyte
  array_out[7] = findMegabyte(array_in[9]);
  fprintf(output_stream," Megabyte from terabytes:  %5.3lf\n", array_out[7]); 
  fprintf(output_stream,"\n");
  
 
/******************************************************************/
  /* Close the file streams when finished                            */
  /******************************************************************/
  fclose(input_stream);
  fclose(output_stream);

  return(0);
}
