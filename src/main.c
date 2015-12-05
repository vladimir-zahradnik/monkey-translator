/*
** Copyright (C) 2011 Vladimir Zahradnik <vladimir.zahradnik@gmail.com>
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 or version 3 of the
** License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* Loading required headers */
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "main.h"
#include "writeData.h"
#include "writeText.h"

int main( int argc, char *argv[] )
{
    /* Initialising parameters */
    char c_option; /* for indicating parameters for getopt */
    int helpflag; /* for indicating bad parameter */
    int decompileflag;
    char *p_progname;
    int i;
    
    helpflag = i = 0; // setting variables to zero value
    
    /* Filtering absolute path of executed file for argv[0] */
    
    if ((p_progname = strrchr (argv[0], PATH)) != NULL)
        p_progname++; /* shift one sign after slash */
  else
    p_progname = argv[0]; /* if program call doesn't contain "/" then it's argv[0] */
    
 /* If were used some options */
  while ((c_option = getopt (argc, argv, "hvcd")) != EOF)
    {
      switch (c_option)
      {
      case 'v':        /* -v for printing version */
        printf ("%s-%d.%d\n", p_progname, VERSION, REVISION);
        return(1);
      case 'h':        /* -h for printing program help */
        helpflag++;      /* incrementing helpflag from 0 to 1 */
        break;
      case 'd':        /* -d for decompiling source text */
         writeText(argv[2]);
         return(3);
        break;
      case 'c':        /* -c for compiling translated text */
        writeData(argv[2]);
        return(4);
        break;
      default:          /* other args */
        fprintf (stderr, BADCHOICE, argv[1],p_progname);
        return(5);
      }

      if (helpflag)
      {
        printf (USAGE, p_progname);
        return(2);
      }
    }

/* If no args are present */
  if (argc == 1)
    {
      fprintf (stderr, NOARGS, p_progname);
      return(0);
    }

/* Everything done */
return 0;
}
