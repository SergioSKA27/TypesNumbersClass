#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
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

    virtual void print(); // Imprime el valor almacenada

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
template <class T>
void Number<T>::print()
{
    std::cout << this->value << std::endl;
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
    Natural(Number<unsigned long long> &Num);

    unsigned long long _value() const; //retorna el  valor del objeto
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

    virtual ~Natural();
};

Natural::Natural(long long Num)
{
    if (Num < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    else //De lo contrario usando la clase Number  asignamos el valor
        this->setvalue(Num);
}

Natural::Natural(Number<unsigned long long> &Num)
{
    if (Num < 1) //Si el valor es menor a 1 arrojamos una excepcion
        throw std::invalid_argument("Value need be more greater than zero");
    else //De lo contrario usando la clase Number  asignamos el valor
        this->setvalue(Num.valcopy);
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
    return (this->value == Num2.value);
}

bool Natural::operator!=(const Natural &Num2) const
{
    return (this->value != Num2.value);
}

bool Natural::operator<(const Natural &Num2) const
{
    return (this->value < Num2.value);
}

bool Natural::operator>(const Natural &Num2) const
{
    return (this->value > Num2.value);
}

bool Natural::operator<=(const Natural &Num2) const
{
    return (this->value <= Num2.value);
}

bool Natural::operator>=(const Natural &Num2) const
{
    return (this->value >= Num2.value);
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

Natural::~Natural() {}

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
    Entero(Number<long long> &Num2);
    Entero(); //Constructor vacio

    long long _value() const;
    int val();

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

    void operator delete(void *p)
    {
        free(p);
    }

    friend std::ostream &operator<<(std::ostream &os, const Entero &Num)
    {
        os << Num.value;
        return os;
    }

    virtual ~Entero();
};

Entero::Entero(long long Value)
{
    this->value = Value;
}
Entero::Entero(const Entero &Num2)
{
    this->value = Num2.value;
}
Entero::Entero(Number<long long> &Num2)
{
    this->value = Num2.valcopy;
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
    Result.value = this->value + Num2._value();
    return Result;
}
Entero Entero::operator-(const Natural &Num2)
{
    Entero Result;

    Result.value = this->value - Num2._value();
    return Result;
}
Entero Entero::operator*(const Natural &Num2)
{
    Entero Result;
    Result.value = this->value * Num2._value();
    return Result;
}
Entero &Entero::operator=(const Natural &Num2)
{
    this->value = Num2._value();
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
    return (this->value == Num2._value());
}
bool Entero::operator!=(const Natural &Num2) const
{
    return (this->value != Num2._value());
}
bool Entero::operator<(const Natural &Num2) const
{
    return (this->value < Num2._value());
}
bool Entero::operator>(const Natural &Num2) const
{
    return (this->value > Num2._value());
}
bool Entero::operator<=(const Natural &Num2) const
{
    return (this->value <= Num2._value());
}
bool Entero::operator>=(const Natural &Num2) const
{
    return (this->value >= Num2._value());
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
}

class Racional : private Number<long long>
{
private:
    Entero Numerador;
    Entero Denominador;

public:
    Racional(long long Num, long long Den);
    Racional(const Racional &N2);
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
            if (this->Numerador.val() % i == 0)
            {
                if (this->Denominador.val() % i == 0)
                {
                    this->Numerador = this->Numerador.val() / i;
                    this->Denominador = this->Denominador.val() / i;
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
        std::cout << this->Numerador.val() << std::endl;
    }
    else
    {
        std::cout << this->Numerador.val() << " / " << this->Denominador.val() << std::endl;
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

    Result.Numerador = (this->Numerador * (R2._value() / R2._value())) + (this->Denominador * R2._value());
    Result.Denominador = this->Denominador * (R2._value() / R2._value());

    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const Entero &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2._value() / R2._value())) - (this->Denominador * R2._value());
    Result.Denominador = this->Denominador * (R2._value() / R2._value());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const Entero &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2._value();
    Result.Denominador = this->Denominador * (R2._value() / R2._value());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const Entero &R2)
{
    this->Numerador = R2._value();
    this->Denominador = (R2._value() / R2._value());
    return *this;
}

Racional Racional::operator+(const Natural &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2._value() / R2._value())) + (this->Denominador * R2._value());
    Result.Denominador = this->Denominador * (R2._value() / R2._value());

    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator-(const Natural &R2)
{
    Racional Result;

    Result.Numerador = (this->Numerador * (R2._value() / R2._value())) - (this->Denominador * R2._value());
    Result.Denominador = this->Denominador * (R2._value() / R2._value());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional Racional::operator*(const Natural &R2)
{
    Racional Result;

    Result.Numerador = this->Numerador * R2._value();
    Result.Denominador = this->Denominador * (R2._value() / R2._value());
    Result.simplify(); //simplificamos el resultado

    return Result; //retornamos el resultado simplificado
}
Racional &Racional::operator=(const Natural &R2)
{
    this->Numerador = R2._value();
    this->Denominador = (R2._value() / R2._value());
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
}

class Irracional : private Number<long double>
{
private:
    char num; //para imprir el caracter
    std::string N;

public:
    Irracional(std::string nombre);
    Irracional(const Irracional &I2);
    Irracional();

    void print();
    ~Irracional();
};

Irracional::Irracional(std::string nombre)
{

    std::for_each(nombre.begin(), nombre.end(), [](char &c) { c = std::tolower(c); });

    this->N = nombre;

    if (N == "pi" || N == "p")
    {
        this->num = 227;
        this->value = M_PI;
    }
    else if (N == "e")
    {
        this->num = 'e';
        this->value = M_E;
    }
    else if (N == "sr2" || N == "s2" || N == "r2" || N == "sqrt2")
    {
        this->value = M_SQRT2;
        this->num = 201;
    }
    else if (N == "phi")
    {
        this->num = 232;
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
    this->num = 227;
    this->value = M_PI;
}

void Irracional::print()
{
    std::cout << this->num << std::endl;
}

Irracional::~Irracional()
{
}

class Real : public Number<long double>
{
private:
    long double _pot(int k);

public:
    Real(long double Rvalue);
    Real(const Real &R2);
    Real(Natural &N);
    Real(Entero &E);
    Real(Racional &R);
    Real();

    long double nroot(int k); //Calcula la raiz n-esima y retorna el resultado
    void root(int k);         //Calcula la raiz n-esima y asigna el resultado al objeto que se le aplico la funcion
    void potencia(int k);
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
/*Real::Real(Natural &N)
{
}*/
Real::Real(Entero &E)
{
    this->value = E.val();
}
/*Real::Real(Racional &R)
{
    this->value = R.
}*/
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

void Real::potencia(int k)
{
    if (k >= 0)
        this->value = this->_pot(k);
    else
        this->value = 1 / this->_pot((unsigned)k);
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

    Result.value = this->value + Num2.value;

    return Result;
}

Real Real::operator-(const Real &Num2)
{
    Real Result;

    Result.value = this->value - Num2.value;

    return Result;
}
Real Real::operator*(const Real &Num2)
{
    Real Result;

    Result.value = this->value * Num2.value;

    return Result;
}
Real Real::operator/(const Real &Num2)
{
    if (Num2.value == 0) //si se quiere dividir por cero se aroja una excepcion
        throw std::invalid_argument("Division entre 0\n");

    Real Result;

    Result.value = this->value / Num2.value;

    return Result;
}
Real &Real::operator=(const Real &Num2)
{

    this->value = Num2.value;

    return *this;
}

Real::~Real()
{
}

/*
La clase complejo herda la clase Number como  long double y almacena 
la parte real el el valor heredado.
*/
/*class Complejo : public Number<long double>
{
private:
    long long value_I;

public:
    Complejo(long double Real, long long Imaginary);
    Complejo(const Complejo &B);
    Complejo();

    Complejo conjugado();
    void print();

    Complejo operator+(const Complejo &Num2);
    Complejo operator-(const Complejo &Num2);
    Complejo operator*(const Complejo &Num2);
    Complejo operator/(const Complejo &Num2);
    Complejo &operator=(const Complejo &Num2);

    virtual ~Complejo();
};

Complejo::Complejo(long double Real, long long Imaginary)
{
    this->value = Real;
    this->value_I = Imaginary;
}
Complejo::Complejo(const Complejo &B)
{
    this->value = B.value;
    this->value_I = B.value_I;
}
Complejo::Complejo()
{
}

Complejo Complejo::conjugado()
{
    Complejo C;
    C.value = this->value;
    C.value_I = -(this->value_I);
    return C;
}

Complejo Complejo::operator+(const Complejo &Num2)
{
    Complejo result;

    result.value = this->value + Num2.value;
    result.value_I = this->value_I + Num2.value_I;

    return result;
}

Complejo Complejo::operator-(const Complejo &Num2)
{
    Complejo result;

    result.value = this->value - Num2.value;
    result.value_I = this->value_I - Num2.value_I;

    return result;
}

Complejo::~Complejo()
{
}
*/
template <class type>
class Matriz
{
private:
    type **Mat;
    int filas;
    int columnas;

    long long Det(type **Mat, int sz);

    inline Matriz<type> ExtractMat(type **Mat, int sz, int F, int C);

    type brackethelp(type *fila, int col); //funcion de ayuda para el operador corche
    int brcketaux, bracketaux2;

public:
    Matriz(const type init, int filas, int columnas); //Para cualquier Matriz inicializada
    Matriz(int filas, int columnas);                  //Para cualquier Matriz
    Matriz(int size);                                 //Para Matrices cuadradas
    Matriz();                                         //Constructor vacio

    Matriz &resize(int filas, int columnas); //Redimensionar Matriz sin perder los datos

    void print();

    Matriz<type> operator+(const Matriz<type> &Mat2);
    Matriz<type> operator-(const Matriz<type> &Mat2);
    Matriz<type> operator*(const Matriz<type> &Mat2);
    Matriz<type> &operator=(const Matriz<type> &Mat2);

    type *operator[](const int index);
    type operator[](short int index2);
    Matriz<type> &operator=(const type Data); //Para asignar valor a las caillas de la matriz

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
long long Matriz<type>::Det(type **Mat, int sz)
{
    return 1;
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
    Matriz<int> A(10, 2, 3), B(2, 3, 2), C(2, 2);
    A[0][0] = 5;
    A.print();
    B[0][0] = 1;
    B.print();
    C = A * B;

    C.print();

    std::cout << C[0][0] << std::endl;
    /*Racional R(2, 16), B(-4, 9), C;
    R.print();
    R.simplify();
    R.print();
    B.print();
    C = R + B;
    C.print();*/

    return 0;
}
