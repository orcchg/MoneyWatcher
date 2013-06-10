dnl Process this file with autoconf to produce a configure script.

AC_INIT(moneywatch, 1.0)
AC_PREREQ(2.68)
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([configure.ac])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_SYSTEM

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AC_GNU_SOURCE
AC_C_BIGENDIAN
AC_PROG_CXX
AC_PROG_CC
AC_HEADER_STDC

dnl Initialize automake
AM_INIT_AUTOMAKE([1.11 dist-xz foreign color-tests])
dnl Nicely formatted make output
AM_SILENT_RULES([yes])

dnl This allows us specify individual liking flags for each target
AM_PROG_CC_C_O

dnl Check for GCC version
AC_MSG_CHECKING([whether gcc version is >= 4.5.0])
AC_EGREP_CPP(passed, [
#ifdef __GNUC__
#if !(__GNUC__ < 4 || __GNUC_MINOR__ < 5 || __GNUC_PATCHLEVEL__ < 0)
passed
#endif
#endif
], AC_MSG_RESULT([yes]), AC_MSG_RESULT([no])
					     AC_MSG_ERROR([Building this project requires GCC >= 4.5.0]))

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

AC_OUTPUT
