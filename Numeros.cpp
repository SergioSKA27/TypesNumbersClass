#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <exception>

/*
Creamos  una clase número la  cual será la clase base  para  representar el  conjunto 
total de números, dicha clase funciona como un template con la diferencia de que esta
diseñada para arrojar un error  en  caso de que el tipo seleccionado no sea del  tipo
numérico (int,long,float,...,etc.), dicha clase contiene los operadores aritméticos y
booleanos sobrecargados para poder  interactuar con otros objetos de la misma clase y
con datos de tipo numérico.
*/

template <class T>
class Number
{
protected: //el valor solo es accesible en las clases derivadas
    T value;
    T getvalue();

public: //copia en caso de querer utilizar la clase como un objeto
    T valcopy;

public:
    /*Constructores*/
    Number(T value);              //constructor base
    Number();                     //Constructor vacio
    Number(const Number<T> &Num); //Constructor copia

    /*Metodos*/
    Number<T> &setvalue(T new_value); //Cambiar el valor del numero

    /*Operadores aritmeticos*/

    //Operadores para objetos de la clase
    Number<T> &operator+(const Number<T> &val2); //Operador para sumas(modifican el valor del elemento usando el operador a + b)
    Number<T> &operator-(const Number<T> &val2); //Operador para restas(modifican el valor del elemento usando el operador a-b)
    Number<T> &operator*(const Number<T> &val2); //Operador para multiplicaciones(modifican el valor del elemento usando el operador a * b)
    Number<T> &operator/(const Number<T> &val2); //Operador para divisiones(modifican el valor del elemento usando el operador a/b)
    Number<T> &operator=(const Number<T> &val2); //Operador de asignacion(modifican el valor del elemento usando el operador a = x)

    //Operadores para objetos de la clase y numeros
    Number<T> &operator+(const T &val2); //su funcion es la misma solo que en esta podemos usar numeros con objetos(ObjNum + 10)
    Number<T> &operator-(const T &val2); //su funcion es la misma solo que en esta podemos usar numeros con objetos(ObjNum - 10)
    Number<T> &operator*(const T &val2); //su funcion es la misma solo que en esta podemos usar numeros con objetos(ObjNum * 10)
    Number<T> &operator/(const T &val2); //su funcion es la misma solo que en esta podemos usar numeros con objetos(ObjNum / 10)
    Number<T> &operator=(const T &val2); //su funcion es la misma solo que en esta podemos usar numeros con objetos(ObjNum = 10)

    /*Operadores booleanos*/
    //Operadores para objetos de la clase
    bool &operator<(const Number<T> &Val2) const;
    bool &operator>(const Number<T> &val2) const;
    bool &operator<=(const Number<T> &val2) const;
    bool &operator>=(const Number<T> &val2) const;
    bool &operator==(const Number<T> &val2) const;
    bool &operator!=(const Number<T> &val2) const;
    //Operadores para objetos de la clase y numeros
    bool operator<(const T &Val2) const;
    bool operator>(const T &val2) const;
    bool operator<=(const T &val2) const;
    bool operator>=(const T &val2) const;
    bool operator==(const T &val2) const;
    bool operator!=(const T &val2) const;

    virtual ~Number();
};
/*CONSTRUCTORES*/
template <class T>
Number<T>::Number(T value)
{ // Constructor base recibe un numero
    //Si el tipo de dato no es numerico se arroja un error
    if (sizeof(T) != sizeof(int) && sizeof(T) != sizeof(float) && sizeof(T) != sizeof(double) &&
        sizeof(T) != sizeof(short) && sizeof(T) != sizeof(long) && sizeof(T) != sizeof(long long) &&
        sizeof(T) != sizeof(short int) && sizeof(T) != sizeof(long int) && sizeof(T) != sizeof(long double))
        throw std::invalid_argument("The type is not a numeric type");

    this->value = value;
    this->valcopy = value;
}
template <class T>
Number<T>::Number()
{ //Constructor vacio
    //Si el tipo de dato no es numerico se arroja un error
    if (sizeof(T) != sizeof(int) && sizeof(T) != sizeof(float) && sizeof(T) != sizeof(double) &&
        sizeof(T) != sizeof(short) && sizeof(T) != sizeof(long) && sizeof(T) != sizeof(long long) &&
        sizeof(T) != sizeof(short int) && sizeof(T) != sizeof(long int) && sizeof(T) != sizeof(long double))
        throw std::invalid_argument("The type is not a numeric type");
}
template <class T>
Number<T>::Number(const Number<T> &Num)
{ //Recibe un objeto Numero y construye una copia del mismo
    this->value = Num.value;
    this->valcopy = Num.value;
}
/*METODOS*/
template <class T>
Number<T> &Number<T>::setvalue(T new_value)
{
    value = new_value;
    valcopy = new_value;
    return *this;
}
template <class T>
T Number<T>::getvalue()
{

    return this->value;
}
/*OPERADORES ARITMETICOS CON OBJETOS DE LA CLASE*/
template <class T>
Number<T> &Number<T>::operator+(const Number<T> &val2)
{
    this->value = this->value + val2.value;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator-(const Number<T> &val2)
{
    this->value = this->value - val2.value;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator*(const Number<T> &val2)
{
    this->value = this->value * val2.value;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator/(const Number<T> &val2)
{
    this->value = this->value / val2.value;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator=(const Number<T> &val2)
{
    this->value = val2.value;
    this->valcopy = val2.value;
    return *this;
}

/*OPERADORES ARITMETICOS CON NUMEROS*/
template <class T>
Number<T> &Number<T>::operator+(const T &val2)
{
    this->value = this->value + val2;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator-(const T &val2)
{
    this->value = this->value - val2;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator*(const T &val2)
{
    this->value = this->value * val2;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator/(const T &val2)
{
    this->value = this->value / val2;
    this->valcopy = this->value;
    return *this;
}
template <class T>
Number<T> &Number<T>::operator=(const T &val2)
{
    this->value = val2;
    this->valcopy = this->value;
    return *this;
}

/*OPERADORES BOOLEANOS CON OBJETOS DE LA CLASE*/
template <class T>
bool &Number<T>::operator<(const Number<T> &num2) const
{
    return this->value < num2.value;
}
template <class T>
bool &Number<T>::operator>(const Number<T> &num2) const
{
    return this->value > num2.value;
}
template <class T>
bool &Number<T>::operator<=(const Number<T> &num2) const
{
    return this->value <= num2.value;
}
template <class T>
bool &Number<T>::operator>=(const Number<T> &num2) const
{
    return this->value >= num2.value;
}
template <class T>
bool &Number<T>::operator==(const Number<T> &num2) const
{
    return this->value == num2.value;
}
template <class T>
bool &Number<T>::operator!=(const Number<T> &num2) const
{
    return this->value != num2.value;
}

/*OPERADORES BOOLEANOS CON NUMEROS*/
template <class T>
bool Number<T>::operator<(const T &num2) const
{
    return this->value < num2;
}
template <class T>
bool Number<T>::operator>(const T &num2) const
{
    return this->value > num2;
}
template <class T>
bool Number<T>::operator<=(const T &num2) const
{
    return this->value <= num2;
}
template <class T>
bool Number<T>::operator>=(const T &num2) const
{
    return this->value >= num2;
}
template <class T>
bool Number<T>::operator==(const T &num2) const
{
    return this->value == num2;
}
template <class T>
bool Number<T>::operator!=(const T &num2) const
{
    return this->value != num2;
}

template <class T>
Number<T>::~Number()
{
}

/*NUMEROS NATURALES*/
/*
La clase de los numeros naturales hereda las funciones de la clase Number
las cuales  se heredan como 'private' , heredando la clase Number como un 
Entero(int) sin signo.
*/
class Natural : private Number<unsigned long long>
{
public:
    /*Constructores*/
    Natural(long long Num);       //Constructor por valor
    Natural();                    //Constructor vacio
    Natural(const Natural &copy); //Constructor copia

    unsigned long long _value() const; //retorna el  valor del objeto

    void print();

    /*Operadores aritmeticos*/

    //Operadores con objetos de la misma clase
    Natural operator+(const Natural &Num2);
    Natural operator-(const Natural &Num2);
    Natural operator*(const Natural &Num2);
    Natural &operator=(const Natural &Num2);

    //Operadores para numeros simpre y cuando pertenezcan al conjunto de los naturales
    Natural operator+(const long long &Num2);
    Natural operator-(const long long &Num2);
    Natural operator*(const long long &Num2);
    Natural &operator=(const long long &Num2);

    long long operator()() const //retorna el valor del objeto
    {
        return this->value;
    }

    /*Operadores Booleanos*/
    //Operadores con objetos de la clase
    bool operator==(const Natural &Num2) const;
    bool operator!=(const Natural &Num2) const;
    bool operator<(const Natural &Num2) const;
    bool operator>(const Natural &Num2) const;
    bool operator<=(const Natural &Num2) const;
    bool operator>=(const Natural &Num2) const;

    bool operator==(const long long &Num2) const;
    bool operator!=(const long long &Num2) const;
    bool operator<(const long long &Num2) const;
    bool operator>(const long long &Num2) const;
    bool operator<=(const long long &Num2) const;
    bool operator>=(const long long &Num2) const;

    friend std::ostream &operator<<(std::ostream &os, const Natural &Num)
    {
        os << Num.value;
        return os;
    }

    ~Natural();
};

Natural::Natural(long long Num)
{
    if (Num < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    else //De lo contrario usando la clase Number  asignamos el valor
        this->setvalue(Num);
}

Natural::Natural()
{ //si no se inicializa el objeto el valor por default es 1
    this->setvalue(1);
}
Natural::Natural(const Natural &copy)
{ //Constructor copia(copia los datos de un Objeto de la misma clase)
    this->setvalue(copy.value);
}

unsigned long long Natural::_value() const
{
    return this->value;
}

void Natural::print()
{
    std::cout << this->value << std::endl;
}

Natural Natural::operator+(const Natural &Num2)
{ //Suma dos numeros naturales y retorna el resultado como un Natural
    Natural Resultado;
    Resultado.value = this->value + Num2.value;
    return Resultado;
}

Natural Natural::operator-(const Natural &Num2)
{ //Resta dos numeros naturales y retorna el resultado como un Natural
    Natural Resultado;
    Resultado.value = this->value - Num2.value;
    //Excepcion en caso de que la resta sea negativa
    return Resultado;
}

Natural Natural::operator*(const Natural &Num2)
{ //Multiplicacion dos numeros natures y retorna el resultado como un Natural
    Natural Resultado;
    Resultado.value = this->value * Num2.value;
    return Resultado;
}

Natural &Natural::operator=(const Natural &Num2)
{ //Asigna el valor de un Natural a otro(o el resultado de alguno de los operadores)
    this->value = Num2.value;
    return *this;
}

Natural Natural::operator+(const long long &Num2)
{ //Suma dos numeros naturales y retorna el resultado como un Natural

    if (Num2 < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    Natural Resultado;
    Resultado.value = this->value + Num2;
    return Resultado;
}

Natural Natural::operator-(const long long &Num2)
{ //Resta dos numeros naturales y retorna el resultado como un Natural

    if (Num2 < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    Natural Resultado;
    Resultado.value = this->value - Num2;
    //Excepcion en caso de que la resta sea negativa
    return Resultado;
}

Natural Natural::operator*(const long long &Num2)
{ //Multiplicacion dos numeros natures y retorna el resultado como un Natural

    if (Num2 < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    Natural Resultado;
    Resultado.value = this->value * Num2;
    return Resultado;
}

Natural &Natural::operator=(const long long &Num2)
{ //Asigna el valor de un Natural a otro(o el resultado de alguno de los operadores)

    if (Num2 < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    this->value = Num2;
    return *this;
}

bool Natural::operator==(const Natural &Num2) const
{
    return (this->value == Num2());
}

bool Natural::operator!=(const Natural &Num2) const
{
    return (this->value != Num2());
}

bool Natural::operator<(const Natural &Num2) const
{
    return (this->value < Num2());
}

bool Natural::operator>(const Natural &Num2) const
{
    return (this->value > Num2());
}

bool Natural::operator<=(const Natural &Num2) const
{
    return (this->value <= Num2());
}

bool Natural::operator>=(const Natural &Num2) const
{
    return (this->value >= Num2());
}

bool Natural::operator==(const long long &Num2) const
{
    return (this->value == Num2);
}

bool Natural::operator!=(const long long &Num2) const
{
    return (this->value != Num2);
}

bool Natural::operator<(const long long &Num2) const
{
    return (this->value < Num2);
}

bool Natural::operator>(const long long &Num2) const
{
    return (this->value > Num2);
}

bool Natural::operator<=(const long long &Num2) const
{
    return (this->value <= Num2);
}

bool Natural::operator>=(const long long &Num2) const
{
    return (this->value >= Num2);
}

Natural::~Natural()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    D << this->value << " N\n";
    D.close();
}

/*NUMEROS ENTEROS*/

/*
La clase entero de igual forma hereda como private las funciones de la clase
Number esta vez con un valor entero.
*/
class Entero : public Number<long long>
{

public:
    Entero(long long Value);    //Constructor por valor
    Entero(const Entero &Num2); //Constructor copia
    Entero(const Natural &N);
    Entero(); //Constructor vacio

    long long _value() const;
    int val();

    void print();

    Entero operator+(const Entero &Num2);  //Suma dos enteros y retorna el resultado como un Entero
    Entero operator-(const Entero &Num2);  //Resta dos enteros y retorna el resultado como un Entero
    Entero operator*(const Entero &Num2);  //Multiplica dos enteros y retorna el resultado como un Entero
    Entero &operator=(const Entero &Num2); //Asigna el valor de un Entero a otro( o el resultado de alguna operacion )

    Entero operator+(const Natural &Num2);  //Suma un entero y un natural y retorna el resultado como un Entero
    Entero operator-(const Natural &Num2);  //Resta un entero y un natural y retorna el resultado como un Entero
    Entero operator*(const Natural &Num2);  //Multiplica un entero y un natural y retorna el resultado como un Entero
    Entero &operator=(const Natural &Num2); //Asigna el valor de un Natural a un entero( o el resultado de alguna operacion )

    Entero operator+(const long long &Num2);  //Suma un entero y un numero(int) y retorna el resultado como un Entero
    Entero operator-(const long long &Num2);  //Resta un entero y un numero(int) y retorna el resultado como un Entero
    Entero operator*(const long long &Num2);  //Multiplicacion un entero y un numero(int) y retorna el resultado como un Entero
    Entero &operator=(const long long &Num2); //Asigna el valor de un numero(int) a un entero

    long long operator()() const //retorna el valor del objeto
    {
        return this->value;
    }

    /*Operadores Booleanos Con objetos de la clase*/
    bool operator!=(const Entero &Num2) const;
    bool operator==(const Entero &Num2) const;
    bool operator<(const Entero &Num2) const;
    bool operator>(const Entero &Num2) const;
    bool operator<=(const Entero &Num2) const;
    bool operator>=(const Entero &Num2) const;

    bool operator!=(const Natural &Num2) const;
    bool operator==(const Natural &Num2) const;
    bool operator<(const Natural &Num2) const;
    bool operator>(const Natural &Num2) const;
    bool operator<=(const Natural &Num2) const;
    bool operator>=(const Natural &Num2) const;
    /*Operadores Booleanos Con numeros(int) */
    bool operator!=(const long long &Num2) const;
    bool operator==(const long long &Num2) const;
    bool operator<(const long long &Num2) const;
    bool operator>(const long long &Num2) const;
    bool operator<=(const long long &Num2) const;
    bool operator>=(const long long &Num2) const;

    friend std::ostream &operator<<(std::ostream &os, const Entero &Num)
    {
        os << Num.value;
        return os;
    }

    ~Entero();
};

Entero::Entero(long long Value)
{
    this->value = Value;
}
Entero::Entero(const Entero &Num2)
{
    this->value = Num2.value;
}
Entero::Entero(const Natural &N)
{
    this->value = N();
}
Entero::Entero()
{
    this->value = 0;
}

long long Entero::_value() const
{
    return this->value;
}

int Entero::val()
{
    return this->value;
}

void Entero::print()
{
    std::cout << this->value << std::endl;
}

Entero Entero::operator+(const Entero &Num2)
{
    Entero Result;
    Result.value = this->value + Num2.value;
    return Result;
}
Entero Entero::operator-(const Entero &Num2)
{
    Entero Result;

    Result.value = this->value - Num2.value;
    return Result;
}
Entero Entero::operator*(const Entero &Num2)
{
    Entero Result;

    Result.value = this->value * Num2.value;
    return Result;
}
Entero &Entero::operator=(const Entero &Num2)
{
    this->value = Num2.value;
    return *this;
}

Entero Entero::operator+(const Natural &Num2)
{
    Entero Result;
    Result.value = this->value + Num2();
    return Result;
}
Entero Entero::operator-(const Natural &Num2)
{
    Entero Result;

    Result.value = this->value - Num2();
    return Result;
}
Entero Entero::operator*(const Natural &Num2)
{
    Entero Result;
    Result.value = this->value * Num2();
    return Result;
}
Entero &Entero::operator=(const Natural &Num2)
{
    this->value = Num2();
    return *this;
}

Entero Entero::operator+(const long long &Num2)
{
    Entero Result;

    Result.value = this->value + Num2;
    return Result;
}
Entero Entero::operator-(const long long &Num2)
{
    Entero Result;

    Result.value = this->value - Num2;
    return Result;
}
Entero Entero::operator*(const long long &Num2)
{
    Entero Result;

    Result.value = this->value * Num2;
    return Result;
}
Entero &Entero::operator=(const long long &Num2)
{
    this->value = Num2;
    return *this;
}

bool Entero::operator==(const Entero &Num2) const
{
    return (this->value == Num2.value);
}
bool Entero::operator!=(const Entero &Num2) const
{
    return (this->value != Num2.value);
}
bool Entero::operator<(const Entero &Num2) const
{
    return (this->value < Num2.value);
}
bool Entero::operator>(const Entero &Num2) const
{
    return (this->value > Num2.value);
}
bool Entero::operator<=(const Entero &Num2) const
{
    return (this->value <= Num2.value);
}
bool Entero::operator>=(const Entero &Num2) const
{
    return (this->value >= Num2.value);
}

bool Entero::operator==(const Natural &Num2) const
{
    return (this->value == Num2());
}
bool Entero::operator!=(const Natural &Num2) const
{
    return (this->value != Num2());
}
bool Entero::operator<(const Natural &Num2) const
{
    return (this->value < Num2());
}
bool Entero::operator>(const Natural &Num2) const
{
    return (this->value > Num2());
}
bool Entero::operator<=(const Natural &Num2) const
{
    return (this->value <= Num2());
}
bool Entero::operator>=(const Natural &Num2) const
{
    return (this->value >= Num2());
}

bool Entero::operator==(const long long &Num2) const
{
    return (this->value == Num2);
}
bool Entero::operator!=(const long long &Num2) const
{
    return (this->value != Num2);
}
bool Entero::operator<(const long long &Num2) const
{
    return (this->value < Num2);
}
bool Entero::operator>(const long long &Num2) const
{
    return (this->value > Num2);
}
bool Entero::operator<=(const long long &Num2) const
{
    return (this->value <= Num2);
}
bool Entero::operator>=(const long long &Num2) const
{
    return (this->value >= Num2);
}

Entero::~Entero()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    D << this->value << " Z\n";
    D.close();
}

class Racional : private Number<long long>
{
private:
    Entero Numerador;
    Entero Denominador;

public:
    Racional(long long Num, long long Den);
    Racional(const Racional &N2);
    Racional(const Entero &E);
    Racional(const Natural &N);
    Racional();
    //Metodos de la clase Racional
    void simplify(); //Simplifica el numero racional si no es simplificable el numero no se modifica
    void print();

    Racional operator+(const Racional &R2);
    Racional operator-(const Racional &R2);
    Racional operator*(const Racional &R2);
    Racional &operator=(const Racional &R2);

    Racional operator+(const Entero &R2);
    Racional operator-(const Entero &R2);
    Racional operator*(const Entero &R2);
    Racional &operator=(const Entero &R2);

    Racional operator+(const Natural &R2);
    Racional operator-(const Natural &R2);
    Racional operator*(const Natural &R2);
    Racional &operator=(const Natural &R2);

    Racional operator+(const long long &R2);
    Racional operator-(const long long &R2);
    Racional operator*(const long long &R2);
    Racional &operator=(const long long &R2);

    long double operator()() const //retorna el valor del objeto como un real
    {
        return this->Numerador() / this->Denominador();
    }

    bool operator==(const Racional &R2) const;
    bool operator!=(const Racional &R2) const;
    bool operator<(const Racional &R2) const;
    bool operator>(const Racional &R2) const;
    bool operator<=(const Racional &R2) const;
    bool operator>=(const Racional &R2) const;

    bool operator==(const Entero &R2) const;
    bool operator!=(const Entero &R2) const;
    bool operator<(const Entero &R2) const;
    bool operator>(const Entero &R2) const;
    bool operator<=(const Entero &R2) const;
    bool operator>=(const Entero &R2) const;

    bool operator==(const Natural &R2) const;
    bool operator!=(const Natural &R2) const;
    bool operator<(const Natural &R2) const;
    bool operator>(const Natural &R2) const;
    bool operator<=(const Natural &R2) const;
    bool operator>=(const Natural &R2) const;

    bool operator==(const long long &R2) const;
    bool operator!=(const long long &R2) const;
    bool operator<(const long long &R2) const;
    bool operator>(const long long &R2) const;
    bool operator<=(const long long &R2) const;
    bool operator>=(const long long &R2) const;

    friend std::ostream &operator<<(std::ostream &os, const Racional &Num)
    {
        os << Num.Numerador << '/' << Num.Denominador;
        return os;
    }

    virtual ~Racional();
};

Racional::Racional(long long Num, long long Den)
{
    if (Den == 0)
        throw std::invalid_argument("El denominador no puede ser 0");
    this->Numerador = Num;
    this->Denominador = Den;
}

Racional::Racional(const Racional &N2)
{
    this->Numerador = N2.Numerador;
    this->Denominador = N2.Denominador;
}

Racional::Racional(const Entero &E)
{
    this->Numerador = E();
    this->Denominador = 1;
}

Racional::Racional(const Natural &N)
{
    this->Numerador = N();
    this->Denominador = 1;
}

Racional::Racional()
{
    this->Numerador = 1;
    this->Denominador = 1;
}

void Racional::simplify()
{
    bool is_simplifying = false;
    if (this->Numerador == this->Denominador)
    {
        this->Numerador = 1;
        this->Denominador = 1;
        return;
    }
    else
    {
        for (int i = 2; i < this->Numerador.val() + 1; i++)
        {
            if (this->Numerador() % i == 0)
            {
                if (this->Denominador() % i == 0)
                {
                    this->Numerador = this->Numerador() / i;
                    this->Denominador = this->Denominador() / i;
                    is_simplifying = true;
                    break;
                }
            }
        }
        if (!is_simplifying)
            return;
        else
            this->simplify();
    }
}

void Racional::print()
{
    if (this->Numerador == this->Denominador || this->Denominador == 1)
    { //Si el numerador y el denominador son el mismo o el denominador es igual a uno imprimos el numero Entero
        std::cout << this->Numerador() << std::endl;
    }
    else
    {
        std::cout << this->Numerador() << " / " << this->Denominador() << std::endl;
    }
}

Racional Racional::operator+(const Racional &R2)
{
    Racional Result;

    if (this->Denominador == R2.Denominador)
    {
        Result.Numerador = this->Numerador + R2.Numerador;
        Result.Denominador = this->Denominador;
    }
    else
    {
        Result.Numerador = (this->Numerador * R2.Denominador) + (this->Denominador * R2.Numerador);
        Result.Denominador = this->Denominador * R2.Denominador;
    }
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const Racional &R2)
{
    Racional Result;

    if (this->Denominador == R2.Denominador)
    {
        Result.Numerador = this->Numerador + R2.Numerador;
        Result.Denominador = this->Denominador;
    }
    else
    {
        Result.Numerador = (this->Numerador * R2.Denominador) - (this->Denominador * R2.Numerador);
        Result.Denominador = this->Denominador * R2.Denominador;
    }
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const Racional &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2.Numerador;
    Result.Denominador = this->Denominador * R2.Denominador;
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const Racional &R2)
{
    this->Numerador = R2.Numerador;
    this->Denominador = R2.Denominador;
    return *this;
}

Racional Racional::operator+(const Entero &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2() / R2())) + (this->Denominador * R2());
    Result.Denominador = this->Denominador * (R2() / R2());

    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const Entero &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2() / R2())) - (this->Denominador * R2());
    Result.Denominador = this->Denominador * (R2() / R2());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const Entero &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2();
    Result.Denominador = this->Denominador * (R2() / R2());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const Entero &R2)
{
    this->Numerador = R2();
    this->Denominador = (R2() / R2());
    return *this;
}

Racional Racional::operator+(const Natural &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2() / R2())) + (this->Denominador * R2());
    Result.Denominador = this->Denominador * (R2() / R2());

    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const Natural &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2() / R2())) - (this->Denominador * R2());
    Result.Denominador = this->Denominador * (R2() / R2());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const Natural &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2();
    Result.Denominador = this->Denominador * (R2() / R2());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const Natural &R2)
{
    this->Numerador = R2();
    this->Denominador = (R2() / R2());
    return *this;
}

Racional Racional::operator+(const long long &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2 / R2)) + (this->Denominador * R2);
    Result.Denominador = this->Denominador * (R2 / R2);

    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const long long &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2 / R2)) - (this->Denominador * R2);
    Result.Denominador = this->Denominador * (R2 / R2);
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const long long &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2;
    Result.Denominador = this->Denominador * (R2 / R2);
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const long long &R2)
{
    this->Numerador = R2;
    this->Denominador = (R2 / R2);
    return *this;
}

bool Racional::operator==(const Racional &R2) const
{
    return (this->Denominador == R2.Denominador && this->Numerador == R2.Numerador);
}
bool Racional::operator!=(const Racional &R2) const
{
    return (this->Denominador != R2.Denominador && this->Numerador != R2.Numerador);
}
bool Racional::operator<(const Racional &R2) const
{
    return (this->Numerador._value() / this->Denominador._value() < R2.Numerador._value() / R2.Denominador._value());
}
bool Racional::operator>(const Racional &R2) const
{
    return (this->Numerador._value() / this->Denominador._value() > R2.Numerador._value() / R2.Denominador._value());
}
bool Racional::operator<=(const Racional &R2) const
{
    return (this->Numerador._value() / this->Denominador._value() <= R2.Numerador._value() / R2.Denominador._value());
}
bool Racional::operator>=(const Racional &R2) const
{
    return (this->Numerador._value() / this->Denominador._value() >= R2.Numerador._value() / R2.Denominador._value());
}

Racional::~Racional()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    D << this->Numerador << "/" << this->Denominador << " Q\n";
    D.close();
}

class Irracional : private Number<long double>
{
private:
    std::string num; //para imprir el caracter
    std::string N;

public:
    Irracional(std::string nombre);
    Irracional(const Irracional &I2);
    Irracional();

    long double operator()() const //retorna el valor del objeto
    {
        return this->value;
    }

    bool operator==(const Irracional &I2) const;
    bool operator!=(const Irracional &I2) const;
    bool operator<(const Irracional &I2) const;
    bool operator>(const Irracional &I2) const;
    bool operator<=(const Irracional &I2) const;
    bool operator>=(const Irracional &I2) const;

    void print();

    friend std::ostream &operator<<(std::ostream &os, const Irracional &Num)
    {
        os << Num.num;
        return os;
    }
    ~Irracional();
};

Irracional::Irracional(std::string nombre)
{

    std::for_each(nombre.begin(), nombre.end(), [](char &c) { c = std::tolower(c); });

    this->N = nombre;

    if (N == "pi" || N == "p")
    {
        this->num = "╔╗";
        this->value = M_PI;
    }
    else if (N == "e")
    {
        this->num = "e";
        this->value = M_E;
    }
    else if (N == "sr2" || N == "s2" || N == "r2" || N == "sqrt2")
    {
        this->value = M_SQRT2;
        this->num = "_|2";
    }
    else if (N == "phi")
    {
        this->num = "Ø";
        this->value = 1.61803398874989;
    }
}
Irracional::Irracional(const Irracional &I2)
{
    this->N = I2.N;
    this->num = I2.num;
    this->value = I2.value;
}
Irracional::Irracional()
{ //Si no se inicializa el constructor el numero por default es PI
    this->num = "╔╗";
    this->value = M_PI;
    this->N = "pi";
}

void Irracional::print()
{
    std::cout << this->num << std::endl;
}

bool Irracional::operator==(const Irracional &I2) const
{
    return (this->value == I2.value);
}

bool Irracional::operator!=(const Irracional &I2) const
{
    return (this->value != I2.value);
}

bool Irracional::operator<(const Irracional &I2) const
{
    return (this->value < I2.value);
}

bool Irracional::operator>(const Irracional &I2) const
{
    return (this->value > I2.value);
}

bool Irracional::operator<=(const Irracional &I2) const
{
    return (this->value <= I2.value);
}

bool Irracional::operator>=(const Irracional &I2) const
{
    return (this->value >= I2.value);
}

Irracional::~Irracional()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    D << this->num << " I\n";
    D.close();
}

class Real : public Number<long double>
{
private:
    long double _pot(int k);

public:
    Real(long double Rvalue);
    Real(const Real &R2);
    Real(const Natural &N);
    Real(const Entero &E);
    Real(const Racional &R);
    Real(const Irracional &R);
    Real();

    long double nroot(int k); //Calcula la raiz n-esima y retorna el resultado
    void root(int k);         //Calcula la raiz n-esima y asigna el resultado al objeto que se le aplico la funcion
    long double potencia(int k);
    void print();

    Real operator+(const Real &Num2);
    Real operator-(const Real &Num2);
    Real operator*(const Real &Num2);
    Real operator/(const Real &Num2);
    Real &operator=(const Real &Num2);
    Real operator^(const Real &Num2);

    Real operator+(const Natural &Num2);
    Real operator-(const Natural &Num2);
    Real operator*(const Natural &Num2);
    Real operator/(const Natural &Num2);
    Real &operator=(const Natural &Num2);

    Real operator+(const Entero &Num2);
    Real operator-(const Entero &Num2);
    Real operator*(const Entero &Num2);
    Real operator/(const Entero &Num2);
    Real &operator=(const Entero &Num2);

    Real operator+(const Racional &Num2);
    Real operator-(const Racional &Num2);
    Real operator*(const Racional &Num2);
    Real operator/(const Racional &Num2);
    Real &operator=(const Racional &Num2);

    Real operator+(const Irracional &Num2);
    Real operator-(const Irracional &Num2);
    Real operator*(const Irracional &Num2);
    Real operator/(const Irracional &Num2);
    Real &operator=(const Irracional &Num2);

    Real operator+(const long double &Num2);
    Real operator-(const long double &Num2);
    Real operator*(const long double &Num2);
    Real operator/(const long double &Num2);
    Real &operator=(const long double &Num2);

    long double operator()() const //retorna el valor del objeto
    {
        return this->value;
    }

    bool operator==(const Real &Num2) const;
    bool operator!=(const Real &Num2) const;
    bool operator<(const Real &Num2) const;
    bool operator>(const Real &Num2) const;
    bool operator<=(const Real &Num2) const;
    bool operator>=(const Real &Num2) const;

    bool operator==(const Natural &Num2) const;
    bool operator!=(const Natural &Num2) const;
    bool operator<(const Natural &Num2) const;
    bool operator>(const Natural &Num2) const;
    bool operator<=(const Natural &Num2) const;
    bool operator>=(const Natural &Num2) const;

    bool operator==(const Entero &Num2) const;
    bool operator!=(const Entero &Num2) const;
    bool operator<(const Entero &Num2) const;
    bool operator>(const Entero &Num2) const;
    bool operator<=(const Entero &Num2) const;
    bool operator>=(const Entero &Num2) const;

    bool operator==(const Racional &Num2) const;
    bool operator!=(const Racional &Num2) const;
    bool operator<(const Racional &Num2) const;
    bool operator>(const Racional &Num2) const;
    bool operator<=(const Racional &Num2) const;
    bool operator>=(const Racional &Num2) const;

    bool operator==(const Irracional &Num2) const;
    bool operator!=(const Irracional &Num2) const;
    bool operator<(const Irracional &Num2) const;
    bool operator>(const Irracional &Num2) const;
    bool operator<=(const Irracional &Num2) const;
    bool operator>=(const Irracional &Num2) const;

    bool operator==(const long double &Num2) const;
    bool operator!=(const long double &Num2) const;
    bool operator<(const long double &Num2) const;
    bool operator>(const long double &Num2) const;
    bool operator<=(const long double &Num2) const;
    bool operator>=(const long double &Num2) const;

    friend std::ostream &operator<<(std::ostream &os, const Real &Num)
    {
        os << Num();
        return os;
    }

    virtual ~Real();
};

Real::Real(long double Rvalue)
{
    this->value = Rvalue;
}
Real::Real(const Real &R2)
{
    this->value = R2.value;
}
Real::Real(const Natural &N)
{
    this->value = N();
}
Real::Real(const Entero &E)
{
    this->value = E();
}
Real::Real(const Racional &R)
{
    this->value = R();
}
Real::Real()
{
    this->value = 0;
}
void Real::print()
{
    std::cout << this->value << std::endl;
}

long double Real::_pot(int k)
{
    if (k == 0)
        return 1;
    else if (k == 1)
        return this->value;
    else
        return this->_pot(k - 1) * this->value;
}

long double Real::potencia(int k)
{
    long double result;
    if (k >= 0)
        result = this->_pot(k);
    else
        result = 1 / this->_pot(-(k));

    return result;
}

long double Real::nroot(int k)
{
    double exp = 1 / k;
    long double res = std::pow(this->value, exp);
    return res;
}

void Real::root(int k)
{
    this->value = this->nroot(k);
}

Real Real::operator+(const Real &Num2)
{
    Real Result;

    Result.value = this->value + Num2();

    return Result;
}
Real Real::operator-(const Real &Num2)
{
    Real Result;

    Result.value = this->value - Num2();

    return Result;
}
Real Real::operator*(const Real &Num2)
{
    Real Result;

    Result.value = this->value * Num2();

    return Result;
}
Real Real::operator/(const Real &Num2)
{
    if (Num2.value == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2();

    return Result;
}
Real &Real::operator=(const Real &Num2)
{

    this->value = Num2();

    return *this;
}

Real Real::operator+(const Natural &Num2)
{
    Real Result;

    Result.value = this->value + Num2();

    return Result;
}
Real Real::operator-(const Natural &Num2)
{
    Real Result;

    Result.value = this->value - Num2();

    return Result;
}
Real Real::operator*(const Natural &Num2)
{
    Real Result;

    Result.value = this->value * Num2();

    return Result;
}
Real Real::operator/(const Natural &Num2)
{
    Real Result;

    Result.value = this->value / Num2();

    return Result;
}
Real &Real::operator=(const Natural &Num2)
{

    this->value = Num2();

    return *this;
}

Real Real::operator+(const Entero &Num2)
{
    Real Result;

    Result.value = this->value + Num2();

    return Result;
}
Real Real::operator-(const Entero &Num2)
{
    Real Result;

    Result.value = this->value - Num2();

    return Result;
}
Real Real::operator*(const Entero &Num2)
{
    Real Result;

    Result.value = this->value * Num2();

    return Result;
}
Real Real::operator/(const Entero &Num2)
{
    if (Num2() == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2();

    return Result;
}
Real &Real::operator=(const Entero &Num2)
{

    this->value = Num2();

    return *this;
}

Real Real::operator+(const Racional &Num2)
{
    Real Result;

    Result.value = this->value + Num2();

    return Result;
}
Real Real::operator-(const Racional &Num2)
{
    Real Result;

    Result.value = this->value - Num2();

    return Result;
}
Real Real::operator*(const Racional &Num2)
{
    Real Result;

    Result.value = this->value * Num2();

    return Result;
}
Real Real::operator/(const Racional &Num2)
{
    if (Num2() == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2();

    return Result;
}
Real &Real::operator=(const Racional &Num2)
{

    this->value = Num2();

    return *this;
}

Real Real::operator+(const Irracional &Num2)
{
    Real Result;

    Result.value = this->value + Num2();

    return Result;
}
Real Real::operator-(const Irracional &Num2)
{
    Real Result;

    Result.value = this->value - Num2();

    return Result;
}
Real Real::operator*(const Irracional &Num2)
{
    Real Result;

    Result.value = this->value * Num2();

    return Result;
}
Real Real::operator/(const Irracional &Num2)
{
    if (Num2() == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2();

    return Result;
}
Real &Real::operator=(const Irracional &Num2)
{

    this->value = Num2();

    return *this;
}

Real Real::operator+(const long double &Num2)
{
    Real Result;

    Result.value = this->value + Num2;

    return Result;
}
Real Real::operator-(const long double &Num2)
{
    Real Result;

    Result.value = this->value - Num2;

    return Result;
}
Real Real::operator*(const long double &Num2)
{
    Real Result;

    Result.value = this->value * Num2;

    return Result;
}
Real Real::operator/(const long double &Num2)
{
    if (Num2 == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2;

    return Result;
}
Real &Real::operator=(const long double &Num2)
{

    this->value = Num2;

    return *this;
}

bool Real::operator==(const Real &Num2) const
{
    return (this->value == Num2());
}
bool Real::operator!=(const Real &Num2) const
{
    return (this->value != Num2());
}
bool Real::operator<(const Real &Num2) const
{
    return (this->value < Num2());
}
bool Real::operator>(const Real &Num2) const
{
    return (this->value > Num2());
}
bool Real::operator<=(const Real &Num2) const
{
    return (this->value <= Num2());
}
bool Real::operator>=(const Real &Num2) const
{
    return (this->value >= Num2());
}

bool Real::operator==(const Natural &Num2) const
{
    return (this->value == Num2());
}
bool Real::operator!=(const Natural &Num2) const
{
    return (this->value != Num2());
}
bool Real::operator<(const Natural &Num2) const
{
    return (this->value < Num2());
}
bool Real::operator>(const Natural &Num2) const
{
    return (this->value > Num2());
}
bool Real::operator<=(const Natural &Num2) const
{
    return (this->value <= Num2());
}
bool Real::operator>=(const Natural &Num2) const
{
    return (this->value >= Num2());
}

bool Real::operator==(const Entero &Num2) const
{
    return (this->value == Num2());
}
bool Real::operator!=(const Entero &Num2) const
{
    return (this->value != Num2());
}
bool Real::operator<(const Entero &Num2) const
{
    return (this->value < Num2());
}
bool Real::operator>(const Entero &Num2) const
{
    return (this->value > Num2());
}
bool Real::operator<=(const Entero &Num2) const
{
    return (this->value <= Num2());
}
bool Real::operator>=(const Entero &Num2) const
{
    return (this->value >= Num2());
}

bool Real::operator==(const Racional &Num2) const
{
    return (this->value == Num2());
}
bool Real::operator!=(const Racional &Num2) const
{
    return (this->value != Num2());
}
bool Real::operator<(const Racional &Num2) const
{
    return (this->value < Num2());
}
bool Real::operator>(const Racional &Num2) const
{
    return (this->value > Num2());
}
bool Real::operator<=(const Racional &Num2) const
{
    return (this->value <= Num2());
}
bool Real::operator>=(const Racional &Num2) const
{
    return (this->value >= Num2());
}

bool Real::operator==(const Irracional &Num2) const
{
    return (this->value == Num2());
}
bool Real::operator!=(const Irracional &Num2) const
{
    return (this->value != Num2());
}
bool Real::operator<(const Irracional &Num2) const
{
    return (this->value < Num2());
}
bool Real::operator>(const Irracional &Num2) const
{
    return (this->value > Num2());
}
bool Real::operator<=(const Irracional &Num2) const
{
    return (this->value <= Num2());
}
bool Real::operator>=(const Irracional &Num2) const
{
    return (this->value >= Num2());
}

bool Real::operator==(const long double &Num2) const
{
    return (this->value == Num2);
}
bool Real::operator!=(const long double &Num2) const
{
    return (this->value != Num2);
}
bool Real::operator<(const long double &Num2) const
{
    return (this->value < Num2);
}
bool Real::operator>(const long double &Num2) const
{
    return (this->value > Num2);
}
bool Real::operator<=(const long double &Num2) const
{
    return (this->value <= Num2);
}
bool Real::operator>=(const long double &Num2) const
{
    return (this->value >= Num2);
}

Real::~Real()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    D << this->value << " R\n";
    D.close();
}

class Complejo : private Number<long double>
{
private:
    signed long long Ivalue;

public:
    Complejo(long double realPart, long long imaginaryPart);
    Complejo(const Complejo &C2);
    Complejo();

    Complejo conj(); //retorna el conjugado

    void print();

    Complejo operator+(const Complejo &C2);
    Complejo operator-(const Complejo &C2);
    Complejo operator*(const Complejo &C2);
    Complejo operator/(const Complejo &C2);
    Complejo &operator=(const Complejo &C2);

    long double operator()() const
    { //retorna el valor real del complejo
        return this->value;
    }

    friend std::ostream &operator<<(std::ostream &os, const Complejo &Num)
    {
        if (Num.Ivalue < 0)
            os << Num() << Num.Ivalue;
        else
            os << Num() << "+" << Num.Ivalue << "i";
        return os;
    }

    ~Complejo();
};

Complejo::Complejo(long double realPart, signed long long imaginaryPart)
{
    this->value = realPart;
    this->Ivalue = imaginaryPart;
}

Complejo::Complejo(const Complejo &C2)
{
    this->value = C2.value;
    this->Ivalue = C2.Ivalue;
}

Complejo::Complejo()
{
    this->value = 0;
    this->Ivalue = 0;
}

Complejo Complejo::conj()
{
    Complejo result;

    result.value = this->value;
    result.Ivalue = -(this->Ivalue);

    return result;
}

void Complejo::print()
{

    if (this->Ivalue < 0)
        std::cout << this->value << this->Ivalue << "i" << std::endl;
    else
        std::cout << this->value << "+" << this->Ivalue << "i" << std::endl;
}

Complejo Complejo::operator+(const Complejo &C2)
{
    Complejo result;
    result.value = this->value + C2.value;
    result.Ivalue = this->Ivalue + C2.Ivalue;

    return result;
}

Complejo Complejo::operator-(const Complejo &C2)
{
    Complejo result;
    result.value = this->value - C2.value;
    result.Ivalue = this->Ivalue - C2.Ivalue;

    return result;
}

Complejo Complejo::operator*(const Complejo &C2)
{
    Complejo result;

    result.value = (((this->value * C2.value) - (this->Ivalue * C2.Ivalue)));
    result.Ivalue = (((this->value * C2.Ivalue) + (this->Ivalue * C2.value)));

    return result;
}

Complejo Complejo::operator/(const Complejo &C2)
{
    Complejo result;
    result.value = ((this->value * C2.value) + (this->Ivalue * C2.Ivalue)) / (C2.value * C2.value) + (C2.Ivalue * C2.Ivalue);
    result.Ivalue = ((this->Ivalue * C2.value) + (this->value * C2.Ivalue)) / (C2.value * C2.value) + (C2.Ivalue * C2.Ivalue);
    return result;
}

Complejo &Complejo::operator=(const Complejo &C2)
{
    this->value = C2.value;
    this->Ivalue = C2.Ivalue;
    return *this;
}

Complejo::~Complejo()
{
    std::ofstream D;

    D.open("NUMEROS.txt", std::ios_base::app);

    if (this->Ivalue < 0)
        D << this->value << this->Ivalue << "i C\n";
    else
        D << this->value << "+" << this->Ivalue << "i C\n";
    D.close();
}

template <class type>
class Matriz
{
private:
    type **Mat;
    int filas;
    int columnas;

    inline Matriz<type> ExtractMat(type **Mat, int sz, int F, int C); //funcion para el Determinate
    type Det(type **Mat, int sz);                                     //Calcula el determinante por cofactores

    type brackethelp(type *fila, int col); //funcion de ayuda para el operador corche
    int brcketaux, bracketaux2;            //variables auxiliares para indices en corchetes

public:
    Matriz(const type init, int filas, int columnas); //Para cualquier Matriz inicializada
    Matriz(int filas, int columnas);                  //Para cualquier Matriz
    Matriz(int size);                                 //Para Matrices cuadradas
    Matriz();                                         //Constructor vacio

    Matriz &resize(int filas, int columnas); //Redimensionar Matriz sin perder los datos

    void print(); //Imprimir la matriz

    type Determinante(); //Devuelve el determinante de la matriz

    Matriz<type> transp(); //Devuelve la transpuesta de la matriz
    Matriz<type> adj();    //devuelve la adjunta de la matriz

    Matriz<type> inversa(); //Retorna la inversa de una matriz (mediante la ajunta de la matriz)

    Matriz<type> operator+(const Matriz<type> &Mat2);  //Suma de matrices
    Matriz<type> operator-(const Matriz<type> &Mat2);  //Resta de matrices
    Matriz<type> operator*(const Matriz<type> &Mat2);  //Multiplicacion de matrices
    Matriz<type> &operator=(const Matriz<type> &Mat2); //Operador de asignacion

    type *operator[](const int index);        //Operador corchete para filas
    type operator[](short int index2);        //Operador corchete para columnas
    Matriz<type> &operator=(const type Data); //Para asignar valor a las casillas de la matriz

    ~Matriz();
};

template <class type>
Matriz<type>::Matriz(int filas, int columnas)
{
    this->Mat = new type *[filas];

    for (int i = 0; i < filas; i++)
    {
        this->Mat[i] = new type[columnas];
    }
    this->filas = filas;
    this->columnas = columnas;
}

template <class type>
Matriz<type>::Matriz(int size)
{
    this->Mat = new type *[size];

    for (int i = 0; i < size; i++)
    {
        this->Mat[i] = new type[size];
    }
    this->filas = size;
    this->columnas = size;
}

template <class type>
Matriz<type>::Matriz(const type init, int filas, int columnas)
{
    this->Mat = new type *[filas];

    for (int i = 0; i < filas; i++)
    {
        this->Mat[i] = new type[columnas];
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            this->Mat[i][j] = init;
        }
    }

    this->filas = filas;
    this->columnas = columnas;
}

template <class type>
Matriz<type>::Matriz()
{
    this->Mat = NULL;
    this->filas = 0;
    this->columnas = 0;
}

template <class type>
Matriz<type> &Matriz<type>::resize(int filas, int columnas)
{
    type **newMat;

    newMat = new type *[filas];

    for (int i = 0; i < filas; i++)
    {
        newMat[i] = new type[columnas];
    }

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            if (i < this->filas && j < this->columnas)
                newMat[i][j] = this->Mat[i][j];
        }
    }

    this->Mat = newMat;
    this->filas = filas;
    this->columnas = columnas;

    return *this;
}

template <class type>
inline Matriz<type> Matriz<type>::ExtractMat(type **Mat, int sz, int F, int C)
{
    Matriz<type> result(sz - 1, sz - 1);
    int k = 0, l = 0;

    for (int i = 0; i < sz; i++)
    {
        l = 0;
        for (int j = 0; j < sz; j++)
        {
            if (i != F && j != C)
            { //Si no estamos en la fila y la columna que se van a eliminar asignamos
                //el valor en esa posicion al valor k,l de la matriz resultado
                result.Mat[k][l] = Mat[i][j];
                l++; //iteramos las columnas de la matriz resultado
            }
        }
        if (i != F) //si no estamos en la fila que se va a eliminar iteramos k
            k++;    //iteramos las filas de la matriz resultado
    }

    return result;
}

template <class type>
type Matriz<type>::Det(type **Mat, int sz)
{
    Matriz<type> res(sz - 1, sz - 1);
    type detval = 0;

    type dt;

    if (sz == 2)
    {
        detval = ((Mat[0][0] * Mat[1][1]) - (Mat[0][1] * Mat[1][0]));
        return detval;
    }
    else
    {
        for (int i = 0; i < sz; i++)
        {
            res = this->ExtractMat(Mat, sz, 0, i);

            dt = this->Det(res.Mat, sz - 1);

            if (i % 2 == 0)
            {
                detval += Mat[i][0] * dt;
            }
            else
            {
                detval += -(Mat[i][0] * dt);
            }
        }
        return detval;
    }
}

template <class type>
type Matriz<type>::Determinante()
{
    if (this->filas != this->columnas)
        throw std::invalid_argument("La matriz no es cuadrada");

    return this->Det(this->Mat, this->filas);
}

template <class type>
Matriz<type> Matriz<type>::transp()
{
    Matriz<type> T(this->columnas, this->filas);

    for (int i = 0; i < this->columnas; i++)
    {
        for (int j = 0; j < this->filas; j++)
        {
            T.Mat[i][j] = this->Mat[j][i];
        }
    }

    return T;
}

template <class type>
Matriz<type> Matriz<type>::adj()
{
    Matriz<type> AD(this->filas, this->columnas);
    Matriz<type> aux(this->filas - 1, this->columnas - 1);

    for (int i = 0; i < this->columnas; i++)
    {

        for (int j = 0; j < this->filas; j++)
        {
            aux = this->ExtractMat(this->Mat, this->filas, i, j);
            if (((i + 1) + (j + 1)) % 2 == 0)
            {
                AD.Mat[i][j] = aux.Determinante();
            }
            else
            {
                AD.Mat[i][j] = -(aux.Determinante());
            }
        }
    }

    return AD;
}

template <class type>
Matriz<type> Matriz<type>::inversa()
{ /*Calculamos la inversa sabiendo que la inversa de una matriz A es:
            trans(adj(A))
    inv(A)= -------------
                |A|
    Donde |A| representa el determiante de la matriz.
    (la  Inversa  de  la  matriz  solo es  aplicable  apartir  del  conjuto 
    de los numeros reales(Naturales, Enteros, Racionales e Irracionales no))
*/
    if (this->Determinante() == 0)
        throw std::invalid_argument("La matriz no tiene inversa(Determinante igual a 0\n");

    Matriz<type> Inv, aux;

    type det = this->Determinante();

    aux = this->adj();

    Inv = aux.transp();

    for (int i = 0; i < Inv.filas; i++)
    {
        for (int j = 0; j < Inv.columnas; j++)
        {
            Inv.Mat[i][j] = Inv.Mat[i][j] / det;
        }
    }

    return Inv;
}

template <class type>
void Matriz<type>::print()
{
    if (Mat == NULL)
        throw std::invalid_argument("La Matriz est de tamano 0\n");

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            std::cout << this->Mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <class type>
Matriz<type> Matriz<type>::operator+(const Matriz<type> &Mat2)
{
    if (this->filas != Mat2.filas || this->columnas != Mat2.columnas)
        throw std::invalid_argument("Las Matrices no tienen el mismo tamano\n");
    Matriz<type> Result(this->filas, this->columnas);

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            Result.Mat[i][j] = this->Mat[i][j] + Mat2.Mat[i][j];
        }
    }

    return Result;
}

template <class type>
Matriz<type> Matriz<type>::operator-(const Matriz<type> &Mat2)
{
    if (this->filas != Mat2.filas || this->columnas != Mat2.columnas)
        throw std::invalid_argument("Las Matrices no tienen el mismo tamano\n");
    Matriz<type> Result(this->filas, this->columnas);

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            Result.Mat[i][j] = this->Mat[i][j] - Mat2.Mat[i][j];
        }
    }

    return Result;
}

template <class type>
Matriz<type> Matriz<type>::operator*(const Matriz<type> &Mat2)
{
    if (this->filas != Mat2.columnas)
        throw std::invalid_argument("Las Matrices no se pueden multiplicar\n");
    Matriz<type> Result(this->filas, Mat2.columnas);

    type sum = 0; //si se planea usar objetos estos tienen que tener un 0 y sobrecargar el operador = para poder asignarlo

    for (int i = 0; i < this->filas; i++)
    {
        sum = 0;
        for (int j = 0; j < Mat2.columnas; j++)
        {
            for (int k = 0; k < Mat2.columnas; k++)
            {
                sum = sum + (this->Mat[i][k] * Mat2.Mat[k][j]);
                Result.Mat[k][j] = sum;
            }
        }
    }

    return Result;
}

template <class type>
Matriz<type> &Matriz<type>::operator=(const Matriz<type> &Mat2)
{
    if (this->filas != Mat2.filas || this->columnas != Mat2.columnas)
        this->resize(Mat2.filas, Mat2.columnas);

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            this->Mat[i][j] = Mat2.Mat[i][j];
        }
    }

    this->filas = Mat2.filas;
    this->columnas = Mat2.columnas;

    return *this;
}

template <class type>
type Matriz<type>::brackethelp(type *fila, int col)
{
    return fila[col];
}

template <class type>
type *Matriz<type>::operator[](const int index)
{
    if (index >= this->filas)
        throw std::out_of_range("Fuera del rango de la matriz\n");
    this->brcketaux = index;
    return this->Mat[index];
}

template <class type>
type Matriz<type>::operator[](short int index2)
{
    if (index2 >= this->columnas)
        throw std::out_of_range("Fuera del rango de la matriz\n");

    this->bracketaux2 = index2;
    return (this->brackethelp((*this)[this->brcketaux], index2));
}

template <class type>
Matriz<type> &Matriz<type>::operator=(const type Data)
{
    this->Mat[brcketaux][bracketaux2] = Data;
    return *this;
}

template <class type>
Matriz<type>::~Matriz()
{
    std::ofstream D;

    D.open("Matrices.txt", std::ios_base::app);

    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++)
        {
            D << this->Mat[i][j] << "\t";
        }
        D << "\n";
    }
    D << "\n";

    if (sizeof(type) == sizeof(Entero) || sizeof(type) == sizeof(Racional) || sizeof(type) == sizeof(Natural) ||
        sizeof(type) == sizeof(Racional) || sizeof(type) == sizeof(Irracional) || sizeof(type) == sizeof(Real))
    {
    }
    else
    {

        for (int i = 0; i < this->filas; i++)
        {
            delete this->Mat[i];
        }
        delete this->Mat;
    }
}

int main(int argc, char const *argv[])
{
    Natural N1(2), N2(10), N3, NS, NR, NM; //Podemos declarara un Natural con un valor inicial o dejarlo vacio(el valor por default es 1)
    //Si intentamos utilizar un numero que no pertenezca al conjunto de los naturales se arroja una excepcion.

    Entero E1(1), E2(-54), E3, ES, ER, EM; //Podemos declarara un enetero con un valor inicial o dejarlo vacio(el valor por default es 0)
    Entero NtoE(N1);                       //Podemos declarar un entero usando un natural(no podemos declar un Natural con un entero)
    //Si intentemos utilizar un dato que no sea un numero entero se toma la parte entera de dicho numero unicamente

    Racional R1(4, 5), R2(8, 9), R3, RS, RR, RM; //Podemos declarara un Racional con un valor inicial o dejarlo vacio(el valor por default es 1)
    Racional EtoR(E1), NtoR(N1);                 //Podemos declarar un racional con un Entero o un Natural(no de manera inversa)
    //Si intentemos utilizar un datos que no sean un numero(numerador y denominador) entero se toma la parte entera de dichos numeros unicamente

    Irracional P("Pi"), E("e"), Raiz2("SQRT2"), Phi("phi"); //Podemos declarar un irracional colocando el nombre del irracional que queremos utilizar
    //Si no definimos que irracinal vamos a usar el valor por default es PI

    Real Re1(1.35363), Re2(2), Re3, ReS, ReR, ReM, ReD, RePow, ReSqrt; //podemos declarar un real con un valor inicial(el valor por default)
    Real NtoRe(N2), EtoRe(E2), RtoRe(R2);                              //Podemos declarar un Real con un Natural, Entero , Racional o Irracional(no de forma inversa)

    Complejo A(1.3, 5), B(2, -4), C, CS, CR, CM, CD; //podemos declarar un complejo con valor inicial(el valor por default es 0 + 0i)

    /*Funcionamineto de las clases*/
    //Naturales
    //Podemos Imprimir el valor de el numero con la funcion print o directamente utilizando cout
    N1.print();
    std::cout << N1 << std::endl;

    N3 = 100; //podemos asignar un numero diractamente a un objeto siempre y cuando pertenezca al conjunto de numeros utilizado
    /*Podemos operar con objetos de la clase o con numeros siempre y cuando pertenezcan a el conjunto de numeros utilizado*/
    NS = N1 + N2;
    NS.print();

    NR = N3 - N2;
    NR.print();

    NM = N2 * N3;
    NM.print();

    NS = N1 + 3;
    NS.print();

    NR = N3 - 6;
    NR.print();

    NM = N2 * 4;
    NM.print();

    //ENTEROS
    //Podemos Imprimir el valor de el numero con la funcion print o directamente utilizando cout
    E1.print();
    std::cout << E1 << std::endl;

    E3 = -100; //podemos asignar un numero diractamente a un objeto siempre y cuando pertenezca al conjunto de numeros utilizado

    /*Podemos operar con objetos de la clase Entero(o de la clase Natural) o con numeros siempre y cuando pertenezcan a el conjunto de numeros utilizado*/
    ES = E1 + E2;
    ES.print();

    ER = E2 - E3;
    ER.print();

    NM = N2 * N3;
    NM.print();

    ES = E1 + N3;
    ES.print();

    ER = E2 - N1;
    ER.print();

    EM = E2 * N2;
    NM.print();

    ES = E1 + (-3);
    ES.print();

    ER = E2 - 10;
    ER.print();

    EM = E2 * 4;
    NM.print();

    //Racionales
    //Podemos Imprimir el valor de el numero con la funcion print o directamente utilizando cout
    R1.print();
    std::cout << R1 << std::endl;

    R3 = -10; //podemos asignar un numero diractamente a un objeto siempre y cuando pertenezca al conjunto de numeros utilizado

    /*Podemos operar con objetos de la clase Racional(de la clase Natural o Entera) o con numeros, siempre y cuando pertenezcan a el conjunto de numeros utilizado*/
    RS = R1 + R2; //Cuando operamos con racionales el resultado siempre se simplifica(si es posible)
    RS.print();

    RR = R2 - R1;
    RR.print();

    RM = R2 * R3;
    RM.print();

    RS = R1 + N1;
    RS.print();

    RR = R2 - N2;
    RR.print();

    RM = R2 * NS;
    RM.print();

    RS = R1 + E1;
    RS.print();

    RR = R2 - ER;
    RR.print();

    RM = R2 * E3;
    RM.print();

    RS = R1 + 10;
    RS.print();

    RR = R2 - 7;
    RR.print();

    RM = R2 * 42;
    RM.print();

    //Reales
    //Podemos Imprimir el valor de el numero con la funcion print o directamente utilizando cout
    Re1.print();
    std::cout << Re1 << std::endl;

    Re3 = -10.192; //podemos asignar un numero diractamente a un objeto siempre y cuando pertenezca al conjunto de numeros utilizado

    /*Podemos operar con objetos de la clase Real(de la clase Natural,Entera, Racional e Irracional) o con numeros*/
    ReS = Re1 + R2;
    ReS.print();

    ReR = Re2 - Re3;
    ReR.print();

    ReM = Re2 * Re3;
    ReM.print();

    ReD = Re3 / Re2;
    ReD.print();

    RePow = Re1.potencia(3);
    RePow.print();

    RePow = Re1.potencia(-1); //podemos elevar a potencias negativas
    RePow.print();

    ReS = Re1 + N1;
    ReS.print();

    ReR = Re2 - N2;
    ReR.print();

    ReM = Re2 * N3;
    ReM.print();

    ReD = Re3 / NS;
    ReD.print();

    ReS = R1 + E1;
    ReS.print();

    ReR = Re2 - E2;
    ReR.print();

    ReM = Re2 * E3;
    ReM.print();

    ReD = Re3 / ES;
    ReD.print();

    ReS = Re1 + R1;
    ReS.print();

    ReR = Re2 - R2;
    ReR.print();

    ReM = Re2 * RS;
    ReM.print();

    ReD = Re3 / RM;
    ReD.print();

    ReS = Re1 + P;
    ReS.print();

    ReR = Re2 - E;
    ReR.print();

    ReM = Re2 * Phi;
    ReM.print();

    ReD = Re3 / Raiz2;
    ReD.print();

    ReS = Re1 + 10;
    ReS.print();

    ReR = Re2 - 1.5;
    ReR.print();

    ReM = Re2 * 10.5;
    ReM.print();

    ReD = Re3 / 3.333;
    ReD.print();

    //Complejos
    //Podemos Imprimir el valor de el numero con la funcion print o directamente utilizando cout
    A.print();
    std::cout << A << std::endl;

    C = A.conj(); //Conjugado de A
    C.print();

    CS = A + B;
    CS.print();

    CR = B - A;
    CR.print();

    CM = B * A;
    CM.print();

    CD = A / C;
    CD.print();

    std::cout << "\n\n\n";

    Matriz<float> AM(10, 2, 3), BM(2, 3, 2), MC(2, 2), DM(3, 3), t, KM(4, 4);
    Matriz<Racional> ZM(R1, 3, 3);

    AM[0][0] = 5;
    AM.print();
    BM[0][0] = 1;
    BM.print();
    MC = AM * BM;
    MC.print();

    ZM.print();

    srand(time(NULL));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            KM[i][j] = 1 + rand() % (11 - 1);
        }
    }
    KM.print();
    //KM.Determinante();

    DM[0][0] = -2;
    DM[0][1] = -6;
    DM[0][2] = 2;

    DM[1][0] = 0;
    DM[1][1] = 1;
    DM[1][2] = 3;

    DM[2][0] = 0;
    DM[2][1] = 0;
    DM[2][2] = 6;

    DM.print();

    std::cout << "Determinante: " << DM.Determinante() << "\n\n";

    t = DM.inversa();
    std::cout << "Inversa: \n";
    t.print();

    return 0;
}
