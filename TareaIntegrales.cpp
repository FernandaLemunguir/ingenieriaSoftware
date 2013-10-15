#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>

 
using namespace std;

void menu();
void crear_polinomio(int, int a[]);
void mostrar(int, int a[]);
void calculo(int, int b[10]);
void resultado(int , int a[10], int b[10]);
void fraccion(int, int b[10]);
void den(int, int b[10]);
void calculo_con_limites(int, int a[10], int b[10], float c[10], int, int);
void resultado(int, float c[10]);
void informacion();

main()
{
	system("TITLE INGENIERIA DE SOFTWARE - CALCULO DE INTEGRALES");
     
      char op;
      int n, A=0, B=0;
      int m=0;//condicion 
	  int a[10],b[10];
	  float c[10]; 
      do
      {
      	 menu();
      	 cin>> op;
         switch (op)
		 	{
		 		
		 		case 'i':  	system("cls");
                        	system("TITLE ..:::: CALCULO DE INTEGRALES NO DEFINIDA ::::..");
                       	 	cout<<"      ..:::: CALCULO DE INTEGRALES NO DEFINIDA ::::.."<<endl<<endl; 
								while(m<=0)
    						{
    							cout<<"Ingrese Grado del polinomio"<<endl;
    							cin>>n;
    							if(n>=0)
    							{
    								m=1;
    							}
    						
    							else
    							{
    								cout<<"Error al ingresar grado del polinomio, debe ser mayor a cero"<<endl<<endl;
									m--;
    								n=0;
    							}
    						}
    						m=0;    
    						crear_polinomio(n,a); 
    						system("cls");
    						cout<<endl<<endl;
    						cout<<"    .::Polinomio a integrar: ";
    						mostrar(n,a);
    						cout<<" dx"<<endl<<endl;
    						calculo(n, b);
    					    resultado(n, a, b);
    					    fraccion(n, b);
    					    den(n, b);
				 			system("pause");
                           	system("cls");
                           	break;
                
                case 'g':  	system("cls");
                        	system("TITLE ..:::: CALCULO DE INTEGRALES DEFINIDAS ::::..");
                       	 	cout<<"      ..:::: CALCULO DE INTEGRALES DEFINIDAS ::::.."<<endl<<endl; 
							 
    						
    						while(m<=0)
    						{
    							cout<<"Ingrese Grado del polinomio"<<endl;
    							cin>>n;
    							if(n>=0)
    							{
    								m=1;
    							}
    						
    							else
    							{
    								cout<<"Error al ingresar grado del polinomio, debe ser mayor a cero"<<endl<<endl;
									m--;
    								n=0;
    							}
    						}
    						m=0;
    						while(m<=0)//condicion para comprobar si se ingresan bien los limites de integracion
    						{
    						
							cout<<"Ingrese Limite inferior: ";
							cin>>A;
							cout<<"Ingrese Limite Superior: ";
							cin>>B;   
							
							if(A>B)
							{
								cout<<endl<<"****Error al definir los limites de integracion****"<<endl;
								cout<<"****(Limite inferior debe ser menor a limite superior)****"<<endl<<endl<<endl;
								cout<<"ingrese nuevamente los limites: "<<endl<<endl;
								m--;
							}
							else
							{
								m=1;
							}
							
							}
							m=0;
							system("cls");
							cout<<"      ..:::: CALCULO DE INTEGRALES DEFINIDAS ::::.."<<endl<<endl; 
    						crear_polinomio(n,a); 
    					    
    						cout<<endl<<endl;
    						cout<<"    .::Polinomio a integrar: ";
    						mostrar(n,a);
    						cout<<" dx"<<endl<<endl;
    						cout<<"    .::Limites de integracion entre: "<<A<<" y "<<B<<endl<<endl;
    						calculo(n, b);
    						
    						calculo_con_limites(n, a, b, c, A,B);
    						resultado(n, c);
    						
    						cout<<endl<<endl;
						   system("pause");
                           system("cls");
                           break;
                
                case 'v':  	informacion();
							system("pause");
                           	system("cls");
                           	break;
                           
                case 's':	exit(1);
                
		 		default:   cout<<"Opcion no valida"<<endl;
                           system("pause");
                           break;
		 		
		 	}          
      }while(op!= 's'); 
      system("pause");
}

void menu()
{
	system("cls"); 
    system("TITLE INGENIERIA DE SOFTWARE - CALCULO DE INTEGRALES");
    int op;
    
    cout << "                  ..::::MENU::::.." <<endl<<endl;
    cout<<"         i.-  Calcular Integral Indefinida"<<endl;
    cout<<"         g.-  Calcular Integral Definida"<<endl;
    cout<<"         v.-  Informacion"<<endl;
    cout<<"         s.-  Salir"<<endl<<endl;
    cout<<"opcion: ";
}

void crear_polinomio(int n, int a[10])//crea el polinomio y lo ingresa en un arreglo
{
	int z = n, i=0;
        while(i<=n)
    {
     	cout<<"Ingrese el coeficiente numerico para x^"<<(z-i)<<" : ";//el coeficiente lo obtine restando en cada iteracion hasta llegar a 0
     	cin>> a[i]; //aca se lee el coeficiente numerico asociado a x por es 3:coef numerico es asociado a x^2
        i++;
    }
}

void mostrar(int n, int a[10])//muestra el polinomio en pantalla
{ 
        
	int i, z;
	z=n;
	
	
    for(i = 0; i<= n; i++)
    {
    	if(a[i] != 0)//excepcion para el caso que el coef. numerico sea 0, este no se va a mostrar ya que una multiplicacion por cero es siempre 0
    	{
    	  if(a[i] != 1)//excepcion para el caso que los coef. numericos sean distintos de 1, ya que no es necesario mostrar 1X, ya que es = a tener X
    	  {
		    	if(z-i != 0)//excepcion para el exponente, ya que si es cero, nuestra base sera igual a 1, ej: x^0 = 1
		         {
		         	if(z-i != 1)//con esta excepcion se mostraran todos los exponentes que sean distintos de 1, ya que no es necesario mostrar x^1 
		         	 {           //ya que es igual a mostrar x
		         	 
			         	if(a[i]>0)//si el coef. numerico es mayor que cero, será positivo por lo tanto se le agregara el signo + ej: 3 = mostrara en pantalla + 3
			     			{
			     				cout<<"+"<<a[i]<<"x^"<<(z-i);//muestra en pantalla: signo coef. numerico * X ^exponente. ej: + 7x^2
			     			}
			     		else
			     			{         //y si el coef. numerico es negativo, este se mantendra ya que por defecto muestra su signo
			     				cout<<a[i]<<"x^"<<(z-i);//muestra en pantalla: coef. numerico * X ^exponente. ej: - 4x^2
			     			}
			          }
			          
			        else //con esta excepcion se mostrara el exponente x (x^1)
		         	 {           
			        
		         	 
			         	if(a[i]>0)
			     			{
			     				cout<<"+"<<a[i]<<"x"; //muestra en pantalla: signo coef. numerico * X. ej: + 7x
			     			}
			     		else
			     			{
			     				cout<<a[i]<<"x"; //muestra en pantalla: coef. numerico * X ^exponente. ej: -4x
			     			}
			          
		         }
		     }
		         else  //en este caso se muestran los caso en los cuales el exponente de x es igual a 0. x^0 = 1
		         {
		         	if(a[i]>0)
		     			{
		     				cout<<"+"<<a[i]; //muestra en pantalla: signo y coef. numerico ej:+6
		     			}
	     			else
	     				{
	     					cout<<a[i];//se muestra solo el coef.numerico ej: -2
	     				}
	        	 }
         }
         else // este caso muestra cuando el coef. numerico es igual a 1
         {
         	if(z-i != 0)//caso que el exponente sea distinto a cero
		         {
		         	if(a[i]>0)
		     			{
		     				cout<<"+x^"<<(z-i); //muestra en pantalla signo x^exponente ej: +x^5
		     			}
		     		else
		     			{
		     				cout<<"-x^"<<(z-i);//muestra en pantalla signo xêxponente ej: -x^2
		     			}
		         }
		      else//caso en que el exponente es igual a cero (no se muestra la base x^0, solo se muestran los coef. numericos)
		         {
		         	if(a[i]>0)
		     			{
		     				cout<<"+"<<a[i]; //muestra en pantalla: signo coef. numerico ej: + 4
		     			}
	     			else
	     				{
	     					cout<<a[i]; //muestra en pantalla: coef. numerico ej: - 4
	     				}
	        	 }
         }
       }
    }
    

}

void calculo(int n, int b[10])//formula para integrar un polinomio: x^n -> integrado x^(n+1) / (n+1) 
 {                            //por lo tanto aca calculo el exponente de cada x de mi polinomio con la formula z+1 y el exponente lo guardo en un arreglo auxiliar
	int z,i;                   //y a medida que avanzo en mis calculos voy restando 1 a z, hasta llegar a 0
	z=n;
    for(i = 0; i<= n; i++)
    {
    	b[i] = z+1;   //ej: si tengo x^0 -> b[i]=0+1
    	z--;	
    }
}

void resultado(int n, int a[10], int b[10])//se utiliza solo para el caso de integrales no definidas
{                                         //utilizo excepciones iguales a la funcion mostrar, con la diferencia que ahora el exponente esta 
	int i;                                //guardado en el arreglo b[i], calculado en la funcion anterior
	for(i=0; i<=n; i++)
    {
    	
	    	if(b[i] != 1)
	    	{  
	    	   if(a[i]!= 1)
	    	    {
			    	if(a[i] > 0)
			    	{
			    		cout<<" + "<<a[i]<<"x^"<<b[i];
			    	}
			    	else
			    	{
			    	    cout<<"  "<<a[i]<<"x^"<<b[i];	
			    	}
			    }
			    else
			    {
			       if(a[i] > 0)
			    	{
			    		cout<<" +  "<<"x^"<<b[i];
			    	}
			    	else
			    	{
			    	    cout<<" - "<<"x^"<<b[i];	
			    	}	
			    }
		    }
		    else
		    {
		    	if(a[i]!=1)
		    	 {
		    	 	if(a[i] > 0)
			    	{
			    		cout<<"  +  "<<a[i]<<" x ";
			    	}
			    	else
			    	{
			    	    cout<<"   "<<a[i]<<" x ";	
			    	}
		    	 }
			    else
				{
					if(a[i] > 0)
			    	{
			    		cout<<"  + "<<" x ";
			    	}
			    	else
			    	{
			    	    cout<<"  - "<<" x ";	
			    	}
				}	
		    }
    }
    cout<<"+ C "; //agrego la constante de integracion
    cout<<endl;
}

void fraccion(int n, int b[10])//imita la linea de division entre el numerador y denominador
{
	int i;
	 for(i=0; i<=n; i++)
     {
     	if(b[i] != 1)
     	{
     		cout<<"   ----";//si el denominados el distinto a uno, pone la linea divisoria
     	}
     	else
     	{
     		cout<<"       ";//si no se salta ese espacio 
     	}
     	 	
     }  
     
	 cout<<endl;
}

void den(int n, int b[10])//ingresa el valor del denominador
{

 	int i;
	for(i=0; i<=n; i++)//va a realizar la operacion la cantidad n = grado del polinomio
     {
     	if(b[i] != 1)
	     	{
	     		cout<<"     "<<b[i]<<" ";//si el denominados el distinto a uno, pone el calculo del denominador que se obtienes de la funcion "calculo"
	     	}
	  	else
	     	{
	     		cout<<"       ";//y si es igual a 1, omite el denominador e ingresa espacios en blanco
	     	}
     
     }  
     cout<<endl<<endl;
}


void calculo_con_limites(int n, int a[10], int b[10], float c[10], int A, int B)//se utiliza para integrales definidas
{
	int i;
	for(i = 0; i<=n; i++)
	{
		c[i] = ((a[i]*(pow(B,b[i]))/b[i]) - (a[i]*pow(A,b[i]))/b[i]);//los resultados los guardo en otro arreflo aux.
    }                                                                 //  donde A es el limite inferior y B el limite superior
}																	//y se realiza la formula de integrar (a*(B^n) / n) - (a*(A^n) / n)

void resultado(int n, float c[10])//Calcula la suma de los resultados guardados en la funcion anterior y nos da el resultado de nuestra integral
{
	float res = 0;
	for(int i=0; i<=n; i++)
	{
		res = res + c[i];
	}
	
	cout<<"Calculo de polinomio integrado : "<<res<<endl<<endl;
}


void informacion()//Informacion del los integrantes del gurpo
{
	system("cls");
	cout<<"          ..:: INTEGRANTES ::.."<<endl<<endl;
	cout<<"   :: Fernanda Lemunguir Sepulveda"<<endl;
	cout<<"   .: Rut: 17.251.739-0"<<endl<<endl;
	cout<<"   :: Camilo Candia Rubinstein"<<endl;
	cout<<"   .: Rut: 17.407.159-4"<<endl<<endl;
	
	cout<<"          ..:: FECHA COMPILACION ::.."<<endl<<endl;//muestra fecha y hora de compilacion
	cout<<"   .: Fecha: ";
	system("date /t");
	time_t hora;
	time(&hora);
	struct tm *local = localtime(&hora);
	cout<<"   .: Hora: "<<local->tm_hour << ":" << local->tm_min << ":" << local->tm_sec <<endl<<endl<<endl;
	
}




