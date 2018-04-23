#include <stdio.h>
#include <time.h>

int main (void)
{
	int breaknote = 1;
	int guess;
	srand(time(NULL));

	while (breaknote)
	{
		printf("Enter your guess: ");
		scanf("%d", &guess);
		int r = rand() % 6;
		if ( guess == 0 )
		{
			breaknote = 0;
		} else if ( guess == r ) {
			printf("We rolled %d: you win!", r);
		} else {
			printf("We rolled %d: you lose!", r);
		}
	}	

	return 0;
}
