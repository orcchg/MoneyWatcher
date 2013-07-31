bin_PROGRAMS =  moneywatcher


#######################################
# Sources 
#######################################
# Linker options
moneywatcher_LDFLAGS = -I$(top_srcdir) -all-static

# C/C++ files
moneywatcher_SOURCES = main.cpp money.cpp datetime.cpp cycle.cpp database.cpp entry.cpp record.cpp engine.cpp

# Compiler options. Here we are adding the include directory
# to be searched for headers included in the source code.
moneywatcher_CPPFLAGS =

# Used libraries
moneywatcher_LDADD = lib_moneywatcher.la

# Building Libtool library
lib_LTLIBRARIES = lib_moneywatcher.la

lib_moneywatcher_la_LDFLAGS = -module -avoid-version -shared -version-info 1:0:0

lib_moneywatcher_la_SOURCES = main.cpp money.cpp datetime.cpp cycle.cpp database.cpp entry.cpp record.cpp engine.cpp

lib_moneywatcher_la_CPPFLAGS = -I$(top_srcdir) -fPIC

lib_moneywatcher_la_LIBADD =


#######################################
# Cleaning rule
#######################################
clean:
	rm Makefile
	rm ${bin_PROGRAMS}
	rm *.o
