#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	ctd;

	ctd = 0;
	while (src[ctd] != '\0')
	{
		dest[ctd] = src[ctd];
		ctd++;
	}
	dest[ctd] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(ft_strlen(src) + 1);
	if (str == NULL)
		return (str);
	ft_strcpy(str, src);
	return (str);
}
