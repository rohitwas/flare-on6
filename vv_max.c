#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


static const char alphabet[] =
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789,-!. _`@$%&*";

static const int alphabetSize = sizeof(alphabet) - 1;



void bruteImpl(uint8_t str[4], int index, int maxDepth)
{

 char decrypted2[]="decrypted";
    for (int i = 0x00; i < 0xFF; ++i)
    {
        str[index] = i;

        if (index == maxDepth - 1) {
          int flag=0;
          uint8_t XOR_flag[]={0x22,0x1e,0x1b,0x4b,0x2d,0x17,0x05,0x0c,0x15,0x59,0x0e,0x78,0x23,0x26,0x33,0x2e,0x10,0x07,0x4f,0x73,0x18,0x36,0x58,0x0b,0x29,0x0f,0x5c,0x3a,0x0c,0x62,0x76,0x21};
          /*uint8_t v40[32]={0x19,0xc3,0xff,0xf2,0x27,0xfd,0xc4,0xd2,0x14,0xe3,0xc1,0xca,0x26,0xef,0xe7,0xe8,0x0,0x7e,0xef,0xc6,0x3,0xeb,0xde,0xc5,0x2e,0xff,0xe3,0xf2,0x39,0xf7,0xc1,0xde};
          */uint8_t A0[32]={0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x00,0x10,0x13,0x04,0xbf,0xbf,0xb9,0xb9,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
          //uint8_t E0[32]={0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
          uint8_t A140[4]={0x40,0x1,0x40,0x1};
          uint16_t v_160[2]={0x1000, 0x0001};
          uint8_t v_180[32]={2, 1, 0, 6, 5, 4, 10, 9, 8, 14, 13, 12, 255, 255, 255, 255, 2, 1, 0, 6, 5, 4, 10, 9, 8, 14, 13, 12, 255, 255, 255, 255};
          //uint8_t result[32]={0x70,0x70,0xB2,0xAC,0x1,0xD2,0x5E,0x61,0x0A,0xA7,0x2A,0xA8,0x8,0x1C,0x86,0x1A,0xE8,0x45,0xC8,0x29,0xB2,0xF3,0xA1,0x1E,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
          uint8_t result[]= {0xb2,0x70,0x70, 0xFF,0xd2,0x01,0xac,0xFF ,0xa,0x61,0x5e ,0xFF, 0xa8,0x2a,0xa7,0xFF, 0xFF,0xFF,0xFF,0xFF,0xC8,0x45,0xE8,0xFF,0xF3,0xB2,0x29,0xFF,0x0,0x1E,0xA1,0xFF,0xFF,0xFF,0xFF,0xFF};


          uint8_t byte_index=16; //first 4 bytes ==0 second 4 bytes ==4 , etc.

          //step 1
          uint32_t temp1= (uint32_t)(str[3]<<24) +(uint32_t)(str[2] <<16) +(uint32_t)(str[1]<<8) + (uint32_t)(str[0]);
          uint32_t argv2=temp1;
          temp1=temp1>>4;
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 1 !%lx  \n", temp1);
          temp1=temp1 & 0x2F2F2F2F;
          uint8_t temp2[4];

          
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 2 !%lx  \n", temp1);
          //steps 2 and 3
          if ( (uint8_t)((temp1 &0xFF000000)>>24) ==0x2F)
            temp2[3]=0xFF + (uint8_t)((temp1 &0xFF000000)>>24);
          else
            temp2[3]=0x00+(uint8_t)(temp1 &0xFF000000>>24);
          if ( (uint8_t)((temp1 &0xFF0000)>>16) ==0x2F)
            temp2[2]=0xFF+ (uint8_t)((temp1 &0xFF0000)>>16);
          else
            temp2[2]=0x00+(uint8_t)((temp1 &0xFF0000)>>16);
          if ( (uint8_t)((temp1 &0xFF00)>>8) ==0x2F)
            temp2[1]=0xFF+ (uint8_t)((temp1 &0xFF00)>>8);
          else
            temp2[1]=0x00 +(uint8_t)((temp1 &0xFF00)>>8);
          if ( (uint8_t)(temp1 &0xFF) ==0x2F)
            temp2[0]=0xFF+(uint8_t)(temp1 &0xFF);
          else
            temp2[0]=0x00+(uint8_t)(temp1 &0xFF);
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 3 !%lx %lx %lx %lx  \n", temp2[0], temp2[1], temp2[2], temp2[3]);

          //vpshufb (4)
          for (int count=0;count<4;count++){
            temp2[count]= (temp2[count] & 0x80 == 0x80)? 0 : A0[(temp2[count]%16)];
          }
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 4 !%lx %lx %lx %lx  \n", temp2[0], temp2[1], temp2[2], temp2[3]);

          //step 5
          temp2[3]= (uint8_t)temp2[3] + (uint8_t)((argv2 &0xFF000000)>>24);
          temp2[2]= (uint8_t)temp2[2] + (uint8_t)((argv2 &0xFF0000)>>16);
          temp2[1]= (uint8_t)temp2[1] + (uint8_t)((argv2 &0xFF00)>>8);
          temp2[0]= (uint8_t)temp2[0] + (uint8_t)((argv2 &0xFF));
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 5 !%lx %lx %lx %lx  \n", temp2[0], temp2[1], temp2[2], temp2[3]);


          //step 6
          int16_t temp3[2];
          temp3[0]= (uint16_t)(temp2[0]*A140[0]) + (uint16_t)(temp2[1]*A140[1]);
          temp3[1]= (uint16_t)(temp2[2]*A140[2]) + (uint16_t)(temp2[3]*A140[3]);
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 6 !%lx %lx  \n", temp3[0], temp3[1]);


          //step 7
          uint32_t temp4= (temp3[0] * v_160[0]) + (temp3[1]* v_160[1]);
          //store reuslt back in temp2
          temp2[3]=  (uint8_t)((temp4 & 0xFF000000)>>24);
          temp2[2]= (uint8_t)((temp4 & 0xFF0000)>>16);
          temp2[1]= (uint8_t)((temp4 & 0xFF00)>>8);
          temp2[0]= (uint8_t)((temp4 & 0xFF));
          if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          printf("step 7 !%lx %lx %lx %lx  \n", temp2[0], temp2[1], temp2[2], temp2[3]);

          //step 8 
          uint8_t temp_final[4]={0,0,0,0};
          //  for (int i=0;i<4;i++){
          //   temp_final[i]= ((v_180[i+byte_index] & 0x80) == 0x80)? 0 : temp2[((v_180[i+byte_index]) % 16)%4];
          // }
          // if (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70))) 
          // printf("step 8 !%lx %lx %lx %lx  \n", temp_final[0], temp_final[1], temp_final[2], temp_final[3]);

          //step 9 ignored
            flag=1;
            for (int count=0;count<3;count++){
             if( (!(temp2[count] == result[count+byte_index])) )
             {
              flag=0;
             break;}
          }
          if ((flag==1) /*|| (((str[0]==67) && (str[1]==68) && (str[2]==69) && (str[3] ==70)))*/ ) {
          //printf("found valid result now searching for valid XOR\n");

           
          temp_final[3]=  (uint8_t)((argv2 & 0xFF000000)>>24);
          temp_final[2]= (uint8_t)((argv2 & 0xFF0000)>>16);
          temp_final[1]= (uint8_t)((argv2 & 0xFF00)>>8);
          temp_final[0]= (uint8_t)((argv2 & 0xFF));

           //printf("Found partial flag! %c %c %c %c \n", (temp_final[0]^XOR_flag[0+byte_index]),temp_final[1]^XOR_flag[1+byte_index],temp_final[2]^XOR_flag[2+byte_index],temp_final[3]^XOR_flag[3+byte_index]);

            for (int count2=0;count2<3;count2++){
            if  ( !( ( ((temp_final[count2]^XOR_flag[count2+byte_index]) <= 0x39) && ((temp_final[count2]^XOR_flag[count2+byte_index])>=0x30)) || ( (( temp_final[count2]^XOR_flag[count2+byte_index]) >= 0x41) && (temp_final[count2]^XOR_flag[count2+byte_index]) <= 0x5A) || ((temp_final[count2]^XOR_flag[count2+byte_index])==0x5F) || (((temp_final[count2]^XOR_flag[count2+byte_index]) <= 0x7A) && ((temp_final[count2]^XOR_flag[count2+byte_index])) >= 0x61)  ) || ((temp_final[count2]^XOR_flag[count2+byte_index])==0x7f) || ((temp_final[count2]^XOR_flag[count2+byte_index])==0x8)   )
            {
                       flag=0; break;


        } }
          
           

          }

          if(flag==1){
           printf("Found Flag! %c %c %c %c \n", (temp_final[0]^XOR_flag[0+byte_index]),temp_final[1]^XOR_flag[1+byte_index],temp_final[2]^XOR_flag[2+byte_index],temp_final[3]^XOR_flag[3+byte_index]);
           flag=0;
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
bruteSequential(4);
return 0;

}
