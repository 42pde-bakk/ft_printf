#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int	main(void)
{
	char		s1[] = "Lookie";
	char		s2[] = "Here";
	char		s3[] = "Wow this is a really big string wowow";
	char		s4[] = "Old man";
	char		*nlptr = NULL;


	char		c1 = '&';
	char		c2 = 'D';
	char		c3 = '7';
	char		c4 = 48;

	int			i1 = 8902;
	int			i2 = 97;
	int			i3 = 0;
	int			i4 = INT_MIN;
	int			i5 = INT_MAX;

	unsigned	o1 = 11;
	unsigned	o2 = 67;
	unsigned	o3 = 88;
	unsigned	o4 = 111;

	unsigned	x1 = 15;
	unsigned	X1 = 15;
	unsigned	x2 = 23;
	unsigned	X2 = 23;
	unsigned	x3 = 64;
	unsigned	X3 = 64;
	unsigned	x4 = 128;
	unsigned	X4 = 128;

	char		n1;
	char		n2;
	char		*nstr1;
	int			H = 7;
	char		*str;

	float		f1 = 392.65;
	float		f2 = 413.6587;
	float		f3 = 81201727.2;

	double		d1 = 392.65;
	double		d2 = 413.6587;
	double		d3 = 81201727.2;

	ft_printf("\033[0;31m");
	ft_printf("Strings: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	printf("<- %i\n\n", printf("%-8s$ %7s$ %.8s$ %.*s$", s1, s2, s3, H, s4));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Strings: -010Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-10s$ %+s$ %-8.7s$ %#s$", s1, s2, s3, s4));
	printf("<- %i \n\n", printf("%-10s$ %+s$ %-8.7s$ %#s$", s1, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;32m");
	ft_printf("Chars: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%7c$ %07c$ %.8c$ %.*c$", c1, c2, c3, 0, c4));
	printf("<- %i \n\n", printf("%7c$ %07c$ %.8c$ %.*c$", c1, c2, c3, 0, c4));
	ft_printf("\033[0m");

	ft_printf("\033[1;32m");
	ft_printf("Chars: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0c$ %+0c$ %-8.7c$ %#c$", c1, c2, c3, c4));
	printf("<- %i \n\n", printf("%-0c$ %+0c$ %-8.7c$ %#c$", c1, c2, c3, c4));
	ft_printf("\033[0m");

	ft_printf("\033[0;33m");
	ft_printf("Integers: .6(-3) +.7(-446) 07(-54) +5(432)\n");
	ft_printf("<- %i \n", ft_printf("%.6i, |%+.7i, |%07i, |%+5i", -3, -446, -54, 432));
	printf("<- %i \n\n", printf("%.6i, |%.7i, |%07i, |%+5i", -3, -446, -54, 432));
	ft_printf("\033[0m");

	ft_printf("\033[1;33m");
	printf("Integers: +08.6, +8.6, +07,       +7,     + 7,     +.7,      +0.7:\n");
	ft_printf("<- %i \n", ft_printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, -32, -32, -32));
	printf("<- %i \n\n", printf("%+08.6d , |%+8.6d, |%+07d, |%+7d, |%+ 7d, |%+.7d, |%+0.7d", 32, 32, 32, 32, -32, -32, -32));
	ft_printf("\033[0m");

	ft_printf("\033[0;34m");
	ft_printf("Octals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3o$ %07o$ %.8o$ %.*o$", o1, o2, o3, 5, o4));
	printf("<- %i \n\n", printf("%-3o$ %07o$ %.8o$ %.*o$", o1, o2, o3, 5, o4));
	ft_printf("\033[0m");

	ft_printf("\033[1;34m");
	ft_printf("Octals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i\n", ft_printf("%-3o$ %+0o$ %-8.7o$ %#o$", o1, o2, o3, o4));
	printf("<- %i \n\n", printf("%-3o$ %+0o$ %-8.7o$ %#o$", o1, o2, o3, o4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("hexadecimals: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	printf("<- %i \n\n", printf("%3x$ %07x$ %.8x$ %.*x$", x1, x2, x3, 11, x4));
	ft_printf("\033[0m");

	ft_printf("\033[1;35m");
	ft_printf("hexadecimals: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0x$ %+0x$ %-8.7x$ %x$", x1, x2, ULONG_MAX, x4));
	printf("<- %i \n\n", printf("%-0x$ %+0x$ %-8.7x$ %x$", x1, x2, ULONG_MAX, x4));
	ft_printf("\033[0m");

	ft_printf("\033[0;36m");
	ft_printf("HEXADECIMALS: -Flag, 0Flag, .Flag, *Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	printf("<- %i \n\n", printf("%-3X$ %07X$ %.8X$ %.*X$", X1, X2, X3, 8, X4));
	ft_printf("\033[0m");

	ft_printf("\033[1;36m");
	ft_printf("HEXADECIMALS: -0Flag, +0Flag, -8.7Flag, #Flag:\n");
	ft_printf("<- %i \n", ft_printf("%-0X$ %+0X$ %-8.7X$ %#X$", ULONG_MAX, X2, X3, X4));
	printf("<- %i \n\n", printf("%-0X$ %+0X$ %-8.7X$ %#X$", ULONG_MAX, X2, X3, X4));
	ft_printf("\033[0m");

	ft_printf("\033[0;31m");
	ft_printf("Pointer addresses:\n");
	ft_printf("<- %i \n", ft_printf("%-8p$ %07p$ %.8p$ %.*p$", ULONG_MAX, &s2, &s3, H, &s4));
	printf("<- %i \n\n", printf("%-8p$ %07p$ %.8p$ %.*p$", ULONG_MAX, &s2, &s3, H, &s4));
	ft_printf("\033[0m");

	ft_printf("\033[1;31m");
	ft_printf("Simply check each conversion without any flags \n\n");
	ft_printf("<- %i \n", ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));
	printf("<- %i \n\n", printf("%c, %s, %p, %d, %i, %u, %x, %X, %% ", c1, s1, &s1, i1, i2, o1, x1, X1));

	ft_printf("\033[0;32m");
	printf("Try special case like 0 or smallest int or empty string or null pointer\n");
	ft_printf("<- %i \n", ft_printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483648, "", &nlptr));
	printf("<- %i \n\n\n", printf("%i, %i, %s, %p $and some final words after the last conversion$", 0, -2147483648, "", &nlptr));

	ft_printf("\033[1;32m");
	ft_printf("\033[0;33m");

	ft_printf("Simple Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	printf("<- %i \n\n", printf("%7s, %7s, %7s, %*s$", s1, s2, s3, 7, s4));
	ft_printf("\033[1;33m");
	ft_printf("<- %i \n", ft_printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	printf("<- %i \n\n", printf("%-7s, %-7s, %-7s, %-8s$", s1, s2, s3, s4));
	ft_printf("\033[0;34m");
	ft_printf("%i \n", ft_printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	printf("%i \n\n", printf("%7s, %7s, %7s, %7s$", s1, s2, s3, s4));
	ft_printf("\033[1;34m");
	ft_printf("<- %i \n", ft_printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	printf("<- %i \n\n\n", printf("%6.8s, %8.6s, %.5s, %.23s$", s1, s2, s3, s4));
	ft_printf("\033[0m");

	ft_printf("\033[0;35m");
	ft_printf("Advanced Flags Management:\n");
	ft_printf("<- %i \n", ft_printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	printf("<- %i \n\n", printf("%*s, %*s, %*s, %*s$", -1, s1, 0, s2, 9, s3, 7, s4));
	ft_printf("\033[1;35m");
	ft_printf("<- %i \n", ft_printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	printf("<- %i \n\n", printf("Precision *: %.*s, %.*s, %.*s,%*.*s", -1, s1, 0, s2, 23, s3, 8, 7, s4));
	ft_printf("\033[0;36m");
	ft_printf("<- %i \n", ft_printf("Duplicate flags: %---i, %###X, %009s, %**i$", -20, 67, s2, 7, 8, 90127));
  	printf("<- %i \n\n", printf("Duplicate flags: %---i, %###X, %009s, %**i$", -20, 67, s2, 7, 8, 90127));

	ft_printf("\033[1;36m");
	ft_printf("Now for the bonus tests:\n\n");

	ft_printf("\033[0;31m");
	ft_printf("Testing the n flag\n");
	ft_printf("%s - 123456789%n\n", "voorbeeldstring1", &n2);
	ft_printf("%i\n", n2);
	printf("%s - 123456789%n\n", "voorbeeldstring2", &n1);
	printf("%i\n\n", n1);

	ft_printf("\033[1;31m");
	ft_printf("Starting with l and ll flags: LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX \n\n");
	ft_printf("<- %i \n", ft_printf("%li, %li, %u, %uli$", LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX));
	printf("<- %i \n\n", printf("%li, %li, %u, %uli$", LONG_MIN, LONG_MAX, UINT_MAX, ULONG_MAX));

	ft_printf("\033[0;32m");
	ft_printf("Now some h and hh flags:\n\n");
	ft_printf("<- %i \n", ft_printf("%hi, %hhi, %h7i, %hh8.6i$", i1, i2, i3, i4));
	printf("<- %i \n\n", printf("%hi, %hhi, %h7i, %hh8.6i$", i1, i2, i3, i4));

	ft_printf("\033[1;32m");
	ft_printf("2 with #flag and 2 with +flag:\n\n");
	ft_printf("<- %i \n", ft_printf("%#x, %#-7o, %+10.8i, %+u", x1, o1, i1, x3));
	printf("<- %i \n\n", printf("%#x, %#-7o, %+10.8i, %+u", x1, o1, i1, x3));


	ft_printf("\033[0;33m");
	ft_printf(" ' flags and \\  :\n");
	printf(" \%% \n");
	ft_printf(" \%% \n");
	ft_printf("hello \n world\n\n"); 

	ft_printf("\033[1;33m");
	ft_printf("Edge case checks: negative precision, negative width w/e \n");
	ft_printf("<- %i \n", ft_printf("%*i, %.*i, %*.*i$", -5, i1, -6, i2, -3, -5, i3));
	printf("<- %i \n", printf("%*i, %.*i, %*.*i$", -5, i1, -6, i2, -3, -5, i3));

	ft_printf("\033[0;34m");
	ft_printf("Ints: 3.7i, 3.7i, 3.3i, -3.7i \n");
	ft_printf("<- %i \n", ft_printf("%3.7i, %3.7i, %3.3i, %-03.7i", 3267, -2375, -8462, 3267));
	printf("<- %i \n\n", printf("%3.7i, %3.7i, %3.3i, %-03.7i", 3267, -2375, -8462, 3267));

	ft_printf("\033[1;34m");
	ft_printf("Ints: 08.5i, 010.5i, 08.5i, 08.3i \n");
	ft_printf("<- %i \n", ft_printf("%08.5i, %010.5i, %08.5i, %08.3i", 34, -216, 0, 8375));
	printf("<- %i \n\n", printf("%08.5i, %010.5i, %08.5i, %08.3i", 34, -216, 0, 8375));

	ft_printf("\033[0;35m");
	ft_printf("Shorts and Longs: hhi, hi, li, lli, hhi\n");
	ft_printf("<- %i \n", ft_printf("%hhi, %hi, %li, %lli, %hhi", (char)-45, (short)-385, (long)-32, (long long)-43, (char)-87));
	printf("<- %i \n\n", printf("%hhi, %hi, %li, %lli, %hhi", (char)-45, (short)-385, (long)-32, (long long)-43, (char)-87));

	ft_printf("\033[1;35m");
	ft_printf("Ints: | i, |4 i, |+ i, |05 i \n");
	ft_printf("<- %i \n", ft_printf("this % i number, % i, % d, % +i, % 5i", -267, -1, -267, -7, -2562));
	printf("<- %i \n\n", printf("this % i number, % i, % d, % +i, % 5i", -267, -1, -267, -7, -2562));

	ft_printf("\033[0;36m");
	ft_printf("Int 0: +.0i, +.i, +-5.0i, +-5.i \n");
	ft_printf("<- %i \n", ft_printf("%+.0i, %+.i, %+-5.0i, %+1.i", 0, 0, 0, 0));
	printf("<- %i \n\n", printf("%+.0i, %+.i, %+-5.0i, %+1.i", 0, 0, 0, 0));

	ft_printf("\033[1;36m");
	ft_printf("Octal: #.5o, #8.5o, #2.7o, #-8.5o, $-2.7o\n");
	ft_printf("<- %i \n", ft_printf("%#.5o, %#8.5o, %#2.7o, %-#8.5o, %#-2.7o", 21, 34, 3267, 34, 3267));
	printf("<- %i \n\n", printf("%#.5o, %#8.5o, %#2.7o, %-#8.5o, %#-2.7o", 21, 34, 3267, 34, 3267));

	ft_printf("\033[0;31m");
	ft_printf("Hexa: #.0x, #.x, #5.0x, #5.x, #-5.0x, #-5.x \n");
	ft_printf("<- %i \n", ft_printf("%#.0x, %#.x, %#5.0x, %-5.0x, %#-5.x", 0, 0, 0, 0, 0));
	printf("<- %i \n\n", printf("%#.0x, %#.x, %#5.0x, %-5.0x, %#-5.x", 0, 0, 0, 0, 0));

	ft_printf("\033[0;31m");
	ft_printf("Null pointers :\n");
	ft_printf("<- %i \n", ft_printf("%p, %9.2p, %2.9p, %.5p", NULL, 1234, 1234, 0));
	printf("<- %i \n\n", printf("%p, %9.2p, %2.9p, %.5p", NULL, 1234, 1234, 0));

	ft_printf("\033[1;31m");
	ft_printf("Floats: f, 07.2f, .0f\n");
	ft_printf("<- %i \n", ft_printf("%.7f, %07.2f, %.0f", f1, f1, f1));
	printf("<- %i \n\n", printf("%.7f, %07.2f, %.0f", f1, f1, f1));
	ft_printf("<- %i \n", ft_printf("%f, %07.2f, %.f", d1, d1, d1));
	printf("<- %i \n\n", printf("%f, %07.2f, %.f", d1, d1, d1));
	ft_printf("\033[0;32m");
	ft_printf("Hexadecimal floats: a, 07.2a, .0a\n"); 
	ft_printf("<- %i \n", ft_printf("%#a, %-13.2a, %.0a", f1, f1, f1));
	printf("<- %i \n\n", printf("%#a, %-13.2a, %.0a", f1, f1, f1));

	ft_printf("\033[1;32m");
	ft_printf("Scientific notation!:\n");
	ft_printf("<- %d \n", ft_printf("%e, %14e, %.e, %.8e", f1, f1, f1, f3));
	printf("<- %d \n\n", printf("%e, %14e, %.e, %.8e", f1, f1, f1, f3));

	ft_printf("\033[1;32m");
	ft_printf("G conversion:\n");
	printf("<- %d \n\n", printf("%g, %g, %g", f1, f2, f1));
	ft_printf("<- %d \n", ft_printf("%g, %g, %g", f1, f2, f1));

	ft_printf("\033[1;32m");
	ft_printf("Apostrophe flag:\n");
	setlocale(LC_ALL, "en_US");
	ft_printf("<- %i \n", ft_printf("%'i, %8'd, %'p, %'x", 12757, 965787, &nlptr, 286331153));
	printf("<- %i \n\n", printf("%'i, %8'd, %'p, %'x", 12757, 965787, &nlptr, 286331153));

	ft_printf("\033[1;31m");
	ft_printf("R ");
	ft_printf("\033[1;32m");
	ft_printf("A ");
	ft_printf("\033[1;33m");
	ft_printf("I ");
	ft_printf("\033[1;34m");
	ft_printf("N ");
	ft_printf("\033[1;35m");
	ft_printf("B ");
	ft_printf("\033[1;36m");
	ft_printf("O ");
	ft_printf("\033[1;31m");
	ft_printf("W ");
	ft_printf("\033[1;32m");
	ft_printf("!\n");
//	while (1) {}

	return 0;
}
