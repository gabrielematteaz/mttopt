#ifndef MTTOPT_H
#define MTTOPT_H

#include <stddef.h>

struct mttopt_opt_t
{
	int shrt, asoff, aoff;
};

size_t mttopt_extr_args_opts(char **args, struct mttopt_opt_t* opts);

#endif