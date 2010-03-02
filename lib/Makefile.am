INCLUDES = \
	-I$(top_srcdir)/include	\
	@DIRECTFB_INTERNAL_CFLAGS@

lib_LTLIBRARIES = libdivine.la

libdivine_la_SOURCES = \
	divine.c	\
	idivine.c

libdivine_la_LDFLAGS = \
        -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)	\
        -release $(LT_RELEASE)

libdivine_la_LIBADD = \
	@DIRECTFB_LIBS@
