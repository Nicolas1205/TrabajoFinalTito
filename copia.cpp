#include <iostream>
#include <ctime>
using namespace std;

// Declaraciones
int ocup = 0;
string player1 = "", player2 = "";
const int MAX = 10;
typedef int vector2d [MAX][MAX];
typedef bool check [9999];

const int MAXP = 100;
typedef struct {
  string nombre;
  string apellido;
  string apodo;
  int puntaje;
} reg;
typedef reg arr_reg[MAXP];

// Funciones & Procedimientos
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

bool search(reg nuevo, arr_reg pl) {
  for(int i=0; i<=ocup; i++) {
    if(pl[i].apodo == nuevo.apodo || (pl[i].nombre == nuevo.nombre && pl[i].apellido == nuevo.apellido)) {
      return true;
    }
  }

  return false;
}

void add_player(arr_reg &pl, reg nuevo){
  cout << "INGRESE NOMBRE: ";
  cin >> nuevo.nombre;
  cout << "INGRESE APELLIDO: ";
  cin >> nuevo.apellido;
  cout << "INGRESE APODO: ";
  cin >> nuevo.apodo;

  if(search(nuevo, pl)) {
    cout << "JUGADOR EXISTENTE" << endl;
  } else {
    pl[ocup] = nuevo;
    ocup++;
  }
}

void sort_players(arr_reg pl) {
  reg aux;
  bool ord = false;
  while(ord == false) {
    ord = true;
    for(int i=0; i < ocup-1; i++) {
      if(pl[i].apellido > pl[i+1].apellido) {
        aux = pl[i];
        pl[i] = pl[i+1]; 
        pl[i+1] = aux;
        ord = false;
      }
    }
  }
}

void show_players(arr_reg pl) {
  if(ocup == 0) {
    cout << "NO SE REGISTRARON JUGADORES" << endl;
    return;
  }

  sort_players(pl);

  cout << endl << "LISTADO DE JUGADORES" << endl;
  for(int i=0; i < ocup; i++) {
    cout << endl;
    cout << "NOMBRE: " << pl[i].nombre << endl;
    cout << "APELLIDO: " << pl[i].apellido << endl;
    cout << "APODO: " << pl[i].apodo << endl;
  }
}

void select_player(arr_reg pl) {
  if(player1 != "" && player2 != "") {
    cout << endl;
    cout << "¡Ya hay jugadores registrados!" << endl;
    return;
  }
  
  bool band = true;
  while(band) {
    cout << endl;
    cout << "Ingrese apodo del 1er Jugador: " << endl;
    cin >> player1;
    for(int i=0; i < ocup; i++) {
      if(player1 == pl[i].apodo) {
        cout << "Jugador Seleccionado. " << endl;
        band = false;
        break;
      }
    }

    if(band) {
      cout << "No se encontro el jugador. " << endl;
    }
  }

  band = true;
  while(band) {
    cout << endl;
    cout << "Ingrese apodo del 2do Jugador: " << endl;
    cin >> player2;
    for(int i = 0; i < ocup; i++) {
      if(player2 == pl[i].apodo) {
        cout << "Jugador Seleccionado. " << endl;
        band = false;
        break;
      }
    }

    if(band) {
      cout << "No se encontro el jugador. " << endl;
    }
  }
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
  bool b1 = false;
  vector2d tablero;
  arr_reg player_list;
  reg player;

  while(true) {
    main_menu();
    cin >> o;
    if(o == 1) {
      gen_table(tablero);
      b1 = true;
    } else if(o == 2) {
      add_player(player_list, player);
    } else if (o == 3) {
      show_players(player_list);
    } else if (o == 4) {
      if (b1 && ocup == 2) {
        while(true) {
          cout << endl;
          play_menu();
          cin >> p;
          if(p == 1) {
            select_player(player_list);
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