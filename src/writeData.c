#include <stdio.h>
#include "main.h"
#include "writeText.h"
#include "writeData.h"

int initialBufferSP(spEntryNew *p_block)
{
    int j = 0;
    do{
        p_block->sk[j] = 0x20;
        j++;
        } while( j <= 255 );
}

int initialBufferUI(uiEntryNew *p_block)
{
    int j = 0;
    do{
        p_block->sk[j] = 0x20;
        j++;
        } while( j <= 255 );
}

int writeData(char *f_read)
{
    /* Initialising parameters */
     int bytes_read;
     int items_written = 0;
     int option;
              
     /* Loading required files */
    FILE *f_input, *f_output, *f_sk;
    
    /* Opening input and output files */
    if( (f_input = fopen(f_read, "rb")) == NULL ){
    printf("Subor '%s' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_output = fopen("locale.bin", "wb")) == NULL ){
    printf("Subor 'locale.bin' sa nepodarilo otvorit.\n", f_read);
    return 1;
    }
    if( (f_sk = fopen("locale.sk", "rb")) == NULL ){
    printf("Subor 'locale.sk' sa nepodarilo otvorit.\n");
    return 1;
    }
    
    printf("Prajete si skompilovat subor s dialogmi - speech.info (A/N)?");
    while ((option = toupper(getchar())) != 'A'  &&  option != 'N') {
    while (getchar() != '\n')
      ;
    printf("[A / N]: ");
  }

     printf("Prebieha kompilacia textu zo suboru %s...\n", f_read);
     printf("------------------------------------------------------\n");
     
    while (!feof(f_input)) {
         printf("Pocet zapisanych retazcov: %d\r", items_written);
         
         if(option == 'A'){
        spEntryNew entry;
        bytes_read = fread(&entry, sizeof(spEntry), 1, f_input);
        initialBufferSP(&entry);
        
         /* For Slovak */
            int i = 0;
            int c;
            
            while( (c = getc(f_sk)) != '\n' ){
              
              if(c == '\\'){
              entry.sk[i] = '\n';
              getc(f_sk);
              }
                            
              else{
              entry.sk[i] = c;
              }       
             i++;
             entry.sk[i] = '\0';
            };
        
        fwrite(&entry, sizeof(spEntryNew), 1, f_output);
        }
      else{
           uiEntryNew entry;
           bytes_read = fread(&entry, sizeof(uiEntry), 1, f_input);
           initialBufferUI(&entry);
           
            /* For Slovak */
            int i = 0;
            int c;
            
            while( (c = getc(f_sk)) != '\n' ){
              
              if(c == '\\'){
              entry.sk[i] = '\n';
              getc(f_sk);
              }
                            
              else{
              entry.sk[i] = c;
              }       
             i++;
             entry.sk[i] = '\0';
            };
                   
           fwrite(&entry, sizeof(uiEntryNew), 1, f_output);
           }       
             
    items_written++; // number of written lines of text
    };
    
    /* Closing files */
    if ((fclose(f_input)) == EOF){
    printf("Subor '%s' sa nepodarilo uzavriet.\n", f_read);
    return 1;
    }
    
    if ((fclose(f_output)) == EOF){
    printf("Subor 'locale.bin' sa nepodarilo uzavriet.\n");
    return 1;
    }

    if ((fclose(f_sk)) == EOF){
    printf("Subor 'locale.sk' sa nepodarilo uzavriet.\n");
    return 1;
    }    

    return 0;
}
