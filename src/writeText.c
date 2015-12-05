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
#include <ctype.h>
#include <stdlib.h>
#include <string.h> 
#include "main.h"
#include "writeText.h"

int WriteToFile(spEntry *p_entry, FILE *f_en, FILE *f_fr, FILE *f_it, FILE *f_de, FILE *f_es)
{
    
    /* For English */
    int i = 0;
    
    while( (p_entry->en[i]) != '\0'){
      
      if( (p_entry->en[i]) == '\n' ){
        fprintf(f_en, "\\n");
        }
        
      else{
      fprintf(f_en, "%c", p_entry->en[i]);
       }
       i++;
    }
      fprintf(f_en, "\n");
      
      /* For French */
      i = 0;
    
    while( (p_entry->fr[i]) != '\0'){
      
      if( (p_entry->fr[i]) == '\n' ){
        fprintf(f_fr, "\\n");
        }
        
      else{
      fprintf(f_fr, "%c", p_entry->fr[i]);
       }
       i++;
    }
      fprintf(f_fr, "\n");
      
      /* For Italian */
      i = 0;
    
    while( (p_entry->it[i]) != '\0'){
      
      if( (p_entry->it[i]) == '\n' ){
        fprintf(f_it, "\\n");
        }
        
      else{
      fprintf(f_it, "%c", p_entry->it[i]);
       }
       i++;
    }
      fprintf(f_it, "\n");
      
      /* For German */
      i = 0;
    
    while( (p_entry->de[i]) != '\0'){
      
      if( (p_entry->de[i]) == '\n' ){
        fprintf(f_de, "\\n");
        }
        
      else{
      fprintf(f_de, "%c", p_entry->de[i]);
       }
       i++;
    }
      fprintf(f_de, "\n");
      
      /* For Spanish */
      i = 0;
    
    while( (p_entry->es[i]) != '\0'){
      
      if( (p_entry->es[i]) == '\n' ){
        fprintf(f_es, "\\n");
        }
        
      else{
      fprintf(f_es, "%c", p_entry->es[i]);
       }
       i++;
    }
      fprintf(f_es, "\n");
          
      return 0;
} 

int writeText(char *f_read)
{
     /* Initialising parameters */
     int bytes_read = 0;
     int items_written = 0;
     int option;
              
     /* Loading required files */
    FILE *f_input, *f_en, *f_fr, *f_it, *f_de, *f_es;
        
    printf("Do you want to decompile file containing dialogs - speech.info (Y/N)?");
    while ((option = toupper(getchar())) != 'Y'  &&  option != 'N') {
    while (getchar() != '\n')
      ;
    printf("[Y / N]: ");
  }

     printf("Decompiling text from file %s...\n", f_read);
     printf("------------------------------------------------------\n");
     
     if(option == 'A'){
        spEntry entry;
        
    /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Unable to open file '%s'.\n", f_read);
    return 1;
    }
    if( (f_en = fopen("speech.en", "wb")) == NULL ){
    printf("Unable to open file 'speech.en'.\n");
    return 1;
    }
    
    if( (f_fr = fopen("speech.fr", "wb")) == NULL ){
    printf("Unable to open file 'speech.fr'.\n");
    return 1;
    }
    
    if( (f_it = fopen("speech.it", "wb")) == NULL ){
    printf("Unable to open file 'speech.it'.\n");
    return 1;
    }
    
    if( (f_de = fopen("speech.de", "wb")) == NULL ){
    printf("Unable to open file 'speech.de'.\n");
    return 1;
    }
    
    if( (f_es = fopen("speech.es", "wb")) == NULL ){
    printf("Unable to open file 'speech.es'.\n");
    return 1;
    }
    
    
    while(!feof(f_input)){
       if( (bytes_read = fread(&entry, sizeof(spEntry), 1, f_input)) != 0 ){
       
         printf("Strings written: %d\r", items_written);
                 
        WriteToFile(&entry, f_en, f_fr, f_it, f_de, f_es);
        items_written++; // number of written lines of text
          }
           };
      }
      
      else{
           uiEntry entry;
           
    /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Unable to open file '%s'.\n", f_read);
    return 1;
    }
    if( (f_en = fopen("uiText.en", "wb")) == NULL ){
    printf("Unable to open file 'uiText.en'.\n");
    return 1;
    }
    
    if( (f_fr = fopen("uiText.fr", "wb")) == NULL ){
    printf("Unable to open file 'uiText.fr'.\n");
    return 1;
    }
    
    if( (f_it = fopen("uiText.it", "wb")) == NULL ){
    printf("Unable to open file 'uiText.it'.\n");
    return 1;
    }
    
    if( (f_de = fopen("uiText.de", "wb")) == NULL ){
    printf("Unable to open file 'uiText.de'.\n");
    return 1;
    }
    
    if( (f_es = fopen("uiText.es", "wb")) == NULL ){
    printf("Unable to open file 'uiText.es'.\n");
    return 1;
    }
           
       while(!feof(f_input)){   
                   
           if( (bytes_read = fread(&entry, sizeof(uiEntry), 1, f_input)) != 0 ){
       
       printf("Strings written: %d\r", items_written);
       fprintf(f_en, "%s\n", entry.en);
       fprintf(f_fr, "%s\n", entry.fr);
       fprintf(f_it, "%s\n", entry.it);
       fprintf(f_de, "%s\n", entry.de);
       fprintf(f_es, "%s\n", entry.es); 
                       
    items_written++; // number of written lines of text
           }
            };
    }
    
    /* Closing files */
    if ((fclose(f_input)) == EOF){
    printf("Unable to close file '%s'.\n", f_read);
    return 1;
    }

    if ((fclose(f_en) && fclose(f_fr) && fclose(f_it) && fclose(f_de) && fclose(f_es)) == EOF){
    printf("Unable to close files.\n");
    return 1;
    }    

    return 0;
}
