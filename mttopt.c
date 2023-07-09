#include "mttopt.h"

size_t mttopt_extr_args_opts(char **args, struct mttopt_opt_t* optv)
{
	char **as = args + 1, *arg, *a, ac;
	struct mttopt_opt_t* o;

	while (arg = *as, arg)
	{
		if (*arg == '-')
		{
			a = arg + 1;

			while (ac = *a, ac)
			{
				o = optv;

				while (o->shrt)
				{
					if (ac == o->shrt)
					{
						if (o->aoff < 0)
						{
							o->asoff = as - args;

							break;
						}
						else
						{
							if (*++a) o->asoff = as - args, o->aoff = a - arg;
							else o->asoff = ++as - args, o->aoff = 0;

							goto next;
						}

						break;
					}

					o++;
				}

			next:
				a++;
			}
		}
		else break;

		as++;
	}

	return as - args;
}