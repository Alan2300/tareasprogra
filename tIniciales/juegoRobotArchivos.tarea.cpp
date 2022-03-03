#include <iostream>
#include <fstream>
#include <string>
using namespace std;




void SaveFile(string Nombre, char GameMap[10][10])
{
    ofstream FileMap("Mapa.txt"); // abre el archivo
    if(FileMap.is_open())
    {
        FileMap << Nombre << endl;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
               FileMap << GameMap[i][j];
            }
            FileMap << endl;
        }
    }

    FileMap.close(); // cierra el archivo
}
void DrawMap(int HeroPosX, int HeroPosY, char GameMap[10][10])
{
    GameMap[HeroPosX][HeroPosY] = 'R';
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if (GameMap[i][j] == 'R' )
            {

                if ( i != HeroPosX || j != HeroPosY )
                {
                    GameMap[i][j] = '0';
                }

            }
            cout << GameMap[i][j];
        }
        cout << endl;
    }
}
int PosicionRobot(char eje, char GameMap[10][10])
{
    int posicion=0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(GameMap[i][j] == 'R' && eje == 'x')
            {
                posicion = i;
            }
            else
            if(GameMap[i][j] == 'R' && eje == 'y')
            {
                posicion = j;
            }
        }
    }
    return posicion;
}

string OpenFile(char GameMap[10][10])
{
    ifstream FileMap("Mapa.txt"); // abre el archivo
    string line;
    string name="No encontre nombre";
    int renglon = 0;
    int row = 0;

    if(FileMap.is_open())
    {
        while(getline(FileMap, line))
        {
            if(renglon == 0)
                name = line; // Obtiene el nombre de jugador
            else
            {
                for(int i = 0; i < 10; i++)
                {
                        GameMap[row][i] = line[i];
                }
                row++;
            }
            renglon++;
        }

        FileMap.close();
    }
    else
    {
        cout << "Error. No se pudo abrir el archivo." << endl;
    }
    return name;
}

int main()
{
    int HeroPosX=0;
    int HeroPosY=0;
    bool isGameOver = false;
    char Input = ' ';
    char GameMap[10][10];
    string NamePlayer = "";
    // Obtiene el nombre del jugador
    NamePlayer = OpenFile(GameMap);
    cout << "Bienvenido/a " << NamePlayer << endl;
    // Obtiene la posición almacenada del robot en la coordenada X
    HeroPosX = PosicionRobot('x', GameMap);
    // Obtiene la posición almacenada del robot en la coordenada Y
    HeroPosY = PosicionRobot('y', GameMap);
    // dibuja o despliega el mapa asignado a la matriz
    DrawMap(HeroPosX, HeroPosY, GameMap);

    while(isGameOver == false)
    {
        cout << "Controles Teclas --> w(arriba), a(izquierda), d(derecha) y s(abajo)" << endl;
        cout << "Controles Teclas --> p(Salida)" << endl;
        cin >> Input;

        switch (Input)
        {
            case 'd':
                if(HeroPosY < 9)
                    HeroPosY++;
                break;
            case 'a':
                if(HeroPosY > 0)
                    HeroPosY--;
                break;
            case 'w':
                if(HeroPosX > 0)
                    HeroPosX--;
                break;
            case 's':
                if(HeroPosX < 9)
                    HeroPosX++;
                break;
            case 'p':
                isGameOver = true;
                break;
            default:
                cout << "Tecla Invalida" << endl;
                break;
        }
        DrawMap(HeroPosX, HeroPosY, GameMap);
    }
    // Grabar los datos temporales en la matriz y los envia al archivo en disco
    SaveFile(NamePlayer, GameMap);

    return 0;
}
