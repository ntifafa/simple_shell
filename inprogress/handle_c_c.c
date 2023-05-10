#include "main.h"


/**
 * _handle - handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return:
 */

void _handle(int signals)
{
	(void)signals;
	write(1, "RN_SHELL $ ", 11);
}
