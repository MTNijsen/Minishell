/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 20:28:58 by lde-koni      #+#    #+#                 */
/*   Updated: 2024/10/02 20:26:48 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
num_elem = The number of elements you want to allocate memory for.
size_elem = The size (in bytes) of each element. */

#include "test.h"

void	*ft_calloc(size_t num_elem, size_t size_elem)
{
	void	*ptr;

	if (size_elem != 0 && (num_elem * size_elem) / size_elem != num_elem)
		return (NULL);
	ptr = malloc(num_elem * size_elem);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (num_elem * size_elem));
	return (ptr);
}

// int main() {
//     size_t numElements = 5;
//     size_t elementSize = sizeof(int);

//     // Using the standard calloc function
//     int* callocArray = (int*)calloc(numElements, elementSize);
//     if (callocArray != NULL) {
//         printf("Memory allocated using calloc:\n");

//         size_t i = 0;
//         while (i < numElements) {
//             printf("callocArray[%zu] = %d\n", i, callocArray[i]);
//             i++;
//         }
//     } else {
//         printf("Memory allocation using calloc failed.\n");
//     }

//     // Using the custom ft_calloc function
//     int* ftCallocArray = (int*)ft_calloc(numElements, elementSize);
//     if (ftCallocArray != NULL) {
//         printf("\nMemory allocated using ft_calloc:\n");

//         size_t i = 0;
//         while (i < numElements) {
//             printf("ftCallocArray[%zu] = %d\n", i, ftCallocArray[i]);
//             i++;
//         }
//         free(ftCallocArray); // Free the memory allocated by ft_calloc
//     } else {
//         printf("Memory allocation using ft_calloc failed.\n");
//     }

//     // Free the memory allocated by calloc
//     free(callocArray);

//     return 0;
// }