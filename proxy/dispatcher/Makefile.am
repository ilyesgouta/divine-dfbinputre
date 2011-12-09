## Makefile.am for DiVine/proxy/dispatcher

INTERFACES_DIR = $(MODULEDIR)/interfaces

idivinedir = $(INTERFACES_DIR)/IDiVine

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_srcdir)/include		\
	-I$(top_builddir)/lib		\
	-I$(top_srcdir)/lib		\
	-I$(top_srcdir)/proxy/requestor	\
	$(DIRECTFB_CFLAGS)	\
	-DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\"

LIBS = \
	$(top_builddir)/lib/libdivine.la	\
	-lvoodoo				\
	$(DIRECTFB_LIBS)


idivine_LTLIBRARIES = \
	libidivine_dispatcher.la

if BUILD_STATIC
idivine_DATA              = libidivine_dispatcher.o
endif

libidivine_dispatcher_la_SOURCES = idivine_dispatcher.c idivine_dispatcher.h
libidivine_dispatcher_la_LDFLAGS = -avoid-version -module
libidivine_dispatcher_la_LIBADDD = $(LIBS)


include $(top_srcdir)/rules/libobject.make
