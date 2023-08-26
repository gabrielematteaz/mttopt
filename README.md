# mttopt
My personal C library to parse arguments options

# Enums
- mttopt_opt_fs_t

# Structs
- mttopt_opt_t

# Functions
- mttopt_extr_opt

# Example
```c
#include "mttopt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct mttopt_opt_t optv[] = {
		{ 'f', REQUIRED_ARG },
		{ 'u', NO_ARG },
		{ 't', REQUIRED_ARG }
	};

	while (1)
	{
		struct mttopt_opt_t *opt = mttopt_extr_opt(argc, argv, 3, optv);

		if (opt == NULL) break;

		int alias = opt->alias;

		switch (alias)
		{
		case 'f':
			/* ... */

			break;
		case 'u':
			/* ... */

			break;
		case 't':
			/* ... */

			break;
		}
	}
```
