#if !defined( __WINDOWS__ ) && ( defined( _Windows ) || defined( _WINDOWS ) )
  #define __WINDOWS__
#endif /* !__WINDOWS__ && ( _Windows || _WINDOWS ) */
#if !defined( __WIN32__ ) && ( defined( WIN32 ) || defined( _WIN32 ) )
  #ifndef __WINDOWS__
    #define __WINDOWS__
  #endif /* __WINDOWS__ */
  #define __WIN32__
#endif /* !__WIN32__ && ( WIN32 || _WIN32 ) */
#if defined( __WINDOWS__ ) && !defined( __WIN32__ )
  #define __WIN16__
#endif /* __WINDOWS__ && !__WIN32__ */

/* and now I map it to my version of the above define --tjh */
#ifdef __WINDOWS__
#ifndef WINDOWS
#define WINDOWS
#endif
#endif /* __WINDOWS__ */

#ifdef linux
#ifndef LINUX
#define LINUX
#endif
#endif

#if ( defined( __FreeBSD__ ) || defined ( __NetBSD__ ) )
#ifndef FREEBSD
#define FREEBSD
#endif
#endif

#if defined(__sparc)
#ifndef SOLARIS
#define SOLARIS
#endif
#endif
