                        /*Un comercio mantiene su inventario en un arreglo de hasta 10000 productos,
                        con la estructura:
                        nroItem, producto, marca, tipo, costo, stockMin, stockActual.
                        Implementar un sistema que permita:
                        - Insertar nuevos productos (manteniendo el arreglo ordenado por ‘nroItem’).
                        - Borrar productos por código.
                        - Modificar productos.
                        - Buscar un producto por número de ítem.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int nroItem;
    char producto[20];
    char marca[20];
    char tipo[20];
    float costo;
    int stockMin;
    int stockActual;
} Producto;


Producto leerProducto();                                           //Modulo que retorna un producto p cargado
void imprimirVector(Producto productos[], int dimL);
void mostrarMenu(Producto productos[], int *dimL, int dimF);
void imprimirProducto(Producto p);
void insertarProducto(Producto productos[], int *dimL, int dimF);  //Inserta de forma ordenada un nuevo producto
void borrarProducto(Producto productos[], int *dimL, int dimF);
void editarProducto(Producto productos[], int dimL);
int buscarProducto(Producto productos[], int dimL, int codBuscar);
void buscarMostrarProducto(Producto productos[], int dimL);
void editarCampo(Producto *p, Producto productos[], int dimL);
void ordenarVector(Producto productos[], int dimL);


int main()
{
    int dimL = 0 ; int dimF = 1000;                                //Inicializacion de la dimension logica del vector
    Producto productos[dimF];                                      //Declaracion del vector

    mostrarMenu(productos, &dimL, dimF);                           //Accede al menu controlador
    imprimirVector(productos, dimL);

    return 0;
}

void mostrarMenu(Producto productos[], int *dimL, int dimF){
    int operacion;
    do {
        printf("\n\n   ---------Menu--------\n\n");
        printf("   1 - Insertar un nuevo producto\n   2 - Borrar un producto\n   3 - Modificar un producto\n   4 - Buscar un producto\n   5 - Finalizar.\n");
        printf("\n Que operacion desea realizar?: "); scanf("%d", &operacion);
        printf("\n");

        switch (operacion){
        case 1 : insertarProducto(productos, dimL, dimF);
                 break;
        case 2 : borrarProducto(productos, dimL, dimF);
                 break;
        case 3 : editarProducto(productos, *dimL);
                 break;
        case 4 : buscarMostrarProducto(productos, *dimL);
                 break;
        case 5 : printf("-------Fin del programa--------\n");
                 break;
        default : printf("Error, ingreso una opcion invalida\n");
                 break;

        }

    } while (operacion != 5);

}
void imprimirProducto(Producto p) {
  printf("Item: %d | Producto: %s | Marca: %s | Tipo: %s | Costo: %.2f | Stock: %d/%d\n",
           p.nroItem, p.producto, p.marca, p.tipo, p.costo, p.stockActual, p.stockMin);
}

Producto leerProducto(){                                                                    //Modificar este proceso, crear el proceso limpiarBuffer();
    Producto p;

    printf("Ingrese el numero de Item: "); scanf("%d", &p.nroItem); getchar();
    printf("Ingrese el nombre del producto: ");  scanf("%19[^\n]", p.producto); getchar();
    printf("Ingrese la marca: "); scanf("%19[^\n]", p.marca); getchar();
    printf("Ingrese el tipo: "); scanf("%19[^\n]", p.tipo); getchar();
    printf("Ingrese el costo: "); scanf("%f", &p.costo); getchar();
    printf("Ingrese el stock actual: "); scanf("%d", &p.stockActual); getchar();
    printf("Ingrese el stock minimo: "); scanf("%d", &p.stockMin); getchar();

    return p;
}

void insertarProducto(Producto productos[], int *dimL, int dimF){                          //Mejorar este proceso con una busqueda binaria

    Producto nuevo = leerProducto();
    int i = *dimL -1;

    if ( *dimL >= dimF) {                                          //Controla que no desborde por el lado superior del array
    printf("Error: el array esta completo, no puede insertar mas productos.\n");
    } else {
    while (i >= 0 && productos[i].nroItem > nuevo.nroItem){        //Mientras el producto a insertar sea mayo que el producto "i" muevo una posicion hacia la derecha
        productos[i+1] = productos[i];
        i--;
    }
    productos[i+1] = nuevo;
    (*dimL)++;                                                     //Este va entre parentesis (*dimL) porque sino mueve el puntero en vez de modificar la variable
    }
}

void borrarProducto(Producto productos[], int *dimL, int dimF){
    bool ok = false;
    int itemEliminar;
    int pos = -1;
    printf("Ingrese el codigo del producto que desea eliminar: "); scanf("%d", &itemEliminar);

    int i = 0;
    while ( i < *dimL && !ok){                                     //ok detiene la busqueda cuando se encuentra el producto buscado
        if (productos[i].nroItem == itemEliminar){
            pos = i;                                               //pos guarda la posicion del producto a eliminar
            ok = true;
        }
    i++;
    }
    if ( pos == -1){
        printf("Producto no encontrado.\n");
    } else {
        for (i = pos; i < *dimL; i++){                             //Realiza un corrimiento desde la posicion siguiente a la anterior desde pos hasta dimL
            productos[i] = productos[i+1];
        }
        (*dimL)--;                                                 //Este va entre parentesis porque sino modifica el puntero en vez de su contenido
        printf("El producto se elimino correctamente.\n");
    }
}

int buscarProducto(Producto productos[], int dimL, int codBuscar){

    int i = 0;
    while (i < dimL){
        if (productos[i].nroItem == codBuscar){
                return i;                                           //Retorna la posicion del elemento
        }
        i++;
    }
    return -1;                                                      //Si no existe el codigo buscado retorna -1
}

void buscarMostrarProducto(Producto productos[], int dimL){

    int codigo, pos;
    printf("Ingrese el codigo del producto a buscar: "); scanf("%d", &codigo);

    pos = buscarProducto(productos, dimL, codigo);                  //Asigna a pos la posicion en el vector del codigo de producto ingresado
    if (pos == -1){                                                 //Por si no existe
        printf("Error: el codigo ingresado no existe.\n");
    } else if (pos >= 0 && pos < dimL) {
        imprimirProducto(productos[pos]);                           //Si existe lo imprime
    }
}


void editarProducto(Producto productos[], int dimL){
    int codEditar, pos, operacion;
    printf("Ingrese el codigo del producto que desea editar: "); scanf("%d", &codEditar);
    pos = buscarProducto(productos, dimL, codEditar);               //Reutiliza el buscar producto (el que retorna la posicion, no el que imprime)
    if (pos == -1 ){
            printf("Error: el codigo ingresado no existe.\n");
    } else {
        imprimirProducto(productos[pos]);                           //Lo imprime para que vea el usuario vea el campo que quiere modificar
        editarCampo(&productos[pos], productos, dimL);              //Esta funcion realiza las modificaciones
        imprimirProducto(productos[pos]);                           //Muestra el producto con el cambio realizado
    }
}

void editarCampo(Producto *p, Producto productos[], int dimL){      //Cree esta funcion para no obligar a modificar todos los campos


        int operacion;
        printf("\n 1 - Codigo\n 2 - Nombre\n 3 - Marca\n 4 - Tipo\n 5 - Costo\n 6 - Stock actual\n 7 - Stock minimo\n Ingrese la operacion: ");
        scanf("%d", &operacion); getchar();

        switch (operacion){
            case 1 : printf("Ingrese el codigo: "); scanf("%d", &p->nroItem); getchar();
                     ordenarVector(productos, dimL);                 //Si se modifica el codigo se desordena el vector
                     break;

            case 2 : printf("Ingrese el nombre del producto: ");  scanf("%19[^\n]", p->producto); getchar();
                     break;

            case 3 : printf("Ingrese la marca: "); scanf("%19[^\n]", p->marca); getchar();
                     break;

            case 4 : printf("Ingrese el tipo: "); scanf("%19[^\n]", p->tipo); getchar();
                     break;

            case 5 : printf("Ingrese el costo: "); scanf("%f", &p->costo); getchar();
                     break;

            case 6 : printf("Ingrese el stock actual: "); scanf("%d", &p->stockActual); getchar();
                     break;

            case 7 : printf("Ingrese el stock minimo: "); scanf("%d", &p->stockMin); getchar();
                     break;
        }
}

void ordenarVector(Producto productos[], int dimL){
    int i, j;
    Producto aux;
    for (i = 0; i < dimL - 1; i++) {
        for (j = 0; j < dimL - i - 1; j++) {
            if (productos[j].nroItem > productos[j + 1].nroItem) {
                aux = productos[j];
               productos[j] = productos[j + 1];
                productos[j + 1] = aux;
            }
        }
    }
}

void imprimirVector(Producto productos[], int dimL){

    for (int i = 0; i < dimL; i++){
        imprimirProducto(productos[i]);
    }
}


