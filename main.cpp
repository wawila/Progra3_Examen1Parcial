#include <iostream>
#include <math.h>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Suma a (dado) y b (dado) y almacena el resultado en la direccion de memoria donde apunta resultado (dado)
void sumar(int a, int b, int *resultado)
{
    *resultado = a + b;
}

//Devuelve el elemento mayor del arreglo (dado) con el tamano dado
template <typename T>
T getMax(T*arreglo, int tamano)
{
     T x = arreglo[0];
     for(int i = 0; i < tamano; i++)
     {
        if(x < arreglo[i])
            x = arreglo[i];
     }
    return x;
}

//Devuelve el factorial de num (dado)
//Definicion del factorial https://en.wikipedia.org/wiki/Factorial
int factorial(int num)
{
    int x = 1;
    for(int i =1 ; i <= num; i++)
        x *= i;

    return x;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las clases Usuario, UsuarioNormal, UsuarioAdministrador

//Todas las clases:
//Los contructores inicializan los atributos de la clase

//Usuario:
//getMensaje() es una funcion virtual que devuelve una cadena vacia ""
//soyAdministrador() es una funcion virtual pura

//UsuarioNormal
//getMensaje() devuelve el atributo mensaje
//soyAdministrador() devuelve false
//operator== devuelve true si el mensaje que viene de paramentro es igual al atributo de la clase, de lo contrario devuelve false

//Usuario administrador
//soyAdministrador() devuelve true

class Usuario
{
public:
    string nombre;
    string pass;
    virtual string getMensaje()
    {
        return "";
    };
    virtual bool soyAdministrador()=0;
};

class UsuarioNormal : public Usuario
{
    public:
        string mensaje;
        UsuarioNormal(string nom, string pass, string mens){
            this->nombre = nom;
            this->pass = pass;
            this->mensaje = mens;
        }

        string getMensaje()
        {
            return mensaje;
        }

        bool soyAdministrador()
        {
            return false;
        }

        bool operator==(string mens)
        {
            return mensaje == mens;
        }
};

class UsuarioAdministrador: public Usuario
{
    public:

    UsuarioAdministrador(string nom, string pass)
    {
        this->nombre = nom;
        this->pass = pass;
    }

    bool soyAdministrador()
    {
        return true;
    }
};

///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar()
{
    double nota = 0;

    int a1=4,b1=5,*c1=new int(0);
    int a2=10,b2=15,*c2=new int(0);
    int a3=7,b3=3,*c3=new int(0);

    sumar(a1,b1,c1);
    sumar(a2,b2,c2);
    sumar(a3,b3,c3);

    cout<<"sumar():\t\t";
    if(*c1 == 9
        && *c2 == 25
        && *c3 == 10
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    int *arr = new int[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    int *arr2 = new int[5];
    arr2[0]=1;
    arr2[1]=9;
    arr2[2]=2;
    arr2[3]=7;
    arr2[4]=8;

    cout<<"getMax():\t\t";
    if(getMax(arr,3)==3
        && getMax(arr2,5)==9
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"factorial():\t\t";
    if(factorial(0)==1
        && factorial(4)==24
        && factorial(9)==362880
        && factorial(3)==6
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/5"<<endl<<endl;
}

void evaluar2()
{
    double nota = 0;

    cout<<"Prueba 1 - Constructor de UsuarioNormal:\t";

    UsuarioNormal *un1 = new UsuarioNormal("lolo","secreto","estoy feliz");
    UsuarioNormal *un2 = new UsuarioNormal("lola","secreto777","tomandome una selfie");
    if(un1->nombre == "lolo"
        && un1->pass == "secreto"
        && un1->mensaje == "estoy feliz"
        && un2->nombre == "lola"
        && un2->pass == "secreto777"
        && un2->mensaje == "tomandome una selfie"
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Prueba 2 - Constructor de UsuarioAdministrador:\t";
    UsuarioAdministrador *ua1 = new UsuarioAdministrador("punpun", "admin");
    UsuarioAdministrador *ua2 = new UsuarioAdministrador("rufo", "campeon007");
    if(ua1->nombre == "punpun"
        && ua1->pass == "admin"
        && ua2->nombre == "rufo"
        && ua2->pass == "campeon007"
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Prueba 3 - Funcion virtual soyAdministrador():\t";
    Usuario *u1 = new UsuarioNormal("ponpon","secreto23","escribe lo que estas pensando");
    Usuario *u2 = new UsuarioAdministrador("punpun","amoaponpon22");
    Usuario *u3 = new UsuarioAdministrador("punpun","amoaponpon22");
    Usuario *u4 = new UsuarioNormal("ponpon","secreto23","escribe lo que estas pensando");
    if(!u1->soyAdministrador()
        && u2->soyAdministrador()
        && u3->soyAdministrador()
        && !u4->soyAdministrador()
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Prueba 4 - Funcion virtual pura getMensaje():\t";
    if(u1->getMensaje() == "escribe lo que estas pensando"
        && u2->getMensaje() == ""
        && u3->getMensaje() == ""
        && u4->getMensaje() == "escribe lo que estas pensando"
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Prueba 5 - operator==:\t\t\t\t";
    if(*(UsuarioNormal*)u1 == "escribe lo que estas pensando"
        && *(UsuarioNormal*)u4 == "escribe lo que estas pensando"
        && *(UsuarioNormal*)un1 == "estoy feliz"
        && *(UsuarioNormal*)un2 == "tomandome una selfie"
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/10"<<endl;
}
