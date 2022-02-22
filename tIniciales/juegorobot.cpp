#include <iostream>
#include <fstream>
using namespace std;
void drawMap(int posX,int posY,char gameMap[10][10]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(posX==j && posY==i)
        {
            cout<<"R";
        }
      else
      {
            cout<<gameMap[i][j];
      }
    }
    cout<<endl;
  }
}
int main()
{
  ///creación de archivo
  ofstream myfile ("gameData.txt");
  string nom = "";
  cout<<"Bienvenido/a!!! Ingrese su nombre: "<<endl;
  cin >>nom;
  int iz=0,der=0,arr=0,ab=0,numIte=0;
  int posX=3;
  int posY=3;
  char map[10][10]={{'1','1','1','1','1','1','1','1','1','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','0','0','0','0','0','0','0','0','1'},
		  {'1','1','1','1','1','1','1','1','1','1'}};
  char teclado;
  bool gameOver= false;
  drawMap(posX,posY,map);
  while(!gameOver)
  {
    cout << "Bienvenido(a) "<< nom << endl;
    cout << "Controles Teclas --> w(arriba), a(izquierda), d(derecha) y s(abajo)" << endl;
    cout << "Controles Teclas --> p(Salida)" << endl;
    cin >> teclado;
    switch (teclado)
    {
        case 'a':
            if(posX!=1)
            {
             posX-=1;
             iz+=1;
            }
            break;
        case 'd':
            if(posX!=8)
            {
             posX+=1;
             der+=1;
            }
            break;
        case 'w':
            if (posY!=1)
            {
              posY-=1;
              arr+=1;
            }
            break;
        case 's':
            if (posY!=8)
            {
              posY+=1;
              ab+=1;
            }
            break;
        case 'p':
            gameOver=true;
        default:
            break;
    }
  drawMap(posX,posY,map);
  }
  numIte=iz+der+arr+ab;
  if (myfile.is_open())
  {
      myfile<<"Nombre: " << endl;
      myfile<<nom<<endl;
      myfile<<"Numero de iteraciones a la izquierda: " << endl;
      myfile<<iz<<endl;
      myfile<<"Numero de iteraciones a la derecha: " << endl;
      myfile<<der<<endl;
      myfile<<"Numero de iteraciones hacia arriba: " << endl;
      myfile<<arr<<endl;
      myfile<<"Numero de iteraciones hacia abajo: " << endl;
      myfile<<ab<<endl;
      myfile<<"Numero de iteraciones: " << endl;
      myfile<<numIte<<endl;
      myfile.close();
  }
  else cout<<"Unable to open file";
 return 0;
}
