/*
 * $Id: cfg.h,v 1.5 1998/11/12 15:15:42 glehner Exp $
 * History:
 * $Log: cfg.h,v $
 * Revision 1.5  1998/11/12 15:15:42  glehner
 * Cleaned up includes, moved from .h file to .c
 * added #ifndef __CFG_H ....
 *
 * Revision 1.4  1998/11/04 13:37:46  glehner
 * removed #include <malloc.h>
 *
 * Revision 1.3  1998/07/03 07:01:28  glehner
 * added ReadLg() for language.cfg files
 * fixed open_cfg search path parsing
 *
 * Revision 1.2  1997/02/15 20:36:29  ralf
 * Almost complete rewrite of config file reading.
 * The interface was made cleaner, there are no external functions
 * that access internal data structures now.
 * The opening of config files was also cleaned up.
 * There was a bug fix for parsing of the environment settings
 * that prevented some directories from being found on second
 * parsing. This was reported by L. Mugnier and there was a proposed fix
 * by V. Menkov.
 *
 * Revision 1.1  1995/03/23 16:09:01  ralf
 * Initial revision
 *
 */

#ifndef __CFG_H
#define __CFG_H

/*** global definitons used in many(!) files ***/

typedef int (*fptr) (const void*, const void*);

typedef struct ConfigEntryT
{
   /*@shared@*/ const char  *TexCommand;
   /*@shared@*/ const char  *RtfCommand;
} ConfigEntryT;

extern void ReadCfg (void)
/*@globals configinfo@*/
/*@modifies configinfo@*/
;

/*@null@*//*@dependent@*/
extern size_t SearchRtfIndex ( /*@in@*/ const char *theCommand
                              ,                int WhichArray
                              );
/*@null@*/ 
extern const char *SearchRtfCmd ( /*@in@*/ const char *theCommand
                                ,                int WhichArray
	                        );
/*@null@*/
extern const ConfigEntryT **CfgStartIterate (/*@unused@*/ int WhichCfg);

/*@null@*/
extern const ConfigEntryT **CfgNext (                  int            WhichCfg
                                    , /*@null@*/ const ConfigEntryT **last
				    );


/* Values for WhichArray */
#define DIRECT_A	0
#define FONT_A		1
#define IGNORE_A	2
#define LANGUAGE_A      3

extern void ReadLg(char *lang);
/*@null@*/ 
extern const char *TranslateName(char *name);

#endif /* ndefined __CFG_H */
