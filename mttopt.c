#include "mttopt.h"

int mttopt_extr_optv(int argc, char *argv[], int optc, struct mttopt_opt_t *optv)
{
	char **av, **avc, *arg, *a;
	struct mttopt_opt_t *ov, *ovc;
	uint8_t ac, flags;

	if (argv == NULL || optv == NULL) return 0;

	av = argv + 1;
	avc = argv + argc;
	ovc = optv + optc;
	
	while (av < avc)
	{
		arg = *av;

		if (*arg == '-')
		{
			a = arg + 1;

			if (*a == '-')
			{
				av++;

				break;
			}

			ac = *a;

			while (ac)
			{
				ov = optv;

				while (ov < ovc)
				{
					if (ac == ov->shrt)
					{
						flags = ov->flags;

						if (ov->found)
						{
							if (flags & OPT_FLAGS_IGNORE_COPIES)
							{
								if (flags & OPT_FLAGS_CAN_HAVE_ARG)
								{
									if (flags & OPT_FLAGS_MUST_HAVE_ARG)
									{
										a++;

										if (*a == 0) av++;
									}

									goto next;
								}

								break;
							}
							else if (flags & OPT_FLAGS_EXIT_ON_COPY)
							{
								av++;

								if (flags & OPT_FLAGS_MUST_HAVE_ARG)
								{
									a++;

									if (*a == 0) av++;
								}

								goto exit;
							}
						}

						ov->found = 1;

						if (flags & OPT_FLAGS_CAN_HAVE_ARG)
						{
							a++;

							if ((flags & OPT_FLAGS_MUST_HAVE_ARG) == 12)
							{
								if (*a) ov->arg = a;
								else
								{
									av++;
									ov->arg = *av;
								}
							}
							else ov->arg = *a ? a : NULL;

							goto next;
						}

						ov->arg = NULL;

						break;
					}

					ov++;
				}

				a++;
				ac = *a;
			}
		}
		else break;

	next:
		av++;
	}

exit:
	return av - argv;
}

int mttopt_extr_woptv(int wargc, wchar_t *wargv[], int woptc, struct mttopt_wopt_t *woptv)
{
	wchar_t **wav, **wavc, *warg, *wa, wac;
	struct mttopt_wopt_t *wov, *wovc;
	uint8_t flags;

	if (wargv == NULL || woptv == NULL) return 0;

	wav = wargv + 1;
	wavc = wargv + wargc;
	wovc = woptv + woptc;
	
	while (wav < wavc)
	{
		warg = *wav;

		if (*warg == '-')
		{
			wa = warg + 1;

			if (*wa == '-')
			{
				wav++;

				break;
			}

			wac = *wa;

			while (wac)
			{
				wov = woptv;

				while (wov < wovc)
				{
					if (wac == wov->wshrt)
					{
						flags = wov->flags;

						if (wov->found)
						{
							if (flags & OPT_FLAGS_IGNORE_COPIES)
							{
								if (flags & OPT_FLAGS_CAN_HAVE_ARG)
								{
									if (flags & OPT_FLAGS_MUST_HAVE_ARG)
									{
										wa++;

										if (*wa == 0) wav++;
									}

									goto next;
								}

								break;
							}
							else if (flags & OPT_FLAGS_EXIT_ON_COPY)
							{
								wav++;

								if (flags & OPT_FLAGS_MUST_HAVE_ARG)
								{
									wa++;

									if (*wa == 0) wav++;
								}

								goto exit;
							}
						}

						wov->found = 1;

						if (flags & OPT_FLAGS_CAN_HAVE_ARG)
						{
							wa++;

							if ((flags & OPT_FLAGS_MUST_HAVE_ARG) == 12)
							{
								if (*wa) wov->warg = wa;
								else
								{
									wav++;
									wov->warg = *wav;
								}
							}
							else wov->warg = *wa ? wa : NULL;

							goto next;
						}

						wov->warg = NULL;

						break;
					}

					wov++;
				}

				wa++;
				wac = *wa;
			}
		}
		else break;

	next:
		wav++;
	}

exit:
	return wav - wargv;
}