#include <stdio.h>
#include "get_next_line.h"

int		main()
{
	char *line;
	int i = 0;

	while (get_next_line(0, &line){
		printf("%s\nCount: %d\n", line, i);
		i++;
	}
}