# mttopt
My personal C library to parse arguments options

# Example
In this example I use the "mttopt_exctr_optv" function without a limit (-1) to get 2 options and a flag
```c
#include "mttopt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	char **args = argv + 1;

	struct mttopt_opt_t optv[] = {
		'o', 1, NULL,
		'l', 1, NULL,
		'u', 0, NULL,
		0,   0, 0,
	};

	printf("First non-option argument: %s\n", args[mttopt_exctr_optv(-1, args, -1, optv)]);
	printf("%c %s\n", optv[0].shrt, optv[0].arg);
	printf("%c %s\n", optv[1].shrt, optv[1].arg);
	printf("%s\n", optv[2].shrt == 0 ? "Found" : "Not found");

	return 0;
}
```
