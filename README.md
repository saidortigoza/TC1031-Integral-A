# Student Management System

El proyecto maneja la información de los estudiantes de una universidad y mediante estructuras de datos utiliza la información contenida en *alumnos.txt* para implementar algoritmos que ayuden a la universidad a organizar y encontrar la información de una manera más eficiente.

### SICT0302B: Toma decisiones

#### - Selecciona un algoritmo de ordenamiento adecuado al problema

Para este proyecto utilicé el algoritmo de ordenamiento Bubble Sort, para organizar las matrículas de los estudiantes registrados en la base de datos de forma ascendente, porque es fácil de implementar y funciona bien en la mayoría de los casos, en especial en este debido a que solo es un registro de 10 añumnos, ya que su complejidad es *O(n^2)* para el peor de los casos. La función donde se puede ver es en el archivo *sorts.h* en las líneas 26-36.

#### - Selecciona y usa una estructura lineal adecuada al problema

Implementé una clase para crear una lista ligada simple, de manera que se lean los registros ordenados para almacenarlos en una lista y almacenar la matricula de los estudiantes en un nuevo archivo *alumnosList.txt*. El análisis de complejidad temporal de las funciones que utiliza la lista ligada se muestra a continuación:
