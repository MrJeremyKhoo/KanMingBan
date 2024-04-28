# Set the name of the executable
bin_PROGRAMS = kmb

# Define the source files here
kmb_SOURCES = \
    Application/dataParser.c \
    Application/errorHandler.c \
    Application/kmbInit.c \
    Application/headerParser.c \
    main.c \
    Presentation/table.c \
    Business/commandParser.c \
    Application/add.c \
    Application/delete.c \
    Application/promote.c \
    Application/regress.c \
    Application/availID.c \
    Application/taskString.c \
    Application/makeAvailID.c

include_HEADERS = \
    Application/dataParser.h \
    Application/errorHandler.h \
    Application/kmbInit.h \
    Application/headerParser.h \
    global.h \
    Presentation/table.h \
    Business/commandParser.h \
    Application/add.h \
    Application/delete.h \
    Application/promote.h \
    Application/regress.h \
    Application/availID.h \
    Application/taskString.h \
    Application/makeAvailID.h

AM_CFLAGS = -Wall -Wextra

dist_data_DATA = data/kmb.dat

AUTOMAKE_OPTIONS = subdir-objects
# Specify the data file to be included in the distribution tarball

# Specify where the data file should be installed
install-data-local:
	@mkdir -p $(DESTDIR)$(bindir)/data
	$(INSTALL_DATA) $(srcdir)/data/kmb.dat $(DESTDIR)$(bindir)/data/
	chmod 666 $(DESTDIR)$(bindir)/data/kmb.dat

uninstall-local:
	-rm -f $(DESTDIR)$(bindir)/data/kmb.dat
