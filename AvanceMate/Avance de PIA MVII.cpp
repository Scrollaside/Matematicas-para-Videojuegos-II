#include <iostream>
#include <math.h>
#include <locale.h>
#include <string>
#include <conio.h>
#define PI 3.14159265

using namespace std;
//Lo que sea que jaime hizo----------------------------------------------
int max;
int Pprima[20];
int longitud;
int a, b;
float matriz1[10][10], matriz2[10][10], matriz3[10][10];
float Tmatriz[4][4];
float MatrizAct[4][4];
int op_cal = 0;
int op;
struct puntos
{
    float punto[4];
    float puntoPrimo[4];
    puntos* sig;
};
puntos* aux = nullptr;
puntos* raiz = nullptr;
void agregar_nodo(float param[4])
{
    if (raiz == nullptr)
    {
        raiz = new puntos;
        for (int i = 0; i < 4; i++)
        {
            raiz->punto[i] = param[i];

        }
        raiz->sig = nullptr;
        aux = raiz;
    }
    else
    {
        aux = raiz;
        while (aux->sig != nullptr)
        {
            aux = aux->sig;
        }
        aux->sig = new puntos;
        aux->sig->sig = nullptr;
        aux = aux->sig;

        for (int i = 0; i < 4; i++)
        {
            aux->punto[i] = param[i];

        }
    }

}
void borrar_lista()
{
    aux = raiz;
    while (raiz != nullptr)
    {
        raiz = aux->sig;
        delete aux;
        aux = raiz;
    }
}
int LongNum(int param) {

    if (param > -1 && param < 10)
        return 1;

    if (param > -10 && param < 0 || param > 9 && param < 100)
        return 2;

    if (param > -100 && param < -9 || param > 99 && param < 1000)
        return 3;

    if (param > -1000 && param < -99 || param > 999 && param < 10000)
        return 4;

    return 5;
}
bool tipoIntValido(string numero) {

    int dot = 0;
    int i = 0;

    if (numero.length() == 0)
        return false;

    if (numero[0] == '+' || numero[0] == '-') {
        i = 1;

        if (numero.length() == 1)
            return false;
    }

    for (i; i < numero.length(); i++) {

        if (!isdigit(numero[i]))
        {
            if (numero[i] == 46)
            {
                dot = dot + 1;
            }
            else
            {
                return false;
            }
            if (dot > 1)
            {
                return false;
            }
        }
    }

    return true;
}
float NumeroValido() {
    string numero;
    bool Validez = false;

    while (Validez == false) {

        getline(cin, numero);

        Validez = tipoIntValido(numero);

        if (Validez == false)
            cout << "ERROR. Favor de introducir únicamente números: ";
    }
    return stof(numero);
}
void Transladar()
{
    system("cls");

    float Tpunto[3];
    float result[4][4];
    float Tmatriz[4][4];
    do
    {
        cout << "Ingrese la translación a realizar: " << endl;
        cout << "x: ";
        cin >> Tpunto[0];
        cout << "y: ";
        cin >> Tpunto[1];
        cout << "z: ";
        cin >> Tpunto[2];

        cout << "¿Confirmar translación: (" << Tpunto[0] << ", " << Tpunto[1] << ", " << Tpunto[2] << ") ?" << endl;
        cout << "1 -> Si" << endl;
        cout << "2 -> No" << endl;
        cin >> op;

        system("cls");

    } while (op == 2);

    Tmatriz[0][0] = 1, Tmatriz[0][1] = 0, Tmatriz[0][2] = 0, Tmatriz[0][3] = Tpunto[0];
    Tmatriz[1][0] = 0, Tmatriz[1][1] = 1, Tmatriz[1][2] = 0, Tmatriz[1][3] = Tpunto[1];
    Tmatriz[2][0] = 0, Tmatriz[2][1] = 0, Tmatriz[2][2] = 1, Tmatriz[2][3] = Tpunto[2];
    Tmatriz[3][0] = 0, Tmatriz[3][1] = 0, Tmatriz[3][2] = 0, Tmatriz[3][3] = 1;

    cout << endl << "Matriz resultante de Translación" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {


            cout << Tmatriz[i][j];
            longitud = LongNum(Tmatriz[i][j]);

            for (longitud; longitud < 7; longitud++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;

    if (op_cal == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = Tmatriz[i][j];
            }

        }
    }
    else
    {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {
                result[i][j] = 0;
            }
        }

        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {

                for (int k = 0; k < 4; k++)
                {
                    result[i][j] += MatrizAct[i][k] * Tmatriz[k][j];
                }

            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = result[i][j];
            }

        }

    }
    system("PAUSE");

}
void Rotar()
{
    float Rmatriz[4][4];
    const double pi = acos(-1);
    float grados = 0;
    float rad = 0;
    float result[4][4];

    cout << "Ingrese el ángulo (en grados) con el que se rotará" << endl;
    cin >> grados;
    cout << "Seleccione el eje donde se rotará" << endl;
    cout << "1 -> Eje x\n2 -> Eje y\n 3 -> Eje z" << endl;
    cin >> op;

    rad = (grados * pi / 180);

    switch (op)
    {
    case 1://X
        Pprima[op_cal - 1] = 2;
        Rmatriz[0][0] = 1, Rmatriz[0][1] = 0, Rmatriz[0][2] = 0, Rmatriz[0][3] = 0;
        Rmatriz[1][0] = 0, Rmatriz[1][1] = cos(rad), Rmatriz[1][2] = 0 - sin(rad), Rmatriz[1][3] = 0;
        Rmatriz[2][0] = 0, Rmatriz[2][1] = sin(rad), Rmatriz[2][2] = cos(rad), Rmatriz[2][3] = 0;
        Rmatriz[3][0] = 0, Rmatriz[3][1] = 0, Rmatriz[3][2] = 0, Rmatriz[3][3] = 1;

        break;

    case 2://Y
        Pprima[op_cal - 1] = 3;
        Rmatriz[0][0] = cos(rad), Rmatriz[0][1] = 0, Rmatriz[0][2] = sin(rad), Rmatriz[0][3] = 0;
        Rmatriz[1][0] = 0, Rmatriz[1][1] = 1, Rmatriz[1][2] = 0, Rmatriz[1][3] = 0;
        Rmatriz[2][0] = 0 - sin(rad), Rmatriz[2][1] = 0, Rmatriz[2][2] = cos(rad), Rmatriz[2][3] = 0;
        Rmatriz[3][0] = 0, Rmatriz[3][1] = 0, Rmatriz[3][2] = 0, Rmatriz[3][3] = 1;
        break;

    case 3://Z
        Pprima[op_cal - 1] = 4;
        Rmatriz[0][0] = cos(rad), Rmatriz[0][1] = 0 - sin(rad), Rmatriz[0][2] = 0, Rmatriz[0][3] = 0;
        Rmatriz[1][0] = sin(rad), Rmatriz[1][1] = cos(rad), Rmatriz[1][2] = 0, Rmatriz[1][3] = 0;
        Rmatriz[2][0] = 0, Rmatriz[2][1] = 0, Rmatriz[2][2] = 1, Rmatriz[2][3] = 0;
        Rmatriz[3][0] = 0, Rmatriz[3][1] = 0, Rmatriz[3][2] = 0, Rmatriz[3][3] = 1;
        break;

    default: cout << "OPCION NO VALIDA" << endl;
        return Rotar();
    }

    cout << endl << "Matriz resultante de Rotación" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {


            cout << Rmatriz[i][j];
            longitud = LongNum(Rmatriz[i][j]);

            for (longitud; longitud < 7; longitud++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;

    if (op_cal == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = Rmatriz[i][j];
            }

        }
    }
    else
    {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {
                result[i][j] = 0;
            }
        }

        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {

                for (int k = 0; k < 4; k++)
                {
                    result[i][j] += MatrizAct[i][k] * Rmatriz[k][j];
                }

            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = result[i][j];
            }

        }

    }
    system("PAUSE");


}
void Escalar()
{
    float Spunto[3];
    float Ematriz[4][4];
    float result[4][4];

    cout << "Ingrese la escala a realizar: " << endl;
    cout << "x: ";
    cin >> Spunto[0];
    cout << "y: ";
    cin >> Spunto[1];
    cout << "z: ";
    cin >> Spunto[2];

    Ematriz[0][0] = Spunto[0], Ematriz[0][1] = 0, Ematriz[0][2] = 0, Ematriz[0][3] = 0;
    Ematriz[1][0] = 0, Ematriz[1][1] = Spunto[1], Ematriz[1][2] = 0, Ematriz[1][3] = 0;
    Ematriz[2][0] = 0, Ematriz[2][1] = 0, Ematriz[2][2] = Spunto[2], Ematriz[2][3] = 0;
    Ematriz[3][0] = 0, Ematriz[3][1] = 0, Ematriz[3][2] = 0, Ematriz[3][3] = 1;



    cout << endl << "Matriz resultante de Escalación" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {


            cout << Ematriz[i][j];
            longitud = LongNum(Ematriz[i][j]);

            for (longitud; longitud < 7; longitud++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;

    if (op_cal == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = Ematriz[i][j];
            }

        }
    }
    else
    {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {
                result[i][j] = 0;
            }
        }

        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {

                for (int k = 0; k < 4; k++)
                {
                    result[i][j] += MatrizAct[i][k] * Ematriz[k][j];
                }

            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                MatrizAct[i][j] = result[i][j];
            }

        }

    }
    system("PAUSE");
}
void MultP()
{
    float P[4];
    int i = 0;
    float result[4][4];


    do
    {

        cout << "Escriba el punto " << i + 1 << endl;
        cout << "x: ";
        cin >> P[0];
        cout << "y: ";
        cin >> P[1];
        cout << "z: ";
        cin >> P[2];
        P[3] = 1;
        agregar_nodo(P);

        cout << "¿Desea agregar otro punto?\n1 -> si\n 2 -> no" << endl;
        cin >> op;
        i++;



    } while (op == 1);


    aux = raiz;

    do
    {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 4; j++) {
                result[i][j] = 0;
            }
        }

        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 1; j++) {

                for (int k = 0; k < 4; k++)
                {
                    result[i][j] += MatrizAct[i][k] * aux->punto[k];

                }

            }

        }
        aux->puntoPrimo[0] = result[0][0];
        aux->puntoPrimo[1] = result[1][0];
        aux->puntoPrimo[2] = result[2][0];
        aux->puntoPrimo[3] = result[3][0];

        aux = aux->sig;
    } while (aux != nullptr);



    system("PAUSE");
}
void PprimaPantalla()
{
    cout << "P': ";

    for (int i = 0; i < op_cal; i++)
    {
        switch (Pprima[i])
        {
        case 1://TRANSLACION
            cout << "(T) ";
            break;

        case 2://RÓTACION en x
            cout << "(Rx) ";
            break;

        case 3://ROTACION en y
            cout << "(Ry) ";
            break;

        case 4://ROTACION en z
            cout << "(Rz) ";
            break;

        case 5://Escalar
            cout << "(S) ";

        case 6://Puntos
            cout << "(P) ";
            break;
        }
    }
    cout << "\n\n\n" << endl;
}
//--------------------------------------------------------------------------
void SumaResta(bool band);
void Multiplicacion();
void Cuaternios();
void Rotacion();
void Matriz();

int main() {
    setlocale(LC_ALL, "spanish");
    int opcion = 0;
    bool band = false;
    while (opcion != 7) {
        system("cls");
        system("color 70");
        cout << ">-----------OPERACIONES-----------<" << endl;
        cout << "1. Suma de matrices." << endl;
        cout << "2. Resta de matrices." << endl;
        cout << "3. Multiplicación de matrices" << endl;
        cout << "4. Calculo de cuaterniones" << endl;
        cout << "5. Operaciones de matriz" << endl;
        cout << "6. Rotacion paralela a un eje" << endl;
        cout << "7. Salir" << endl;
        cout << "\nIngrese la opción que desea realizar: ";
        cin >> opcion;

        switch (opcion) {
            system("CLS");
        case 1: {
            band = true;
            SumaResta(band);
            break;
        }
        case 2: {
            band = false;
            SumaResta(band);
            break;
        }
        case 3: {
            Multiplicacion();
            break;
        }
        case 4: {
            Cuaternios();
            break;
        }
        case 5: {
            Matriz();
            break;
        }
        case 6: {
            Rotacion();
            break;
        }
        case 7: {
            cout << "\nAdiós" << endl << endl;
            system("pause");
            return 0;
        }
              break;
        default: {
            system("color 74");
            cout << "\n   ERROR. Opción no existente." << endl << endl;
            system("pause");
            break;
        }
        }
    }
}

void SumaResta(bool band) {
    system("cls");
    int a, b, matriz1[10][10], matriz2[10][10];
    if (band == true) {
        cout << "<<Suma de Matrices>>" << endl;
    }
    else {
        cout << "<<Resta de Matrices>>" << endl;
    }

    cout << endl << "\nIngrese el número de columnas que tendrán sus matrices: ";
    cin >> a;

    cout << endl << "Ingrese el número de filas que tendrán sus matrices: ";
    cin >> b;

    cout << endl;
    system("PAUSE");
    system("CLS");

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < a; j++) {
            cout << endl << endl << "Ingrese el número de la columna " << j + 1 << " y la fila " << i + 1 << " de la matriz 1: ";
            cin >> matriz1[i][j];

            system("CLS");
            cout << "Matriz 1:" << endl;

            for (int k = 0; k < b; k++) {
                cout << endl;

                for (int l = 0; l < a; l++) {

                    if (matriz1[k][l] < -100000) {
                        cout << "  --";
                    }
                    else {
                        cout << "  " << matriz1[k][l];
                    }
                }
            }
        }
    }

    cout << endl << endl;
    system("PAUSE");
    system("CLS");

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < a; j++) {
            cout << endl << endl << "Ingrese el número de la columna " << j + 1 << " y la fila " << i + 1 << " de la matriz 2: ";
            cin >> matriz2[i][j];

            system("CLS");
            cout << "Matriz 2:" << endl;

            for (int k = 0; k < b; k++) {
                cout << endl;

                for (int l = 0; l < a; l++) {

                    if (matriz2[k][l] < -100000) {
                        cout << "  --";
                    }
                    else {
                        cout << "  " << matriz2[k][l];
                    }
                }
            }
        }
    }

    cout << endl << endl;
    system("PAUSE");
    system("CLS");

    if (band == true) {
        cout << endl << "Matriz resultante de Matriz 1 + Matriz 2 =" << endl;

        for (int i = 0; i < b; i++) {
            cout << endl;

            for (int j = 0; j < a; j++) {
                cout << "  " << matriz1[i][j] + matriz2[i][j];
            }
        }
        cout << endl << endl;
        system("PAUSE");
    }
    else {
        cout << endl << "Matriz resultante de Matriz 1 - Matriz 2 =" << endl;

        for (int i = 0; i < b; i++) {
            cout << endl;

            for (int j = 0; j < a; j++) {
                cout << "  " << matriz1[i][j] - matriz2[i][j];
            }
        }
        cout << endl << endl;
        system("PAUSE");
    }
}
void Multiplicacion() {

    int a = 0;
    int b = 0;
    int c, d, matriz1[10][10], matriz2[10][10];
    int resultado[10][10];
    bool Matrizvalid = false;
    while (Matrizvalid != true) {
        system("cls");
        system("color 70");
        cout << "<<Multiplicacion de Matrices>>" << endl;
        cout << "\nIngrese el número de columnas que tendrá la matriz 1: ";
        cin >> a;
        cout << "Ingrese el número de filas que tendrá la matriz 1: ";
        cin >> b;

        cout << "\nIngrese el número de columnas que tendrá la matriz 2: ";
        cin >> c;
        cout << "Ingrese el número de filas que tendrá la matriz 2: ";
        cin >> d;

        if (a != d) {
            system("color 74");
            cout << "\nLas matrices no tienen las dimensiones adecuadas" << endl;
            Matrizvalid = false;
        }
        else {
            cout << "\nMatrices validas" << endl;
            Matrizvalid = true;
        }
        cout << endl;
        system("PAUSE");
    }
    system("CLS");

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < a; j++) {
            cout << "\n\nIngrese el número de la columna " << j + 1 << " y la fila " << i + 1 << " de la matriz 1: ";
            cin >> matriz1[i][j];

            system("CLS");
            cout << ">Matriz 1:" << endl;

            for (int k = 0; k < b; k++) {
                cout << endl;

                for (int l = 0; l < a; l++) {

                    if (matriz1[k][l] < -100000) {
                        cout << "  --";
                    }
                    else {
                        cout << "  " << matriz1[k][l];
                    }
                }
            }
        }
    }

    cout << endl << endl;
    system("PAUSE");
    system("CLS");

    for (int i = 0; i < d; i++) {

        for (int j = 0; j < c; j++) {
            cout << "\n\nIngrese el número de la columna " << j + 1 << " y la fila " << i + 1 << " de la matriz 2: ";
            cin >> matriz2[i][j];

            system("CLS");
            cout << ">Matriz 2:" << endl;

            for (int k = 0; k < d; k++) {
                cout << endl;

                for (int l = 0; l < c; l++) {

                    if (matriz2[k][l] < -100000) {
                        cout << "  --";
                    }
                    else {
                        cout << "  " << matriz2[k][l];
                    }
                }
            }
        }
    }

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < c; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < b; i++) {

        for (int j = 0; j < c; j++) {

            for (int k = 0; k < a; k++) {

                resultado[i][j] += matriz1[i][k] * matriz2[k][j];

            }
        }
    }

    cout << endl << "Matriz resultante de Matriz 1 * Matriz 2 =" << endl;

    for (int i = 0; i < b; i++) {
        cout << endl;

        for (int j = 0; j < c; j++) {
            cout << "  " << resultado[i][j];
        }
    }

    cout << endl << endl;
    system("PAUSE");
    system("CLS");

}
void Cuaternios() {
    system("cls");
    char coord = 'x';
    float punto[4] = { 0 }, vector[3], angle, u, q[4], qconj[4], qp[4] = { 0 }, qpq[4] = { 0 }, aux, ascii = coord;

    for (int i = 1; i < 4; i++) {
        coord = ascii;
        cout << endl << "Escriba la coordenada " << coord << " del punto: ";
        cin >> punto[i];
        ascii++;
    }
    coord = 'x';
    ascii = coord;

    for (int i = 0; i < 3; i++) {
        coord = ascii;
        cout << endl << "Escriba la coordenada " << coord << " del vector: ";
        cin >> vector[i];
        ascii++;
    }

    cout << endl << "Escriba el ángulo de rotación: ";
    cin >> angle;

    u = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
    q[0] = cos(angle * 3.141592654 / 360);
    qconj[0] = q[0];

    for (int i = 1; i < 4; i++) {
        q[i] = (sin(angle * 3.141592654 / 360) * vector[i - 1]) / u;
        qconj[i] = q[i] * -1;
    }

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            aux = q[i] * punto[j];

            if (i != 0 && i == j || i == 1 && j == 3 || i == 2 && j == 1 || i == 3 && j == 2) {
                aux = aux * -1;
            }
            if (i == 0 && i == j || i != 0 && i == j) {
                qp[0] = qp[0] + aux;
            }
            if (i == 0 && j == 1 || i == 1 && j == 0 || i == 2 && j == 3 || i == 3 && j == 2) {
                qp[1] = qp[1] + aux;
            }
            if (i == 0 && j == 2 || i == 2 && j == 0 || i == 3 && j == 1 || i == 1 && j == 3) {
                qp[2] = qp[2] + aux;
            }
            if (i == 0 && j == 3 || i == 3 && j == 0 || i == 1 && j == 2 || i == 2 && j == 1) {
                qp[3] = qp[3] + aux;
            }
        }
    }

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            aux = qp[i] * qconj[j];

            if (i != 0 && i == j || i == 1 && j == 3 || i == 2 && j == 1 || i == 3 && j == 2) {
                aux = aux * -1;
            }
            if (i == 0 && i == j || i != 0 && i == j) {
                qpq[0] = qpq[0] + aux;
            }
            if (i == 0 && j == 1 || i == 1 && j == 0 || i == 2 && j == 3 || i == 3 && j == 2) {
                qpq[1] = qpq[1] + aux;
            }
            if (i == 0 && j == 2 || i == 2 && j == 0 || i == 3 && j == 1 || i == 1 && j == 3) {
                qpq[2] = qpq[2] + aux;
            }
            if (i == 0 && j == 3 || i == 3 && j == 0 || i == 1 && j == 2 || i == 2 && j == 1) {
                qpq[3] = qpq[3] + aux;
            }
        }
    }
    cout << endl << endl << "Cuaternion Resultante:" << endl << endl << qpq[0] << " + " << qpq[1] << "i + " << qpq[2] << "j + " << qpq[3] << "k" << endl;
    system("pause");
}
void Rotacion() {
    struct puntos {
        float x;
        float y;
        float z;
    };
    puntos punto[50];
    struct vectores {
        int x;
        int y;
        int z;
    };
    vectores vector[3];
    float MatrizT[4][4], MatrizE[4][4], Temporal[4][4], Resultado[4][4], Punto[4][1];

    char eje;
    int p, angulo;
    bool valido = false;
    while (valido == false) {
        system("cls");
        cout << "Ingrese la cantidad de puntos:";
        cin >> p;
        for (int i = 0; i < 50; i++) {
            punto[i].x = 0;
            punto[i].y = 0;
            punto[i].z = 0;
        }
        for (int i = 0; i < p; i++) {

            for (int j = 0; j < 3; j++) {
                system("cls");
                cout << "P" << i + 1 << "(" << punto[i].x << ", " << punto[i].y << ", " << punto[i].z << ")" << endl;
                cout << "Ingrese ";
                if (j == 0) {
                    cout << "x del punto " << i + 1 << ":";

                    cin >> punto[i].x;
                }
                else if (j == 1) {
                    cout << "y del punto " << i + 1 << ":";
                    cin >> punto[i].y;
                }
                else if (j == 2) {
                    cout << "y del punto " << i + 1 << ":";
                    cin >> punto[i].z;
                }
            }
            system("cls");
            cout << "P" << i + 1 << "(" << punto[i].x << ", " << punto[i].y << ", " << punto[i].z << ")" << endl;
            system("pause");
        }
        bool SN = false;
        while (SN == false) {
            system("cls");
            cout << "Puntos:" << endl;
            for (int i = 0; i < p; i++) {
                cout << "P" << i + 1 << "(" << punto[i].x << ", " << punto[i].y << ", " << punto[i].z << ")";
                if (i + 1 > 0 && i + 1 < p) {
                    cout << ",";
                }
                cout << " ";
                if (((i + 1) % 4 == 0) && i != p) {
                    cout << endl;
                }
            }
            cout << "\nCambiar numeros?(s/n)";
            char sn;
            sn = _getch();
            if (sn == 'n') {
                valido = true;
                SN = true;
            }
            else if (sn == 's') {
                SN = true;
            }
            else if (sn != 's' && sn != 'n') {
                cout << "\nOpcion invalida" << endl;
                system("pause");
            }
        }
    }
    valido = false;
    while (valido != true) {
        for (int i = 0; i < 3; i++) {
            vector[i].x = 0;
            vector[i].y = 0;
            vector[i].z = 0;
        }
        system("cls");
        for (int i = 0; i < 2; i++) {

            for (int j = 0; j < 3; j++) {
                system("cls");
                cout << "V" << i + 1 << "(" << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ")" << endl;
                cout << "Ingrese ";
                if (j == 0) {
                    cout << "x del vector " << i + 1 << ":";

                    cin >> vector[i].x;
                }
                else if (j == 1) {
                    cout << "y del vector " << i + 1 << ":";
                    cin >> vector[i].y;
                }
                else if (j == 2) {
                    cout << "y del vector " << i + 1 << ":";
                    cin >> vector[i].z;
                }
            }
            system("cls");
            cout << "V" << i + 1 << "(" << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ")" << endl;
            system("pause");
        }
        system("cls");
        cout << "Vectores:" << endl;
        for (int i = 0; i < 2; i++) {
            cout << "V" << i + 1 << "(" << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << ")";
            if (i + 1 > 0 && i + 1 < 2) {
                cout << ",";
            }
            cout << " ";
        }
        cout << endl;

        vector[2].x = vector[1].x - vector[0].x;
        vector[2].y = vector[1].y - vector[0].y;
        vector[2].z = vector[1].z - vector[0].z;
        int nv, c1, c2;

        cout << "VR(" << vector[2].x << ", " << vector[2].y << ", " << vector[2].z << "), ";
        if (vector[2].x >= vector[2].y && vector[2].x >= vector[2].z) {
            nv = vector[2].x;
            c1 = vector[2].y;
            c2 = vector[2].z;
            eje = 'x';
        }
        if (vector[2].y >= vector[2].x && vector[2].y >= vector[2].z) {
            c1 = vector[2].x;
            nv = vector[2].y;
            c2 = vector[2].z;
            eje = 'y';
        }
        if (vector[2].z >= vector[2].x && vector[2].z >= vector[2].y) {
            c1 = vector[2].x;
            c2 = vector[2].y;
            nv = vector[2].z;
            eje = 'z';
        }
        if (c1 == 0 && c2 == 0) {
            valido = true;
        }
        if (c1 == 0 && c2 == 0 && nv == 0) {
            valido = false;
        }
        if (valido == false) {
            cout << "Vectores invalidos" << endl;
            system("pause");
        }

    }

    cout << "Vectores validos." << endl;
    cout << "Matriz T^-1:" << endl;
    MatrizT[0][0] = 1, MatrizT[0][1] = 0, MatrizT[0][2] = 0, MatrizT[0][3] = vector[0].x;
    MatrizT[1][0] = 0, MatrizT[1][1] = 1, MatrizT[1][2] = 0, MatrizT[1][3] = vector[0].y;
    MatrizT[2][0] = 0, MatrizT[2][1] = 0, MatrizT[2][2] = 1, MatrizT[2][3] = vector[0].z;
    MatrizT[3][0] = 0, MatrizT[3][1] = 0, MatrizT[3][2] = 0, MatrizT[3][3] = 1;
    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {
            cout << "  " << MatrizT[i][j];
        }
    }

    cout << "\n\nIngrese el angulo a girar en " << eje << ":";
    cin >> angulo;
    cout << "Matriz R" << eje << ":" << endl;
    float anguloR = angulo * (PI / 180);
    if (eje == 'x') {
        MatrizE[0][0] = 1, MatrizE[0][1] = 0, MatrizE[0][2] = 0, MatrizE[0][3] = 0;
        MatrizE[1][0] = 0, MatrizE[1][1] = cos(anguloR), MatrizE[1][2] = -sin(anguloR), MatrizE[1][3] = 0;
        MatrizE[2][0] = 0, MatrizE[2][1] = sin(anguloR), MatrizE[2][2] = cos(anguloR), MatrizE[2][3] = 0;
        MatrizE[3][0] = 0, MatrizE[3][1] = 0, MatrizE[3][2] = 0, MatrizE[3][3] = 1;
    }
    if (eje == 'y') {
        MatrizE[0][0] = cos(anguloR), MatrizE[0][1] = 0, MatrizE[0][2] = sin(anguloR), MatrizE[0][3] = 0;
        MatrizE[1][0] = 0, MatrizE[1][1] = 1, MatrizE[1][2] = 0, MatrizE[1][3] = 0;
        MatrizE[2][0] = -sin(anguloR), MatrizE[2][1] = 0, MatrizE[2][2] = cos(anguloR), MatrizE[2][3] = 0;
        MatrizE[3][0] = 0, MatrizE[3][1] = 0, MatrizE[3][2] = 0, MatrizE[3][3] = 1;
    }
    if (eje == 'z') {
        MatrizE[0][0] = cos(anguloR), MatrizE[0][1] = -sin(anguloR), MatrizE[0][2] = 0, MatrizE[0][3] = 0;
        MatrizE[1][0] = sin(anguloR), MatrizE[1][1] = cos(anguloR), MatrizE[1][2] = 0, MatrizE[1][3] = 0;
        MatrizE[2][0] = 0, MatrizE[2][1] = 0, MatrizE[2][2] = 1, MatrizE[2][3] = 0;
        MatrizE[3][0] = 0, MatrizE[3][1] = 0, MatrizE[3][2] = 0, MatrizE[3][3] = 1;
    }
    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {
            cout << "  " << MatrizE[i][j];
        }
    }


    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {
            Temporal[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {
            Resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            for (int k = 0; k < 4; k++) {

                Temporal[i][j] += MatrizT[i][k] * MatrizE[k][j];

            }
        }
    }
    MatrizT[0][0] = 1, MatrizT[0][1] = 0, MatrizT[0][2] = 0, MatrizT[0][3] = -vector[0].x;
    MatrizT[1][0] = 0, MatrizT[1][1] = 1, MatrizT[1][2] = 0, MatrizT[1][3] = -vector[0].y;
    MatrizT[2][0] = 0, MatrizT[2][1] = 0, MatrizT[2][2] = 1, MatrizT[2][3] = -vector[0].z;
    MatrizT[3][0] = 0, MatrizT[3][1] = 0, MatrizT[3][2] = 0, MatrizT[3][3] = 1;
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            for (int k = 0; k < 4; k++) {

                Resultado[i][j] += Temporal[i][k] * MatrizT[k][j];

            }
        }
    }

    cout << "\n\nResultado de T^-1(" << vector[0].x << ", " << vector[0].y << ", " << vector[0].z << ")" << "R" << eje
        << "(" << angulo << ")" << "T(" << -vector[0].x << ", " << -vector[0].y << ", " << -vector[0].z << ") =" << endl;
    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {
            cout << "  " << Resultado[i][j];
        }
    }
    cout << endl;
    system("pause");

    for (int h = 0; h < p; h++) {
        Punto[0][0] = punto[h].x;
        Punto[1][0] = punto[h].y;
        Punto[2][0] = punto[h].z;
        Punto[3][0] = 1;
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < 1; j++) {
                Temporal[i][j] = 0;
                for (int k = 0; k < 4; k++) {

                    Temporal[i][j] += Resultado[i][k] * Punto[k][j];

                }
            }
        }
        punto[h].x = Temporal[0][0];
        punto[h].y = Temporal[1][0];
        punto[h].z = Temporal[2][0];

    }
    system("cls");
    cout << "Puntos resultantes:" << endl;
    for (int i = 0; i < p; i++) {
        cout << "P'" << i + 1 << "(" << punto[i].x << ", " << punto[i].y << ", " << punto[i].z << ")";
        if (i + 1 > 0 && i + 1 < p) {
            cout << ",";
        }
        cout << " ";
        if ((i + 1) % 4 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    system("pause");
    system("cls");
}
void Matriz(){
    system("cls");

    setlocale(LC_ALL, "spanish");

    PprimaPantalla();

    cout << endl << "Matriz Actual" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;

        for (int j = 0; j < 4; j++) {


            cout << MatrizAct[i][j];
            longitud = LongNum(MatrizAct[i][j]);

            for (longitud; longitud < 7; longitud++) {
                cout << " ";
            }
        }
    }
    cout << endl << endl;



    cout << "Escriba la opción que desea realizar: " << endl;
    cout << "1 -> Transladar\n2 -> Rotar \n3 -> Escalar\n4 -> Multiplicar por puntos\n5 -> REINICIAR PROCESO\n\n" << endl;

    if (Pprima[op_cal - 1] == 6)
    {
        int z;
        cout << "INGRESE Z PERSPECTIVA: ";
        cin >> z;

        aux = raiz;
        int i = 0;
        cout << "P':" << endl;
        while (aux != nullptr)
        {

            cout << "P" << i + 1 << "': (" << aux->puntoPrimo[0] << ", " << aux->puntoPrimo[1] << ", " << aux->puntoPrimo[2] << ")" << endl;

            aux = aux->sig;
        }
        cout << "\n\n";
        aux = raiz;
        cout << "P'' (Z perspectiva):" << endl;
        while (aux != nullptr)
        {

            cout << "P" << i + 1 << "'': (" << (aux->puntoPrimo[0] * z) / (z - aux->puntoPrimo[2]) << ", " << (aux->puntoPrimo[1] * z) / (z - aux->puntoPrimo[2]) << ")" << endl;

            aux = aux->sig;
        }
        cout << "\n\n";
    }
    cin >> op;

    switch (op)
    {
    case 1://TRANSLADAR
        Transladar();
        Pprima[op_cal] = 1;
        op_cal = op_cal + 1;
        break;

    case 2://ROTACION
        Rotar();
        op_cal = op_cal + 1;
        break;

    case 3://ESCALAR
        Escalar();
        Pprima[op_cal] = 5;
        op_cal = op_cal + 1;
        break;

    case 4://P
        MultP();
        Pprima[op_cal] = 6;
        op_cal = op_cal + 1;
        break;


    case 5:
        borrar_lista();


        for (int i = 0; i < op_cal; i++)
        {
            Pprima[i] = 0;
        }
        op_cal = 0;
        break;

    default: cout << "OPCION NO VALIDA" << endl;
    }

    system("cls");
    return Matriz();

}
