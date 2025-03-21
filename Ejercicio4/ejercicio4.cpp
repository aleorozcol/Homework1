#include <iostream>
#include <chrono>
//#include <string>

using namespace std;
/*
4. Recursión y ejecución en tiempo de compilación:
a. Se requiere el código de una función recursiva que compare dos variables que contengan texto e 
indique mediante una variable bool si son iguales (true si son iguales, false si no lo son). 
Explique su elección entre los tipos string y char* (lea el siguiente item de este ejercicio 
antes de elegir el tipo de variable) y demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres.
*/

bool compare_texts (string text1, string text2, size_t index = 0){
    if (index == text1.length() && index == text2.length()) return true;
    if (index >= text1.length() || index >= text1.length() || text1[index] != text2[index]) return false;
    return compare_texts(text1, text2, index + 1);
}

//bool compare_texts (const char* text1, const char* text2, size_t index = 0){
//    if (text1[index] == '\0' && text2[index] == '\0') return true;
//    if (text1[index] != text2[index]) return false;
//    return compare_texts(text1, text2, index+1);
//}

constexpr bool compare_texts (const char* text1, const char* text2, size_t index = 0){
    if (text1[index] == '\0' && text2[index] == '\0') return true;
    if (text1[index] != text2[index]) return false;
    return compare_texts(text1, text2, index+1);
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

constexpr const char text1[] = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wen";
constexpr const char text2[] = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wen";
constexpr bool compile_time_result = compare_texts(text1, text2);


int main(){
    //string text3 = "fdsjncpsdndsmc df de cjldnckwjnñkjsn c hch ebfeb  vvnd c    wel";
    //cout << "text1 y text2: " << (compare_texts(text1,text2) ? "Son iguales" : "Son distintos") << endl;
    //cout << "text1 y text3: " << (compare_texts(text1,text3) ? "Son iguales" : "Son distintos") << endl;
    // medicion del timepo de ejecucion
    
    auto startTime = chrono::high_resolution_clock::now();
    bool runtime_result = compile_time_result;
    auto endTime = chrono::high_resolution_clock::now();
    // calculo del tiempo transcurrido
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>( endTime - startTime);
    cout << "text1 y text2: " << (runtime_result ? "Son iguales" : "Son distintos") << endl;
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;
    return 0;
}
