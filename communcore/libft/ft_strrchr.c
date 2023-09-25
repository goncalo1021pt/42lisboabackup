#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		ctd;
	char	*str;

	str = (char *)s;
	ctd = 0;
	while (str[ctd])
		ctd++;
	while (ctd >= 0)
	{
		if (s[ctd] == c)
			return (str + ctd);
		ctd--;
	}
	return (NULL);
}

/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	char c[11] = "hello world";
	char *test;

	test = ft_strrchr(c, 's');
	if (test == 0)
		printf("NULL");
	else
		printf("%s\n", test);
	return (0);
} */