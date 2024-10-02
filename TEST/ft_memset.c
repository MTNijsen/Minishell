/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 18:30:55 by lde-koni      #+#    #+#                 */
/*   Updated: 2024/10/02 20:26:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*The memset() function fills the first n bytes of the memory area pointed to 
by s with the constant byte c. The memset() function returns a pointer to 
the memory area s.*/

#include "test.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = ((unsigned char)c);
		i++;
	}
	return (s);
}

// int main() {
// 	/*HERE STARTS TEST 1*/

//     char str1[20]; // Declare an array to work with
//     char str2[20]; // Declare an array to work with
// 	char *ptr;

//     // Use your custom ft_memset function
//     ft_memset(str1, 'A', 10);

//     // Display the result of ft_memset
//     printf("Result of ft_memset: ");
//     ptr = str1;
//     while (*ptr) {
//         printf("%c ", *ptr);
//         ptr++;
//     }
//     printf("\n");

//     // Use the standard memset function
//     memset(str2, 'A', 10);

//     // Display the result of memset
//     printf("Result of memset: ");
//     ptr = str2;
//     while (*ptr) {
//         printf("%c ", *ptr);
//         ptr++;
//     }
//     printf("\n");

//     // Compare the results
//     if (memcmp(str1, str2, 10) == 0) {
//         printf("Both filled the array with 'A' as expected.\n");
//     } else {
//         printf("There is a difference between results.\n");
//     }

//     // Compare the results
//     int diffIndex = -1;
//     int i = 0;

//     while (i < 10) {
//         if (str1[i] != str2[i]) {
//             diffIndex = i;
//             break;
//         }
//         i++;
//     }

//     if (diffIndex == -1) {
//         printf("Test completed. Same output.\n");
//     } else {
//         printf("Difference found at position %d: str1[%d]: 
//'%c' != str2[%d]: '%c'\n", diffIndex, diffIndex, str1[diffIndex], 
//diffIndex, str2[diffIndex]);
//     }

//     return 0;
// }