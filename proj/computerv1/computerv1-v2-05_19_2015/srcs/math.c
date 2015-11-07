#include "computerv1.h"

float	mt_fsqrt(float a)
{
	float	root;
	
	if (a < 0.0)
		return (-1.0);
	else if (a == 0.0)
		return (0.0);
	root = (float)((int)((a > (int)a) ? a : a - 1.0));
	while (((root * root) - a) > 0.000001)
	{
		root = (root + (a / root)) / 2;
	}
	return (root);
}

