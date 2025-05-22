# Sistema de Gestión de Inventario en C

Este proyecto es un sistema de gestión de inventario desarrollado en el lenguaje C, diseñado para ayudar a un comercio a administrar hasta **1.000 productos (escalable) **. 
El sistema almacena los productos en un arreglo ordenado por número de ítem y permite operaciones fundamentales sobre el inventario.

## 🧩 Funcionalidades

- **Insertar productos**: Añade nuevos productos al inventario manteniendo el arreglo ordenado por `nroItem`.
- **Eliminar productos**: Borra productos del inventario buscando por su número de ítem.
- **Modificar productos**: Permite editar campos individuales de un producto existente. (En caso de moficar el `nroItem` reordena el vector).
- **Buscar productos**: Permite buscar un producto por su número de ítem y visualizar sus datos.

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
