#include "include.h"

              /* main */
int main(int argc, char **argv) {
  if (!argv[1]) {
    cout << "No parrameters" << endl;
    return 0;
  }

  int count = 0;
  int command[128]; // the counter of legth command
  command[count++] = 0x2A;
  command[count++] = 0x2B;
  command[count++] = 0x2C;
  command[count++] = 0x2D;
  
  int i = 1;
  bool H = false; // if true, convert in hexadécimal, and if false in décimal
 

  // parcing of commandes

    // the infos
  if (str_compare(argv[i], "info")) {
    cout << "info";
    command[count++] = 0x0; // c'est cette ligne qui plante sans raison.
    command[count++] = 0x70;

    // the led
  } else if (str_compare(argv[i], "led")) {
    cout << "led\n";
    if (!argv[++i]) {
      cout << "led what ?\n" << endl;
      return 0;

      // the ears 
    } else if (str_compare(argv[i], "ear")) {
      cout << "ear\n";
      if (!argv[++i]) {
        cout << "what else ?\n" << endl;
      return 0;
        
      } else if (str_compare(argv[i], "all")) {
        cout << "all\n" << endl;
        command[count++] = 0x3;
        command[count++] = 0x11;

      } else if (str_compare(argv[i], "single")) {
        cout << "single\n" << endl;
        command[count++] = 0x4;
        command[count++] = 0x12;

      } else {
        cout << "what else ?\n" << endl;
      return 0;
      }

      // the belt
    } else if (str_compare(argv[i], "belt")) {
      cout << "belt\n";
      if (!argv[++i]) {
        cout << "what ?\n" << endl;
      return 0;

      } else if (str_compare(argv[i], "all")) {
        cout << "all\n" << endl;
        command[count++] = 0x3;
        command[count++] = 0x13;

      } else if (str_compare(argv[i], "single")) {
        cout << "single\n" << endl;
        command[count++] = 0x4;
        command[count++] = 0x15;

      } else if (str_compare(argv[i], "range")) {
        cout << "range\n" << endl;
        command[count++] = 0x5;
        command[count++] = 0x14;

      } else {
        cout << "what else ?\n" << endl;
      return 0;      }
    }

    // the motor
  } else if (str_compare(argv[i], "motor")) {
    cout << "motor\n";
    if (!argv[++i]) {
      cout << "what ?\n" << endl;
      return 0;

    } else if (str_compare(argv[i], "all")) {
      cout << "all\n" << endl;
        command[count++] = 0x2;
      command[count++] = 0x21;

    } else if (str_compare(argv[i], "duo")) {
      cout << "duo\n" << endl;
        command[count++] = 0x4;
      command[count++] = 0x22;

    } else if (str_compare(argv[i], "left")) {
      cout << "left\n" << endl;
        command[count++] = 0x2;
      command[count++] = 0x23;

    } else if (str_compare(argv[i], "right")) {
      cout << "right\n" << endl;
        command[count++] = 0x2;
      command[count++] = 0x24;

    } else {
      cout << "what else ?\n" << endl;
      return 0;
    }

    // the stop
  } else if (str_compare(argv[i], "stop")) {
    cout << "stop\n";
    if (str_compare(argv[++i], "led")) {
      cout << "led stop\n" << endl;
      command[count++] = 0x0;
      command[count++] = 0xFD;

    } else if (str_compare(argv[i], "motor")) {
      cout << "motor stop\n";
        command[count++] = 0x0;
      command[count++] = 0xFE;

    } else if (str_compare(argv[i], "robot")) {
      cout << "robot stop\n" << endl;
      command[count++] = 0xFF;

    } else {
      cout << "stop what ?\n" << endl;
      return 0;
    }
  }

    // convert parramèters :
  i = 0;
  if (H) {
    while (i < command[5]) {
      if (!(argv[i])) {
        cout << "prarrameters forgot";
        return 0;
      }
      command[count++] = hexaStr_to_int(argv[i]);
    }
  } else {
    while (i < command[5]) {
      if (!(argv[i])) {
        cout << "prarrameters forgot";
        return 0;
      }
      command[count++] = intStr_to_int(argv[i]);
    }
  }

  cout << "\nexit from the parcing ! ";

    // show the command :
  command[count] = -1;
  int j = 0;
  while (command[j] != -1) cout << hex << uppercase << command[j++] << ' ';
  cout << "\n\n";
  return 0;
  cout << argc << endl;
}

