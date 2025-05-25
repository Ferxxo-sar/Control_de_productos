# Sistema de Gestión de Inventario en C

Este proyecto es un sistema de gestión de inventario desarrollado en el lenguaje C, diseñado para ayudar a un comercio a administrar en este caso hasta 10000 productos. 
El sistema se diseño de forma que sea escalable, es decir, si ahora se requiere que sea para 1.000.000 de productos, con solo modificar el tamaño del vector seria suficiente.
A su vez almacena a todos productos en un arreglo ordenado por número de ítem y permite operaciones fundamentales sobre el inventario.

## 🧩 Funcionalidades

- **Insertar productos**: Añade nuevos productos al inventario manteniendo el arreglo ordenado por `nroItem`.
- **Eliminar productos**: Borra productos del inventario buscando por su número de ítem.
- **Modificar productos**: Busca el producto seleccionado mediante el numero de item ingresado, luego requiere que se seleccione el campo que se desea modificar, puede ser cualquiera de
  los definidos en el struct pero en caso de moficar el `nroItem` se reordena el vector para mantenerlo ordenado.
- **Buscar productos**: Busca un producto por su número de ítem y muestra sus campos en pantalla.

El objetivo de este proyecto fue desarrollar un sistema escalable, aplicando buenas prácticas y trabajando con conceptos fundamentales como la modularización, el manejo de punteros, y los algoritmos de ordenamiento y búsqueda

## 🛠️ Estructura del producto

Cada producto se representa con la siguiente estructura:

```c
typedef struct {
    int nroItem;
    char producto[20];
    char marca[20];
    char tipo[20];
    float costo;
    int stockMin;
    int stockActual;
} Producto;
