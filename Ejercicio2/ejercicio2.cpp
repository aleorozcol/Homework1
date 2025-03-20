#include <iostream>
#include <fstream>

using namespace std;

//Enumeramos la etiquetas para representar los niveles de severidad
enum NivelSeveridad {DEBUG, INFO, WARNING, ERROR, CRITICAL};
/*
2. En muchos sistemas, es importante registrar todo lo que sucede mientras están en
funcionamiento. Para ello, se utiliza un sistema de log que almacena los eventos
relevantes. Cada evento recibe una etiqueta que indica su nivel de importancia o
gravedad. Las etiquetas más comunes son: DEBUG, INFO, WARNING, ERROR y
CRITICAL.
a. En este ejercicio, se pide crear un sistema log que permite agregar entradas a un
archivo mediante el llamado a una función logMessage definida en pseudo código de
la siguiente manera:
void logMessage(String mensaje, Integer/Otro NivelSeveridad)
Donde NivelSeveridad corresponderá con unas de las leyendas previamente
mencionadas. El formato esperado en una línea del archivo de log es el siguiente:
[ERROR] <Mensaje>
[INFO] <Mensaje>
etc.
Verifique su funcionamiento con al menos una entrada de cada tipo.
*/

//Función para registrar mensajes segun el nivel de severidad
void logMessage(const string& mensaje, int NivelSeveridad){
    //Abrimos el archivo en el cual queremos guardar todos los mensajes
    ofstream outFile("Messages.txt", ios::app); // ios::app se usa para no sobrescribir en mensajes anteriores
    if (outFile.is_open()){
        switch(NivelSeveridad){
            case NivelSeveridad::DEBUG:
                outFile << "[DEBUG] <" << mensaje << ">\n"; break;
            case NivelSeveridad::INFO:
                outFile << "[INFO] <" << mensaje << ">\n"; break;               
            case NivelSeveridad::WARNING:
                outFile << "[WARNING] <" << mensaje << ">\n"; break;
            case NivelSeveridad::ERROR:             
                outFile << "[ERROR] <" << mensaje << ">\n"; break;
            case NivelSeveridad::CRITICAL: 
                outFile << "[CRITICAL] <" << mensaje << ">\n"; break;
            default:
                outFile << "[UNKNOWN] <" << mensaje << ">\n"; break;
        }
        outFile.close(); // cerramos el arhivo
    } else {
        cout << "No se pudo abrir el archivo.\n"; //error
    }
    return;
}

/*
b. En un proyecto usualmente se solicitan cambios para mejorar o agregar funcionalidad.
Para el caso del código del ejercicio 2.a, se requiere tener la habilidad de agregar
mensajes personalizados para registrar otro tipo de eventos. Los requisitos son los
siguientes:
i. Todos los nuevos mensajes deben ser invocados con logMessage.
ii. Se requiere la posibilidad de registrar errores, indicando el mensaje de error, el
archivo y la línea de código donde sucedió este error, es decir:
logMessage(String Mensage_de_Error, String Archivo, Int Línea_de_Código)
iii. Se requiere la posibilidad de registrar un mensaje de “Acceso de Usuario” a la
aplicación. Este mensaje debe tener una leyenda nueva: [SECURITY]. La misma
debe ser ingresada de la siguiente manera:
logMessage(String Mensaje_De_Acceso, String Nombre_de_Usuario)
Los mensajes de acceso pueden ser: Access Granted, Access Denied, etc.
iv. Se requiere un código que pruebe que el sistema verifica la funcionalidad
requerida y que además demuestre que puede capturar un error en runtime,
crear una entrada en el log y después detener la ejecución del programa y salir
del mismo con un código de error (return 1).
*/

// Función para registrar errores (sobrecarga)
void logMessage(const string& mensaje, const string& archivo, int linea){
    ofstream outFile("Messages.txt", ios::app);
    if (outFile.is_open()){
        outFile << "[ERROR] <" << mensaje << "> en " << archivo << ":" << linea << "\n";
        outFile.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

//Función para registrar accesos (sobrecarga)
void logMessage(const string& mensaje, const string& usuario){
    ofstream outFile("Messages.txt", ios::app);
    if (outFile.is_open()){
        outFile << "[SECURITY] <" << mensaje << "> usuario: " << usuario << "\n";
        outFile.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

int main(){

    ofstream outFile("Messages.txt", ios::trunc); // ios::trunc borra el contenido anterior
    outFile.close();

    cout << "Ingrese el nivel de severidad del mensaje (número):\n";
    cout << "1. DEBUG\n2. INFO\n3. WARNING\n4. ERROR\n5. CRITICAL\n";
    int nivel;
    cin >> nivel;
    cin.ignore(); // Limpiamos el buffer
    cout << "Ingrese el mensaje:\n";
    string mensaje;
    getline(cin, mensaje); // Para poder ingresar mensajes con espacios
    logMessage(mensaje, nivel - 1); // enum empieza en 0, asi que restamos 1

    cout << "Hay problemas con el archivo, por favor ingrese el mensaje de error:\n";
    string error;
    getline(cin, error);
    cout << "Ingrese el nombre del archivo:\n";
    string archivo;
    cin >> archivo;
    cout << "Ingrese la línea de código:\n";    
    int linea;  
    cin >> linea;
    cin.ignore();
    logMessage(error, archivo, linea);

    cout << "Ingrese el mensaje de acceso:\n";
    string acceso;  
    getline(cin, acceso);
    cout << "Ingrese el nombre de usuario:\n";
    string usuario;
    getline(cin, usuario);
    logMessage(acceso, usuario);

    try {
        // Lanzamos una excepción para simular un error en tiempo de ejecución
        throw runtime_error("Error en tiempo de ejecución");
    } catch (const runtime_error& e) {
        //Registramos el error
        logMessage(e.what(), __FILE__, __LINE__);
        return 1; // Salimos del programa con un código de error
    }
    return 0;    
}