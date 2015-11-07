#include "computerv1.h"

void ft_ftoa(float f, char* s, int dec)
{
    long pow;
    int i;

    pow = 1;
    i = 0;
    while(pow * 10 <= f)
        pow *= 10;
    while(pow > 0)
    {
        *s++ = (char)(f / pow + '0');
        f -= ((int)(f / pow)) * pow;
        pow /= 10;
    }
    *s++ = '.';
    while(i < dec)
    {
        f *= 10;
        *s++ = (char)(f + '0');
        f -= (int)f;
        i++;
    }
    *s = '\0';
}

float       ft_atof(char *s)
{
    float res;
	int dec;
	int flag;
	int neg;

	res = 0.0;
	dec = 0;
	flag = 0;
	neg = (*s == '-') ? (s++, 1) : 0;
    while (*s != '\0' && (ft_isdigit(*s) || *s == '.'))
    {
        dec += flag ? 1 : 0;
        if (*s != '.')
            res = res * 10.0 + (*s - '0');
        else
            flag = 1;
        s++;
	}
	while (dec-- > 0)
		res *= 0.1;
	return (neg ? -res : res);
}
