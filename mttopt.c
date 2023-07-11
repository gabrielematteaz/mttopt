#include "mttopt.h"

int mttopt_exctr_optv(int argc, char **argv, int optc, struct mttopt_opt_t* optv)
{
	char **av, **avc, *arg, ac;
	struct mttopt_opt_t *ov, *ovc;

	if (argv && optv)
	{
		av = argv;

		if (argc < 0)
		{
			while (*av) av++;

			argc = av - argv;
		}

		ov = optv;

		if (optc < 0)
		{
			while (ov->shrt) ov++;

			optc = ov - optv;
		}

		av = argv, avc = argv + argc, ovc = optv + optc;

		while (av < avc)
		{
			arg = *av;

			if (*arg == '-')
			{
				while (ac = *++arg, ac)
				{
					ov = optv;

					while (ov < ovc)
					{
						if (ac == ov->shrt)
						{
							if (ov->fs)
							{
								ov->arg = *++arg ? arg : *++av;

								goto next;
							}
							else
							{
								ov->shrt = 0;

								break;
							}
						}
								
						ov++;
					}
				}
			}
			else break;

		next:
			av++;
		}

		return av - argv;
	}

	return -1;
}