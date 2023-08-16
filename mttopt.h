#ifndef MTTOPT_H
#define MTTOPT_H

#include <stddef.h>

#define OPT_FS_OVERWRITE_ON_COPY 0x00
#define OPT_FS_IGNORE_COPIES 0x01
#define OPT_FS_EXIT_ON_COPY 0x02
#define OPT_FS_HAS_NO_ARG 0x00
#define OPT_FS_CAN_HAVE_ARG 0x04
#define OPT_FS_MUST_HAVE_ARG 0x0C

struct mttopt_opt_t
{
	char shrt;
	int fs;
	int found;
	const char *arg;
};

struct mttopt_wopt_t
{
	wchar_t shrt;
	int fs;
	int found;
	const wchar_t *arg;
};

int mttopt_extr_optv(int argc, char *argv[], int optc, struct mttopt_opt_t *optv);

int mttopt_extr_woptv(int wargc, wchar_t *wargv[], int woptc, struct mttopt_wopt_t *woptv);

#endif