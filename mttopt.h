#ifndef MTTOPT_H
#define MTTOPT_H

#include <stdint.h>
#include <stddef.h>

struct mttopt_opt_t
{
	char val;
	uint8_t flags, status;
	char *arg;
};

enum mttopt_opt_flags_t
{
	HAS_NO_ARG = 0,
	CAN_REPEAT = 0,
	HAS_ARG = 1,
	CANNOT_REPEAT = 2,
};

enum mttopt_opt_status_t
{
	NOT_FOUND,
	FOUND,
};

int mttopt_extract_optv(int argc, char **argv, int optc, struct mttopt_opt_t *optv);

#endif