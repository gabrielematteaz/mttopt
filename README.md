# mttopt
My personal C library to parse arguments options

# Structs
- mttopt_opt_t
- mttopt_wopt_t

# Macros
- OPT_FS_OVERWRITE_ON_COPY
- OPT_FS_IGNORE_COPIES
- OPT_FS_EXIT_ON_COPY
- OPT_FS_HAS_NO_ARG
- OPT_FS_CAN_HAVE_ARG
- OPT_FS_MUST_HAVE_ARG

# Functions
- mttopt_extr_optv
- mttopt_extr_woptv

# Example
```c
#include "mttopt.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct mttopt_opt_t optv[] = {
		'f', OPT_FLAGS_MUST_HAVE_ARG, 0, NULL,
		't', OPT_FLAGS_CAN_HAVE_ARG, 0, NULL,
		'u', OPT_FLAGS_HAS_NO_ARG, 0, NULL
	};

	char **av = argv + mttopt_extr_optv(argc, argv, 3, optv), **avc = argv + argc;

	if (optv[0].found) printf("'%c' '%s'\n", optv[0].shrt, optv[0].arg);

	if (optv[1].found) printf("'%c' '%s'\n", optv[1].shrt, optv[1].arg);

	if (optv[2].found) printf("'%c'\n", optv[2].shrt);

	while (av < avc)
	{
		puts(*av);
		av++;
	}

	return 0;
}
```
