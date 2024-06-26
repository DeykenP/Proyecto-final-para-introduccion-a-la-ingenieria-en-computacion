#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#define MAX_TRABAJADORES 10
#define MAX_INTENTOS 3

typedef struct{
    char nombre[50];
    char codigo[10];
    float salario;
    float deducciones;
    float comisiones;
    float horasExtras;
}Trabajador;

Trabajador trabajadores[MAX_TRABAJADORES] = {
    {"Juan Perez", "Ju0001", 10000, 100, 200, 20},
    {"Pedro Lopez", "Pe0002", 10000, 100, 200, 12},
    {"Maria Huratdo", "Ma0003", 10000, 100, 200, 10},
    {"Jose Mendez", "Jo0004", 10000, 100, 200, 11},
    {"Ana Jarquin", "An0005", 10000, 100, 200, 8},
};


int numTrabajadores = 5;
char usuariosRegistrados[20] = "admin";
char contraseñasRegistradas[20] = "admin123";


void registrarUsuario(){
    char Nuevacontrasena[20];
    char Nuevousuario[20];
    printf("ingrese su nuevo usuario: ");
    scanf("%s", Nuevousuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", Nuevacontrasena);
    strcpy(usuariosRegistrados, Nuevousuario) && strcpy(contraseñasRegistradas, Nuevacontrasena);
    printf("Usuario y contraseña registrados con exito");

}

void cambiarContraseña(){
    char usuarioActual[20];
    char contrasenaActual[20];
    char contrasenaNueva[20];

    printf("Ingrese su usuario actual: ");
    scanf("%s", usuarioActual);
    printf("Ingrese su contraseña actual: ");
    scanf("%s", contrasenaActual);

    if (strcmp(usuarioActual, usuariosRegistrados) == 0 && strcmp(contrasenaActual, contraseñasRegistradas) == 0){
        printf("Ingrese su nueva contraseña: ");
        scanf("%s", contrasenaNueva);
        strcpy(contraseñasRegistradas, contrasenaNueva);
        printf("Contraseña cambiada con exito");
    }
    else
    {
        printf("Usuario o contraseña incorrectos");
    }
    
    
}

int iniciarSesion(){
    char usuario[20];
    char contraseña[20];
    int intentosRestantes = MAX_INTENTOS;
    
    while (intentosRestantes > 0)
    {
        printf("Ingrese su usuario: ");
        scanf("%s", usuario);
        printf("Ingrese su contraseña: ");
        scanf("%s", contraseña);
        
        if(strcmp(usuario, usuariosRegistrados) == 0 && strcmp(contraseña, contraseñasRegistradas) == 0){
            printf("Inicio de sesion exitoso \n");
            return 1;
        }
        else
        {
            intentosRestantes --;
            printf("Usuario y/o contraseña incorrectos. Intentos restantes: %d\n", intentosRestantes);
        }
        
        
    }

    printf("Se han agotado los intentos de inicio de sesion.\n");
    return 0;
}

void presentacion(){
    printf("Bienvenido al sistema de planilla\n");
    printf("Universidad nacional de ingenieria");
    printf("Ingenieria en computacions\n");
    printf("DACTIC");
}

#include <stdio.h>

void VerTrabajadores() {
    // Imprimir el encabezado de la tabla
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-12s | %-10s | %-12s |\n", 
           "Nombre", "Codigo", "Salario", "Deducciones", "Comisiones", "Horas Extras");
    printf("--------------------------------------------------------------------------------\n");

    // Imprimir los datos de cada trabajador
    for (int i = 0; i < numTrabajadores; i++) {
        printf("| %-20s | %-10s | %-10.2f | %-12.2f | %-10.2f | %-12.2f |\n", 
               trabajadores[i].nombre, 
               trabajadores[i].codigo, 
               trabajadores[i].salario, 
               trabajadores[i].deducciones, 
               trabajadores[i].comisiones, 
               trabajadores[i].horasExtras);
    }
    printf("--------------------------------------------------------------------------------\n");
}




void BuscarTrabajador() {
    int opcion;
    char nombre[50];
    char codigo[10];
    
    printf("Buscar por: \n 1. Nombre \n 2. Codigo: \n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    
    
    switch (opcion) {
        case 1:
            printf("Ingrese el nombre del trabajador: ");
            fgets(nombre, sizeof(nombre), stdin);
            // Eliminar el carácter de nueva línea si está presente
            int encontrado_nombre = 0;
            nombre[strcspn(nombre, "\n")] = '\0';
            for (int i = 0; i < numTrabajadores; i++) {
                if (strcmp(trabajadores[i].nombre, nombre) == 0) {
                    printf("Nombre: %s \n", trabajadores[i].nombre);
                    printf("Codigo: %s \n", trabajadores[i].codigo);
                    printf("Salario: %.2f \n", trabajadores[i].salario);
                    printf("Deducciones: %.2f \n", trabajadores[i].deducciones);
                    printf("Comisiones: %.2f \n", trabajadores[i].comisiones);
                    printf("Horas extras: %.2f \n", trabajadores[i].horasExtras);
                    printf("\n");
                }
                encontrado_nombre = 1;
            }
            if (!encontrado_nombre){
                printf("Trabajador no encontrado.\n");
            }
            break;
        case 2:
            printf("Ingrese el codigo del trabajador: ");
            fgets(codigo, sizeof(codigo), stdin);
            // Eliminar el carácter de nueva línea si está presente
            int encontrado_codigo = 0;
            codigo[strcspn(codigo, "\n")] = '\0';
            for (int i = 0; i < numTrabajadores; i++) {
                if (strcmp(trabajadores[i].codigo, codigo) == 0) {
                    printf("Nombre: %s \n", trabajadores[i].nombre);
                    printf("Codigo: %s \n", trabajadores[i].codigo);
                    printf("Salario: %.2f \n", trabajadores[i].salario);
                    printf("Deducciones: %.2f \n", trabajadores[i].deducciones);
                    printf("Comisiones: %.2f \n", trabajadores[i].comisiones);
                    printf("Horas extras: %.2f \n", trabajadores[i].horasExtras);
                    printf("\n");
                }
                encontrado_codigo = 1;

            }
            if (!encontrado_codigo){
                printf("Trabajador no encontrado.\n");
            }
            break;
        default:
            system("cls");
            printf("Opcion invalida.\n");
            getch();
            break;
    }
}


void agregarTrabajador(){
    int opcion;
    if (numTrabajadores >= MAX_TRABAJADORES){
        printf("Maximo de trabajadores alcanzado\n");
        return;
    }


    Trabajador nuevotrabajador;
    printf("\nIngrese el nombre del trabajador: ");
    gets(nuevotrabajador.nombre);
    
    printf("\nIngrese el salario del trabajador: \n");
    scanf("%f", &nuevotrabajador.salario);
    printf("\nIngrese las deducciones del trabajador: \n");
    scanf("%f", &nuevotrabajador.deducciones);
    printf("\nIngrese las comisiones del trabajador: \n");
    scanf("%f", &nuevotrabajador.comisiones);
    printf("\nIngrese las horas extras del trabajador: \n");
    scanf("%f", &nuevotrabajador.horasExtras);

    sprintf(nuevotrabajador.codigo, "%.2s%04d", nuevotrabajador.nombre, numTrabajadores + 1);
    trabajadores[numTrabajadores++] = nuevotrabajador;
    
    printf("\nTrabajador agregado con exito\n");
    printf("\n");
    printf("================================\n");
    printf("\n");
    printf("Desea agregar otro trabajador?\n");
    printf("1. Si \n 2. No \n");
    scanf("%d", &opcion);

    if (opcion == 1) {
        agregarTrabajador();
    }
    else {
        return;
    }
}



void actualizarTrabajador(){
    char codigo[10];
    int opcion;
    printf("Ingrese el código del trabajador a actualizar: ");
    scanf("%s", codigo);

    for (int i = 0; i < numTrabajadores; i++) {
        if (strcmp(trabajadores[i].codigo, codigo) == 0) {
            printf("Actualizar: \n 1. Salario \n 2. Deducciones \n 3. Horas Extras \n 4. Comisiones\n");
            printf("Ingrese una opcion: \n");
            scanf("%d", &opcion);
            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo salario: ");
                    scanf("%f", &trabajadores[i].salario);
                    break;
                case 2:
                    printf("Ingrese las nuevas deducciones: ");
                    scanf("%f", &trabajadores[i].deducciones);
                    break;
                case 3:
                    printf("Ingrese las nuevas horas extras: ");
                    scanf("%f", &trabajadores[i].horasExtras);
                    break;
                case 4:
                    printf("Ingrese las nuevas comisiones: ");
                    scanf("%f", &trabajadores[i].comisiones);
                    break;
                default:
                    printf("Opción no válida.\n");
                    return;
            }
            printf("Trabajador actualizado exitosamente.\n");
            return;
        }
    }

    printf("Trabajador no encontrado.\n");
    
}

float calcularIngresos(Trabajador trabajador) {
    float salarioBase = trabajador.salario;
    float pagoHorasExtras = trabajador.horasExtras * 25; 
    float comisiones = trabajador.comisiones;
    
    float ingresos = salarioBase + pagoHorasExtras + comisiones;
    return ingresos;
}


float calcularEgresos(Trabajador trabajador) {
    float deducciones = trabajador.deducciones;
    float seguroSocial = trabajador.salario * 0.07; 
    float impuestoSobreRenta = 0.0;
    
    float ingresosTotales = calcularIngresos(trabajador);
    
    if (ingresosTotales*12 > 500000) {
        impuestoSobreRenta = (((((ingresosTotales*12) - 500000) * 0.30) + 82500)/ 12);
    } else if (ingresosTotales*12 > 330000) {
        impuestoSobreRenta = (((((ingresosTotales*12) - 350000) * 0.25) + 45000)/ 12);
    } else if (ingresosTotales*12 > 200000) {
        impuestoSobreRenta = (((((ingresosTotales*12) - 200000) * 0.20) + 15000)/ 12);
    }else if (ingresosTotales*12 > 100000) {
        impuestoSobreRenta = ((((ingresosTotales*12) - 100000) * 0.15)/ 12);
    }
    
    float egresos = deducciones + seguroSocial + impuestoSobreRenta;
    return egresos;
}


void calcularIngresosEgresosParaTodos(Trabajador trabajadores[], int numTrabajadores, float ingresos[], float egresos[]) {
    for (int i = 0; i < numTrabajadores; ++i) {
        ingresos[i] = calcularIngresos(trabajadores[i]);
        egresos[i] = calcularEgresos(trabajadores[i]);
    }
}


void mostrarPlanilla() {
    // Imprimir el encabezado de la tabla
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s | %-12s |\n", 
           "Codigo", "Nombre", "Salario Base", "Deducciones", "Horas Extras", "Comisiones", "Ingresos", "Egresos", "Neto a Pagar");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Imprimir los datos de cada trabajador
    for (int i = 0; i < numTrabajadores; i++) {
        float ingresos = calcularIngresos(trabajadores[i]);
        float egresos = calcularEgresos(trabajadores[i]);
        float neto = ingresos - egresos;
        printf("| %-10s | %-20s | %-12.2f | %-12.2f | %-12.2f | %-12.2f | %-12.2f | %-12.2f | %-12.2f |\n", 
               trabajadores[i].codigo, 
               trabajadores[i].nombre, 
               trabajadores[i].salario, 
               trabajadores[i].deducciones,
               trabajadores[i].horasExtras, 
               trabajadores[i].comisiones, 
               ingresos, 
               egresos, 
               neto);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void menuPlanilla(){
    int Opcion;
    do
    {
        printf("\n Menu Planilla \n");
        printf("1. Buscar trabajador \n");
        printf("2. Agregar trabajador \n");
        printf("3. Actualizar trabajador \n");
        printf("4. Ver Trabajdores\n");
        printf("5. Mostrar planilla \n");
        printf("6. Volver\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &Opcion);

        switch (Opcion){
            case 1:
                system("cls");
                printf("Buscar trabajador\n");
                printf("\n");
                BuscarTrabajador();
                break;
            case 2:
                system("cls");
                printf("Agregar trabajador\n");
                printf("\n");
                agregarTrabajador();
                break;
            case 3:
                system("cls");
                printf("Actualizar trabajador\n");
                printf("\n");
                actualizarTrabajador();
                break;
            case 4:
                system("cls");
                printf("Ver trabajadores\n");
                printf("\n");
                VerTrabajadores();

                break;
            case 5:
                system("cls");
                printf("Mostrar planilla\n");
                printf("\n");
                mostrarPlanilla();
                break;
            case 6:
                printf("Volver al menu principal\n");
                printf("\n");
                break;
            default:
                printf("Ingrese una opcion valida\n");
                printf("\n");
                break;
        }
    } while (Opcion != 6);
    


}


int menu(){
    int Opcion;
    do {
        int Opcion;
        printf("\n Menu \n");
        printf("1.Presentacion \n");
        printf("2. Menu de Planilla \n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &Opcion);

        switch (Opcion){
            
            case 1:
                system("cls");
                presentacion();
                break;
            case 2:
                system("cls");
                menuPlanilla();
                break;
            case 3:
                printf("Saliendo del sistema...\n");
                exit(0);
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
        }
        
    }while (Opcion != 3);


    return 0;
}



int menuInicio(){
    int Opcion;
    do{
        int Opcion;
        printf("\n Menu \n");
        printf("1. Iniciar Sesion\n");
        printf("2. Registrarse\n");
        printf("3. Cambiar contraseña\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &Opcion);
        switch(Opcion){
            case 1:
                if (iniciarSesion()){
                    menu();
                    
                }
                break;
            case 2:
                
                registrarUsuario();
                break;
            case 3:
                
                cambiarContraseña();
                break;
            case 4:
                printf("Saliendo del sistema...\n");
                exit(0);
                break;
            default:
                
                printf("Ingrese una opcion valida\n");
                getch();
                break;
        }
    } while (Opcion != 4);
    return 0;
}

int main(){
    menuInicio();
    return 0;
}