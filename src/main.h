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

/* Defining macros */
#define WINDOWS             1 // ifdef 1 os = windows, else unix
#define BLOCK_SIZE          256 // maximum size of a buffer
#define VERSION             0  // macro for printing current version
#define REVISION            3 // macro for printing current revision
#define USAGE               "Usage: %s [-hvcd] input_file ['rb' mode] output_file ['wb' mode]\n" // prints usage of this program
#define NOARGS              "No input arguments entered. Usage: %s [-hvcd] arguments\n" // when no arguments were used
#define BADCHOICE           "Invalid option %s, usage: %s [-hvcd] arguments\n" // when bad arguments were used

#ifdef WINDOWS
  #define PATH              '\\' // standard path in Windows
#else
  #define PATH              '/'  // standard path in Unix
#endif
