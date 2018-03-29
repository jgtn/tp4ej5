#include <stdio.h>
#define CTE_ROW 3   /*constantes para la dimension de la matriz(para probar)*/
#define CTE_COL 3
#define THRD_DIM 2
/*LEER!!! en los prototipos puse int para probar pero supongo que pondremos char para mostrar los asteriscos CUIDADO!!!*/
void swap_matrix (int[THRD_DIM][CTE_ROW][CTE_COL]);/*prototipo de función que intercambia las matrices*/
void print_matrix(int[THRD_DIM][CTE_ROW][CTE_COL],int);/*prototipo de funcion que imprime matrices*/

int main (void)/*todo lo que esta aca es para probar NO USAR*/
{
int matrix [THRD_DIM][CTE_ROW][CTE_COL]={{{1,2,3},{1,1,1},{1,1,1}},{{5,4,3},{6,2,5},{2,2,2}}};
print_matrix(matrix,0);
swap_matrix(matrix);
print_matrix(matrix,1 );

int hello=1;
hello=2;

return 0;
}


/*SWAP_MATRIX permite copiar, en una matriz de 3 dimensiones, el contenido de
una dimensión siguiente, a la actual (de 1 a 0, de 2 a 1 y asi).  EL CONTENIDO
DE LA MATRIZ "0" SE PIERDE!!! ADEMÁS EL CONTENIDO DE LA MATRIZ N Y LA (N-1)
SERÁ EL MISMO*/
void swap_matrix (int matrix [THRD_DIM][CTE_ROW][CTE_COL])
{
  int i,j,k;/*indices para moverme en la matriz*/
  for(i=0;i<CTE_ROW;i++)/*me muevo por la matriz con estos for*/
  {
    for(j=0;j<CTE_COL;j++)
    {
      for(k=0;k<THRD_DIM-1;k++)
      {
        matrix[k][i][j]=matrix[k+1][i][j];/*copia de contenido*/
      }
    }
  }
}

/*PRINT_MATRIX imprime la matriz "0" de una matriz tridimensional,
los valores estarán separados por "|" y para que se muentre correctamente
en la consola los valores o caracteres deberán ocupar solo 1 espacio*/
void print_matrix(int matrix [THRD_DIM][CTE_ROW][CTE_COL],int gen)
{
  printf("Generación número:%d\n\n",gen );
  int i,j;/*indices para moverme en la matriz*/
  for(i=0;i<CTE_ROW;i++)
  {
    for(j=0;j<CTE_COL;j++)
    {
      printf("|%d",matrix[0][i][j] );/*para imprimir un caracter cambiar %d por %c*/
    }
    printf("|\n");
  }

}
