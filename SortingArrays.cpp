#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "data.h"

#define SIZE 1140
//function protypes
void bubbleSort(float a[]);
void printArray(float a[]);
void selectionSort(float a[]);
void windData(float a[]);


// function main begins program execution
int main(void) {

	
	// Create Arrays same data.h
	float bubbleArray[SIZE];
	float selectionArray[SIZE];
	

	// copy header data to two arrays so sorting algorithms for both works
	for (long int i = 0; i < SIZE; i++) {
	
		bubbleArray[i] = data[i];
		selectionArray[i] = data[i];
	}
	

	// Q1 Sort, time and measure swaps & comparisons of sorting algorithms
	
	selectionSort(selectionArray);
	printf("\n\n");
    bubbleSort(bubbleArray);
	printf("\n\nSorted Array Example: \n");
	printArray(bubbleArray);
	puts("");


	// Q2 Print out max and min wind speed from sorted array
	// Q2 Print out in to ranges of 5 from unsorted array
	windData(bubbleArray);
	
	
	

}// end main

void bubbleSort(float a[])
{
	int pass; // pass counter
	size_t j; // comparison counter (size_t is basically an unsigned int - non neg int)
	float hold; // temp location for swapping elements
	int comparison = 0;
	int bubbleSwap = 0;

	clock_t start, end;
	double bubbleTime;
	start = clock();
	// loop to control number of passes
	for (pass = 1; pass < SIZE; ++pass) {

		// loop to control number of comparisons per pass
		for (j = 0; j < SIZE - 1; ++j) {
			// swap if element is greater
			if (a[j] > a[j + 1]) {
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
				bubbleSwap = bubbleSwap + 1;
			}// end if
			comparison = comparison + 1;
		}// end inner for
	
}// end outer for
	printf("%25s\n", "BUBBLE SORT");
	printf("Number of bubble sort comparisons are: %d\n", comparison);
	printf("No. of bubble sort swaps are: %d\n", bubbleSwap);
	end = clock();
	bubbleTime = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Bubble sort time: %f", bubbleTime);
}

// prints array
void printArray(float a[])
{
	size_t i; //counter

	// output array contents
	for (i = 0; i < SIZE; ++i) {

		if (i % 20 == 0) { // begin new line every x values
			puts("");
		}
		printf("%f ", a[i]); // note to self - type may change later also with header!!
	}
}

void selectionSort(float a[])
{
	int i, j, position;
	float hold;
	int comparison = 0;
	int swaps = 0;
	int x = 0;

	clock_t start, end;
	double selectionTime;
	start = clock();

	for (i = 0; i < (SIZE - 1); i++) {
		position = i;
		for (j = i + 1; j < SIZE; j++) {
			if (a[position] > a[j])
				position = j;
			comparison = comparison +1; // number of comparisons made
		}// end if
		
		if (position != i) {
			hold = a[i];
			a[i] = a[position];
			a[position] = hold;	
			swaps = swaps + 1;
		}// end if
		
	} // outer for loop
	printf("%25s\n", "SELECTION SORT");
	printf("Number of selection sort comparisons are: %d\n", comparison);
	printf("No. of selection sort swaps are: %d\n", swaps);
	end = clock();
	selectionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Selection sort time: %f", selectionTime);
}

void windData(float bubbleArray[])
{
	// Q2 Print out max and min wind speed from sorted array
	double max = bubbleArray[1139];
	double min = bubbleArray[0];
	printf("\nMax wind speed: %.3fmph\nMin wind speed %.3fmph\n", max, min);
	
	//take unsorted data and sort in to ranges
	int ranges[5] = { 0 }; // create array of ranges
	const int PSIZE = 5; // partitions size
	int partitions[PSIZE] = { 0 };

		//Creates 5 partitions between zero and max wind value
	for (int i = 0; i < PSIZE; i++) {
		partitions[i] = (max / PSIZE) * i;
	}

	for (long int i = 0; i < SIZE; i++) {
		
		if (data[i] >= partitions[0] && data[i] < partitions[1]) {
			ranges[0] = ranges[0] + 1;
		}
		else if (data[i] >= partitions[1] && data[i] < partitions[2]){
			ranges[1] = ranges[1] + 1;
		}
		else if (data[i] >= partitions[2] && data[i] < partitions[3]) {
			ranges[2] = ranges[2] + 1;
		}
		else if (data[i] >= partitions[3] && data[i] < partitions[4]) {
			ranges[3] = ranges[3] + 1;
		}
		else if (data[i] > partitions[4] ) {
			ranges[4] = ranges[4] + 1;
		}

	}//end of for
	puts("");

	// Q2 print out frequency in user friendly format
	printf(" *************************************** \n%s\n ***************************************\n", " Peak Wind at 80 Meters - June 25, 2013");
	printf("%16s%22s\n", "Range(mph)", "Frequency\n");
	printf("%9d - %d%20d\n\n%9d - %d%20d\n\n%9d - %d%19d\n\n%9d - %d%19d\n\n%9d - %.0f%19d\n", partitions[0], partitions[1], ranges[0], partitions[1], partitions[2], ranges[1], partitions[2], partitions[3], ranges[2], partitions[3], partitions[4], ranges[3], partitions[4], max, ranges[4]);

}// end of function




