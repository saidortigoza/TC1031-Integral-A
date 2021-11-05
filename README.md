# Student Management System

El proyecto maneja la información de los estudiantes de una universidad y mediante estructuras de datos utiliza la información contenida en *alumnos.txt* para implementar algoritmos que ayuden a la universidad a administrar, organizar y encontrar la información de una manera más eficiente.

## SICT0301B: Evalúa los componentes

### - Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa

Los casos de prueba se corren en el main por medio de las funciones del archivo *casosPrueba.h*.

### - Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes

El análisis de complejidad de todas las funciones de los archivos del programa se encuentran aquí mismo en el archivo *README.md*.

## SICT0302B: Toma decisiones

### - Selecciona un algoritmo de ordenamiento adecuado al problema

Para este proyecto utilicé el algoritmo de ordenamiento Bubble Sort, para organizar las matrículas de los estudiantes registrados en la base de datos de forma ascendente, porque es fácil de implementar y funciona bien en la mayoría de los casos, en especial en este debido a que solo es un registro de 10 añumnos, ya que su complejidad es *O(n^2)* para el peor de los casos. La función donde se puede ver es en el archivo *sorts.h* en las líneas 26-36.

### - Selecciona y usa una estructura lineal adecuada al problema

Implementé una clase para crear una lista ligada simple, de manera que se lean los registros ordenados para almacenarlos en una lista y almacenar la matricula de los estudiantes en un nuevo archivo *alumnosList.txt*. El análisis de complejidad temporal de las funciones que utiliza la lista ligada se muestra a continuación:

***insertion***

La función *insertion* inserta un elemento en la estructura de datos, recibe el valor a insertar y aumenta el tamaño de la lista. El algoritmo recorre n pasos, ya que utiliza un ciclo while para insertar el valor ingresado al final de la lista, por lo que su complejidad es *(O(n))* para el peor de los casos.

***search***

La función *search* busca la posición de un número dentro de la lista usando un ciclo while, y si el número no está dentro de la lista devuelve un -1. El algoritmo recorre *n* pasos, por lo que en el peor de los casos (que se daría cuando el número que busca está al final de la lista) su complejidad es lineal *(O(n))*.

***update***

La función *update* actualiza el valor de un elemento dentro de la lista a partir del índice recibido por el usuario, recorriendo *n* pasos mediante un ciclo while, una vez que lo encuentra, cambia el valor actual con el valor nuevo. Debido a que en el peor de los casos tendría que recorrer la lista entera, su complejidad es *(O(n))*.

***deleteAt***

La función *deleteAt* elimina un elemento dentro de la lista según su posición y reduce el tamaño de la lista. El algoritmo funciona mediante un ciclo while que recorre *n* pasos hasta llegar al elemento deseado, por lo que su complejidad temporal es *(O(n))* para el peor de los casos.

***toString***

El algoritmo recorre n pasos, debido a que utiliza un ciclo while que recorre la lista entera, almacenando en un string la matricula de cada estudiante en cada ciclo, por lo tanto, su complejidad es lineal *O(n)*.

### - Usa un árbol adecuado para resolver un problema

## SICT0303B: Implementa acciones científicas

### - Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa

Se implementaron diversas funciones de consulta de información, como la búsqueda binaria, codificada en el archivo *sorts.h*, la función *search* contenida en las líneas 154-168 del archivo *list.h* que se utiliza para buscar por matrícula, y la búsqueda secuencial, dentro del archivo *heap.h*.

### - Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa

Se incluye un archivo inicial *alumnos.txt* para extraer la información de una manera más optimizada, y se crean archivos de texto adicionales

### - Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa
