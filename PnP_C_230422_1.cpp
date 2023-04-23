#include <stdio.h>

void swap(long long* i, long long* j)
{
	long long temp = *i;

	*i = *j;
	*j = temp;


	return;
}

void quicksort(long long arr[], long long lower, long long upper)
{
	if (lower >= upper)
	{
		return;
	}

	long long pivot = lower;
	long long L = lower + 1;
	long long R = upper;

	while (L < R)
	{
		while (L < R && arr[L] <= arr[pivot])
		{
			L++;
		}
		while (R > L && arr[R] > arr[pivot])
		{
			R--;
		}

		swap(&arr[L], &arr[R]);
	}

	swap(&arr[pivot], &pivot[R - 1]);

	quicksort(arr, lower, (pivot - 1));
	quicksort(arr, (pivot + 1), upper);
}

void print_array(long long arr[], long long N)
{
	for (int q = 0; q < N; q++)
	{
		printf("%lld \n", arr[q]);
	}


	return;
}

int main()
{
	long long arr[10000001] = { 0 };
	long long N = 0;

	scanf("%lld", &N);

	for (int q = 0; q < N; q++)
	{
		scanf("%lld", &arr[q]);
	}

	quicksort(arr, 0, N - 1);
	print_array(arr, N);


	return 0;
}