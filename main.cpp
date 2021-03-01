#include <iostream>
using namespace std;
char start_sequence[12] = "2A 2B 2C 2D";

void dec_to_hexa(int nbr, char **hexa) {
   int j = 16, remainder, i = 0;
   while (nbr != 0) {
      remainder = nbr % 16;
      if (remainder < 10) {
         remainder += 48;
      } else {
         remainder += 55;
      }
      (*hexa)[i++] = remainder;
      nbr /= j;
   }
}

bool str_compare(char *str1, char *str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (!(str1[i] == str2[i])) {
      return false;
    }
    i++;
  }
  if (str1[i] == str2[i]) {
    return true;
  }
  return false;
}

              /* main */
int main(int argc, char **argv) {
  if (!argv[1]) {
      cout << "No parrameters" << endl;
      return 0;
  }

  // Parcing des flages
  
  int i = 1;
  /*int j;
  while(argv[i][0] == '-') {
    j = 1;
    while (argv[i][j] != '\0') {
      switch(argv[i][j]) {
        default:
          cout << "Flag vérifiés" << endl;
      }
      j++;
    }
    i++;
    if (!argv[i]) {
      break;
    }
  } */

  // parcing des commandes

    // the led
  if (str_compare(argv[i], "led")) {
    cout << "led\n";
    if (!argv[++i]) {
      cout << "what ?\n";
    } else if (str_compare(argv[++i], "ear")) {
      cout << "ear\n";

    } else if (str_compare(argv[i], "all")) {
      cout << "all\n";

    } else if (str_compare(argv[i], "single")) {
      cout << "single\n";

    } else {
      cout << "what else ?\n";
    }

    // the motor
  } else if (str_compare(argv[i], "motor")) {
    cout << "motor\n";
    if (!argv[++i]) {
      cout << "what ?\n";
    } else if (str_compare(argv[++i], "ear")) {
      cout << "ear\n";

    } else if (str_compare(argv[i], "all")) {
      cout << "all\n";

    } else if (str_compare(argv[i], "single")) {
      cout << "single\n";

    } else {
      cout << "what else ?\n";
    }

    // the stop
  } else if (str_compare(argv[i], "stop")) {
    cout << "stop\n";
    if (!argv[++i]) {
      cout << "robot stop\n";
      

    } else if (str_compare(argv[i], "led")) {
      cout << "led stop\n";

    } else if (str_compare(argv[i], "motor")) {
      cout << "motor stop\n";

    } else if (str_compare(argv[i], "")) {
      cout << "stop what ?\n";
    }
  }
  return 0;
}