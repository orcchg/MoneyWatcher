dnl Process this file with autoconf to produce a configure script.

AC_INIT(moneywatch, 1.0)
AC_PREREQ(2.68)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([configure.ac])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_SYSTEM

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])

AC_GNU_SOURCE
AC_C_BIGENDIAN
AC_PROG_CXX[g++-4.8]
AC_PROG_CC[gcc-4.8]
AC_HEADER_STDC
AC_SUBST([AM_CXXFLAGS], [-std=c++11])

dnl Initialize automake
AM_INIT_AUTOMAKE([1.11 dist-xz foreign color-tests])
dnl Nicely formatted make output
AM_SILENT_RULES([yes])

dnl This allows us specify individual liking flags for each target
AM_PROG_CC_C_O

dnl Check for GCC version
AC_MSG_CHECKING([whether gcc version is >= 4.8.1])
AC_EGREP_CPP(passed, [
#ifdef __GNUC__
#if !(__GNUC__ < 4 || __GNUC_MINOR__ < 8 || __GNUC_PATCHLEVEL__ < 1)
passed
#endif
#endif
], AC_MSG_RESULT([yes]), AC_MSG_RESULT([no])
					     AC_MSG_ERROR([Building this project requires GCC >= 4.8.1]))

dnl Initialize Libtool
LT_INIT

dnl Check if Libtool is present
dnl Libtool is used for building share libraries 
AC_PROG_LIBTOOL

dnl Enable pkg-config      
PKG_PROG_PKG_CONFIG    
EMBEDDED_LIBS=

dnl Check for EFL libraries  
#PKG_CHECK_MODULES([EINA], [eina >= 1.2.0])       
#PKG_CHECK_MODULES([ECORE], [ecore >= 1.2.0])
#PKG_CHECK_MODULES([ECOREX], [ecore-x >= 1.2.0])
#PKG_CHECK_MODULES([EDJE], [edje >= 1.2.0])     
#PKG_CHECK_MODULES([ELEMENTARY], [elementary >= 1.0])

dnl Check for Boost
AC_LANG_PUSH([C++])
AC_CHECK_HEADERS([boost/foreach.hpp], [], [AC_MSG_ERROR(You need the Boost libraries.)])
AC_LANG_POP([C++])

AC_OUTPUT
