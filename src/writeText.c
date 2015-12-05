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
        
    printf("Prajete si dekompilovat subor s dialogmi - speech.info (A/N)?");
    while ((option = toupper(getchar())) != 'A'  &&  option != 'N') {
    while (getchar() != '\n')
      ;
    printf("[A / N]: ");
  }

     printf("Prebieha dekompilacia textu zo suboru %s...\n", f_read);
     printf("------------------------------------------------------\n");
     
     if(option == 'A'){
        spEntry entry;
        
    /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Subor '%s' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_en = fopen("speech.en", "wb")) == NULL ){
    printf("Subor 'speech.en' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_fr = fopen("speech.fr", "wb")) == NULL ){
    printf("Subor 'speech.fr' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_it = fopen("speech.it", "wb")) == NULL ){
    printf("Subor 'speech.it' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_de = fopen("speech.de", "wb")) == NULL ){
    printf("Subor 'speech.de' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_es = fopen("speech.es", "wb")) == NULL ){
    printf("Subor 'speech.es' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    
    while(!feof(f_input)){
       if( (bytes_read = fread(&entry, sizeof(spEntry), 1, f_input)) != 0 ){
       
         printf("Pocet zapisanych retazcov: %d\r", items_written);
                 
        WriteToFile(&entry, f_en, f_fr, f_it, f_de, f_es);
        items_written++; // number of written lines of text
          }
           };
      }
      
      else{
           uiEntry entry;
           
           /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Subor '%s' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_en = fopen("uiText.en", "wb")) == NULL ){
    printf("Subor 'uiText.en' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_fr = fopen("uiText.fr", "wb")) == NULL ){
    printf("Subor 'uiText.fr' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_it = fopen("uiText.it", "wb")) == NULL ){
    printf("Subor 'uiText.it' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_de = fopen("uiText.de", "wb")) == NULL ){
    printf("Subor 'uiText.de' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    if( (f_es = fopen("uiText.es", "wb")) == NULL ){
    printf("Subor 'uiText.es' sa nepodarilo otvorit.\n");
    return 1;
    }
           
       while(!feof(f_input)){   
                   
           if( (bytes_read = fread(&entry, sizeof(uiEntry), 1, f_input)) != 0 ){
       
       printf("Pocet zapisanych retazcov: %d\r", items_written);
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
    printf("Subor '%s' sa nepodarilo uzavriet.\n", f_read);
    return 1;
    }

    if ((fclose(f_en) && fclose(f_fr) && fclose(f_it) && fclose(f_de) && fclose(f_es)) == EOF){
    printf("Subory sa nepodarilo uzavriet.\n");
    return 1;
    }    

    return 0;
}
