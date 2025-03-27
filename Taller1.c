#include <stdio.h>

int main() {
    int id, stock, cantidad, opcion, contc = 0, contv = 0, v = 0;
    float precio, total_ganancias = 0, venta = 0, descuento = 0, totalventa = 0;
    char nombre[30];    

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar un producto:\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el ID del producto: ");
                do {
                    if (scanf("%d", &id) == 1) {
                        v = 1;
                        break;

                    } else {
                        printf("Cantidad no valida. Ingrese nuevamente: ");
                        break;
                    }
                } while (v == 0);

                v = 0;
                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                
                printf("Ingrese la cantidad inicial en stock: ");
                do {
                    scanf("%d", &stock);
                    if (stock < 0) {
                        printf("Cantidad no valida. Ingrese nuevamente: ");
                    }
                } while (stock < 0);
                
                printf("Ingrese el precio unitario del producto: ");
                do {
                    scanf("%f", &precio);
                    if (precio <= 0) {
                        printf("Precio no valido. Ingrese nuevamente: ");
                    }
                } while (precio <= 0);

                break;

            case 2:

                printf("Ingrese la cantidad a vender: ");
                do {
                    do {
                        if (scanf("%d", &cantidad) != 1) {
                            v = 1;
                            break;

                        } else {
                            printf("Cantidad no valida. Ingrese nuevamente: ");
                            break;
                        }
                    } while (v == 0);

                    v = 0;

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
                    printf("Venta realizada con éxito.\n");
                    contc= contc + cantidad;
                    contv++;
                } else {
                    stock -= cantidad;
                    venta = cantidad * precio;
                    total_ganancias += cantidad * precio;
                    printf("Venta realizada con éxito.\n");
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
                
                break;

            case 3:
                printf("Stock actual: %d\n", stock);
                printf("Ingrese la cantidad a agregar al stock: ");
                do {
                    scanf("%d", &cantidad);
                    if (cantidad <= 0) {
                        do {
                            printf("Cantidad no válida. Ingrese nuevamente: ");
                            scanf("%d", &cantidad);
                        } while(cantidad <= 0);
                    } 
                    
                    stock += cantidad;
                    printf("Stock reabastecido con éxito.\n");
                     
                } while (cantidad < 0);
                
                printf("Stock actualizado: %d\n", stock);

                break;

            case 4:

                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                printf("Total de ventas realizadas: %d\n", contv);
                printf("Total de productos vendidos: %d\n", contc);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
                break;
        }    
    } while (opcion != 6);

    return 0;
}
