#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;



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
//
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

    /*  Tmatriz[0][0] = 1, Tmatriz[1][0] = 0, Tmatriz[2][0] = 0, Tmatriz[3][0] = Tpunto[0];
      Tmatriz[0][1] = 0, Tmatriz[1][1] = 1, Tmatriz[2][1] = 0, Tmatriz[3][1] = Tpunto[1];
      Tmatriz[0][2] = 0, Tmatriz[1][2] = 0, Tmatriz[2][2] = 1, Tmatriz[3][2] = Tpunto[2];
      Tmatriz[0][2] = 0, Tmatriz[1][2] = 0, Tmatriz[2][2] = 0, Tmatriz[3][2] = 1;*/


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

int main()
{
    system("cls");
    int max;
    int Pprima[20];
    int longitud;
    int a, b;
    float matriz1[10][10], matriz2[10][10], matriz3[10][10];
    float Tmatriz[4][4];
    float MatrizAct[4][4];
    int op_cal = 0;
    int op;
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
    return main();




}

