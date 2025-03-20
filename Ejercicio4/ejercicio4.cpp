#include <iostream>
#include <chrono>

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
c. Modifique el código del ejercicio 4.1 para que la comparación de los textos se realice en tiempo de 
compilación y obtenga el tiempo de ejecución. Compare este tiempo con el obtenido en el ejercicio 4.2 y 
justifique brevemente la diferencia (puede escribir su conclusión como un comentario al final del código de este item).
*/
