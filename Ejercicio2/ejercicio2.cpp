#include <iostream>
#include <fstream>

using namespace std;
enum NivelSveridad {DEBUG, INFO, WARNING, ERROR, CRITICAL};
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
void logMessage(const string& mensaje, int NivelSeveridad){
    ofstream outFile("Messages.txt", ios::app);
    if (outFile.is_open()){
        switch(NivelSeveridad){
            case DEBUG:
                outFile << "[DEBUG] <" << mensaje << ">\n"; break;
            case INFO:
                outFile << "[INFO] <" << mensaje << ">\n"; break;               
            case WARNING:
                outFile << "[WARNING] <" << mensaje << ">\n"; break;
            case ERROR:             
                outFile << "[ERROR] <" << mensaje << ">\n"; break;
            case CRITICAL: 
                outFile << "[CRITICAL] <" << mensaje << ">\n"; break;
            default:
                outFile << "[UNKNOWN] <" << mensaje << ">\n"; break;
        }
        outFile.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
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
void logMessage(const string& mensaje, const string& archivo, int linea){
    ofstream outFile("Messages.txt", ios::app);
    if (outFile.is_open()){
        outFile << "[ERROR] <" << mensaje << "> en " << archivo << ":" << linea << "\n";
        outFile.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

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
    ofstream outFile("Messages.txt", ios::trunc);
    outFile.close();

    logMessage("Mensaje de DEBUG", 1);
    logMessage("Mensaje de INFO", 2);
    logMessage("Mensaje de WARNING", 3);
    logMessage("Mensaje de ERROR", 4);
    logMessage("Mensaje de CRITICAL", 5);

    logMessage("Mensaje error", "Archivo defectuoso", 125);
    logMessage("Access Granted", "aleorozco");
    logMessage("Access Denied", "aleorozcol");

    try {
        throw runtime_error("Error en tiempo de ejecución");
    } catch (const runtime_error& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    return 0;    
}