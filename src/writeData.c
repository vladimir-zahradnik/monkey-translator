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

#include <stdio.h>
#include "main.h"
#include "writeData.h"

int initialBufferSP(spEntry *p_block)
{
    int j = 0;
    do{
        p_block->fr[j] = 0x20;
        j++;
        } while( j <= 255 );
}

int initialBufferUI(uiEntry *p_block)
{
    int j = 0;
    do{
        p_block->fr[j] = 0x20;
        j++;
        } while( j <= 255 );
}

int writeData(char *f_read)
{
    /* Initialising parameters */
     int bytes_read = 0;
     int items_written = 0;
     int option;
              
     /* Loading required files */
    FILE *f_input, *f_output, *f_sk;
    
    printf("Do you want to compile file containing dialogs - speech.info (Y/N)?");
    while ((option = toupper(getchar())) != 'Y'  &&  option != 'N') {
    while (getchar() != '\n')
      ;
    printf("[Y / N]: ");
  }

     printf("Compiling text strings from file %s...\n", f_read);
     printf("------------------------------------------------------\n");
     
     if(option == 'Y'){
        spEntry entry;
           
     /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Unable to open file '%s'.\n", f_read);
    return 1;
    }
    if( (f_output = fopen("speech.info.new", "wb")) == NULL ){
    printf("Unable to open 'speech.info.new'.\n", f_read);
    return 1;
    }
    if( (f_sk = fopen("speech.sk", "rb")) == NULL ){
    printf("Unable to open file 'speech.sk'.\n");
    return 1;
    }
     
    while (!feof(f_input)) {
          
         if( (bytes_read = fread(&entry, sizeof(spEntry), 1, f_input)) != 0 ){ 
         printf("Strings written: %d\r", items_written);
               
        initialBufferSP(&entry);
         
           /* For Slovak */
            int i = 0;
            int c;
            
            while( (c = getc(f_sk)) != '\n' ){
              
              if(c == '\\'){
              entry.fr[i] = '\n';
              getc(f_sk);
              }
                            
              else{
              entry.fr[i] = c;
              }       
             i++;
             entry.fr[i] = '\0';
            };
        
        fwrite(&entry, sizeof(spEntry), 1, f_output);
        items_written++; // number of written lines of text
          }
        };
        
         /* Closing files */
    if ((fclose(f_input)) == EOF){
    printf("Unable to close file '%s'.\n", f_read);
    return 1;
    }
    
    if ((fclose(f_output)) == EOF){
    printf("Unable to close file 'speech.info.new'.\n");
    return 1;
    }

    if ((fclose(f_sk)) == EOF){
    printf("Unable to close file 'speech.sk'.\n");
    return 1;
    }    
        
        }
        
      else{
           uiEntry entry;
           
    /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Unable to open file '%s'.\n", f_read);
    return 1;
    }
    if( (f_output = fopen("uiText.info.new", "wb")) == NULL ){
    printf("Unable to open file 'uiText.info.new'.\n", f_read);
    return 1;
    }
    if( (f_sk = fopen("uiText.sk", "rb")) == NULL ){
    printf("Unable to open file 'uiText.sk'.\n");
    return 1;
    }
           
      while (!feof(f_input)){
            
           if( (bytes_read = fread(&entry, sizeof(uiEntry), 1, f_input)) != 0 ){ 
               
           printf("Strings written: %d\r", items_written);
           
           initialBufferUI(&entry);
           
            /* For Slovak */
            int i = 0;
            int c;
            
            while( (c = getc(f_sk)) != '\n' ){
              
              if(c == '\\'){
              entry.fr[i] = '\n';
              getc(f_sk);
              }
                            
              else{
              entry.fr[i] = c;
              }       
             i++;
             entry.fr[i] = '\0';
            };
                   
           fwrite(&entry, sizeof(uiEntry), 1, f_output);
           items_written++; // number of written lines of text
             }
           };
           
            /* Closing files */
    if ((fclose(f_input)) == EOF){
    printf("Unable to close file '%s'.\n", f_read);
    return 1;
    }
    
    if ((fclose(f_output)) == EOF){
    printf("Unable to close file 'uiText.info.new'.\n");
    return 1;
    }

    if ((fclose(f_sk)) == EOF){
    printf("Unable to close file 'uiText.sk'.\n");
    return 1;
    }    
           
      }
    
     return 0;
}
