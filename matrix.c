#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/**
 * @fn	    alloc_cont_mem_sq_mat(double *** A, const int N)
 * @brief	parse command line
 * @author	ZM
 * @date	2020/12/07
 * @returns	return 1
 * 			return 0
 */
int alloc_cont_mem_sq_mat(double *** A, const int N)
{
	int i;
	//Pointer to allocated N*N matrix Pointers: dynamically allocated memory, allocated memory for n array Pointers
	double** datapoints=(double**)malloc(N * sizeof(double *));
	if(datapoints==NULL)
	{
		perror("Error allocating memory for matrix\n");
		return 1;
	}
	//Allocates N*N matrix (decimal) : dynamically allocates memory for N*N array Pointers
	double *data=(double *) malloc(N * N * sizeof(double));
	if(data==NULL)
	{
		perror("Error allocating memory for matrix\n");
		return 1;
	}
	for(i = 0; i < N; i++)
	{
		//N*N matrix pointer: using memory bias, using a one-dimensional array as a pointer to a continuous two-dimensional array
		datapoints[i] = data + i * N;
	}
   	*A=datapoints;
    return 0;
}

/**
 * @fn	    print_sq_matrix(double *const *const A, const int dim)
 * @brief	print an dim*dim square matrix(B) in screen
 * @author	ZM
 * @date	2020/12/07
 * @returns	printf
 */
void print_sq_matrix(double *const *const A, const int dim)
{
	int i,j;
	for(i = 0;i < dim;i++)
	{
		printf("|\t");//alignment
		for(j=0;j<dim;j++)
		{
			printf("%.1lf\t",A[i][j]);
		}
		printf("|\n");//change a new line
	}
}

