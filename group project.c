/*                                                            */
/*  This program reads BikeTrip information from a data      */
/*  file into an array and then prints the array              */

#include <stdio.h>
#define FILE_IN "bikeData5000.txt"
#define FILE_OUT "output.txt"

//  Define structure to represent a BikeTrip  
typedef struct BikeTrip_struct{
   char membershipType[10];
   int startStationId, endStationId, bikeId,
       duration, startHr, startMin;
}BikeTrip;

//function declarations
void PrintBikeTrip(BikeTrip t, FILE *outFile);
void PrintArray(BikeTrip tripArray[], int arraySize, FILE *outfile);
void FindMaxDuration(BikeTrip arrayIn[], int arraySize, FILE* outFile);
int TripsInHr(BikeTrip arrayIn[], int arraySize, int hour);
int TripsInTimeInterval(BikeTrip arrayIn[], int arraySize,int lowDuration, int highDuration);
int TripsInTimeIntervalL(BikeTrip arrayIn[], int arraySize, int highDuration);

//main
int main(void)
{
   /*  Declare variables */
   int k=0, elements;
   BikeTrip tripArray[5010];
   /*-----------------------------------------------------*/
   // Students do not need to edit sections that 
   // create the input and output file streams
   FILE *inputFileStream, *outputFileStream;
   /*------------------------------------------------------*/
   //  Open the input file stream to scan data into the array 
   inputFileStream = fopen(FILE_IN,"r");
   if (inputFileStream == NULL){
       printf("Error opening data file. \n");}
   else{
	  while (fscanf(inputFileStream, "%s %d %d %d %d %d %d",
		    tripArray[k].membershipType,&tripArray[k].startStationId,
			&tripArray[k].endStationId, &tripArray[k].bikeId, &tripArray[k].duration,
			&tripArray[k].startHr, &tripArray[k].startMin) == 7){k++;}
	  elements = k;
	}
   fclose(inputFileStream);
   /*-----------------------------------------------------*/
   //  Open the output file stream to write to output.txt        
   outputFileStream = fopen(FILE_OUT,"w");
   if (outputFileStream == NULL){
       printf("Error opening data file. \n");}
   /*-----------------------------------------------------*/
   
     fprintf(outputFileStream, "\n Calling FindMaxDuration( ) \n\n" );
     FindMaxDuration( tripArray, elements, outputFileStream);

	 int tripsInHr17 = TripsInHr( tripArray, elements, 17);
	 fprintf(outputFileStream, "\n tripsinHr17 = %d\n\n", tripsInHr17);

     fprintf(outputFileStream, "\n Print the whole array of BikeTrip structs\n\n" );
     PrintArray( tripArray, elements, outputFileStream );
     PrintBikeTrip( tripArray[3], outputFileStream );
     
   //Q6 number of trips in a time interval
     int tripsIn0to10 = TripsInTimeInterval( tripArray, elements,0, 600000);
     fprintf(outputFileStream,"\n trips in 0 to 10 minutes = %d\n",tripsIn0to10);
     int tripsIn10to11 = TripsInTimeInterval( tripArray, elements,600000, 660000);
     fprintf(outputFileStream,"\n trips in 10 minutes and 1 millisecond to 11 minutes = %d\n",tripsIn10to11);
     int tripsIn11to20 = TripsInTimeInterval( tripArray, elements,660000, 1200000);
     fprintf(outputFileStream,"\n trips in 11 minutes and 1 millisecond to 20 minutes = %d\n",tripsIn11to20);
     int tripsIn20to21 = TripsInTimeInterval( tripArray, elements,1200000, 1260000);
     fprintf(outputFileStream,"\n trips in 20 minutes and 1 millisecond to 21 minutes = %d\n",tripsIn20to21);
     int tripsIn21to30 = TripsInTimeInterval( tripArray, elements,1260000, 1800000);
     fprintf(outputFileStream,"\n trips in 21 minutes and 1 millisecond to 30 minutes = %d\n",tripsIn21to30);
     int tripsInAbove30= TripsInTimeIntervalL( tripArray, elements,1800000);
     fprintf(outputFileStream,"\n trips greater than 30 minutes = %d\n",tripsInAbove30);

   //At the end of main( ) close the output file stream
   fclose(outputFileStream);
   return 0;
}
   /*-----------------------------------------------------*/
//  This function prints the longest trip
void FindMaxDuration(BikeTrip arrayIn[], int arraySize, FILE* outFile){
   int maxDuration = 0;
   int k;
   maxDuration = arrayIn[0].duration;
   for (k = 1; k < arraySize; k++ ){
      if( arrayIn[k].duration > maxDuration){
	     maxDuration = arrayIn[k].duration;
         PrintBikeTrip(arrayIn[k], outFile);
	  }
   }
   return;
}
   /*-----------------------------------------------------*/
//  This function returns the count of trips started for an hour
int TripsInHr(BikeTrip arrayIn[], int arraySize, int hour){
    int k;
    int count = 0;
       for (k = 0; k < arraySize; k++ ){
          if( arrayIn[k].startHr == hour ){
             count++;
          }
      }
   printf("count of trips started in hour %d: %d \n", hour, count);
   return count;
}
//  This funtion returns the number of trips in a time interval
int TripsInTimeInterval(BikeTrip arrayIn[], int arraySize, int lowDuration, int highDuration){
   int k;
   int count = 0;
   for (k = 0; k < arraySize; k++ ){
      if( lowDuration < arrayIn[k].duration && arrayIn[k].duration <= highDuration){
	     count++;
	  }
   }
   printf("Number of trips in %d-%d minutes is %d\n",lowDuration/1000/60,highDuration/1000/60,count);
   return count;
}
//  This funtion returns the number of trips greater than a high duration
int TripsInTimeIntervalL(BikeTrip arrayIn[], int arraySize, int highDuration){
   int k;
   int count = 0;
   for (k = 0; k < arraySize; k++ ){
      if( highDuration < arrayIn[k].duration){
	     count++;
	  }
   }
   printf("Number of trips in greater than %d minutes is %d\n",highDuration/1000/60,count);
   return count;
}
   /*-----------------------------------------------------*/
//  This function prints the array
void PrintArray(BikeTrip tripArray[], int arraySize, FILE *outFile){
   fprintf(outFile,
           "bikeId membershipType startStationId endStationId startHr startMin duration(ms) minutes \n"); 
   int k;
   for (k = 0; k < arraySize; k++ ){
      PrintBikeTrip(tripArray[k], outFile);
   }
   return;
}
   /*-----------------------------------------------------*/
/*  This function prints one BikeTrip struct           */

void PrintBikeTrip(BikeTrip t, FILE *outFile){

   fprintf(outFile, "%6d %11s %15d %12d %7d %8d %10d %6d\n",
            t.bikeId, t.membershipType,t.startStationId,t.endStationId, 
			t.startHr, t.startMin, t.duration, t.duration/1000/60);
   return;
}
   /*-----------------------------------------------------*/


