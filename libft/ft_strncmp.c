#include "../recast.h"

int ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] != ' '&& s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}