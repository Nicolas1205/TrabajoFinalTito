#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Declaraciones
const int MAX = 10;
typedef int vector2d [MAX][MAX];
typedef bool check [9999];

// Procedimientos
void gen_table(vector2d &tablero) {
  int rnd = rand() % 9999 + 1;
  check exists = {false};
  srand(time(NULL));

  cout << "Generando..................." << endl;
  for(int i=0; i < MAX; i++) {
    for(int j=0; j < MAX; j++) {
      while(exists[rnd]) {
        rnd = rand() % 9999 + 1;
      }
      tablero[i][j] = rnd;
      exists[rnd] = true;
    }
  }
  cout << "¡TABLERO GENERADO!" << endl;
  /*
  for(int i=0; i<MAX; i++) {
    for(int j=0; j<MAX; j++) {
      cout << "i: " << i << ", j: " << j << ": " << tablero[i][j] << endl;
    }
  }
  */
}

void play_menu() {
  cout << "**** COMIENZA LA AVENTURA ****" << endl;
  cout << "1- Seleccionar jugadores" << endl;
  cout << "2- Lanzamiento de dados" << endl;
  cout << "3- Salir" << endl;
  cout << "**********************************" << endl;
  cout << "Elija una opcion: " << endl;
}

void main_menu() {
  cout << "*********** PRINCIPAL ***********" << endl;
  cout << "1- Generar Tablero" << endl;
  cout << "2- Registrar Jugadores" << endl;
  cout << "3- Listar Jugadores" << endl;
  cout << "4- Jugar" << endl;
  cout << "5- Salir" << endl;
  cout << "**********************************" << endl;
  cout << "Elija una opcion: " << endl;
}

// Funcion Principal
int main() {
  int o, p;
  bool b1 = false,  b2 = false;
  vector2d tablero;

  while(true) {
    main_menu();
    cin >> o;
    if(o == 1) {
      gen_table(tablero);
      b1 = true;
    } else if(o == 2) {
      b2 = true;
    } else if (o == 3) {
      
    } else if (o == 4) {
      if (b1 && b2) {
        while(true) {
          play_menu();
          cin >> p;
          if(p == 1) {

          } else if(p == 2) {

          } else if(p == 3) {
            break;
          } else {
            cout << "OPCION INCORRECTA, intente de nuevo." << endl;
          }
          cout << endl;
        }
      } else {
        cout << "Asegurese de generar el tablero y registrar almenos 2(dos) jugadores. " << endl;
      }
    } else if (o == 5) {
      cout << "FIN DEL PROGRAMA." << endl;
      break;
    } else {
      cout << "OPCION INCORRECTA, intente de nuevo." << endl;
    }
    cout << endl;
  }

  return 0;
}