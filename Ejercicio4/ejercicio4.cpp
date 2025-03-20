#include <iostream>
#include <chrono>

using namespace std;
/*
4. Recursión y ejecución en tiempo de compilación:
a. Se requiere el código de una función recursiva que compare dos variables que contengan texto e 
indique mediante una variable bool si son iguales (true si son iguales, false si no lo son). 
Explique su elección entre los tipos string y char* (lea el siguiente item de este ejercicio 
antes de elegir el tipo de variable) y demuestre la funcionalidad de su código con un texto de, al menos, 64 caracteres.
*/
constexpr bool compare_texts(const char* text1, const char* text2){
    if (*text1 == '\0' && *text2 == '\0') return true;
    if (*text1 != *text2) return false;
    return compare_texts(text1+1, text2+1);
}
bool compare_texts_runtime(const char* text1, const char* text2){
    if (*text1 == '\0' && *text2 == '\0') return true;
    if (*text1 != *text2) return false;
    return compare_texts_runtime(text1+1, text2+1);
} 

constexpr const char* text1 = "Esta es una cadena de más de sesenta y cuatro caracteres, prueba.";
constexpr const char* text2 = "Esta es una cadena de más de sesenta y cuatro caracteres, prueba.";

int main () {
    cout << (compare_texts_runtime(text1, text2) ? "Iguales.\n" : "Diferentes.\n");
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
    auto startTime = std::chrono::high_resolution_clock::now();
    bool runtime_result = compare_texts_runtime(text1, text2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;
    /*
    c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se realice en tiempo de 
    compilación y obtenga el tiempo de ejecución. Compare este tiempo con el obtenido en el ejercicio 4.2 y 
    justifique brevemente la diferencia (puede escribir su conclusión como un comentario al final del código de este item).
    */
    constexpr bool compile_time_result = compare_texts(text1, text2);
    cout << (compile_time_result ? "Iguales.\n" : "Diferentes.\n");

    auto startTime2 = std::chrono::high_resolution_clock::now();
    bool idk = compile_time_result;
    auto endTime2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>( endTime2 - startTime2);
    std::cout << "A miProcesoAMedir le tomó: " << elapsedTime2.count() << " nanosegundos" << std::endl;
    return 0;
}


