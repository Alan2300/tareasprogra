#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

// Las funciones se declaran antes del main

// Void es si la funcion solo imprime datos
void imprimirCosas(){

    printf("Game over....");

}
//Clase padre
class Mage{
public:
    //Constructor
    Mage(int BasePower, int BaseHp, string name)
    {
        Power = BasePower;
        hp = BaseHp;
        Name = name;
    }
    float Damage()//método damage
    {
        return Power;//devuelve el poder
    }
    void GetDamage(int Value)//método GetDamage (daño)
    {
        hp= hp-Value;//resta el daño al hp
    }
    int life()//metodo life
    {
        return hp;//devuelve hp
    }
    string get_name()//metodo get_name
    {
        return Name;//devuelve el nombre
    }
protected:
    int Power, hp;//power y hp protegidos
    string Name;//nombre protegido
};

//Clase hija 1
class IceMage : public Mage
{
    public:
    IceMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower + 1;//suma 1 al poder
        hp = BaseHp +1;//suma 1 a hp
        Name = name;
    }
    int ice_attack()//método ataque de hielo
    {
        return  (rand() % Power) + 1;//devuelve el residuo de un número aleatorio dividido por el poder más 1
    }
};

//Clase hija 2
class FireMage : public Mage
{
    public:
    FireMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower;
        hp = BaseHp + 10;//suma 10 al hp
        Name = name;
    }
    int fire_attack(){
        return  (rand() % Power) + 1;//devuelve el residuo de un número aleatorio dividido por el poder más 1
    }
};
int main()
{
    Mage* Current_mage;//Current_mage tendra lo que contiene Mage
    Mage Harry(10, 100, "Harry");//el mago harry tiene un poder de 10 y hp de 100
    IceMage Dumbledore(11, 100, "Dumbledore");//El mago de hielo Dumbledore, tiene un poder de 11 y hp de 100
    FireMage Gandalf(11,100, "Gandalf");//El mago de fuego, Gandalf, tiene un poder de 11 y hp de 100
    //fuck_pointers();
    //imprimirCosas();
    bool chance = true;//valor "chance" declarado como verdadero
    int attack_value;//attack_value declarado como entero
    for (int i=0;i<10;i++){
        if (chance)
        {
            Current_mage = &Dumbledore;//current_mage va a ser igual a la dirección en memoria de Dumbledore, es decir el mago actual va a ser Dumbledore
            attack_value = Dumbledore.ice_attack();//El daño del ataque va a ser el resultado del método ice_attack
            cout<<" attack: "<<attack_value<<" ";//se imprime el attack_value
            Current_mage->GetDamage(attack_value);//obtiene el hp despues de restar el daño
            cout<<Current_mage->get_name()<<"- current life: "<<Current_mage->life()<<endl;//imprime el nombre del mago (Dumbledore) y su vida actual
            chance = false;//cambia chance a falso
        }
        else {
            Current_mage = &Gandalf;//current_mage va a ser igual a la dirección en memoria de Gandalf, es decir el mago actual va a ser Gandalf
            attack_value = Gandalf.fire_attack();//El daño del ataque va a ser el resultado del método fire_attack
            cout<<" attack: "<<attack_value<<" ";//se imprime el attack_value
            Current_mage->GetDamage(attack_value);//obtiene el hp despues de restar el daño
            cout<<Current_mage->get_name()<<"- current life: "<<Current_mage->life()<<endl;//imprime el nombre del mago (Gandalf) y su vida actual
            chance = true;//cambia chance a verdadero
        };
    }//chance empieza en verdadero y pasa a falso, por tanto, hace 5 veces la opción verdadera y 5 veces la opción falsa
    return 0;
}

