# Student Management System

El proyecto maneja la información de los estudiantes de una universidad y mediante estructuras de datos utiliza la información contenida en *alumnos.txt* para implementar algoritmos que ayuden a la universidad a administrar, organizar y encontrar la información de una manera más eficiente.

## SICT0301B: Evalúa los componentes

### - Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa

Los casos de prueba se corren en el main por medio de las funciones del archivo *casosPrueba.h*.

### - Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes

El análisis de complejidad de todas las funciones de los archivos del programa se encuentran aquí mismo en el archivo *README.md*.

***main.cpp***

El main utiliza el archivo (alumnos.txt) ya que aqui se encuentran los datos de los alumnos, haciendo uso de un while dentro de otro while se ingresa la información del archivo en un vector, en una lista ligada y en un arbol heap, ya que solo se recorre n pasos hasta haber leido la ultima linea del archivo de texto su complejidad temporal para el peor de los casos es *O(n)* o lineal. Posteriormente se realiza una busqueda binaria de alumno por matricula, el algoritmo de búsqueda binaria funciona dividiendo la búsqueda en mitades utilizando la técnica de recursión, por lo que su complejidad es *O(log n)* para el peor de los casos. Una vez conseguido el arbol con todos los valores dados por el txt, se imprime en consola el string generado por la la funcion *toString* para ver lo contenido en el arbol. Este string es almcenado en el archivo txt *alumnosHeap.txt*, como solo toma un paso guardar el string en el archivo de texto su compejidad temporal para el peor de los casos es O(1) o constante. Lo siguiente es que el main pregunta al usuario que ingrese una matricula y la busca utilizando de la funcion *busqSecuencial* del Arbol Heap, debido a que solo se revisa por medio de ifs el resultado de la funcion booleana la complejidad temporal de este proceso es O(1) o constante para el peor de los casos.

Finalmente se corren algunos casos de prueba, los cuales utilizan funciones cuyas complejidades temporales ya se mencionaron anteriormente, como la función de búsqueda binaria y la función de búsqueda dentro del Arbol Heap.

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

***push***

La funcion *push* inserta un elemento en el siguiente valor disponible dentro de la fila, y reordena la estructura utilizando la funcion *heapify*. Utilizando un ciclo while cada valor que se quiera insertar sera por niveles en el arbol, comparando que el hijo siempre sean mas chico que su padre, por lo que su complejidad temporal es *O(log n)* o logaritmica para el peor de los casos.

***pop***

La funcion *pop* elimina el dato que tiene mayor prioridad en la fila (la raiz del arbol) y reordena el arbol usando la funcion *heapify*, por lo que su complejidad temporal es O(log n) o logaritmica para el peor de los casos dado que usa *heapify*, pero si solo se removiera el elemento sin reorganizar la estructura entonces su complejidad seria *O(1)* o constante para el peor de los casos.

***toString***
La funcion *toString* recorre n pasos, debido a que utiliza un ciclo while que recorre la lista entera, almacenando en un string la matricula de cada estudiante en cada ciclo, por lo tanto, su complejidad es lineal *O(n)*.

***busqSecuencial***
La funcion booleana *busqSecuencial* busca una matricula ingresada dentro del arbol recorriendo n pasos, ya que usa un ciclo for que va de i = 0 hasta count (numero de elementos dentro del arbol), devolviendo True si se ha encontrado o False si no se ha encontrado, por lo que su complejidad temporal es O(n) o lineal para el peor de los casos.

## SICT0303B: Implementa acciones científicas

### - Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa

Se implementaron diversas funciones de consulta de información, como la búsqueda binaria, codificada en el archivo *sorts.h*, la función *search* contenida en las líneas 154-168 del archivo *list.h* que se utiliza para buscar por matrícula, y la búsqueda secuencial, dentro del archivo *heap.h*, misma que se utiliza para correr algunos casos de prueba.

### - Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa

Se incluye un archivo inicial *alumnos.txt* para extraer la información de una manera más optimizada, y se crean archivos de texto adicionales (*alumnosSort.txt*, *alumnosList.txt* y *alumnosHeap.txt*).

### - Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa

Se implementan diversas funciones de escritura, entre ellas *insertion* en las líneas 132-151 del archivo *list.h* y *push* en las líneas 89-98 de archivo *heap.h*
