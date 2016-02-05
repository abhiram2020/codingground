#include <stdio.h>
#include <string.h>

int is_match(char *a, char *b, int i, int j, int k, int l)
{
	if (k >= l)
		return 1;
	if (i >= j)
		return 0;
	if (a[i] == b[k])
		return is_match(a, b, i+1, j, k+1, l);
	else
		return is_match(a, b, i+1, j, k, l);
}

int main()
{
	char foo[] = {"abcNjhgAhGjhfhAljhRkhgRbhjbevfhG"};
	char bar[] = {"NAGARRG"};
	int i, j, k, l;
	i = k = 0;
	j = strlen(foo);
	l = strlen(bar);
	printf("%d\n", is_match(foo, bar, i, j, k, l));
	return 0;
}
