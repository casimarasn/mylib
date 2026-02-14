/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:06:10 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/14 22:12:50 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

/* Structures */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_atod
{
	double		frac;
	double		base;
	double		val;
	const char	*paki;
	int			point;
}				t_atod;

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

/* ========================================== */
/*               CHARACTER TYPE               */
/* ========================================== */

/**
 * @brief Checks for an alphabetic character.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 */
int			ft_isdigit(int n);

/**
 * @brief Checks for an alphanumeric character.
 */
int			ft_isalnum(int a);

/**
 * @brief Checks whether c is a 7-bit unsigned char value that fits
 * into the ASCII character set.
 */
int			ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 */
int			ft_isprint(int p);

/**
 * @brief Checks for white-space characters.
 */
int			ft_isspace(int c);

/**
 * @brief Converts a letter to lowercase.
 */
int			ft_tolower(int c);

/**
 * @brief Converts a letter to uppercase.
 */
int			ft_toupper(int c);

/* ========================================== */
/*                   MEMORY                   */
/* ========================================== */

/**
 * @brief Fills the first n bytes of the memory area pointed to by
 * s with the constant byte c.
 */
void		*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location
 * pointed to by s, by writing zeros (bytes containing '\0') to that area.
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 */
void		*ft_calloc(size_t nmeb, size_t sizem);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap.
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to
 * by s for the first instance of c.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* ========================================== */
/*                   STRING                   */
/* ========================================== */

/**
 * @brief Calculates the length of the string pointed to by s,
 * excluding the terminating null byte.
 */
size_t		ft_strlen(const char *s);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 * to dst, NUL-terminating the result.
 */
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
 * the result.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Returns a pointer to the first occurrence of the character c
 * in the string s.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the character c
 * in the string s.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the two strings s1 and s2. It returns an integer less than,
 * equal to, or greater than zero if s1 is found, respectively, to be less than,
 * to match, or be greater than s2.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string little
 * in the string big, where not more than len characters are searched.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string s.
 */
char		*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of 's1' and 's2'.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of 's1', a space, and 's2'.
 */
char		*ft_strjoin_space(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with the characters specified
 * çin 'set' removed from the beginning and the end of the string.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's'
 * using the character 'c' as a delimiter.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Applies the function 'f' to each character of the string 's'
 * to create a new string resulting from successive applications of 'f'.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' to each character of the string 's',
 * passing its index as the first argument.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ========================================== */
/*               CONVERSIONS                  */
/* ========================================== */

/**
 * @brief Converts the initial portion of the string pointed to by str
 * to int representation.
 */
int			ft_atoi(const char *str);

/**
 * @brief Converts string to long with strict error handling.
 */
int			ft_atoi_strict(const char *str, long *num);

/**
 * @brief Allocates and returns a string representing the integer
 * received as an argument.
 */
char		*ft_itoa(int n);

/**
 * @brief Converts the initial portion of the string pointed to
 * by s to double representation.
 */
double		ft_atod(const char *s, t_atod *atod);

/* ========================================== */
/*               MATH                         */
/* ========================================== */

/**
 * @brief Returns the absolute value of the integer n.
 */
int			ft_abs(int n);

/**
 * @brief Sorts an array of integers in ascending order.
 */
void		sort_int_array(int *arr, int size);

/* ========================================== */
/*               PUT (Output FD)              */
/* ========================================== */

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor,
 * followed by a newline.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 */
void		ft_putnbr_fd(int n, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 */
void		ft_putstr_fd(char *s, int fd);

/* ========================================== */
/*               LISTS                        */
/* ========================================== */

/**
 * @brief Allocates and returns a new element. The variable 'content'
 * is initialized with the value of the parameter 'content'. 'next'
 * is initialized to NULL.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element 'new' at the beginning of the list.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 */
int			ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element 'new' at the end of the list.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the memory of the
 * element’s content using the function 'del' given as a parameter
 * and free the element.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Deletes and frees the given element and every successor of
 * that element, using the function 'del' and free(3).
 */
void		ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Iterates the list 'lst' and applies the function 'f'
 * to the content of each element.
 */
void		ft_lstiter(t_list *lst, void (*f)(void*));

/**
 * @brief Iterates the list 'lst' and applies the function 'f'
 * to the content of each element. Creates a new list resulting of
 * the successive applications of the function 'f'.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *));

/* ========================================== */
/*               GNL (Get Next Line)          */
/* ========================================== */

/**
 * @brief Reads a line from the specified file descriptor.
 */
char		*get_next_line(int fd);

/* ========================================== */
/*               PRINTF                       */
/* ========================================== */

/**
 * @brief Custom implementation of printf. Formats and prints data
 * to the standard output.
 */
int			ft_printf(char const *format, ...);

/**
 * @brief Prints a single character. Helper for ft_printf.
 */
int			ft_print_char(char c);

/**
 * @brief Prints a string. Helper for ft_printf.
 */
int			ft_print_string(char *str);

/**
 * @brief Prints a number. Helper for ft_printf.
 */
int			ft_print_nbr(int n);

/**
 * @brief Prints an unsigned number. Helper for ft_printf.
 */
int			ft_print_unsigned(unsigned int n);

/**
 * @brief Prints a number in hexadecimal (lowercase). Helper for ft_printf.
 */
int			ft_print_hexdecmi(unsigned long long int n);

/**
 * @brief Prints a number in hexadecimal (uppercase). Helper for ft_printf.
 */
int			ft_print_hexdecma(unsigned long long n);

/**
 * @brief Prints a memory address pointer in hexadecimal. Helper for ft_printf.
 */
int			ft_print_pointer(void *str);

/**
 * @brief Prints a percent sign. Helper for ft_printf.
 */
int			ft_print_percent(void);

/**
 * @brief Parses formatting flags. Helper for ft_printf.
 */
int			ft_print_format(va_list args, char c);

#endif
