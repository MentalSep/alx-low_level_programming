#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int rand()
{
	static int ct;

	ct++;
	if (ct == 1)
		return 8;
	if (ct == 2)
		return 8;
	if (ct == 3)
		return 7;
	if (ct == 4)
		return 9;
	if (ct == 5)
		return 23;
	if (ct == 6)
		return 74;
}
