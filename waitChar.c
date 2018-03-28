char waitChar(void);

char waitChar(void)
{
  int caracter;
  while( ( (caracter=getchar()) !='\n') && (caracter!='q') && (caracter!='Q') ); //solo sale cuando ingresan enter, 'q' o 'Q'
  if( (caracter=='q') || (caracter=='Q') )
  {
    return 0;     //devuelve 0 si hubo alguna q o Q entre los caracteres ingresados
  }
  else
  {
    return 1;   //devuelve 1 si apretaron enter
  }
}
