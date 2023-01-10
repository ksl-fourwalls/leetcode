#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int* plusOne(int *digits, int digitsSize, int *returnSize)
{
	int idx, *outarray, carry = 1;
	bool isallnines = true;

	for (idx = 0; idx < digitsSize; idx++)
	{
		if (digits[idx] != 9)
		{
			isallnines = false;
			break;
		}
	}
	*returnSize = isallnines ? digitsSize + 1 : 
		digitsSize; 	// decrease to one if only

	outarray = malloc(*returnSize * sizeof(int));
	assert(outarray != NULL);

	digitsSize--;
	idx = *returnSize-1;

	for (; digitsSize >= 0; digitsSize--, idx--)
	{
		if ((digits[digitsSize] + carry) == 10)
		{
			outarray[idx] = 0;
			carry = 1;
		}
		else
		{
			outarray[idx] = digits[digitsSize] + carry;
			carry = 0;
		}

	}
	outarray[idx] += carry;
	return outarray;
}


#define arraysize(array) (sizeof(array)/sizeof(*array))

int main(int argc, char *argv[])
{
	int digits[] = { 1, 0, 0, 0, 0 };
	int *outputArray, size;

	outputArray = plusOne(digits, arraysize(digits), &size);

	for (int idx = 0; idx < size; idx++)
		printf("%d", outputArray[idx]);

	free(outputArray);
	return 0;
}
