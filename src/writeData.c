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
    
    printf("Prajete si skompilovat subor s dialogmi - speech.info (A/N)?");
    while ((option = toupper(getchar())) != 'A'  &&  option != 'N') {
    while (getchar() != '\n')
      ;
    printf("[A / N]: ");
  }

     printf("Prebieha kompilacia textu zo suboru %s...\n", f_read);
     printf("------------------------------------------------------\n");
     
     if(option == 'A'){
        spEntry entry;
           
     /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Subor '%s' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_output = fopen("speech.info.new", "wb")) == NULL ){
    printf("Subor 'speech.info.new' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_sk = fopen("speech.sk", "rb")) == NULL ){
    printf("Subor 'speech.sk' sa nepodarilo otvorit.\n");
    return 1;
    }
     
    while (!feof(f_input)) {
          
         if( (bytes_read = fread(&entry, sizeof(spEntry), 1, f_input)) != 0 ){ 
         printf("Pocet zapisanych retazcov: %d\r", items_written);
               
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
    printf("Subor '%s' sa nepodarilo uzavriet.\n", f_read);
    return 1;
    }
    
    if ((fclose(f_output)) == EOF){
    printf("Subor 'speech.info.new' sa nepodarilo uzavriet.\n");
    return 1;
    }

    if ((fclose(f_sk)) == EOF){
    printf("Subor 'speech.sk' sa nepodarilo uzavriet.\n");
    return 1;
    }    
        
        }
        
      else{
           uiEntry entry;
           
            /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Subor '%s' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_output = fopen("uiText.info.new", "wb")) == NULL ){
    printf("Subor 'uiText.info.new' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_sk = fopen("uiText.sk", "rb")) == NULL ){
    printf("Subor 'uiText.sk' sa nepodarilo otvorit.\n");
    return 1;
    }
           
      while (!feof(f_input)){
            
           if( (bytes_read = fread(&entry, sizeof(uiEntry), 1, f_input)) != 0 ){ 
               
           printf("Pocet zapisanych retazcov: %d\r", items_written);
           
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
    printf("Subor '%s' sa nepodarilo uzavriet.\n", f_read);
    return 1;
    }
    
    if ((fclose(f_output)) == EOF){
    printf("Subor 'uiText.info.new' sa nepodarilo uzavriet.\n");
    return 1;
    }

    if ((fclose(f_sk)) == EOF){
    printf("Subor 'uiText.sk' sa nepodarilo uzavriet.\n");
    return 1;
    }    
           
      }
    
     return 0;
}
