#include <stdio.h>


unsigned char reverse_bits(unsigned char a)
{
	unsigned char r = 0;
	unsigned len = 8;

	while (len--)
	{
		r = (r << 1) | (a & 1);
		a >>= 1;
	}
	return (r);
}

int main()
{
	unsigned char a = 5;
	printf("%u", reverse_bits(a));
}

10100000