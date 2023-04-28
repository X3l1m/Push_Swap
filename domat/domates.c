#include "../libft/libft.h"

static int max(int i)
{
	write(1, "dom", 3);
	return (i);
}

int main()
{
	int i = 0;
	int first = max(i);
	while(i < 5)
	{
		if (max(i) < 5)
			write(1, "ham", 3);
		i++;
	}
	printf("%d\n", first);
}
