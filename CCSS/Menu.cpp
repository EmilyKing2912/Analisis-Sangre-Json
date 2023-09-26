
#include "Menu.h"

//Universidad Nacional 
    //Proyecto desarollado por:
    //Emily King Bustamante
    //Junio 2021.
void Menu::inicializar() {
    int opcion = 0;
    Analisis* an = Analisis::getInstance();
    Archivo ar;
    string nombre = "";
    string analisis = "";
    while (opcion == 0 || (opcion < 4 && opcion >= 0) || !cin >> opcion) {
        cout << endl;
        cout << "Bienvenido al sistema de Analisis" << endl;
        cout << "1. Analisis 1" << endl;
        cout << "2. Analisis 2" << endl;
        cout << "3. Analisis 3" << endl;
        cout << "4. salir" << endl;

        try {
            cout << "Digite el analisis desea realizar: " << endl;
            cin >> opcion;

            if (!cin >> opcion || opcion < 0 || opcion > 4) {
                throw 1;
            }
            else {
                switch (opcion) {
                case 1: { cout << "El resultado del Analisis 1 es: " << endl;
                    cout << an->mostrarAnalisis1() << endl;
                    cin.get(); }break;
                case 2: { cout << "El resultado del Analisis 2 es:" << endl;
                    cout << an->analisis2() << endl;
                    cin.get(); }break;
                case 3: {cout << "Digite el nombre que desea ponerle al archivo:" << endl;
                    cin >> nombre;
                    cout << "Generando Archivo CVS...." << endl;
                    analisis = an->mostrarAnalisisCVS();
                    ar.escribir(nombre, analisis);
                    cout << "Archivo generado Exitosamente:" << endl;
                    cout << an->mostrarAnalisis3();
                    cin.get(); }break;
                case 4: { cout << "Salir" << endl;
                    cin.get(); }break;
                }
            }
        }
        catch (int a) {
            if (a == 1) {
                system("cls");
                cout << "Dato incorrecto, por favor ingreselo otra vez" << endl;
                cin.ignore();
                cin.clear();
                cin.get();
                opcion = 0;
            }
        }
    };
}
