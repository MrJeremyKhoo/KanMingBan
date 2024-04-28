# Set the name of the executable
bin_PROGRAMS = kmb

# Define the source files
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

AM_CFLAGS = -Wall -Wextra

AUTOMAKE_OPTIONS = subdir-objects
# Specify the data file to be included in the distribution tarball
DISTFILES = data/kmb.dat


# Specify where the data file should be installed
install-data-local:
	@mkdir -p $(DESTDIR)$(bindir)/data
	$(INSTALL_DATA) $(srcdir)/data/kmb.dat $(DESTDIR)$(bindir)/data/
