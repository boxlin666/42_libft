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

Test(ft_isalpha, basic)
{
    {
        char c = 'A';
        cr_assert_eq(ft_isalpha(c), 1, "Expected: 1; Got: %d", ft_isalpha(c));
    }
    {
        char c = 'a';
        cr_assert_eq(ft_isalpha(c), 1, "Expected: 1; Got: %d", ft_isalpha(c));
    }
    {
        char c = '1';
        cr_assert_eq(ft_isalpha(c), 0, "Expected: 0; Got: %d", ft_isalpha(c));
    }
    {
        char c = '!';
        cr_assert_eq(ft_isalpha(c), 0, "Expected: 0; Got: %d", ft_isalpha(c));
    }
}

Test(ft_isdigit, basic)
{
    {
        char c = '0';
        cr_assert_eq(ft_isdigit(c), 1, "Expected: 1; Got: %d", ft_isdigit(c));
    }
    {
        char c = '9';
        cr_assert_eq(ft_isdigit(c), 1, "Expected: 1; Got: %d", ft_isdigit(c));
    }
    {
        char c = 'a';
        cr_assert_eq(ft_isdigit(c), 0, "Expected: 0; Got: %d", ft_isdigit(c));
    }
    {
        char c = '!';
        cr_assert_eq(ft_isdigit(c), 0, "Expected: 0; Got: %d", ft_isdigit(c));
    }
}

Test(ft_isalnum, basic)
{
    {
        char c = 'A';
        cr_assert_eq(ft_isalnum(c), 1, "Expected: 1; Got: %d", ft_isalnum(c));
    }
    {
        char c = 'a';
        cr_assert_eq(ft_isalnum(c), 1, "Expected: 1; Got: %d", ft_isalnum(c));
    }
    {
        char c = '1';
        cr_assert_eq(ft_isalnum(c), 1, "Expected: 1; Got: %d", ft_isalnum(c));
    }
    {
        char c = '!';
        cr_assert_eq(ft_isalnum(c), 0, "Expected: 0; Got: %d", ft_isalnum(c));
    }
}

Test(ft_isascii, basic)
{
    {
        char c = 'A';
        cr_assert_eq(ft_isascii(c), 1, "Expected: 1; Got: %d", ft_isascii(c));
    }
    {
        char c = 127;
        cr_assert_eq(ft_isascii(c), 0, "Expected: 0; Got: %d", ft_isascii(c));
    }
    {
        char c = 128;
        cr_assert_eq(ft_isascii(c), 0, "Expected: 0; Got: %d", ft_isascii(c));
    }
    {
        char c = ' ';
        cr_assert_eq(ft_isascii(c), 1, "Expected: 1; Got: %d", ft_isascii(c));
    }
}

Test(ft_isprint, basic)
{
    {
        char c = 'A';
        cr_assert_eq(ft_isprint(c), 1, "Expected: 1; Got: %d", ft_isprint(c));
    }
    {
        char c = 128;
        cr_assert_eq(ft_isprint(c), 0, "Expected: 0; Got: %d", ft_isprint(c));
    }
    {
        char c = 12;
        cr_assert_eq(ft_isprint(c), 0, "Expected: 0; Got: %d", ft_isprint(c));
    }
    {
        char c = ' ';
        cr_assert_eq(ft_isprint(c), 1, "Expected: 1; Got: %d", ft_isprint(c));
    }
}

Test(ft_strlen, basic)
{
    {
        char *str = "Hello World";
        cr_assert_eq(ft_strlen(str), 11, "Expected: 11; Got: %zu", ft_strlen(str));
    }
    {
        char *str = "";
        cr_assert_eq(ft_strlen(str), 0, "Expected: 0; Got: %zu", ft_strlen(str));
    }
}

Test(ft_memset, sets_characters_correctly)
{
    char str[20] = "Hello World";
    ft_memset(str, 'X', 5);
    cr_assert_str_eq(str, "XXXXX World", "Expected: XXXXX World; Got: %s", str);
}

Test(ft_memset, sets_zeroes_correctly)
{
    char str[20] = "Hello World";
    ft_memset(str, 0, 11);
    for (int i = 0; i < 11; i++)
        cr_assert_eq(str[i], 0, "Expected byte %d to be 0", i);
}

Test(ft_bzero, sets_zeroes_correctly)
{
    char str[20] = "Hello World";
    ft_bzero(str, 5);
    for (int i = 0; i < 5; i++)
        cr_assert_eq((int)str[i], 0, "Expected byte %d to be 0", i);
    cr_assert_str_eq(str + 5, " World", "Expected unchanged remainder");
}

Test(ft_bzero, sets_zeroes_in_buffer)
{
    char buffer[10];
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, sizeof(buffer));
    for (int i = 0; i < 10; i++)
        cr_assert_eq((int)buffer[i], 0, "Expected byte %d to be 0", i);
}

Test(ft_memcpy, copy_string)
{
    char dest[20];
    char *src = "Hello World";
    char *result = ft_memcpy(dest, src, 5);
    dest[5] = '\0';
    cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
}

Test(ft_memcpy, copies_integers_correctly)
{
    int src[] = {1, 2, 3, 4, 5};
    int dest[5] = {0};
    ft_memcpy(dest, src, sizeof(src));
    for (int i = 0; i < 5; i++)
        cr_assert_eq(dest[i], src[i], "Expected dest[%d] == %d", i, src[i]);
}

Test(ft_memmove, dest_before_src)
{
    char dest[20] = "Hello World";
    char *src = "12345";
    ft_memmove(dest, src, 5);
    cr_assert_str_eq(dest, "12345 World", "Expected: 12345 World; Got: %s", dest);
}

Test(ft_memmove, src_before_dest)
{
    char dest[20] = "Hello World";
    char *src = "12345";
    ft_memmove(src, dest, 5);
    cr_assert_str_eq(src, "Hello12345", "Expected: Hello12345; Got: %s", src);
}

Test(ft_memmove, overlapping_memory)
{
    char str[20] = "Hello World";
    ft_memmove(str + 6, str, 5);
    cr_assert_str_eq(str, "Hello Hello", "Expected: Hello Hello; Got: %s", str);
}

Test(ft_strlcpy, basic)
{
    char dest[20];
    char *src = "Hello World";
    size_t res = ft_strlcpy(dest, src, sizeof(dest));
    cr_assert_eq(res, 11, "Expected: 11; Got: %zu", res);
    cr_assert_str_eq(dest, "Hello World", "Expected: Hello World; Got: %s", dest);
}

Test(ft_strlcpy, empty_string)
{
    char dest[20];
    char *src = "";
    size_t res = ft_strlcpy(dest, src, sizeof(dest));
    cr_assert_eq(res, 0, "Expected: 0; Got: %zu", res);
    cr_assert_str_eq(dest, "", "Expected empty string; Got: %s", dest);
}

Test(ft_strlcpy, buffer_too_small)
{
    char dest[5];
    char *src = "Hello World";
    size_t res = ft_strlcpy(dest, src, sizeof(dest));
    cr_assert_eq(res, 11, "Expected: 11; Got: %zu", res);
    cr_assert_str_eq(dest, "Hell", "Expected: Hell; Got: %s", dest);
}

Test(ft_strlcat, basic)
{
    char dest[20] = "Hello";
    char *src = " World";
    size_t res = ft_strlcat(dest, src, sizeof(dest));
    cr_assert_eq(res, 11, "Expected: 11; Got: %zu", res);
    cr_assert_str_eq(dest, "Hello World", "Expected: Hello World; Got: %s", dest);
}

Test(ft_strlcat, empty_string)
{
    char dest[20] = "";
    char *src = "Test";
    size_t res = ft_strlcat(dest, src, sizeof(dest));
    cr_assert_eq(res, 4, "Expected: 4; Got: %zu", res);
    cr_assert_str_eq(dest, "Test", "Expected: Test; Got: %s", dest);
}

Test(ft_strlcat, buffer_too_small)
{
    char dest[10] = "12345";
    size_t res = ft_strlcat(dest, "67890", sizeof(dest));
    cr_assert_eq(res, 10, "Expected: 10; Got: %zu", res);
}

Test(ft_strlcat, buffer_too_small_no_null)
{
    char dest[10] = "12345";
    size_t res = ft_strlcat(dest, "67890", sizeof(dest) - 1);
    cr_assert_eq(res, 10, "Expected: 10; Got: %zu", res);
    cr_assert_str_eq(dest, "123456789", "Expected: 123456789; Got: %s", dest);
}

Test(ft_toupper, basic)
{
    {
        char c = 'a';
        cr_assert_eq(ft_toupper(c), 'A', "Expected: A; Got: %c", ft_toupper(c));
    }
    {
        char c = 'A';
        cr_assert_eq(ft_toupper(c), 'A', "Expected: A; Got: %c", ft_toupper(c));
    }
    {
        char c = '1';
        cr_assert_eq(ft_toupper(c), '1', "Expected: 1; Got: %c", ft_toupper(c));
    }
    {
        char c = '!';
        cr_assert_eq(ft_toupper(c), '!', "Expected: !; Got: %c", ft_toupper(c));
    }
}

Test(ft_tolower, basic)
{
    {
        char c = 'A';
        cr_assert_eq(ft_tolower(c), 'a', "Expected: a; Got: %c", ft_tolower(c));
    }
    {
        char c = 'z';
        cr_assert_eq(ft_tolower(c), 'z', "Expected: z; Got: %c", ft_tolower(c));
    }
    {
        char c = '1';
        cr_assert_eq(ft_tolower(c), '1', "Expected: 1; Got: %c", ft_tolower(c));
    }
    {
        char c = '!';
        cr_assert_eq(ft_tolower(c), '!', "Expected: !; Got: %c", ft_tolower(c));
    }
}

Test(ft_strchr, basic)
{
    char *str = "Hello World";
    char *result = ft_strchr(str, 'W');
    cr_assert_str_eq(result, "World", "Expected: World; Got: %s", result);
}

Test(ft_strchr, no_ascii)
{
    char *str = "Hello World";
    char *result = ft_strchr(str, 'W' + 128);
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_strchr, empty_string)
{
    char *str = "";
    char *result = ft_strchr(str, 'W');
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_strrchr, basic)
{
    char *str = "Hello World";
    char *result = ft_strrchr(str, 'o');
    cr_assert_str_eq(result, "orld", "Expected: orld; Got: %s", result);
}

Test(ft_strrchr, no_ascii)
{
    char *str = "Hello World";
    char *result = ft_strrchr(str, 'W' + 128);
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_strrchr, empty_string)
{
    char *str = "";
    char *result = ft_strrchr(str, 'W');
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_strncmp, equal)
{
    char *str1 = "Hello";
    char *str2 = "Hello";
    int result = ft_strncmp(str1, str2, 5);
    cr_assert_eq(result, 0, "Expected: 0; Got: %d", result);
}

Test(ft_strncmp, not_equal)
{
    char *str1 = "Hello";
    char *str2 = "World";
    int result = ft_strncmp(str1, str2, 5);
    cr_assert_neq(result, 0, "Expected: not 0; Got: %d", result);
}

Test(ft_strncmp, different_length)
{
    char *str1 = "Hello";
    char *str2 = "Hello World";
    int result = ft_strncmp(str1, str2, 5);
    cr_assert_eq(result, 0, "Expected: 0; Got: %d", result);
}

Test(ft_memchr, basic)
{
    char str[] = "Hello World";
    char *p = ft_memchr(str, 'o', 11);
    cr_assert_not_null(p, "Expected non-null pointer for 'o'");
    cr_assert_str_eq(p, "o World", "Expected: o World; Got: %s", p);
}

Test(ft_memchr, no_ascii)
{
    char str[] = "Hello World";
    char *p = ft_memchr(str, 'W' + 128, 11);
    cr_assert_null(p, "Expected NULL; Got: %s", p);
}

Test(ft_memchr, empty_string)
{
    char str[] = "";
    char *p = ft_memchr(str, 'W', 0);
    cr_assert_null(p, "Expected NULL; Got: %s", p);
}

Test(ft_memcmp, string)
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    int result = ft_memcmp(str1, str2, 5);
    cr_assert_eq(result, 0, "Expected: 0; Got: %d", result);
}

Test(ft_memcmp, different)
{
    char str1[] = "Hello";
    char str2[] = "World";
    int result = ft_memcmp(str1, str2, 5);
    cr_assert_neq(result, 0, "Expected: not 0; Got: %d", result);
}

Test(ft_memcmp, int_array)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 6};
    int result = ft_memcmp(arr1, arr2, sizeof(arr1));
    cr_assert_neq(result, 0, "Expected: not 0; Got: %d", result);
}

Test(ft_memcmp, empty_string)
{
    char str1[] = "";
    char str2[] = "";
    int result = ft_memcmp(str1, str2, 0);
    cr_assert_eq(result, 0, "Expected: 0; Got: %d", result);
}

Test(ft_strnstr, basic)
{
    char str[] = "Hello World";
    char *result = ft_strnstr(str, "World", 11);
    cr_assert_not_null(result, "Expected non-null pointer for substring 'World'");
    cr_assert_str_eq(result, "World", "Expected: World; Got: %s", result);
}

Test(ft_strnstr, not_found)
{
    char str[] = "Hello World";
    char *result = ft_strnstr(str, "XYZ", 11);
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_strnstr, limit_too_short)
{
    char str[] = "Hello World";
    char *result = ft_strnstr(str, "World", 4);
    cr_assert_null(result, "Expected NULL; Got: %s", result);
}

Test(ft_atoi, basic)
{
    char str[] = "42";
    int result = ft_atoi(str);
    cr_assert_eq(result, 42, "Expected: 42; Got: %d", result);
}

Test(ft_atoi, negative)
{
    char str[] = "-42";
    int result = ft_atoi(str);
    cr_assert_eq(result, -42, "Expected: -42; Got: %d", result);
}

Test(ft_atoi, overflow)
{
    char str[] = "2147483648";
    int result = ft_atoi(str);
    cr_assert_eq(result, atoi("2147483648"));
}

Test(ft_atoi, underflow)
{
    char str[] = "-2147483649";
    int result = ft_atoi(str);
    cr_assert_eq(result, atoi("-2147483649"));
}

Test(ft_atoi, whitespace)
{
    char str[] = "   42";
    int result = ft_atoi(str);
    cr_assert_eq(result, 42, "Expected: 42; Got: %d", result);
}

Test(ft_atoi, letternumber)
{
    char str[] = "42abc";
    int result = ft_atoi(str);
    cr_assert_eq(result, 42, "Expected: 42; Got: %d", result);
}

Test(ft_calloc, basic)
{
    size_t size = 5;
    char *ptr = ft_calloc(size, sizeof(char));
    cr_assert_not_null(ptr, "Expected non-null pointer");
    for (size_t i = 0; i < size; i++)
        cr_assert_eq(ptr[i], 0, "Expected byte %zu to be 0", i);
    free(ptr);
}

Test(ft_calloc, zero_size)
{
    size_t size = 0;
    char *ptr = ft_calloc(size, sizeof(char));
    cr_assert_not_null(ptr, "Expected non-null pointer even for zero allocation");
    free(ptr);
}

Test(ft_strdup, basic)
{
    char *str = "Hello World";
    char *dup = ft_strdup(str);
    cr_assert_not_null(dup, "Expected non-null pointer");
    cr_assert_str_eq(dup, str, "Expected: Hello World; Got: %s", dup);
    free(dup);
}

Test(ft_strdup, empty_string)
{
    char *str = "";
    char *dup = ft_strdup(str);
    cr_assert_not_null(dup, "Expected non-null pointer for empty string");
    cr_assert_str_eq(dup, "", "Expected empty string; Got: %s", dup);
    free(dup);
}

Test(ft_strdup, null_string)
{
    char *str = NULL;
    char *dup = ft_strdup(str);
    cr_assert_null(dup, "Expected NULL for null string; Got: %s", dup);
}

Test(ft_substr, basic)
{
    char str[] = "Hello World";
    char *result = ft_substr(str, 0, 5);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
    free(result);
}

Test(ft_substr, out_of_bounds)
{
    char str[] = "Hello World";
    char *result = ft_substr(str, 6, 5);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "World", "Expected: World; Got: %s", result);
    free(result);
}

Test(ft_strjoin, basic)
{
    char *s1 = "Hello";
    char *s2 = " World";
    char *result = ft_strjoin(s1, s2);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
    free(result);
}

Test(ft_strjoin, empty_string)
{
    char *s1 = "";
    char *s2 = "Test";
    char *result = ft_strjoin(s1, s2);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "Test", "Expected: Test; Got: %s", result);
    free(result);
}

Test(ft_strjoin, null_string)
{
    char *s1 = NULL;
    char *s2 = "Test";
    char *result = ft_strjoin(s1, s2);
    cr_assert_null(result, "Expected NULL for null string; Got: %s", result);
}

Test(ft_strtrim, basic)
{
    char *str = "   Hello World\t\n";
    char *result = ft_strtrim(str);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
    free(result);
}

Test(ft_strtrim, empty_string)
{
    char *str = "";
    char *result = ft_strtrim(str);
    cr_assert_not_null(result, "Expected non-null pointer for empty string");
    cr_assert_str_eq(result, "", "Expected empty string; Got: %s", result);
    free(result);
}

Test(ft_strtrim, null_string)
{
    char *str = NULL;
    char *result = ft_strtrim(str);
    cr_assert_null(result, "Expected NULL for null string; Got: %s", result);
}

Test(ft_strtrim, no_whitespace)
{
    char *str = "Hello";
    char *result = ft_strtrim(str);
    cr_assert_not_null(result, "Expected non-null pointer");
    cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
    free(result);
}

Test(ft_itoa, basic)
{
    char *result = ft_itoa(12345);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "12345", "Expected: 12345; Got: %s", result);
    free(result);
}

Test(ft_itoa, negative)
{
    char *result = ft_itoa(-12345);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "-12345", "Expected: -12345; Got: %s", result);
    free(result);
}

Test(ft_itoa, zero)
{
    char *result = ft_itoa(0);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "0", "Expected: 0; Got: %s", result);
    free(result);
}

Test(ft_itoa, overflow)
{
    char *result = ft_itoa(INT_MIN);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "-2147483648", "Expected: -2147483648; Got: %s", result);
    free(result);
}

Test(ft_itoa, underflow)
{
    char *result = ft_itoa(INT_MAX);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "2147483647", "Expected: 2147483647; Got: %s", result);
    free(result);
}

void to_upper(unsigned int i, char *c)
{
    (void)i;
    *c = (*c - 32);
}

Test(ft_strmapi, basic)
{
    char str[] = "hello";
    char *result = ft_strmapi(str, to_upper);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "HELLO", "Expected: HELLO; Got: %s", result);
    free(result);
}

Test(ft_striteri, basic)
{
    char str[] = "hello";
    ft_striteri(str, to_upper);
    cr_assert_str_eq(str, "HELLO", "Expected: HELLO; Got: %s", str);
}

Test(ft_putchar_fd, basic)
{
    redirect_all_stdout();
    int fd = 1;
    ft_putchar_fd('A', fd);
    cr_assert_stdout_eq_str("A", "Expected output: A");
}

Test(ft_putstr_fd, basic)
{
    redirect_all_stdout();
    int fd = 1;
    ft_putstr_fd("Hello", fd);
    cr_assert_stdout_eq_str("Hello", "Expected output: Hello");
}

Test(ft_putendl_fd, basic)
{
    redirect_all_stdout();
    int fd = 1; // STDOUT
    ft_putendl_fd("Hello", fd);
    cr_assert_stdout_eq_str("Hello\n", "Expected output: Hello\\n");
}

Test(ft_putnbr_fd, basic)
{
    redirect_all_stdout();
    int fd = 1; // STDOUT
    ft_putnbr_fd(12345, fd);
    cr_assert_stdout_eq_str("12345", "Expected output: 12345");
}

Test(ft_lstnew, basic)
{
    char content[] = "Hello";
    t_list *node = ft_lstnew(content);
    cr_assert_not_null(node, "Expected non-null node");
    cr_assert_str_eq((char *)node->content, "Hello", "Expected node content: Hello");
    cr_assert_eq(node->content_size, strlen("Hello") + 1, "Expected node content_size: %zu", strlen("Hello") + 1);
}

Test(ft_lstnew, null_content)
{
    t_list *node = ft_lstnew(NULL);
    cr_assert_not_null(node, "Expected non-null node");
    cr_assert_null(node->content, "Expected NULL content");
    cr_assert_eq(node->content_size, 0, "Expected content_size: 0");
    free(node);
}

Test(ft_lstadd_front, basic)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    ft_lstadd_front(&node1, node2);
    cr_assert_str_eq((char *)node1->content, "Node 2", "Expected: Node 2; Got: %s", (char *)node1->content);
    cr_assert_str_eq((char *)node1->next->content, "Node 1", "Expected: Node 1; Got: %s", (char *)node1->next->content);
    free(node1->next);
    free(node1);
}

Test(ft_lstsize, basic)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    node1->next = node2;
    int size = ft_lstsize(node1);
    cr_assert_eq(size, 2, "Expected size: 2; Got: %d", size);
    free(node1->next);
    free(node1);
}

Test(ft_lstlast, basic)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    node1->next = node2;
    t_list *last = ft_lstlast(node1);
    cr_assert_str_eq((char *)last->content, "Node 2", "Expected: Node 2; Got: %s", (char *)last->content);
    free(node1->next);
    free(node1);
}

Test(ft_lstlast, single_node)
{
    t_list *node = ft_lstnew("Node 1");
    t_list *last = ft_lstlast(node);
    cr_assert_str_eq((char *)last->content, "Node 1", "Expected: Node 1; Got: %s", (char *)last->content);
    free(node);
}
Test(ft_lstadd_back, basic)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    ft_lstadd_back(&node1, node2);
    cr_assert_str_eq((char *)node1->content, "Node 1", "Expected: Node 1; Got: %s", (char *)node1->content);
    cr_assert_str_eq((char *)node1->next->content, "Node 2", "Expected: Node 2; Got: %s", (char *)node1->next->content);
    free(node1->next);
    free(node1);
}

Test(ft_lstadd_back, null_list)
{
    t_list *node = ft_lstnew("Node 1");
    ft_lstadd_back(NULL, node);
    cr_assert_null(node->next, "Expected NULL next pointer");
    free(node);
}

Test(ft_lstdelone, basic)
{
    char content[] = "Hello";
    t_list *node = ft_lstnew(content);
    ft_lstdelone(node, free);
    cr_assert_null(node, "Expected node to be NULL after deletion");
}

Test(ft_lstdelone, null_node)
{
    t_list *node = NULL;
    ft_lstdelone(node, free);
    cr_assert_null(node, "Expected node to be NULL after deletion");
}

Test(ft_lstclear, basic)
{
    char content1[] = "Node 1";
    char content2[] = "Node 2";
    t_list *node1 = ft_lstnew(content1);
    t_list *node2 = ft_lstnew(content2);
    node1->next = node2;
    ft_lstclear(&node1, free);
    cr_assert_null(node1, "Expected node1 to be NULL after deletion");
}


Test(ft_lstiter, basic)
{
    char content1[] = "Node 1";
    char content2[] = "Node 2";
    t_list *node1 = ft_lstnew(content1);
    t_list *node2 = ft_lstnew(content2);
    node1->next = node2;
    ft_lstiter(node1, to_upper);
    cr_assert_str_eq((char *)node1->content, "NODE 1", "Expected: NODE 1; Got: %s", (char *)node1->content);
    cr_assert_str_eq((char *)node2->content, "NODE 2", "Expected: NODE 2; Got: %s", (char *)node2->content);
    free(node1->next);
    free(node1);
}

Test(ft_lstmap, basic)
{
    char content1[] = "Node 1";
    char content2[] = "Node 2";
    t_list *node1 = ft_lstnew(content1);
    t_list *node2 = ft_lstnew(content2);
    node1->next = node2;
    t_list *mapped_list = ft_lstmap(node1, to_upper, free);
    cr_assert_str_eq((char *)mapped_list->content, "NODE 1", "Expected: NODE 1; Got: %s", (char *)mapped_list->content);
    cr_assert_str_eq((char *)mapped_list->next->content, "NODE 2", "Expected: NODE 2; Got: %s", (char *)mapped_list->next->content);
    free(mapped_list->next);
    free(mapped_list);
}