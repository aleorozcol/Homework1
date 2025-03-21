#include <iostream>
#include <chrono>
#include <string>

using namespace std;
/*
4. Recursión y ejecución en tiempo de compilación:
a. Se requiere el código de una función recursiva que compare dos variables que contengan texto e 
indique mediante una variable bool si son iguales (true si son iguales, false si no lo son). 
Explique su elección entre los tipos string y char* (lea el siguiente item de este ejercicio 
antes de elegir el tipo de variable) y demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres.
*/
// Función recursiva la cual indica si dos variables son iguales, en este caso uso string
bool compare_texts_string (string text1, string text2, size_t index = 0){
    if (index == text1.length() && index == text2.length()) return true; // Caso base, ya se compararon todos los caractes y son iguales los dos textos
    if (index >= text1.length() || index >= text1.length() || text1[index] != text2[index]) return false; // 
    return compare_texts_string(text1, text2, index + 1); //Vamos sumando 1 al index para chequear el siguiente caracter
}
// Función recursiva la cual indica si dos variables son iguales, en este caso uso char
bool compare_texts_char (const char* text1, const char* text2, size_t index = 0){
    if (text1[index] == '\0' && text2[index] == '\0') return true;
    if (text1[index] != text2[index]) return false;
    return compare_texts_char(text1, text2, index+1);
}
// Función recursiva la cual indica si dos variables son iguales, en este caso uso constexpr 
constexpr bool compare_texts_const (const char* text1, const char* text2, size_t index = 0){
    if (text1[index] == '\0' && text2[index] == '\0') return true;
    if (text1[index] != text2[index]) return false;
    return compare_texts_const(text1, text2, index+1);
}

/*
b. El componente high_resolution_clock de <chrono> permite calcular el tiempo de ejecución de un proceso al hacer:
#include <chrono>
…
auto startTime = std::chrono::high_resolution_clock::now();
miProcesoAMedir();
auto endTime = std::chrono::high_resolution_clock::now();
auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
std::cout << “A miProcesoAMedir le tomó: “ << elapsedTime.count() << “ nanosegundos” << std::endl;
Utilice esté código y las modificaciones necesarias que crea conveniente para verificar cuanto tiempo 
toma la ejecución del código del ejercicio 4.1.
*/

/*
c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se realice en tiempo de 
compilación y obtenga el tiempo de ejecución. Compare este tiempo con el obtenido en el ejercicio 4.2 y 
justifique brevemente la diferencia (puede escribir su conclusión como un comentario al final del código de este item).
*/


int main(){

    constexpr const char text_const1[] = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wen";
    constexpr const char text_const2[] = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wen";
    string text_string1 = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wel";
    string text_string2 = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wel";

    //Comparación en tiempo de compilación
    constexpr bool compile_time_result = compare_texts_const(text_const1,text_const2);
    
    // Medicion del tiempo de ejecucion usando string
    auto startTime1 = chrono::high_resolution_clock::now();
    bool result_string = compare_texts_string(text_string1,text_string2);
    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>( endTime1 - startTime1);

    // Medicion del tiempo de ejecucion usando char
    auto startTime2 = chrono::high_resolution_clock::now();
    bool result_char = compare_texts_char(text_const1,text_const2);
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>( endTime2 - startTime2);

    // Medicion del tiempo de ejecucion para la compracion en tiempo de compilación
    auto startTime3 = chrono::high_resolution_clock::now();
    bool runtime_result = compile_time_result;
    auto endTime3 = chrono::high_resolution_clock::now();
    auto elapsedTime3 = chrono::duration_cast<chrono::nanoseconds>( endTime3 - startTime3);
    
    
    cout << "Comparación con string: " << (result_string ? "Son iguales" : "Son distintos") << endl;
    cout << "Tiempo de ejecución (string): " << elapsedTime1.count() << " nanosegundos" << endl;

    cout << "Comparación con char: " << (result_char ? "Son iguales" : "Son distintos") << endl;
    cout << "Tiempo de ejecución (char): " << elapsedTime2.count() << " nanosegundos" << endl;

    cout << "Comparación en tiempo de compilación: " << (runtime_result ? "Son iguales" : "Son distintos") << endl;
    cout << "Tiempo de ejecución (constexpr): " << elapsedTime3.count() << " nanosegundos" << endl;
    return 0;
}


/*
Conclusión:

Cuando comparamos los dos textos utilizando 'constexpr' nos permite evaluar en tiempo de compilación.
Por esto, el resultado ya esta calculado antes de ejecutar el programa.
En cambio, las funciones que utilizan string o solamente char tienen que comparar en tiempo de ejecución, demorando más el proceso.
Acá hay un ejemplo de los distintos tiempos:
Comparación con string: Son iguales
Tiempo de ejecución (string): 25408 nanosegundos
Comparación con char: Son iguales
Tiempo de ejecución (char): 401 nanosegundos
Comparación en tiempo de compilación: Son iguales
Tiempo de ejecución (constexpr): 40 nanosegundos
Podemos ver que 'constexpr' consigue que el tiempo se reduzca en una gran escala.
string nunca podría conseguir este tipo de resultados porque usa memoria dinámica.

*/
