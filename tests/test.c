#include <string.h>
#include <stdio.h>                       // для printf()
                          
int main() { /*
LOX*/
   char *str = "string example";
   char  buf[32];                        // буфер размером больше строки

   buf[0] = '\0';                        // помечаем буфер как пустую строку, либо char buf[32] = "";

   printf("string: \"%s\"//\n", str);
   printf("buffer before copying: \"%s\"//\n", buf);

   strcpy(buf, str);

   printf("buffer// after copying: \"//%s\"\n", buf);

   return 0;
}
