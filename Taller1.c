#include <stdio.h>

int main() {
    int id = 0, stock = 0, cantidad = 0, opcion, contc = 0, contv = 0;
    float precio = 0.00, total_ganancias = 0, venta = 0, descuento = 0, totalventa = 0;
    char nombre[30];    

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar un producto:\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        printf("\n");
        switch(opcion) {
            case 1:
                printf("Ingrese el ID del producto: ");
                do {
                    if (scanf("%d", &id) == 1) {
                        break;
                    } else {
                        printf("ID no valido. Ingrese nuevamente: ");
                        while (getchar() != '\n'); 
                    }
                } while (id <= 0);
                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                    
                printf("Ingrese la cantidad inicial en stock: ");
                do {
                    if (scanf("%d", &stock) == 1 && stock > 0) {
                        break;
                    } else {
                        printf("Cantidad no valida. Ingrese nuevamente: ");
                        while (getchar() != '\n');
                    }
                } while (1);
                    
                printf("Ingrese el precio unitario del producto: ");
                do {
                    if (scanf("%f", &precio) == 1 && precio > 0) {
                        break;
                    } else {
                        printf("Precio no valido. Ingrese nuevamente: ");
                        while (getchar() != '\n');
                    }
                } while (1);
                printf("Producto registrado con exito.\n");

                break;

            case 2:
                if (stock <= 0) {
                    printf("No hay stock disponible para vender.\n");
                    printf("Por favor reabastezca el producto antes de vender.\n");
                    break;
                } else if (id <= 0) {
                    printf("No hay productos registrados.\n");
                    break;
                } else if (id > 0) {
                    printf("Stock disponible: %d\n", stock);

                    printf("Ingrese la cantidad a vender: ");
                    do {
                        do {
                            if (scanf("%d", &cantidad) == 1) {
                                break;

                            } else {
                                printf("Cantidad no valida. Ingrese nuevamente. ");
                                while (getchar() != '\n'); 
                            }
                        } while (cantidad <= 0);

                        if(cantidad > stock) {
                            printf("No hay suficiente stock para vender.\n");
                            do {
                                printf("Ingrese una cantidad menor o igual a %d: ", stock);
                                scanf("%d", &cantidad);
                            } while(cantidad > stock);
                        } 
                    } while(cantidad > stock);

                    if (cantidad >= 10) {
                        stock -= cantidad;
                        venta = cantidad * precio;
                        total_ganancias += cantidad * precio;
                        descuento = venta * 0.25;
                        printf("Venta realizada con exito.\n");
                        contc= contc + cantidad;
                        contv++;
                    } else {
                        stock -= cantidad;
                        venta = cantidad * precio;
                        total_ganancias += cantidad * precio;
                        printf("Venta realizada con exito.\n");
                        contc= contc + cantidad;
                        contv++;
                    }

                    printf("Total de la venta: $%.2f\n", venta);
                    if (cantidad >= 10) {
                        printf("Descuento aplicado: $%.2f\n", descuento);
                        totalventa = venta - descuento;
                        printf("Total de la venta con descuento: $%.2f\n", totalventa);
                    }
                    printf("Stock restante: %d\n", stock);
                }
                
                break;

            case 3:
                if (id <= 0) {
                    printf("No hay productos registrados.\n");
                    
                    break;
                } else {
                    printf("Ingrese la cantidad a reabastecer: ");
                    do {
                        if (scanf("%d", &cantidad) == 1 && cantidad > 0) {
                            break;
                        } else {
                            printf("Cantidad no valida. Ingrese nuevamente: ");
                            while (getchar() != '\n');
                        }
                    } while (1);

                    stock += cantidad;
                    printf("Reabastecimiento realizado con exito.\n");
                    printf("Stock actual: %d\n", stock);
                    break;
                }
                
            case 4:
                if (id <= 0) {
                    printf("No hay productos regisrados.\n");
                    break;
                } else {
                    printf("Stock disponible: %d\n", stock);
                    printf("\nInformacion del producto:\n");
                    printf("ID: %d\n", id);
                    printf("Nombre: %s", nombre);
                    printf("Stock disponible: %d\n", stock);
                    printf("Precio unitario: %.2f\n", precio);
                    break;
                }
                
            case 5:
                if (total_ganancias <= 0) {
                    printf("No se han realizado ventas.\n");
                    break;
                } else {
                    printf("Total de ganancias: $%.2f\n", total_ganancias);
                    printf("Total de ventas realizadas: %d\n", contv);
                    printf("Total de productos vendidos: %d\n", contc);
                    break;
                }

            case 6:
                printf("Saliendo del programa...\n");
                printf("Gracias por usar el sistema de gestion de productos.\n");
                printf("Hasta luego!\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }    
    } while (opcion != 6);

    return 0;
}
