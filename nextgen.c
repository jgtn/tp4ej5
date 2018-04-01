#include  <stdio.h>
#define P 2
#define N 3
#define M 3
#define DEAD 0
#define ALIVE 1
void nextgen(char world[P][N][M]);                        // Declaración de la función nextgen()
char surroundings_chk(char matriz[P][N][M],char,char);    // Declaración de la función surroundings_chk()

int main(void)
{
  char matriz[P][N][M] = {{{0,0,0},{0,1,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0}}};
  nextgen(matriz[P][N][M]);
}
/***************************************************************************************************
FUNCION nextgen()

Para cada posición (células) de la matriz "main" (0), calcula su estado en la siguiente generación,
y lo copia en la matriz "buffer" (1)

Recibe: - Dirección array de 3 Dimensiones (2 x N x M) (mat 0 = main y mat 1 = buffer)

Devuelve: ---------

Requiere: Definición de constantes N (filas matriz) y M (columnas matriz)

**************************************************************************************************/
void nextgen(char world [P][N][M])
{
  int fila,columna;
  for(fila = 0; fila <= (N-1);fila++)
  {
    for(columna = 0; columna <= (M-1);columna++)
    {
      char cell,neighbours;                                                       // creo variable que indica el contenido de una célula y variable que cuenta la cantidad de "vecinos"
      cell = world [0][fila][columna];                                            // asigno a dicha variable el contenido de la célula
      neighbours = surroundings_chk(world[P][N][M],fila,columna);                // llamo a función que informa la cantidad de vecinos de la célula

      if((cell==ALIVE && (neighbours==2 || neighbours==3)) || (cell==DEAD && neighbours==3))
      {
        world[1][fila][columna] = ALIVE;                                         // si la célula está viva y tiene exactamente 2 o 3 vecinos ,o si está muerta y tiene exactamente 3 vecinos, estará viva
      }

      else
      {
        world[1][fila][columna] = DEAD;                                          // si la célula está viva y no tiene exactamente 2 o 3 vecinos, o está muerta y no tiene exactamente 3 vecinos, entonces muere
      }
      }

    }
  }

  /***************************************************************************************************
  FUNCION surroundings_chk()

  Determina, para una posición dada de un arreglo en 2 dimensiones, cuantas posiciones adyacentes contienen el caracter
  1, tomando en cuenta las diagonales. La adyacencia en los bordes de la matriz no comprende un salto de fila/columna

  Recibe: - Dirección array de 3 Dimensiones (2 x N x M) (mat 0 = main y mat 1 = buffer)

  Devuelve: variable char con el número de celdas adyacentes que contienen un 1 (máximo 8)

  Requiere: Definición de constantes N (filas matriz) y M (columnas matriz)

  **************************************************************************************************/

char surroundings_chk(char matriz[P][N][M], char fila, char columna)
{
  char  neighbours = 0;

  if((fila-1)>=0 && (columna-1)>=0 && matriz[0][fila-1][columna-1] == 1)  // chequeo posición arriba izquierda
  {
    neighbours++;
  }

  if((fila-1)>=0 && (columna+1)>=0 && matriz[0][fila-1][columna+1] == 1)  // chequeo posición arriba derecha
  {
    neighbours++;
  }

  if((fila+1)>=0 && (columna-1)>=0 && matriz[0][fila+1][columna-1] == 1)  // chequeo posición abajo izquierda
  {
    neighbours++;
  }

  if((fila+1)>=0 && (columna+1)>=0 && matriz[0][fila+1][columna+1] == 1)  // chequeo posición abajo derecha
  {
    neighbours++;
  }

  if(fila>=0 && (columna-1)>=0 && matriz[0][fila][columna-1] == 1)  // chequeo posición aizquierda
  {
    neighbours++;
  }

  if((fila-1)>=0 && columna>=0 && matriz[0][fila-1][columna] == 1)  // chequeo posición arriba
  {
    neighbours++;
  }

  if(fila>=0 && (columna+1)>=0 && matriz[0][fila][columna+1] == 1)  // chequeo posición derecha
  {
    neighbours++;
  }

  if((fila+1)>=0 && columna>=0 && matriz[0][fila+1][columna] == 1)  // chequeo posición abajo
  {
    neighbours++;
  }

  return neighbours;
}
