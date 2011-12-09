## Makefile.am for DiVine/driver

INCLUDES = @DIRECTFB_CFLAGS@

divine_LTLIBRARIES = libdirectfb_divine.la

divinedir = $(MODULEDIR)/inputdrivers

libdirectfb_divine_la_SOURCES = divine.c

libdirectfb_divine_la_LDFLAGS = \
        -export-dynamic		\
	-avoid-version
