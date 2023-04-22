#include "../libft/libft.h"

typedef struct	domates
{
int 			patates;
struct domates	*next;
}				stack;

stack	*create(int h)
{ 
    stack	*i;
	stack	*head;
    i = (stack*)malloc(sizeof(stack));
	i->patates = h;
	i->next = head;
	head = i;
	return i;
}

void bul(stack *ag)
{
	printf("%d", ag->next->patates);
	ag = ag->next;
	printf("%d", ag->next->patates);
}

int main()
{
	stack *ag;
	stack *dom;
	int h = 5;
	while (h--)
	{
		ag = create(h);
	}
	dom = ag;
	bul(ag);
	printf("%d", ag->patates);
	ag = ag->next;
	printf("%d", ag->patates);
	printf("%d", dom->patates);
	bul(ag);
	ag = dom;
	printf("%d", ag->patates);


    return 0;
}
