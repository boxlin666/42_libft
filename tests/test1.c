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

/* -------------------------- ft_memset -------------------------- */
Test(ft_memset, basic_and_extended)
{
    {
        char str[20] = "Hello World";
        ft_memset(str, 'X', 5);
        cr_assert_str_eq(str, "XXXXX World", "Expected: XXXXX World; Got: %s", str);
    }
    {
        char str[20] = "Hello World";
        ft_memset(str, 0, 11);
        for (int i = 0; i < 11; i++)
            cr_assert_eq(str[i], 0, "Expected byte %d to be 0", i);
    }
}

/* -------------------------- ft_bzero -------------------------- */
Test(ft_bzero, basic_and_extended)
{
    {
        char str[20] = "Hello World";
        ft_bzero(str, 5);
        for (int i = 0; i < 5; i++)
            cr_assert_eq((int)str[i], 0, "Expected byte %d to be 0", i);
        cr_assert_str_eq(str + 5, " World", "Expected unchanged remainder");
    }
    {
        char buffer[10];
        memset(buffer, 'A', sizeof(buffer));
        ft_bzero(buffer, sizeof(buffer));
        for (int i = 0; i < 10; i++)
            cr_assert_eq((int)buffer[i], 0, "Expected byte %d to be 0", i);
    }
}

/* -------------------------- ft_memcpy -------------------------- */
Test(ft_memcpy, basic_and_extended)
{
    {
        char dest[20];
        char *src = "Hello World";
        char *result = ft_memcpy(dest, src, 5);
        dest[5] = '\0';
        cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
    }
    {
        int src[] = {1, 2, 3, 4, 5};
        int dest[5] = {0};
        ft_memcpy(dest, src, sizeof(src));
        for (int i = 0; i < 5; i++)
            cr_assert_eq(dest[i], src[i], "Expected dest[%d] == %d", i, src[i]);
    }
}

/* -------------------------- ft_memccpy -------------------------- */
Test(ft_memccpy, basic_and_extended)
{
    {
        char dest1[20] = {0};
        char dest2[20] = {0};
        char *src = "Hello World";
        char *res1 = ft_memccpy(dest1, src, 'o', 10);
        char *res2 = memccpy(dest2, src, 'o', 10);
        if (res1 && res2)
            cr_assert_str_eq(dest1, dest2, "Expected same copied content; Got: %s vs %s", dest1, dest2);
        else
            cr_assert_null(res1, "Expected both return NULL when delimiter not found or reached");
    }
    {
        /* delimiter not found */
        char dest[20] = {0};
        char *res = ft_memccpy(dest, "Hello", 'x', 5);
        cr_assert_null(res, "Expected NULL when delimiter not found");
        cr_assert_str_eq(dest, "Hello", "Expected full copy when delimiter not found");
    }
}

/* -------------------------- ft_memmove -------------------------- */
Test(ft_memmove, overlapping_and_non_overlapping)
{
    /* Non-overlapping copy */
    {
        char src[20] = "Hello World";
        char dest[20];
        ft_memmove(dest, src, strlen(src) + 1);
        cr_assert_str_eq(dest, src, "Expected identical strings; Got: %s", dest);
    }
    /* Overlapping: dest > src */
    {
        char buffer1[20] = "123456789";
        char buffer2[20] = "123456789";
        memmove(buffer1 + 3, buffer1, strlen(buffer1) + 1);
        ft_memmove(buffer2 + 3, buffer2, strlen(buffer2) + 1);
        cr_assert_str_eq(buffer2, buffer1, "Overlap (dest > src) failed; Got: %s", buffer2);
    }
    /* Overlapping: src > dest */
    {
        char buffer1[20] = "123456789";
        char buffer2[20] = "123456789";
        memmove(buffer1, buffer1 + 3, strlen(buffer1 + 3) + 1);
        ft_memmove(buffer2, buffer2 + 3, strlen(buffer2 + 3) + 1);
        cr_assert_str_eq(buffer2, buffer1, "Overlap (src > dest) failed; Got: %s", buffer2);
    }
    /* Zero length */
    {
        char str[20] = "Hello";
        ft_memmove(str, str + 2, 0);
        cr_assert_str_eq(str, "Hello", "Expected no change on zero length move; Got: %s", str);
    }
}

/* -------------------------- ft_memchr -------------------------- */
Test(ft_memchr, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *p = ft_memchr(str, 'o', strlen(str));
        cr_assert_not_null(p, "Expected non-null pointer for 'o'");
        cr_assert_str_eq(p, "o World", "Expected: o World; Got: %s", p);
    }
    {
        char str[] = "Hello World";
        cr_assert_null(ft_memchr(str, 'x', strlen(str)), "Expected: NULL when char not found");
    }
    {
        char str[] = "Hello World";
        char *p = ft_memchr(str, 'H', strlen(str));
        cr_assert_not_null(p, "Expected non-null pointer for 'H'");
        cr_assert_str_eq(p, "Hello World", "Expected: Hello World; Got: %s", p);
    }
}

/* -------------------------- ft_memcmp -------------------------- */
Test(ft_memcmp, basic_and_extended)
{
    {
        int arr1[] = {1, 2, 3, 4, 5};
        int arr2[] = {1, 2, 3, 4, 6};
        int cmp = ft_memcmp(arr1, arr2, sizeof(arr1));
        cr_assert(cmp < 0, "Expected negative result; Got: %d", cmp);
    }
    {
        cr_assert_eq(ft_memcmp("Hello", "Hello", 5), 0, "Expected: 0");
    }
    {
        int cmp = ft_memcmp("Hello", "World", 5);
        cr_assert(cmp < 0, "Expected result < 0; Got: %d", cmp);
    }
}

/* -------------------------- ft_strlen -------------------------- */
Test(ft_strlen, basic_and_extended)
{
    {
        char str[] = "Hello World";
        cr_assert_eq(ft_strlen(str), 11, "Expected: 11; Got: %zu", ft_strlen(str));
    }
    {
        cr_assert_eq(ft_strlen(""), 0, "Expected: 0");
    }
    {
        cr_assert_eq(ft_strlen("Hello"), 5, "Expected: 5");
    }
}

/* -------------------------- ft_strdup -------------------------- */
Test(ft_strdup, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *dup = ft_strdup(str);
        cr_assert_not_null(dup, "Expected non-null pointer");
        cr_assert_str_eq(dup, str, "Expected: Hello World; Got: %s", dup);
        free(dup);
    }
    {
        char *dup = ft_strdup("");
        cr_assert_not_null(dup, "Expected non-null pointer for empty string");
        cr_assert_str_eq(dup, "", "Expected empty string; Got: %s", dup);
        free(dup);
    }
}

/* -------------------------- ft_strcpy -------------------------- */
Test(ft_strcpy, basic_and_extended)
{
    {
        char dest[20];
        char *src = "Hello World";
        char *result = ft_strcpy(dest, src);
        cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
        cr_assert_str_eq(dest, "Hello World", "Expected: Hello World; Got: %s", dest);
    }
}

/* -------------------------- ft_strncpy -------------------------- */
Test(ft_strncpy, basic_and_extended)
{
    {
        char dest[20];
        char *src = "Hello World";
        char *result = ft_strncpy(dest, src, 5);
        dest[5] = '\0';
        cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
    }
    {
        char dest[20];
        memset(dest, 'A', 20);
        char *src = "Hi";
        ft_strncpy(dest, src, 5);
        cr_assert_str_eq(dest, "Hi", "Expected: Hi; Got: %s", dest);
    }
}

/* -------------------------- ft_strcat -------------------------- */
Test(ft_strcat, basic_and_extended)
{
    {
        char dest[20] = "Hello";
        char *src = " World";
        char *result = ft_strcat(dest, src);
        cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
    }
    {
        char dest[30] = "";
        char *src = "Test";
        ft_strcat(dest, src);
        cr_assert_str_eq(dest, "Test", "Expected: Test; Got: %s", dest);
    }
}

/* -------------------------- ft_strncat -------------------------- */
Test(ft_strncat, basic_and_extended)
{
    {
        char dest[20] = "Hello";
        char *src = " World";
        char *result = ft_strncat(dest, src, 4);
        cr_assert_str_eq(result, "Hello Wor", "Expected: Hello Wor; Got: %s", result);
    }
    {
        char dest[30] = "Foo";
        ft_strncat(dest, "BarBaz", 3);
        cr_assert_str_eq(dest, "FooBar", "Expected: FooBar; Got: %s", dest);
    }
}

/* -------------------------- ft_strlcat -------------------------- */
Test(ft_strlcat, basic_and_extended)
{
    {
        char dest[20] = "Hello";
        char *src = " World";
        size_t res = ft_strlcat(dest, src, sizeof(dest));
        cr_assert_eq(res, 11, "Expected: 11; Got: %zu", res);
        cr_assert_str_eq(dest, "Hello World", "Expected: Hello World; Got: %s", dest);
    }
    {
        char dest[10] = "12345";
        size_t res = ft_strlcat(dest, "67890", sizeof(dest));
        cr_assert_eq(res, 10, "Expected: 10; Got: %zu", res);
    }
}

/* -------------------------- ft_strchr -------------------------- */
Test(ft_strchr, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *p = ft_strchr(str, 'o');
        cr_assert_not_null(p, "Expected non-null pointer for 'o'");
        cr_assert_str_eq(p, "o World", "Expected: o World; Got: %s", p);
    }
    {
        cr_assert_null(ft_strchr("Hello", 'x'), "Expected: NULL when char not found");
    }
    {
        cr_assert_null(ft_strchr("", 'o'), "Expected: NULL");
    }
    {
        char str[] = "Hello World";
        char *p = ft_strchr(str, 'H');
        cr_assert_not_null(p, "Expected non-null pointer for 'H'");
        cr_assert_str_eq(p, "Hello World", "Expected: Hello World; Got: %s", p);
    }
    {
        char *s = "hello world";
        cr_assert_eq(ft_strchr(s, 'h'), s);
        cr_assert_eq(ft_strchr(s, 'w'), s + 6);
        cr_assert_eq(ft_strchr(s, '\0'), s + strlen(s));
        cr_assert_eq(ft_strchr(s, 'z'), NULL);
    }
    {
        char *s = "abc";
        cr_assert_eq(ft_strchr(s, 'a' + 256), ft_strchr(s, (char)('a' + 256)));
    }
}

/* -------------------------- ft_strrchr -------------------------- */
Test(ft_strrchr, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *p = ft_strrchr(str, 'o');
        cr_assert_not_null(p, "Expected non-null pointer for 'o'");
        cr_assert_str_eq(p, strrchr(str, 'o'), "Expected same result as standard strrchr");
    }
    {
        cr_assert_null(ft_strrchr("Hello", 'x'), "Expected: NULL when char not found");
    }
}

/* -------------------------- ft_strstr -------------------------- */
Test(ft_strstr, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *p = ft_strstr(str, "World");
        cr_assert_not_null(p, "Expected non-null pointer for substring 'World'");
        cr_assert_str_eq(p, "World", "Expected: World; Got: %s", p);
    }
    {
        cr_assert_null(ft_strstr("Hello", "XYZ"), "Expected: NULL when substring not found");
    }
    {
        char str[] = "Hello World";
        char *p = ft_strstr(str, "Hello");
        cr_assert_not_null(p, "Expected non-null pointer for substring 'Hello'");
        cr_assert_str_eq(p, "Hello World", "Expected: Hello World; Got: %s", p);
    }
    {
        char *s = "banana";
    cr_assert_eq(ft_strrchr(s, 'a'), s + 5);
    cr_assert_eq(ft_strrchr(s, 'b'), s);
    cr_assert_eq(ft_strrchr(s, 'z'), NULL);
    cr_assert_eq(ft_strrchr(s, '\0'), s + strlen(s));
    }
}

/* -------------------------- ft_strnstr -------------------------- */
Test(ft_strnstr, basic_and_extended)
{
    {
        char str[] = "Hello World";
        cr_assert_null(ft_strnstr(str, "World", 4), "Expected: NULL when limit too short");
    }
    {
        char str[] = "Hello World";
        char *p = ft_strnstr(str, "Hello", 5);
        cr_assert_not_null(p, "Expected non-null pointer for substring 'Hello'");
        cr_assert_str_eq(p, "Hello World", "Expected: Hello World; Got: %s", p);
    }
    {
        cr_assert_null(ft_strnstr("Hello", "XYZ", 5), "Expected: NULL when substring not found");
    }
}

/* -------------------------- ft_strcmp -------------------------- */
Test(ft_strcmp, basic_and_extended)
{
    {
        cr_assert_eq(ft_strcmp("Hello", "Hello"), 0, "Expected: 0");
    }
    {
        cr_assert(ft_strcmp("Hello", "World") < 0, "Expected: negative value");
    }
    {
        cr_assert(ft_strcmp("World", "Hello") > 0, "Expected: positive value");
    }
}

/* -------------------------- ft_strncmp -------------------------- */
Test(ft_strncmp, basic_and_extended)
{
    {
        cr_assert_eq(ft_strncmp("Hello", "Hello", 5), 0, "Expected: 0");
    }
    {
        cr_assert(ft_strncmp("Hello", "World", 5) < 0, "Expected: negative value");
    }
    {
        cr_assert(ft_strncmp("World", "Hello", 5) > 0, "Expected: positive value");
    }
}

/* -------------------------- ft_atoi -------------------------- */
Test(ft_atoi, basic_and_extended)
{
    {
        cr_assert_eq(ft_atoi(" \n\t-0"), atoi(" \n\t-0"), "Expected: %d", atoi(" \n\t-0"));
    }
    {
        cr_assert_eq(ft_atoi("-2147483648"), atoi("-2147483648"), "Expected: -2147483648");
    }
    {
        cr_assert_eq(ft_atoi("2147483647"), atoi("2147483647"), "Expected: 2147483647");
    }
    {
        /* 边界越界情况，标准 atoi 行为未定义，这里测试返回值和系统一致 */
        cr_assert_eq(ft_atoi("-2147483649"), atoi("-2147483649"), "Expected system behavior");
    }
    {
        cr_assert_eq(ft_atoi("2147483648"), atoi("2147483648"), "Expected system behavior");
    }
}

/* -------------------------- ft_isalpha -------------------------- */
Test(ft_isalpha, basic)
{
    cr_assert_eq(ft_isalpha('a'), 1, "Expected: 1 for 'a'");
    cr_assert_eq(ft_isalpha('Z'), 1, "Expected: 1 for 'Z'");
    cr_assert_eq(ft_isalpha('1'), 0, "Expected: 0 for '1'");
    cr_assert_eq(ft_isalpha(' '), 0, "Expected: 0 for ' '");
}

/* -------------------------- ft_isdigit -------------------------- */
Test(ft_isdigit, basic)
{
    cr_assert_eq(ft_isdigit('0'), 1, "Expected: 1 for '0'");
    cr_assert_eq(ft_isdigit('9'), 1, "Expected: 1 for '9'");
    cr_assert_eq(ft_isdigit('a'), 0, "Expected: 0 for 'a'");
    cr_assert_eq(ft_isdigit(' '), 0, "Expected: 0 for ' '");
}

/* -------------------------- ft_isalnum -------------------------- */
Test(ft_isalnum, basic)
{
    cr_assert_eq(ft_isalnum('a'), 1, "Expected: 1 for 'a'");
    cr_assert_eq(ft_isalnum('Z'), 1, "Expected: 1 for 'Z'");
    cr_assert_eq(ft_isalnum('1'), 1, "Expected: 1 for '1'");
    cr_assert_eq(ft_isalnum(' '), 0, "Expected: 0 for ' '");
}

/* -------------------------- ft_isascii -------------------------- */
Test(ft_isascii, basic)
{
    cr_assert_eq(ft_isascii('a'), 1, "Expected: 1 for 'a'");
    cr_assert_eq(ft_isascii(127), 1, "Expected: 1 for 127");
    cr_assert_eq(ft_isascii(128), 0, "Expected: 0 for 128");
    cr_assert_eq(ft_isascii(' '), 1, "Expected: 1 for ' '");
}

/* -------------------------- ft_isprint -------------------------- */
Test(ft_isprint, basic)
{
    cr_assert_eq(ft_isprint('a'), 1, "Expected: 1 for 'a'");
    cr_assert_eq(ft_isprint(127), 0, "Expected: 0 for 127");
    cr_assert_eq(ft_isprint(128), 0, "Expected: 0 for 128");
    cr_assert_eq(ft_isprint(' '), 1, "Expected: 1 for ' '");
}

/* -------------------------- ft_toupper -------------------------- */
Test(ft_toupper, basic)
{
    {
        char c = 'a';
        c = ft_toupper(c);
        cr_assert_eq(c, 'A', "Expected: A; Got: %c", c);
    }
    {
        char c = 'Z';
        c = ft_toupper(c);
        cr_assert_eq(c, 'Z', "Expected: Z; Got: %c", c);
    }
    {
        char c = '1';
        c = ft_toupper(c);
        cr_assert_eq(c, '1', "Expected: 1; Got: %c", c);
    }
}

/* -------------------------- ft_tolower -------------------------- */
Test(ft_tolower, basic)
{
    {
        char c = 'A';
        c = ft_tolower(c);
        cr_assert_eq(c, 'a', "Expected: a; Got: %c", c);
    }
    {
        char c = 'z';
        c = ft_tolower(c);
        cr_assert_eq(c, 'z', "Expected: z; Got: %c", c);
    }
    {
        char c = '1';
        c = ft_tolower(c);
        cr_assert_eq(c, '1', "Expected: 1; Got: %c", c);
    }
}

/* -------------------------- ft_memalloc -------------------------- */
Test(ft_memalloc, basic_and_extended)
{
    {
        char *ptr = ft_memalloc(10);
        cr_assert_not_null(ptr, "Expected non-null pointer");
        for (int i = 0; i < 10; i++)
            cr_assert_eq(ptr[i], 0, "Expected allocated memory zeroed out at index %d", i);
        free(ptr);
    }
    {
        char *ptr = ft_memalloc(0);
        cr_assert_not_null(ptr, "Expected non-null pointer even for zero allocation");
        free(ptr);
    }
}

/* -------------------------- ft_memdel -------------------------- */
Test(ft_memdel, basic)
{
    {
        char *ptr = malloc(10);
        ft_memdel((void **)&ptr);
        cr_assert_null(ptr, "Expected pointer to be set to NULL after ft_memdel");
    }
}

/* -------------------------- ft_strnew -------------------------- */
Test(ft_strnew, basic)
{
    {
        char *str = ft_strnew(10);
        cr_assert_not_null(str, "Expected non-null pointer");
        for (int i = 0; i < 10; i++)
            cr_assert_eq(str[i], '\0', "Expected char at index %d to be '\\0'", i);
        free(str);
    }
}

/* -------------------------- ft_strdel -------------------------- */
Test(ft_strdel, basic)
{
    {
        char *str = malloc(10);
        ft_strdel(&str);
        cr_assert_null(str, "Expected pointer to be set to NULL after ft_strdel");
    }
}

/* -------------------------- ft_strclr -------------------------- */
Test(ft_strclr, basic)
{
    {
        char str[20] = "Hello World";
        ft_strclr(str);
        cr_assert_eq(str[0], '\0', "Expected string to be cleared");
    }
}

/* -------------------------- ft_striter & ft_striteri -------------------------- */
static void to_upper(char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

static void to_upper_index(unsigned int i, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32 + i;
}

Test(ft_striter, basic)
{
    char str[] = "hello";
    ft_striter(str, to_upper);
    cr_assert_str_eq(str, "HELLO", "Expected: HELLO; Got: %s", str);
}

Test(ft_striteri, basic)
{
    char str[] = "hello";
    ft_striteri(str, to_upper_index);
    cr_assert_str_eq(str, "HFNOS", "Expected: HFNOS; Got: %s", str);
}

/* -------------------------- ft_strmap & ft_strmapi -------------------------- */
static char map_func(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

static char map_funci(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A' + i;
    return c;
}

Test(ft_strmap, basic)
{
    char str[] = "hello";
    char *result = ft_strmap(str, map_func);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "HELLO", "Expected: HELLO; Got: %s", result);
    free(result);
}

Test(ft_strmapi, basic)
{
    char str[] = "hello";
    char *result = ft_strmapi(str, map_funci);
    cr_assert_not_null(result, "Expected non-null result");
    cr_assert_str_eq(result, "HFNOS", "Expected: HFNOS; Got: %s", result);
    free(result);
}

/* -------------------------- ft_strequ & ft_strnequ -------------------------- */
Test(ft_strequ, basic)
{
    cr_assert_eq(ft_strequ("Hello", "Hello"), 1, "Expected equal strings");
    cr_assert_eq(ft_strequ("Hello", "World"), 0, "Expected different strings");
}

Test(ft_strnequ, basic)
{
    cr_assert_eq(ft_strnequ("Hello", "Hello", 5), 1, "Expected equal strings for n=5");
    cr_assert_eq(ft_strnequ("Hello", "World", 5), 0, "Expected different strings for n=5");
}

/* -------------------------- ft_strsub -------------------------- */
Test(ft_strsub, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char *result = ft_strsub(str, 0, 5);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
        free(result);
    }
    {
        char str[] = "Hello World";
        char *result = ft_strsub(str, 6, 5);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "World", "Expected: World; Got: %s", result);
        free(result);
    }
    {
        char *s = ft_strsub("hello world", 0, 5);
        cr_assert_str_eq(s, "hello");
        free(s);

        s = ft_strsub("hello world", 6, 5);
        cr_assert_str_eq(s, "world");
        free(s);

        s = ft_strsub("42", 0, 0);
        cr_assert_str_eq(s, "");
        free(s);

        s = ft_strsub("test", 10, 5);
        cr_assert_str_eq(s, "");
        free(s);
    }
}

/* -------------------------- ft_strjoin -------------------------- */
Test(ft_strjoin, basic_and_extended)
{
    {
        char *s1 = "Hello";
        char *s2 = " World";
        char *result = ft_strjoin(s1, s2);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
        free(result);
    }
    {
        char *result = ft_strjoin("", "Test");
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "Test", "Expected: Test; Got: %s", result);
        free(result);
    }
}

/* -------------------------- ft_strtrim -------------------------- */
Test(ft_strtrim, basic_and_extended)
{
    {
        char str[] = "   Hello World   ";
        char *result = ft_strtrim(str);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "Hello World", "Expected: Hello World; Got: %s", result);
        free(result);
    }
    {
        char str[] = "\n\tHello\n\t";
        char *result = ft_strtrim(str);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "Hello", "Expected: Hello; Got: %s", result);
        free(result);
    }
    {
        char *s = ft_strtrim("   hello world   ");
    cr_assert_str_eq(s, "hello world");
    free(s);

    s = ft_strtrim("no_trim");
    cr_assert_str_eq(s, "no_trim");
    free(s);

    s = ft_strtrim("   \t\n  ");
    cr_assert_str_eq(s, "");
    free(s);

    s = ft_strtrim("");
    cr_assert_str_eq(s, "");
    free(s);
    }
}

/* -------------------------- ft_strsplit -------------------------- */
Test(ft_strsplit, basic_and_extended)
{
    {
        char str[] = "Hello World";
        char **result = ft_strsplit(str, ' ');
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result[0], "Hello", "Expected: Hello; Got: %s", result[0]);
        cr_assert_str_eq(result[1], "World", "Expected: World; Got: %s", result[1]);
        cr_assert_null(result[2], "Expected last element to be NULL");
        free(result[0]);
        free(result[1]);
        free(result);
    }
    {
        char str[] = "  Split  multiple   spaces ";
        char **result = ft_strsplit(str, ' ');
        cr_assert_not_null(result, "Expected non-null result");
        /* 验证非空元素数量大于0 */
        int count = 0;
        for (int i = 0; result[i]; i++)
            count++;
        cr_assert_gt(count, 0, "Expected at least one token");
        // 释放内存
        for (int i = 0; result[i]; i++)
            free(result[i]);
        free(result);
    }
}

/* -------------------------- ft_itoa -------------------------- */
Test(ft_itoa, basic_and_extended)
{
    {
        char *result = ft_itoa(12345);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "12345", "Expected: 12345; Got: %s", result);
        free(result);
    }
    {
        char *result = ft_itoa(-12345);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "-12345", "Expected: -12345; Got: %s", result);
        free(result);
    }
    {
        char *result = ft_itoa(0);
        cr_assert_not_null(result, "Expected non-null result");
        cr_assert_str_eq(result, "0", "Expected: 0; Got: %s", result);
        free(result);
    }
}

/* -------------------------- ft_putchar, ft_putstr, ft_putendl, ft_putnbr -------------------------- */
Test(ft_putchar, basic)
{
    redirect_all_stdout();
    ft_putchar('A');
    cr_assert_stdout_eq_str("A", "Expected output: A");
}

Test(ft_putstr, basic)
{
    redirect_all_stdout();
    ft_putstr("Hello");
    cr_assert_stdout_eq_str("Hello", "Expected output: Hello");
}

Test(ft_putendl, basic)
{
    redirect_all_stdout();
    ft_putendl("Hello");
    cr_assert_stdout_eq_str("Hello\n", "Expected output: Hello\\n");
}

Test(ft_putnbr, basic)
{
    redirect_all_stdout();
    ft_putnbr(12345);
    cr_assert_stdout_eq_str("12345", "Expected output: 12345");
}

Test(ft_putchar_fd, basic)
{
    redirect_all_stdout();
    ft_putchar_fd('A', 1);
    cr_assert_stdout_eq_str("A", "Expected output: A");
}

Test(ft_putstr_fd, basic)
{
    redirect_all_stdout();
    ft_putstr_fd("Hello", 1);
    cr_assert_stdout_eq_str("Hello", "Expected output: Hello");
}

Test(ft_putendl_fd, basic)
{
    redirect_all_stdout();
    ft_putendl_fd("Hello", 1);
    cr_assert_stdout_eq_str("Hello\n", "Expected output: Hello\\n");
}

Test(ft_putnbr_fd, basic)
{
    redirect_all_stdout();
    ft_putnbr_fd(12345, 1);
    cr_assert_stdout_eq_str("12345", "Expected output: 12345");
}

/* -------------------------- List Functions -------------------------- */
static void del_mock(void *content, size_t content_size)
{
    (void)content_size;
    free(content);
}

/* ft_lstnew */
Test(ft_lstnew, basic)
{
    {
        char *content = strdup("Hello");
        t_list *node = ft_lstnew(content, strlen(content) + 1);
        cr_assert_not_null(node, "Expected non-null node");
        cr_assert_str_eq((char *)node->content, "Hello", "Expected node content: Hello");
        cr_assert_eq(node->content_size, strlen("Hello") + 1, "Expected node content_size: %zu", strlen("Hello") + 1);
        free(node->content);
        free(node);
    }
}

/* ft_lstdelone */
Test(ft_lstdelone, basic)
{
    {
        char *content = strdup("Hello");
        t_list *node = ft_lstnew(content, strlen(content) + 1);
        ft_lstdelone(&node, del_mock);
        cr_assert_null(node, "Expected node to be NULL after deletion");
    }
}

/* ft_lstdel */
Test(ft_lstdel, basic)
{
    {
        char *content1 = strdup("Hello");
        char *content2 = strdup("World");
        t_list *node1 = ft_lstnew(content1, strlen(content1) + 1);
        t_list *node2 = ft_lstnew(content2, strlen(content2) + 1);
        node1->next = node2;
        ft_lstdel(&node1, del_mock);
        cr_assert_null(node1, "Expected node1 to be NULL after deletion");
        /* 此时 node2 内存已在 ft_lstdel 内释放，不应再次访问 */
    }
}

/* ft_lstadd */
Test(ft_lstadd, basic)
{
    {
        char *content1 = strdup("Hello");
        char *content2 = strdup("World");
        t_list *node1 = ft_lstnew(content1, strlen(content1) + 1);
        t_list *node2 = ft_lstnew(content2, strlen(content2) + 1);
        t_list *list = node1;
        ft_lstadd(&list, node2);
        cr_assert_eq(list, node2, "Expected list to point to new head node2");
        cr_assert_eq(list->next, node1, "Expected node2->next to be node1");
        free(node1->content);
        free(node2->content);
        free(node1);
        free(node2);
    }
}

/* For ft_lstiter, we need a function to count nodes */
static void count_func(t_list *node)
{
    int *counter = (int *)node->content;
    (*counter)++;
}

Test(ft_lstiter, basic)
{
    {
        int a = 0, b = 0;
        t_list *node1 = ft_lstnew(&a, sizeof(int));
        t_list *node2 = ft_lstnew(&b, sizeof(int));
        node1->next = node2;
        /* 预先将内容初始化为 0 */
        *((int *)node1->content) = 0;
        *((int *)node2->content) = 0;
        ft_lstiter(node1, count_func);
        cr_assert_eq(*((int *)node1->content), 1, "Expected first node counter to be 1");
        cr_assert_eq(*((int *)node2->content), 1, "Expected second node counter to be 1");
        free(node1->content);
        free(node2->content);
        free(node1);
        free(node2);
    }
}

/* ft_lstmap */
static t_list *clone_node(t_list *node)
{
    t_list *new_node = ft_lstnew(node->content, node->content_size);
    return new_node;
}

Test(ft_lstmap, basic)
{
    {
        char *content1 = strdup("Hello");
        char *content2 = strdup("World");
        t_list *node1 = ft_lstnew(content1, strlen(content1) + 1);
        t_list *node2 = ft_lstnew(content2, strlen(content2) + 1);
        node1->next = node2;
        t_list *mapped = ft_lstmap(node1, clone_node);
        cr_assert_not_null(mapped, "Expected non-null mapped list");
        cr_assert_str_eq((char *)mapped->content, "Hello", "Expected first node: Hello");
        cr_assert_str_eq((char *)mapped->next->content, "World", "Expected second node: World");
        free(node1->content);
        free(node2->content);
        free(node1);
        free(node2);
        free(mapped->content);
        free(mapped->next->content);
        free(mapped);
        free(mapped->next);
    }
}
