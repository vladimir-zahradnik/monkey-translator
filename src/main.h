/* Defining macros */
#define WINDOWS             1 // ifdef 1 os = windows, else unix
#define BLOCK_SIZE          256 // maximum size of a buffer
#define VERSION             0  // macro for printing current version
#define REVISION            3 // macro for printing current revision
#define USAGE               "Pouzitie: %s [-hvcd] vstupny_subor [rezim 'rb'] vystupny_subor [rezim 'wb']\n" // prints usage of this program
#define NOARGS              "Neboli zadane ziadne argumenty. Pouzitie: %s [-hvcd] argumenty\n" // when no arguments were used
#define BADCHOICE           "Neplatna volba %s, pouzitie: %s [-hvcd] argumenty\n" // when bad arguments were used

#ifdef WINDOWS
  #define PATH              '\\' // standard path in Windows
#else
  #define PATH              '/'  // standard path in Unix
#endif
