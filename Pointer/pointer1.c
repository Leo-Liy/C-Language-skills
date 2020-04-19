#include <stdio.h>

int* move_p(int *pointer, int arr[]){
	pointer = &arr[1];
	return pointer;
}

int main()
{
	int arr[]={5, 6, 7, 8, 9};
	int *p = &arr[0];
	p = move_p(p, arr);
	printf("%d\n", *p);
}
