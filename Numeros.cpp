#include <iostream>
#include <vector>
#include <exception>

/*Creamos una clase numero la cual sera la clase base para representar el conjunto 
total de numeros, dicha clase funciona como un template con la diferencia de que esta
diseñada para arrojar un error en caso de que el tipo seleccionado no sea del tipo
numerico(int,long,float,...,etc.), dicha clase contine los operadores aritmeticos y
booleanos sobrecargados para poder interactuar con otros objetos de la misma clase y
con datos de tipo numerico.*/
template <class T>
class Number
{
protected: //el valor solo es accesible en las clases derivadas
    T value;

public: //copia en caso de querer utilizar la clase como un objeto
    T valcopy;

public:
    /*Constructores*/
    Number(T value);              //constructor base
    Number();                     //Constructor vacio
    Number(const Number<T> &Num); //Constructor copia

    /*Metodos*/
    Number<T> &setvalue(T new_value); //Cambiar el valor del numero
    Number<T> &getvalue();
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

    ~Number();
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
Number<T> &Number<T>::getvalue()
{

    return this->valcopy;
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
/*La clase de los numeros naturales hereda las funciones de la clase Number
las cuales se heredan como 'private' */
class Natural : private Number<unsigned long long>
{

public:
    /*Constructores*/
    Natural(long long &Num);
    Natural();
    Natural(const Natural &copy);
    Natural(Number<unsigned long long> &Num);
    /*Operadores aritmeticos*/
    Natural operator+(const Natural &Num2);
    Natural operator-(const Natural &Num2);
    Natural operator*(const Natural &Num2);
    Natural &operator=(const Natural &Num2);

    ~Natural();
};

Natural::Natural(long long &Num)
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

Natural Natural::operator+(const Natural &Num2)
{
    Natural Resultado;
    Resultado.value = this->value + Num2.value;
    return Resultado;
}

Natural Natural::operator-(const Natural &Num2)
{
    Natural Resultado;
    Resultado.value = this->value - Num2.value;
    return Resultado;
}

Natural Natural::operator*(const Natural &Num2)
{
    Natural Resultado;
    Resultado.value = this->value * Num2.value;
    return Resultado;
}

Natural &Natural::operator=(const Natural &Num2)
{

    this->value = Num2.value;
    return *this;
}

Natural::~Natural() {}

class Entero : private Number<long long>
{

public:
    Entero(long long Value);
    Entero(const Entero &Num2);
    Entero(Number<long long> &Num2);
    Entero();

    Entero operator+(const Entero &Num2);
    Entero operator-(const Entero &Num2);
    Entero operator*(const Entero &Num2);
    Entero &operator=(const Entero &Num2);

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
Entero::Entero(Number<long long> &Num2)
{
    this->value = Num2.valcopy;
}
Entero::Entero()
{
    this->value = 0;
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
    Entero Result;

    this->value = Num2.value;
    return *this;
}

Entero::~Entero()
{
}

int main(int argc, char const *argv[])
{

    Number<long> N(100), N2(1000), C;

    N + N2;

    N.print();

    C = N + N2;

    C.print();
    return 0;
}
