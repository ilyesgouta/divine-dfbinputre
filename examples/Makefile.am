INCLUDES = \
	-I$(top_srcdir)/include	\
	@DIRECTFB_CFLAGS@

bin_PROGRAMS = spooky

noinst_PROGRAMS = divine-test


spooky_SOURCES = spooky.c

spooky_LDADD = \
	$(top_builddir)/lib/libdivine.la	\
	-lm


divine_test_SOURCES = divine-test.c

divine_test_LDADD = \
	$(top_builddir)/lib/libdivine.la
