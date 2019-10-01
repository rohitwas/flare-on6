#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789,-!. _`@$%&*";

static const int alphabetSize = sizeof(alphabet) - 1;



void bruteImpl(uint8_t str[32], int index, int maxDepth)
{

 char decrypted2[]="decrypted";
    for (int i = 0x00; i < 0xFF; ++i)
    {
        str[index] = i;

        if (index == maxDepth - 1) {
          int flag=0;
          uint8_t XOR_flag[]={0x22,0x1e,0x1b,0x4b,0x2d,0x17,0x05,0x0c,0x15,0x59,0x0e,0x78,0x23,0x26,0x33,0x2e,0x10,0x07,0x4f,0x73,0x18,0x36,0x58,0x0b,0x29,0x0f,0x5c,0x3a,0x0c,0x62,0x76,0x21};
          uint8_t v40[32]={0x19,0xc3,0xff,0xf2,0x27,0xfd,0xc4,0xd2,0x14,0xe3,0xc1,0xca,0x26,0xef,0xe7,0xe8,0x0,0x7e,0xef,0xc6,0x3,0xeb,0xde,0xc5,0x2e,0xff,0xe3,0xf2,0x39,0xf7,0xc1,0xde};
          uint8_t A0[32]={0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
          uint8_t E0[32]={0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
          
            for (int count=0;count<index;count++){

              // uint8_t temp = (str[count]==0x2F)? 0xFF:0x0;
              // if( (((str[count] &0x2F) + temp) & 0x80)==0x80 ){
              //   E0[count]=0;
              // }
              // else{
              //   E0[count]=A0[str[count]&31];
              // }
              // if (E0[count]+str[count]==v40[count]){flag=1;}
              // else{flag=0;}
              uint8_t temp=str[count]^XOR_flag[count] ;
              if ((temp <= 0x39 && temp>=0x30) || (temp >= 0x41 && temp <= 0x5A) || (temp==0x5F) || (temp <= 0x7A && temp >= 0x61) ) {
                flag=1;
              }
              else{
                flag=0; break;//count=index; //reset flag. break the loop
              }

            }
            if (flag==1){
              for (int count=0;count<index;count++){
                printf("FLAG is %c", str[count]*XOR_flag[count]);
              }
              
              printf("\n");     
              }     

        }
        else bruteImpl(str, index + 1, maxDepth);
    }
}


void bruteSequential(int maxLen)
{
    char* buf = malloc(maxLen + 1);


        memset(buf, 0, maxLen + 1);

        bruteImpl(buf, 0, maxLen);
        printf("BruteForce finished\n\n");

    free(buf);
}




int main(){
bruteSequential(32);
return 0;

}