INCLUDES = \
	-I$(top_srcdir)/include	\
	@DIRECTFB_CFLAGS@

bin_PROGRAMS = spooky dfbinputre

noinst_PROGRAMS = divine-test


spooky_SOURCES = spooky.c

spooky_LDADD = \
	$(top_builddir)/lib/libdivine.la	\
	$(DIRECTFB_LIBS) -lm

dfbinputre_SOURCES = dfbinputre.c

dfbinputre_LDADD = \
     $(top_builddir)/lib/libdivine.la	\
     $(DIRECTFB_LIBS) -lm

divine_test_SOURCES = divine-test.c

divine_test_LDADD = \
	$(top_builddir)/lib/libdivine.la  \
	$(DIRECTFB_LIBS) -lm

EXTRA_DIST = \
	scroll_circle.spooky	\
	scroll_diagonal.spooky	\
	scroll_vertical.spooky

