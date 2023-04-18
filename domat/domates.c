#include <stdio.h>
#include <stdlib.h>

typedef struct domates
{
	int patates;
	struct domates *next;
}stack;

stack	*create(void)
{ 
    stack	*i;
	int	h = 5;
	while(h--){
    i = (stack*)malloc(sizeof(stack));
	i->patates = h;
	i->next = NULL;}
	return i;
}

int main()
{
	stack *ag = create();
    printf("%d", ag->next->patates);
    return 0;
}
