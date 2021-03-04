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

    // vérify the flags, and if the help is ask, show it and stop the programme.
  for (int k = 0; k < argc; k++) 
    if (argv[k][0] == '-') {
      if (flags(argv[k], &H)) return 0;
      for (int j = k+1; j < argc; j++) 
        argv[j-1] = argv[j];
    }



  // parcing of commandes

    // the infos
  if (str_compare(argv[i], "info")) {
    command[count++] = 0x0; // c'est cette ligne qui plante sans raison.
    command[count++] = 0x70;

    // the led
  } else if (str_compare(argv[i], "led")) {
    if (!argv[++i]) {
      cout << "led what ?\n" << endl;
      return 0;

      // the ears 
    } else if (str_compare(argv[i], "ear")) {
      if (!argv[++i]) {
        cout << "what else ?\n" << endl;
	      return 0;
        
      } else if (str_compare(argv[i], "all")) {
        command[count++] = 0x3;
        command[count++] = 0x11;
	
      } else if (str_compare(argv[i], "single")) {
        command[count++] = 0x4;
        command[count++] = 0x12;
	
      } else {
        cout << "what else ?\n" << endl;
	return 0;
      }

      // the belt
    } else if (str_compare(argv[i], "belt")) {
      if (!argv[++i]) {
        cout << "what ?\n" << endl;
      return 0;

      } else if (str_compare(argv[i], "all")) {
        command[count++] = 0x3;
        command[count++] = 0x13;

      } else if (str_compare(argv[i], "single")) {
        command[count++] = 0x4;
        command[count++] = 0x15;

      } else if (str_compare(argv[i], "range")) {
        command[count++] = 0x5;
        command[count++] = 0x14;
	
      } else {
        cout << "what else ?\n" << endl;
	      return 0;  
      }
    } else {
      cout << "what else ?\n" << endl;
      return 0;
    }

    // the motor
  } else if (str_compare(argv[i], "motor")) {
    if (!argv[++i]) {
      cout << "what ?\n" << endl;
      return 0;

    } else if (str_compare(argv[i], "all")) {
      command[count++] = 0x2;
      command[count++] = 0x21;

    } else if (str_compare(argv[i], "duo")) {
      command[count++] = 0x4;
      command[count++] = 0x22;

    } else if (str_compare(argv[i], "left")) {
      command[count++] = 0x2;
      command[count++] = 0x23;

    } else if (str_compare(argv[i], "right")) {
      command[count++] = 0x2;
      command[count++] = 0x24;

    } else {
      cout << "what else ?\n" << endl;
      return 0;
    }

    // the stop
  } else if (str_compare(argv[i], "stop")) {
    if (str_compare(argv[++i], "led")) {
      command[count++] = 0x0;
      command[count++] = 0xFD;

    } else if (str_compare(argv[i], "motor")) {
      command[count++] = 0x0;
      command[count++] = 0xFE;

    } else if (str_compare(argv[i], "robot")) {
      command[count++] = 0x0;
      command[count++] = 0xFF;

    } else {
      cout << "stop what ?\n" << endl;
      return 0;
    }

  } else if (str_compare(argv[i], "motivator")) {
    command[count++] = 0x1;
    command[count++] = 0x50;

  } else if (str_compare(argv[i], "guidance")) {
    command[count++] = 0x2;
    command[count++] = 0x40;

  } else {
    cout << "lk what ?\n" << endl;
    return 0;
  }

  cout << "      convert parramèters : " << hex << uppercase << command[4] << " : i_" << i << " : \n";
  
    // convert the str number in int
  int k = 0;
  if (H) {
    while (k++ < command[4]) {
      if (!(argv[++i])) {
        cout << i << " : parrameters forgot\n";
        return 0;
      }
      command[count] = hexaStr_to_int(argv[i]);
      if (command[count++] == -1) {
        cout << "parrameters " << k << " invalid\n";
        return 0;
      }
    }
  } else {
    while (k++ < command[4]) {
      if (!(argv[++i])) {
        cout << i << " : parrameters forgot\n";
        return 0;
      }
      command[count] = intStr_to_int(argv[i]);
      if (command[count++] == -1) {
        cout << "parrameters " << k << " invalid\n";
        return 0;
      }
    }
  }

    // show the command :
  command[count] = -1;
  int j = 0;
  while (command[j] != -1) cout << hex << uppercase << command[j++] << ' ';
  cout << "\n\n";
  return 0;
  cout << argc << endl;
}
