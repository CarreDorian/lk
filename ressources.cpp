#include <iostream>
using namespace std;
#include "include.h"

void help() {
    cout << "\n============================== HELP ===============================\n\n";
    cout << "Using the Leka commands : lk [flags] [commands] [parameters]\n\n";

    cout << "____________________________ commands : _____________________________\n\n";
    cout << "lk led ...       : change the led color ...\n";
    cout << "       ear ...           : ... of the ear ...\n";
    cout << "           all [R G B]           : ... of all the led.\n";
    cout << "           singel [idLed R G B]  : ... of one led.\n";
    cout << "       belt ...           : ... of the body ...\n";
    cout << "           all [R G B]           : ... of all the led.\n";
    cout << "           singel [idLed R G B]  : ... of one led.\n";
    cout << "           range [idFirstLed idLastLed R G B]\n";
    cout << "                                 : ... of all led from firstLed to lastLed.\n\n";

    cout << "   motor ...                        : change the motor contrôle ...\n";
    cout << "         all [speed] [direction]            : ... of all the motor\n";
    cout << "         left [spin] [direction]            : ... of the left motor\n";
    cout << "         right [spin] [direction]           : ... of the right motor\n";
    cout << "         dual [leftSpin] [leftSpeed] [rightSpin] [rightSpeed]\n";
    cout << "                                            : ... of the left motor\n\n";

    cout << "   stop ...                        : switch of ...\n";
    cout << "        all [speed] [direction]            : ... of all the robot\n";
    cout << "        left [spin] [direction]            : ... of the motor\n";
    cout << "        right [spin] [direction]           : ... of the led\n";
    cout << "        dual [leftSpin] [leftSpeed] [rightSpin] [rightSpeed]\n";
    cout << "                                            : ... of the left motor ...\n";

    cout << "____________________________ flags : ______________________________\n\n";
    cout << "   -h, --help                     Show the help page on the CLI ised\n";
    cout << "   -H, --hexa, --hexadécimal      enter the value in hexadécimal. The default is décimal\n\n";
}

    // compare les str
bool str_compare(char *str1, const char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) return false;
    i++;
  }
  if (str1[i] == str2[i]) return true;
  return false;
}

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
   cout << endl << endl << i << " ; ";
   while (str[i] != '\0') {
       cout << i << " ; ";
      nbr *= 10;
      char_nbr = str[i];
      if (char_nbr >= 48 && char_nbr <= 57) nbr += char_nbr - 48;
      else return (-1);
      i++;
   }
   cout << endl;
   return nbr;
}

    // prise en charge des drapeaux.
    // prend en parramètres l'entièretée du parramètre d'appel de la fonction (argv[i]).
    // ne possède aucun return.
bool flags(char *str, bool *H) {
    int j = 1;
    if (str[1] == '-') {
        if (str_compare(&str[2], "hexa") || str_compare(&str[2], "hexadécimal")) (*H) = 1;
        else if (str_compare(&str[2], "help")) help();
    }
    while (str[j] != '\0') {
        switch(str[j]) {
            case 'H':
                (*H) = 1;
                break;
            case 'h':
                help();
                return true;
        }
        j++;
    }
    return false;
}
    

