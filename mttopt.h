#ifndef MTTOPT_H
#define MTTOPT_H

#include <stddef.h>

struct mttopt_opt_t
{
	int shrt, flag;
	char *arg;
};

int mttopt_exctr_opts(int argc, char **args, int optc, struct mttopt_opt_t *opts);

#endif