## Makefile.am for DiVine/proxy/requestor

INTERFACES_DIR = $(MODULEDIR)/interfaces

idivinedir = $(INTERFACES_DIR)/IDiVine

INCLUDES = \
	-I$(top_builddir)/include	\
	-I$(top_srcdir)/include		\
	-I$(top_builddir)/lib		\
	-I$(top_srcdir)/lib		\
	-I$(top_srcdir)/proxy/dispatcher	\
	$(DIRECTFB_CFLAGS)		\
	-DDATADIR=\"${RUNTIME_SYSROOT}@DATADIR@\"

LIBS = \
	$(top_builddir)/lib/libdivine.la	\
	-lvoodoo				\
	$(DIRECTFB_LIBS)


idivine_LTLIBRARIES = \
	libidivine_requestor.la

if BUILD_STATIC
idivine_DATA              = libidivine_requestor.o
endif

libidivine_requestor_la_SOURCES = idivine_requestor.c
libidivine_requestor_la_LDFLAGS = -avoid-version -module
libidivine_requestor_la_LIBADDD = $(LIBS)


include $(top_srcdir)/rules/libobject.make
