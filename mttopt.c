#include "mttopt.h"

int mttopt_extract_optv(int argc, char **argv, int optc, struct mttopt_opt_t *optv)
{
	char **av, **avc, *arg, *a, ac;
	struct mttopt_opt_t *ov, *ovc;

	if (argv != NULL && optv != NULL)
	{
		av = argv + 1;

		if (argc == 0)
		{
			while (*av != NULL) av++;

			argc = av - argv;
		}

		avc = argv + argc;

		if (optc == 0)
		{
			ov = optv;

			while (ov->val) ov++;

			optc = ov - optv;
		}

		av = argv + 1;
		ovc = optv + optc;

		while (av < avc)
		{
			arg = *av;

			if (*arg == '-')
			{
				a = arg + 1;
				ac = *a;

				if (ac == '-')
				{
					av++;

					break;
				}

				while (ac)
				{
					a++;
					ov = optv;

					while (ov < ovc)
					{
						if (ac == ov->val)
						{
							if (ov->flags & CANNOT_REPEAT && ov->status == FOUND)
							{
								if (ov->flags & HAS_ARG)
								{
									if (*a) break;
									else
									{
										av++;

										goto next;
									}
								}
								else break;
							}

							ov->status = FOUND;

							if (ov->flags & HAS_ARG)
							{
								if (*a) ov->arg = a;
								else
								{
									av++;
									ov->arg = *av;
								}

								goto next;
							}
							else break;
						}
						
						ov++;
					}

					ac = *a;
				}
			}
			else break;

		next:
			av++;
		}

		return av - argv;
	}

	return 0;
}