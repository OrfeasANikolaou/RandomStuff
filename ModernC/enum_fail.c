
 /* you can do this: */
enum { p0 = 1, p1 = 2*p0, p2 = 2*p1, p3 = 2*p2};

/* but not this: */
signed const o42 = 42;
enum {
	b42 = 42,					// THIS IS OKAY
	c52 = o42 + 10,		// NOT OKAY, o42 is an object (holds data), and not a literal
	b52 = b42 + 10		// OKAY, b42 is a literal (is data)
};
