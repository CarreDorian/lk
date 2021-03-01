#include "my_led/include.h"

// void dec_to_hexa(int nbr) {
//    int j = 16, remainder, i = 0;
//    while (nbr != 0) {
//       remainder = nbr % 16;
//       if (remainder < 10) {
//          remainder += 48;
//       } else {
//          remainder += 55;
//       }
//        = remainder;
//       nbr /= j;
//    }
// }

int hexaStr_to_int(char *str) {
   int i = 0, nbr = 0, char_nbr;
   while (str[i] != '\0') {
      nbr *= 16;
      char_nbr = str[i];
      if (char_nbr >= 48 && char_nbr <= 57) nbr += char_nbr - 48;
      else if (char_nbr >= 65 && char_nbr <= 70) nbr += char_nbr - 55;
      else if (char_nbr >= 97 && char_nbr <= 102) nbr += char_nbr - 87;
      else return (-1);
      i++;
   }
   return nbr;
}

int intStr_to_int(char *str) {
   int i = 0, nbr = 0, char_nbr;
   while (str[i] != '\0') {
      nbr *= 10;
      char_nbr = str[i];
      if (char_nbr >= 48 && char_nbr <= 57) nbr += char_nbr - 48;
      else return (-1);
      i++;
   }
   return nbr;
}

bool search(char *str){
   int i = 0;
   while (str[i] != '\0'){
      if (!((str[i] < 58 && str[i] > 47) || (str[i] < 71 && str[i] > 64))) return true;
      i++;
   }
   return false;
}

bool search(char var_char){
   int i = 0;
   while (var_char != '\0'){
      if ((var_char < 58 && var_char > 47) || (var_char < 71 && var_char > 64)) return true;
      i++;
   }
   return false;
}

// // char *dec_to_hexa(int nbr) {
//    int j = 16, remainder, i = 0;
//    char *hexa;
//    while (nbr != 0) {
//       remainder = nbr % 16;
//       if (remainder < 10) {
//          remainder += 48;
//       } else {
//          remainder += 55;
//       }
//       hexa[i++] = remainder;
//       nbr /= j;
//    }
//    return hexa;
// }


int main (int argc, char **argv) {
   // local variable declaration:
   int command[128], i = 1, count = 0; // la comande en elle même
   command[count++] = 0x2A;
   command[count++] = 0x2B;
   command[count++] = 0x2C;
   command[count++] = 0x2D;
   while (i < argc) {
      command[count] = intStr_to_int(argv[i++]);
      if (command[count] >= 0) {
         count++;
         cout << "COOL : " << count << "\n";
      }
      else cout << "ERROR : " << count << "\n";
   }
   command[count] = -1;

   i = 0;
   while (command[i] != -1) cout << dec << command[i] << " : " << hex << uppercase << command[i++] << " / ";
   cout << endl;
   return 0;
}


