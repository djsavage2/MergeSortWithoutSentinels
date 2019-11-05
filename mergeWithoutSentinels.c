#include<stdio.h>
#include<math.h>

void PrintArray(int A[], int beg, int end) {
	for (int i = beg; i < end; i++) {
		printf("%d ", A[i]);
		printf("\n");
	}
}

void Merge(int A[], int p, int q, int r) {
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	printf("Array L before merging:\n");
	PrintArray(L, 0,  n1);
	for (j = 0; j < n2; j++) {
		R[j] = A[q + 1 + j];
	}
	printf("Array R before merging:\n");
	PrintArray(R, 0,  n2);
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
	printf("Resulting array after merging L and R:\n");
	PrintArray(A, p,  r + 1);
}

void MergeSort(int A[], int p, int r) {	
	printf("\nArray inside MergeSort function:\n");
	PrintArray(A, p, r + 1);
	if (p < r) {
		printf("p < r, so MergeSort function is recursively called\n");
		int q = floor(p + (r - p) / 2);
		printf("Subarray A[%d...%d] to be sorted:\n", p, q);
		MergeSort(A, p, q);
		printf("Subarray A[%d...%d] to be sorted:\n", q + 1, r);
		MergeSort(A, q + 1, r);
		printf("PREPARE TO MERGE!\n\n");
		Merge(A, p, q, r);
	} else {
		printf("\nBase Case Reached!\n");
	}
	printf("\n*********************************************************************\n");
}

int main() {
	int arr[] = {3, 41, 52, 26, 38, 57, 9, 49};
	int arr_size = sizeof(arr)/sizeof(arr[0]);			
	printf("Array before sorting:\n");
	PrintArray(arr, 0, arr_size);
	MergeSort(arr, 0, arr_size - 1);
	printf("Array after sorting:\n");
	PrintArray(arr, 0, arr_size);
	return 0;
}
