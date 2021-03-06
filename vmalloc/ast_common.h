/* : : generated from features/common by iffe version 2002-02-14 : : */
#ifndef _AST_COMMON_H
#define _AST_COMMON_H	1
#define _typ_size_t	1
#define _hdr_stdlib     0
#define	_sys_types	1	/* #include <sys/types.h> ok */
#define _typ_long_double	1	/* long double is a type */
#define	_sys_stat	1	/* #include <sys/stat.h> ok */
#define	_sys_socket	1	/* #include <sys/socket.h> ok */
#define _std_proto	1	/* standard C prototypes ok  */
#define _ptr_void	1	/* standard C void* ok  */
/* disable non-standard linux/gnu inlines */
#ifdef __GNUC__
#	undef	__OPTIMIZE_SIZE__
#	define	__OPTIMIZE_SIZE__	1
#endif

/* __STD_C indicates that the language is ANSI-C or C++ */
#if !defined(__STD_C) && __STDC__
#	define	__STD_C		1
#endif
#if !defined(__STD_C) && (__cplusplus || c_plusplus)
#	define __STD_C		1
#endif
#if !defined(__STD_C) && _std_proto
#	define __STD_C		1
#endif
#if !defined(__STD_C)
#	define __STD_C		0
#endif

/* extern symbols must be protected against C++ name mangling */
#ifndef _BEGIN_EXTERNS_
#	if __cplusplus || c_plusplus
#		define _BEGIN_EXTERNS_	extern "C" {
#		define _END_EXTERNS_	}
#	else
#		define _BEGIN_EXTERNS_
#		define _END_EXTERNS_
#	endif
#endif

/* _ARG_ simplifies function prototyping among flavors of C */
#ifndef _ARG_
#	if __STD_C
#		define _ARG_(x)	x
#	else
#		define _ARG_(x)	()
#	endif
#endif

/* _NIL_ simplifies defining nil pointers to a given type */
#ifndef _NIL_
#	define _NIL_(x)	((x)0)
#endif

/* __INLINE__ is the inline keyword */
#if !defined(__INLINE__) && defined(__cplusplus)
#	define __INLINE__	inline
#endif
#if !defined(__INLINE__) && defined(_WIN32) && !defined(__GNUC__)
#	define __INLINE__	__inline
#endif

/* Void_t is defined so that Void_t* can address any type */
#ifndef Void_t
#	if __STD_C
#		define Void_t		void
#	else
#		define Void_t		char
#	endif
#endif

/* dynamic linked library external scope handling */
#ifdef __DYNAMIC__
#	undef	__DYNAMIC__
#	ifndef _DLL
#		define _DLL
#	endif
#endif
#if _dll_import
#	if _BLD_STATIC && !_BLD_DLL
#		undef	_DLL
#	else
#		if !_UWIN && !defined(_DLL)
#			define _DLL		1
#		endif
#	endif
#	if !defined(__EXPORT__) && _BLD_DLL
#		define __EXPORT__	__declspec(dllexport)
#	endif
#	if !defined(__IMPORT__) && ( _BLD_DLL || _DLL )
#		define __IMPORT__	__declspec(dllimport)
#	endif
#	if _BLD_DLL && _UWIN
#	define __DYNAMIC__(v)		(_ast_getdll()->_ast_ ## v)
#	endif
#endif
#if !defined(_astimport)
#	if defined(__IMPORT__) && _DLL
#		define _astimport	__IMPORT__
#	else
#		define _astimport	extern
#	endif
#endif
#if _dll_import && !_BLD_DLL
#	ifdef __STDC__
#	define __EXTERN__(T,obj)	extern T obj; T* _imp__ ## obj = &obj
#	define __DEFINE__(T,obj,val)	T obj = val; T* _imp__ ## obj = &obj
#	else
#	define __EXTERN__(T,obj)	extern T obj; T* _imp__/**/obj = &obj
#	define __DEFINE__(T,obj,val)	T obj = val; T* _imp__/**/obj = &obj
#	endif
#else
#	define __EXTERN__(T,obj)	extern T obj
#	define __DEFINE__(T,obj,val)	T obj = val
#endif

#define __ast_LL	1	/* LL numeric suffix supported  */
#define _ast_int1_t		char
#define _ast_int2_t		short
#define _ast_int4_t		int
#define _ast_int8_t		long long
#define _ast_intmax_t		_ast_int8_t
#define _ast_intswap		7

#define _ast_flt4_t		float
#define _ast_flt8_t		double
#define _ast_flt12_t		long double
#define _ast_fltmax_t		_ast_flt12_t

#ifndef va_listref
#define va_listref(p) (p)	/* pass va_list to varargs function */
#define va_listval(p) (p)	/* retrieve va_list from va_arg(ap,va_listarg) */
#define va_listarg va_list	/* va_arg() va_list type */
#undef	_ast_va_list
#ifdef	va_start
#define _ast_va_list va_list
#else
#define _ast_va_list void*	/* va_list that avoids #include */
#endif
#endif
#ifndef _AST_STD_H
#	if __STD_C && _hdr_stddef
#	include	<stddef.h>
#	endif
#	if _sys_types
#	include	<types.h>
#	endif
#endif
#if !_typ_size_t
#	define _typ_size_t	1
typedef int size_t;
#endif
#if !_typ_ssize_t
#	define _typ_ssize_t	1
typedef int ssize_t;
#endif
#if !_typ_ptrdiff_t
#	define _typ_ptrdiff_t	1
typedef int ptrdiff_t;
#endif

#endif
