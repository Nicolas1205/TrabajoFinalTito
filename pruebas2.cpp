#include <iostream>
using namespace std;

const int MAXP = 100;
typedef char str[30];
typedef struct {
  str nombre;
  str apellido;
  str apodo;
  int puntaje;
} reg;
typedef reg arr_reg[MAXP];

// Busqueda
bool search(reg player, arr_reg pl) {
  for (int i=0; i < MAXP; i++) {
    if (pl[i].nombre == player.nombre && pl[i].apellido == player.apellido) {
      return true;
    }
  }
  return false;
}

// Adicion de Jugadores
void add_player (arr_reg &pl, int &ocup, reg nuevo){
  cout << "INGRESE NOMBRE: ";
  cin >> nuevo.nombre;
  cout << "INGRESE APELLIDO: ";
  cin >> nuevo.apellido;
  cout << "INGRESE APODO: ";
  cin >> nuevo.apodo;

  if(search(nuevo, pl)) {
    cout << "JUGADOR EXISTENTE." << endl;
    return;
  }
  
  pl[ocup] = nuevo;
  ocup++;
}

// Funcion Principal
int main() {
  int ocup = 0;
  arr_reg player_list;
  reg player;

  add_player (player_list, ocup, player);
}
