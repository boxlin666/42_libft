#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(libft, ft_memset)
{
    char str[20] = "Hello World";
    ft_memset(str, 'X', 5);
    cr_assert_str_eq(str, "XXXXX World", "Expected: XXXXX World");
}

Test(libft, ft_bzero)
{
    char str[20] = "Hello World";
    ft_bzero(str, 5);
    cr_assert_str_eq(str, "\0\0\0\0\0 World", "Expected: \0\0\0\0\0 World");
}

Test(libft, ft_memcpy)
{
    char dest[20];
    char *src = "Hello World";
    char *result = ft_memcpy(dest, src, 5);
    cr_assert_str_eq(result, "Hello", "Expected: Hello");
    cr_assert_str_eq(dest, "Hello", "Expected: Hello");
}

Test(libft, ft_memccpy)
{
    char dest[20];
    char *src = "Hello World";
    char *result1 = ft_memccpy(dest, src, 'o', 5);
    char *result2 = memccpy(dest, src, 'o', 5);
    cr_assert_str_eq(result1, result2, "Expected: %s; Result: %s", result2, result1);
}

Test(libft, ft_memmove_various_cases)
{
    // Case 1: Basic copy
    {
        char src[20] = "Hello World";
        char dest[20];
        char expected[20];
        memmove(expected, src, sizeof(src));
        ft_memmove(dest, src, sizeof(src));
        cr_assert_str_eq(dest, expected, "Basic copy failed. Expected: %s; Got: %s", expected, dest);
    }

    // Case 2: Overlapping (dest > src)
    {
        char buffer1[] = "123456789";
        char buffer2[] = "123456789";
        memmove(buffer1 + 3, buffer1, sizeof(buffer1) - 4);
        ft_memmove(buffer2 + 3, buffer2, sizeof(buffer2) - 4);
        cr_assert_str_eq(buffer2, buffer1, "Overlap (dest > src) failed. Expected: %s; Got: %s", buffer1, buffer2);
    }

    // Case 3: Overlapping (src > dest)
    {
        char buffer1[] = "123456789";
        char buffer2[] = "123456789";
        memmove(buffer1, buffer1 + 3, sizeof(buffer1) - 4);
        ft_memmove(buffer2, buffer2 + 3, sizeof(buffer2) - 4);
        cr_assert_str_eq(buffer2, buffer1, "Overlap (src > dest) failed. Expected: %s; Got: %s", buffer1, buffer2);
    }

    // Case 4: NULL pointers with size 0
    {
        char *null_ptr1 = NULL;
        char *null_ptr2 = NULL;
        memmove(null_ptr1, null_ptr1, 0);
        ft_memmove(null_ptr2, null_ptr2, 0);
        cr_assert_null(null_ptr2, "NULL with zero size should stay NULL.");
    }
}

Test(libft, ft_memchr)
{
    char str[] = "Hello World";
    cr_assert_str_eq(ft_memchr(str, 'o', 5), "o World", "Expected: o World");
    // cr_assert_eq(ft_memchr(str, 'x', 5), NULL, "Expected: NULL");
    cr_assert_null(ft_memchr(str, 'x', 5), "Expected: NULL");
    cr_assert_str_eq(ft_memchr(str, 'H', 5), "Hello World", "Expected: Hello World");
}

Test(libft, ft_memcmp)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    cr_assert_eq(ft_memcmp(arr1, arr2, sizeof(arr1)), -1, "Expected: -1");
    cr_assert_eq(ft_memcmp("Hello", "Hello", 5), 0, "Expected: 0");
    cr_assert_lt(ft_memcmp("Hello", "World", 5), 0, "Expected: lt 0; Result: %d", ft_memcmp("Hello", "World", 5));
}

Test(libft, ft_strlen)
{
    char str[] = "Hello World";
    cr_assert_eq(ft_strlen(str), 11, "Expected: 11");
    cr_assert_eq(ft_strlen(""), 0, "Expected: 0");
    cr_assert_eq(ft_strlen("Hello"), 5, "Expected: 5");
}

Test(libft, ft_strdup)
{
    char str[] = "Hello World";
    char *dup = ft_strdup(str);
    cr_assert_str_eq(dup, str, "Expected: Hello World");
    free(dup);
}

Test(libft, ft_strcpy)
{
    char dest[20];
    char *src = "Hello World";
    char *result = ft_strcpy(dest, src);
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World");
    cr_assert_str_eq(dest, "Hello World", "Expected: Hello World");
}

Test(libft, ft_strncpy)
{
    char dest[20];
    char *src = "Hello World";
    char *result = ft_strncpy(dest, src, 5);
    cr_assert_str_eq(result, "Hello", "Expected: Hello");
    cr_assert_str_eq(dest, "Hello", "Expected: Hello");
}

Test(libft, ft_strcat)
{
    char dest[20] = "Hello";
    char *src = " World";
    char *result = ft_strcat(dest, src);
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World");
    cr_assert_str_eq(dest, "Hello World", "Expected: Hello World");
}

Test(libft, ft_strncat)
{
    char dest[20] = "Hello";
    char *src = " World";
    char *result = ft_strncat(dest, src, 4);
    cr_assert_str_eq(result, "Hello Wor", "Expected: Hello Wor");
    cr_assert_str_eq(dest, "Hello Wor", "Expected: Hello Wor");
}

Test(libft, ft_strlcat)
{
    char dest[20] = "Hello";
    char *src = " World";
    size_t result = ft_strlcat(dest, src, sizeof(dest));
    cr_assert_eq(result, 11, "Expected: 11");
    cr_assert_str_eq(dest, "Hello World", "Expected: Hello World");
}

Test(libft, ft_strchr)
{
    char str[] = "Hello World";
    cr_assert_str_eq(ft_strchr(str, 'o'), "o World", "Expected: o World");
    cr_assert_eq(ft_strchr(str, 'x'), NULL, "Expected: NULL");
    cr_assert_str_eq(ft_strchr(str, 'H'), "Hello World", "Expected: Hello World");
}
Test(libft, ft_strrchr)
{
    char str[] = "Hello World";
    cr_assert_null(ft_strrchr(str, 'x'), "Expected: NULL");
    cr_assert_str_eq(ft_strrchr(str, 'o'), strrchr(str, 'o'), "Expected: o World");
}

Test(libft, ft_strstr)
{
    char str[] = "Hello World";
    cr_assert_str_eq(ft_strstr(str, "World"), "World", "Expected: World");
    cr_assert_eq(ft_strstr(str, "x"), NULL, "Expected: NULL");
    cr_assert_str_eq(ft_strstr(str, "Hello"), "Hello World", "Expected: Hello World");
}

Test(libft, ft_strnstr)
{
    char str[] = "Hello World";
    cr_assert_null(ft_strnstr(str, "x", 5), "Expected: NULL");
    cr_assert_str_eq(ft_strnstr(str, "Hello", 5), "Hello World", "Expected: Hello World; Result: %s", ft_strnstr(str, "Hello", 5));
    cr_assert_eq(ft_strnstr(str, "x", 5), NULL, "Expected: NULL");
}
Test(libft, ft_strcmp)
{
    cr_assert_eq(ft_strcmp("Hello", "Hello"), 0, "Expected: 0");
    cr_assert_lt(ft_strcmp("Hello", "World"), 0, "Expected: lt 0");
    cr_assert_gt(ft_strcmp("World", "Hello"), 0, "Expected: gt 0");
}
Test(libft, ft_strncmp)
{
    cr_assert_eq(ft_strncmp("Hello", "Hello", 5), 0, "Expected: 0");
    cr_assert_lt(ft_strncmp("Hello", "World", 5), 0, "Expected: lt 0");
    cr_assert_gt(ft_strncmp("World", "Hello", 5), 0, "Expected: gt 0");
}

Test(libft, ft_atoi)
{
    cr_assert_eq(ft_atoi(" \n\t-0"), atoi(" \n\t-0"), "Expected: 0");
    cr_assert_eq(ft_atoi("-2147483648"), atoi("-2147483648"), "Expected: -2147483648");
    cr_assert_eq(ft_atoi("2147483647"), atoi("2147483647"), "Expected: 2147483647");
    cr_assert_eq(ft_atoi("-2147483649"), atoi("-2147483649"), "Expected: 0");
    cr_assert_eq(ft_atoi("2147483648"), atoi("2147483648"), "Expected: 0");
}

Test(libft, ft_isalpha)
{
    cr_assert_eq(ft_isalpha('a'), 1, "Expected: 1");
    cr_assert_eq(ft_isalpha('Z'), 1, "Expected: 1");
    cr_assert_eq(ft_isalpha('1'), 0, "Expected: 0");
    cr_assert_eq(ft_isalpha(' '), 0, "Expected: 0");
}

Test(libft, ft_isdigit)
{
    cr_assert_eq(ft_isdigit('0'), 1, "Expected: 1");
    cr_assert_eq(ft_isdigit('9'), 1, "Expected: 1");
    cr_assert_eq(ft_isdigit('a'), 0, "Expected: 0");
    cr_assert_eq(ft_isdigit(' '), 0, "Expected: 0");
}

Test(libft, ft_isalnum)
{
    cr_assert_eq(ft_isalnum('a'), 1, "Expected: 1");
    cr_assert_eq(ft_isalnum('Z'), 1, "Expected: 1");
    cr_assert_eq(ft_isalnum('1'), 1, "Expected: 1");
    cr_assert_eq(ft_isalnum(' '), 0, "Expected: 0");
}

Test(libft, ft_isascii)
{
    cr_assert_eq(ft_isascii('a'), 1, "Expected: 1");
    cr_assert_eq(ft_isascii(127), 1, "Expected: 1");
    cr_assert_eq(ft_isascii(128), 0, "Expected: 0");
    cr_assert_eq(ft_isascii(' '), 1, "Expected: 1");
}

Test(libft, ft_isprint)
{
    cr_assert_eq(ft_isprint('a'), 1, "Expected: 1");
    cr_assert_eq(ft_isprint(127), 0, "Expected: 0");
    cr_assert_eq(ft_isprint(128), 0, "Expected: 0");
    cr_assert_eq(ft_isprint(' '), 1, "Expected: 1");
}

Test(libft, ft_toupper)
{
    char c = 'a';
    c = ft_toupper(c);
    cr_assert_eq(c, 'A', "Expected: A");
    c = 'Z';
    c = ft_toupper(c);
    cr_assert_eq(c, 'Z', "Expected: Z");
    c = '1';
    c = ft_toupper(c);
    cr_assert_eq(c, '1', "Expected: 1");
}
Test(libft, ft_tolower)
{
    char c = 'A';
    c = ft_tolower(c);
    cr_assert_eq(c, 'a', "Expected: a; Result: %c", c);
    c = 'z';
    c = ft_tolower(c);
    cr_assert_eq(c, 'z', "Expected: z");
    c = '1';
    c = ft_tolower(c);
    cr_assert_eq(c, '1', "Expected: 1");
}

/* Additional Functions*/
Test(libft, ft_memalloc)
{
    char *ptr = ft_memalloc(10);
    cr_assert_not_null(ptr, "Expected: Non-null pointer");
    free(ptr);
}
Test(libft, ft_memdel)
{
    char *ptr = malloc(10);
    ft_memdel((void **)&ptr);
    cr_assert_null(ptr, "Expected: NULL");
}
Test(libft, ft_strnew)
{
    char *str = ft_strnew(10);
    cr_assert_not_null(str, "Expected: Non-null pointer");
    free(str);
}
Test(libft, ft_strdel)
{
    char *str = malloc(10);
    ft_strdel(&str);
    cr_assert_null(str, "Expected: NULL");
}

Test(libft, ft_strclr)
{
    char str[] = "Hello World";
    ft_strclr(str);
    cr_assert_str_eq(str, "", "Expected: Empty string");
}

void to_upper(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}
void to_upper_index(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c -= 32 + i;
}

Test(libft, ft_striter)
{
    char str[] = "hello";
    ft_striter(str, to_upper);
    cr_assert_str_eq(str, "HELLO", "Expected: HELLO");
}

Test(libft, ft_striteri)
{
    char str[] = "hello";
    ft_striteri(str, to_upper_index);
    cr_assert_str_eq(str, "HDJIK", "Expected: HDJIK; Result: %s", str);
}

char map_func(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

char map_funci(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A' + i;
    return c;
}
Test(libft, ft_strmap)
{
    char str[] = "hello";
    char *result = ft_strmap(str, map_func);
    cr_assert_str_eq(result, "HELLO", "Expected: HELLO");
    free(result);
}

Test(libft, ft_strmapi)
{
    char str[] = "hello";
    char *result = ft_strmapi(str, map_funci);
    cr_assert_str_eq(result, "HFNOS", "Expected: HFNOS");
    free(result);
}

Test(libft, ft_strequ)
{
    cr_assert_eq(ft_strequ("Hello", "Hello"), 1, "Expected: 1");
    cr_assert_eq(ft_strequ("Hello", "World"), 0, "Expected: 0");
}

Test(libft, ft_strnequ)
{
    cr_assert_eq(ft_strnequ("Hello", "Hello", 5), 1, "Expected: 1");
    cr_assert_eq(ft_strnequ("Hello", "World", 5), 0, "Expected: 0");
}

Test(libft, ft_strsub)
{
    char str[] = "Hello World";
    char *result = ft_strsub(str, 0, 5);
    cr_assert_str_eq(result, "Hello", "Expected: Hello");
    free(result);
}

Test(libft, ft_strjoin)
{
    char *s1 = "Hello";
    char *s2 = " World";
    char *result = ft_strjoin(s1, s2);
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World");
    free(result);
}

Test(libft, ft_strtrim)
{
    char str[] = "   Hello World   ";
    char *result = ft_strtrim(str);
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World");
    free(result);
}
Test(libft, ft_strsplit)
{
    char str[] = "Hello World";
    char **result = ft_strsplit(str, ' ');
    cr_assert_str_eq(result[0], "Hello", "Expected: Hello");
    cr_assert_str_eq(result[1], "World", "Expected: World");
    free(result[0]);
    free(result[1]);
    free(result);
}

Test(libft, ft_itoa)
{
    char *result = ft_itoa(12345);
    cr_assert_str_eq(result, "12345", "Expected: 12345; Result: %s", result);
    free(result);
}

Test(libft, ft_putchar)
{
    redirect_all_stdout();
    ft_putchar('A');
    cr_assert_stdout_eq_str("A", "Expected: A");
}

Test(libft, ft_putstr)
{
    redirect_all_stdout();
    ft_putstr("Hello");
    cr_assert_stdout_eq_str("Hello", "Expected: Hello");
}

Test(libft, ft_putendl)
{
    redirect_all_stdout();
    ft_putendl("Hello");
    cr_assert_stdout_eq_str("Hello\n", "Expected: Hello\n");
}

Test(libft, ft_putnbr)
{
    redirect_all_stdout();
    ft_putnbr(12345);
    cr_assert_stdout_eq_str("12345", "Expected: 12345");
}

Test(libft, ft_putchar_fd)
{
    redirect_all_stdout();
    ft_putchar_fd('A', 1);
    cr_assert_stdout_eq_str("A", "Expected: A");
}

Test(libft, ft_putstr_fd)
{
    redirect_all_stdout();
    ft_putstr_fd("Hello", 1);
    cr_assert_stdout_eq_str("Hello", "Expected: Hello");
}

Test(libft, ft_putendl_fd)
{
    redirect_all_stdout();
    ft_putendl_fd("Hello", 1);
    cr_assert_stdout_eq_str("Hello\n", "Expected: Hello\n");
}

Test(libft, ft_putnbr_fd)
{
    redirect_all_stdout();
    ft_putnbr_fd(12345, 1);
    cr_assert_stdout_eq_str("12345", "Expected: 12345");
}

// list functions
void	del_mock(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}
Test(libft, ft_lstnew)
{
    char *content = "Hello";
    t_list *node = ft_lstnew(content, 5);
    cr_assert_str_eq(node->content, content, "Expected: Hello");
    cr_assert_eq(node->content_size, 5, "Expected: 5");
    free(node->content);
    free(node);
}

Test(libft, ft_lstdelone)
{
    char *content = "Hello";
    t_list *node = ft_lstnew(content, 5);
    ft_lstdelone(&node, del_mock);
    cr_assert_null(node, "Expected: NULL");
}



Test(libft, ft_lstdel)
{
    char *content1 = "Hello";
    char *content2 = "World";
    t_list *node1 = ft_lstnew(content1, 5);
    t_list *node2 = ft_lstnew(content2, 5);
    node1->next = node2;
    ft_lstdel(&node1, del_mock);
    cr_assert_null(node1, "Expected: NULL");
    cr_assert_null(node2, "Expected: NULL");
}

Test(libft, ft_lstadd)
{
    char *content1 = "Hello";
    char *content2 = "World";
    t_list *node1 = ft_lstnew(content1, 5);
    t_list *node2 = ft_lstnew(content2, 5);
    ft_lstadd(&node1, node2);
    cr_assert_eq(node1->next, node2, "Expected: node2");
    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}


Test(libft, ft_lstiter)
{
    char *content1 = "Hello";
    char *content2 = "World";
    t_list *node1 = ft_lstnew(content1, 5);
    t_list *node2 = ft_lstnew(content2, 5);
    node1->next = node2;
    int count = 0;

    ft_lstiter(node1, count_func);
    cr_assert_eq(count, 2, "Expected: 2");
    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}

Test(libft, ft_lstmap)
{
    char *content1 = "Hello";
    char *content2 = "World";
    t_list *node1 = ft_lstnew(content1, 5);
    t_list *node2 = ft_lstnew(content2, 5);
    node1->next = node2;
    t_list *result = ft_lstmap(node1, ft_lstnew);
    cr_assert_str_eq(result->content, content1, "Expected: Hello");
    cr_assert_str_eq(result->next->content, content2, "Expected: World");
    free(node1->content);
    free(node2->content);
    free(node1);
    free(node2);
}
