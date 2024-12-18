

#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
static int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to sort an array of integers
void sortArray(int *array, size_t size) {
    qsort(array, size, sizeof(int), compare);

}

int abs(int x) {
    return (x < 0) ? -x : x;
}

int main(){
	FILE *file = fopen("numbers", "r");

	if (file == NULL){
		return 1;
	}

	int firstArray[1000];
	int secondArray[1000];
	int first = 0;
	int second = 0;
	int i = 0;
	while(fscanf(file, "%d   %d", &first, &second) == 2){
		firstArray[i] = first;
		secondArray[i] = second;
		i++;
	}

	int firstSize = sizeof(firstArray) / sizeof(firstArray[0]);
	int secondSize = sizeof(secondArray) / sizeof(secondArray[0]);

	sortArray(firstArray, firstSize);
	sortArray(secondArray, secondSize);


	int sum = 0;
	for (int k = 0; k < firstSize; k++){
		int sameNums = 0;
		for(int j = 0; j < secondSize; j++){
			if(firstArray[k] == secondArray[j]){
				sameNums++;
			}
		}
		sum += sameNums * firstArray[k];
	}
	printf("Sum: %d\n", sum);

	fclose(file);
	return 0;

}
