#include "mttopt.h"
#include <stdio.h>

int mttopt_exctr_opts(int argc, char **args, int optc, struct mttopt_opt_t *opts)
{
	char **as, **asc, *arg, *a, ac;
	struct mttopt_opt_t *os, *osc;

	if (args && opts)
	{
		as = args;

		if (argc < 0)
		{
			while (*as != NULL) as++;

			argc = as - args;
		}

		as = args;
		asc = args + argc;
		os = opts;

		if (optc < 0)
		{
			while (os->shrt) os++;

			optc = os - opts;
		}

		osc = opts + optc;

		while (as < asc)
		{
			arg = *as;

			if (*arg == '-')
			{
				a = arg + 1;
				ac = *a;

				while (ac)
				{
					a++;
					os = opts;

					while (os->shrt)
					{
						if (ac == os->shrt)
						{
							if (os->flag)
							{
								os->shrt = 0;

								break;
							}
							else
							{
								if (*a) os->arg = a;
								else
								{
									as++;
									os->arg = *as;
								}

								goto next;
							}
						}

						os++;
					}

					ac = *a;
				}
			}
			else break;

	next:
			as++;
		}

		return as - args;
	}

	return -1;
}