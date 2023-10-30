#include <string.h>
#include <stdio.h>                       
  
   

int main() {      
                                
      
   char *str = "string example";
   char  buf[32];                        

   buf[0] = '\0';                        

   printf("string: \"%s\"//\n", str);
   printf("buffer before copying: \"%s\"//\n", buf);

   strcpy(buf, str);

   printf("buffer// after copying: \"//%s\"\n", buf);

   return 0;
}
