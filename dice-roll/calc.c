#include <stdio.h>

int main (void)
{
	int breaknote;
	int userInput;
	int tally;

	breaknote = 1;

	/* Start with the first number */
	printf("  ");
	scanf("%d", &tally);

	while (breaknote)
	{
		/* Keep adding to the first number */
		/* 0 breaks our of the loop */
		printf("+ ");
		scanf("%d", &userInput);
		if ( userInput == 0)
		{
			breaknote = 0;
		} else {
			tally = tally + userInput;
		}
	}
	printf("----\n%d\n", tally);
}
