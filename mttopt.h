#ifndef MTTOPT_H
#define MTTOPT_H

struct mttopt_opt_t
{
	int shrt, fs;
	char *arg;
};

int mttopt_exctr_optv(int argc, char **argv, int optc, struct mttopt_opt_t* optv);

#endif