# mttopt
My personal C library to parse arguments options

# Structs
- mttopt_opt_t

# Enums
- mttopt_opt_copymode_t
- mttopt_opt_argmode_t
- mttopt_opt_status_t

# Functions
- mttopt_extract_optv

# Example
In this example I use the "mttopt_exctract_optv" function without a limit (argc == 0) to get 3 options
```c
#include "mttlib/mttopt/mttopt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct mttopt_opt_t optv[] = {
		{ 'f', 0, MUST_HAVE_ARG, 0, },
		{ 't', 0, MUST_HAVE_ARG, 0, },
		{ 'u', IGNORE_COPIES, 0, 0, },
	};

	int avoff = mttopt_extract_optv(0, argv, 3, optv);

	if (avoff)
	{
		printf("First argument: %i\n", argvoff);

		if (optv[0].status == FOUND) printf("'%c' %s\n", optv[0].val, optv[0].arg);

		if (optv[1].status == FOUND) printf("'%c' %s\n", optv[1].val, optv[1].arg);

		if (optv[2].status == FOUND) printf("'%c'\n", optv[2].val);
	}

	return 0;
}
```
