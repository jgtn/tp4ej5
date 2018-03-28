#include  <stdio.h>
#define P 2
#define N 2
#define M 2
#define DEAD 0
#define ALIVE 1

void nextgen(char world[N][M][P]);  // Declaración de la función nextgen()

int main(void)
{

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
    for(columna = 0; columna <= (M-1))
    {
      char cell,neighbours;                                         // creo variable que indica el contenido de una célula y variable que cuenta la cantidad de "vecinos"
      cell = world [0][fila][columna];                              // asigno a dicha variable el contenido de la célula
      neighbours = surroundings_chk(0,fila,columna);                // llamo a función que informa la cantidad de vecinos de la célula

      if((cell==ALIVE && (neighbours==2 || neighbours==3)) || (cell==DEAD && neighours==3))
      {
        world[1][fila][columna] = ALIVE;                             // si la célula está viva y tiene exactamente 2 o 3 vecinos ,o si está muerta y tiene exactamente 3 vecinos, estará viva
      }

      else
      {
        world[1][fila][columna] = DEAD;                               // si la célula está viva y no tiene exactamente 2 o 3 vecinos, o está muerta y no tiene exactamente 3 vecinos, entonces muere
      }
      }

    }
  }

/**********************************************************************/

char surroundings_chk(char matriz, char fila, char columna)
{
  char  neighbours = 0;

  if((fila-1))
}





























/***************************************************************************************************
FUNCION get_cell()

Devuelve el contenido del elemento de un arreglo de 3 dimensiones cuya posición es (i,j,k)
donde, i = matriz - j = fila - k = columnas

Recibe: - Dirección array de 3 Dimensiones (2 x N x M) (mat 0 = main y mat 1 = buffer)
        - Coordendas del elemento que se busca (matriz,fila,columna)

Devuelve: - Contenido de la posición (char)

Requiere: Definición de constantes P (número de matriz), N (filas matriz) y M (columnas matriz)

**************************************************************************************************/

char get_cell(char array[P][N][M],unsigned int matriz,unsigned int fila, unsigned int columna)
{


}
