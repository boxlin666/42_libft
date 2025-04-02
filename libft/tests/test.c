#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Test(ft_strlen, basic_tests) {
    cr_assert_eq(ft_strlen("Hello"), 5, "Expected: 5");
    cr_assert_eq(ft_strlen(""), 0, "Expected: 0");
    cr_assert_eq(ft_strlen("123456789"), 9, "Expected: 9");
}

Test(ft_atoi, basic_tests) {
    cr_assert_eq(ft_atoi("42"), 42, "Expected: 42");
    cr_assert_eq(ft_atoi("-42"), -42, "Expected: -42");
    cr_assert_eq(ft_atoi("0"), 0, "Expected: 0");
    cr_assert_eq(ft_atoi("   42"), 42, "Expected: 42");
    cr_assert_eq(ft_atoi("42abc"), 42, "Expected: 42");
    cr_assert_eq(ft_atoi("abc42"), 0, "Expected: 0");
    cr_assert_eq(atoi("2147483647"), 2147483647, "Expected: 2147483647");
    cr_assert_eq(ft_atoi("2147483647"), 2147483647, "Expected: 2147483647");
    cr_assert_eq(ft_atoi("-2147483648"), -2147483648, "Expected: -2147483648");
    cr_assert_eq(ft_atoi("2147483648"), 2147483647, "Expected: 2147483647");
    cr_assert_eq(ft_atoi("-2147483649"), -2147483648, "Expected: -2147483648");
    cr_assert_eq(ft_atoi("   -42abc"), -42, "Expected: -42");
    cr_assert_eq(ft_atoi("   +42abc"), 42, "Expected: 42");
}

Test(ft_putchar, basic_tests) {
    cr_redirect_stdout();
    ft_putchar('A');
    cr_assert_stdout_eq_str("A", "Expected: A");
}