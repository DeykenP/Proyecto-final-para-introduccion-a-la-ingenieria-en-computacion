#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define MAX_TRABAJADORES 10
#define MAX_INTENTOS 3


//Estructura para trabajador tipo trabajador

typedef struct{
    char nombre[50];
    char codigo[10];
    float salario;
    float deducciones;
    float comisiones;
    float horasExtras;
}Trabajador;

//Areglo de trabajadores tipo trabajador
Trabajador trabajadores[MAX_TRABAJADORES] = {
    {"Juan Perez", "Ju0001", 10000, 100, 200, 20},
    {"Pedro Lopez", "Pe0002", 10000, 100, 200, 12},
    {"Maria Hurtado", "Ma0003", 10000, 100, 200, 10},
    {"Jose Mendez", "Jo0004", 10000, 100, 200, 11},
    {"Ana Jarquin", "An0005", 10000, 100, 200, 8},
};

//variables globales
int numTrabajadores = 5;
char usuariosRegistrados[20] = "admin";
char contraseñasRegistradas[20] = "admin123";


//funciones
void registrarUsuario(){
    char Nuevacontrasena[20];
    char Nuevousuario[20];
    printf("ingrese su nuevo usuario: ");
    scanf("%s", Nuevousuario);
    printf("Ingrese su contraseña: ");
    scanf("%s", Nuevacontrasena);
    strcpy(usuariosRegistrados, Nuevousuario); //string copy para guardar el nuevo usuario y la nueva contrasena en las contrasenas registradas
    strcpy(contraseñasRegistradas, Nuevacontrasena);
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
    //validamos que el usuario y contraseña existan para proceder al cambio
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
        //validamos que el usuario y contraseña existan usando strcmp 
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


//Presentacion usando asteriscos como separadores de texto para que se vea limpio y ordenado
void presentacion() {
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                       Bienvenido al sistema de planilla                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                      Universidad Nacional de Ingenieria                      *\n");
    printf("*                          Ingenieria en Computacion                           *\n");
    printf("*                                  DACTIC                                      *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
    printf("*                                                                              *\n");
    printf("*                               Integrantes:                                   *\n");
    printf("*                                                                              *\n");
    printf("*                    Deyken Adolfo Pulido Peters 2024-1944U                    *\n");
    printf("*                   Gustavo Adolfo Orozco Jarquin 2024-1938U                   *\n");
    printf("*                  Martin Enrrique Bermudez Gonzales 2024-1936U                *\n");
    printf("*                                                                              *\n");
    printf("*                                Docente:                                      *\n");
    printf("*                               Nelson Barrios                                 *\n");
    printf("*                                                                              *\n");
    printf("*                                Grupo: 1M2                                    *\n");
    printf("*                                Fecha: 01/04/2024                             *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n");
}


void VerTrabajadores() {
    // Imprimir el encabezado de la tabla mostrando solo los datos generales del trabajador
    printf("--------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-12s | %-10s | %-12s |\n", 
           "Nombre", "Codigo", "Salario", "Deducciones", "Comisiones", "Horas Extras");
    printf("--------------------------------------------------------------------------------\n");

    // Imprimir los datos de cada trabajador iterando sobre el arreglo trabajadores tomando cada uno de los modelos de datos de la estructora Trabajador
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



//funcion de buscar trabajador permitiendo buscar por nombre y por codigo utilizando un switch con estructuras for para iterar sobre el arreglo de trabajadores
void BuscarTrabajador() {
    int opcion;
    char nombre[50];
    char codigo[10];
    
    printf("Buscar por: \n 1. Nombre \n 2. Codigo: \n");
    printf("Ingrese la opción: ");
    scanf("%d", &opcion);
    getchar(); // Para limpiar el buffer de entrada
    
    switch (opcion) {
        case 1:
            printf("Ingrese el nombre del trabajador: ");
            fgets(nombre, sizeof(nombre), stdin); //Utilizamos fgets para el nombre del trabajador para poder capturar las cadenas de textos
            nombre[strcspn(nombre, "\n")] = '\0'; //aqui eliminamos el salto de linea que genera el fgets para evitar problemas con los buffers
            int encontrado_nombre = 0; //inicializamos esta variable para poder validar cuando se encuentra al trabajador
            for (int i = 0; i < numTrabajadores; i++) {
                if (strcmp(trabajadores[i].nombre, nombre) == 0) {
                    printf("Nombre: %s \n", trabajadores[i].nombre);
                    printf("Codigo: %s \n", trabajadores[i].codigo);
                    printf("Salario: %.2f \n", trabajadores[i].salario);
                    printf("Deducciones: %.2f \n", trabajadores[i].deducciones);
                    printf("Comisiones: %.2f \n", trabajadores[i].comisiones);
                    printf("Horas extras: %.2f \n", trabajadores[i].horasExtras);
                    printf("\n");
                    encontrado_nombre = 1;
                }
            }
            if (!encontrado_nombre){
                printf("Trabajador no encontrado.\n");
            }
            break;
        case 2:
            printf("Ingrese el código del trabajador: ");
            fgets(codigo, sizeof(codigo), stdin);//utilizamos fgets igual para capturar el codigo ya que contiene caracteres y numeros
            codigo[strcspn(codigo, "\n")] = '\0';
            int encontrado_codigo = 0;
            for (int i = 0; i < numTrabajadores; i++) {
                if (strcmp(trabajadores[i].codigo, codigo) == 0) {
                    printf("Nombre: %s \n", trabajadores[i].nombre);
                    printf("Codigo: %s \n", trabajadores[i].codigo);
                    printf("Salario: %.2f \n", trabajadores[i].salario);
                    printf("Deducciones: %.2f \n", trabajadores[i].deducciones);
                    printf("Comisiones: %.2f \n", trabajadores[i].comisiones);
                    printf("Horas extras: %.2f \n", trabajadores[i].horasExtras);
                    printf("\n");
                    encontrado_codigo = 1;
                }
            }
            if (!encontrado_codigo){
                printf("Trabajador no encontrado.\n");
            }
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
}


void agregarTrabajador() {
    int Opcion;
    if (numTrabajadores >= MAX_TRABAJADORES) {
        printf("No se puede agregar más trabajadores.\n");
        return;
    }
    
    Trabajador nuevoTrabajador; //creamos una variable nuevo trabajador de tipo trabajador para guardar los datos del nuevo trabajador tomando la estructura de datos Trabajador
    
    while (getchar() != '\n'); //Limpiamos el bufer de entrada para evitar problemas a la hora de la impresion y la entrada de datos
    
    printf("Ingrese el nombre del trabajador: ");
    fgets(nuevoTrabajador.nombre, sizeof(nuevoTrabajador.nombre), stdin);
    nuevoTrabajador.nombre[strcspn(nuevoTrabajador.nombre, "\n")] = '\0';//usamos esta linea de codigo para eliminar el salto de linea que genera fgets
    
    printf("Ingrese el salario del trabajador: ");
    while (scanf("%f", &nuevoTrabajador.salario) != 1) {
        while (getchar() != '\n'); // Limpiar buffer de entrada
        printf("Entrada inválida. Ingrese un número: ");
    }
    
    printf("Ingrese las deducciones del trabajador: ");
    while (scanf("%f", &nuevoTrabajador.deducciones) != 1) {
        while (getchar() != '\n'); // Limpiar buffer de entrada
        printf("Entrada inválida. Ingrese un número: ");
    }
    
    printf("Ingrese las comisiones del trabajador: ");
    while (scanf("%f", &nuevoTrabajador.comisiones) != 1) {
        while (getchar() != '\n'); // Limpiar buffer de entrada
        printf("Entrada inválida. Ingrese un número: ");
    }
    
    printf("Ingrese las horas extras del trabajador: ");
    while (scanf("%f", &nuevoTrabajador.horasExtras) != 1) {
        while (getchar() != '\n'); // Limpiar buffer de entrada
        printf("Entrada inválida. Ingrese un número: ");
    }
    
    // Asignar código al trabajador tomando las primeras dos letras del nombre y agregando una serie de 4 digitos en conseutivo 
    sprintf(nuevoTrabajador.codigo, "%.2s%04d", nuevoTrabajador.nombre, numTrabajadores + 1);

    trabajadores[numTrabajadores] = nuevoTrabajador;//agregamos el nuevo trabajador a nuestro arreglo de trabajadores
    numTrabajadores++;//incrementa el numero de trabajadores al agregar el trabajador
    
    printf("Trabajador agregado con exito, Presione enter para continuar.\n");
    getch();
    system("cls");

    printf("Desea agregar otro trabajador?\n");
    printf("1. Sí\n");
    printf("2. No\n");
    scanf("%d", &Opcion);
    if (Opcion == 1) {
        system("cls");
        agregarTrabajador();
    }
    system("cls");
}



void actualizarTrabajador(){
    char codigo[10];
    int opcion;
    printf("Ingrese el código del trabajador a actualizar: ");//Utilizamos codigo por comodidad a demas para ahorrar espacio ya que si permitimos la busqueda por nombre seria mucho codigo y podria generar errores
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
            }//dependiendo de que seleccione actualizar el usuario en la estructura switch solo guardamos los datos en la posicion i del arreglo en el modelo de la estructura
            printf("Trabajador actualizado exitosamente.\n");
            return;
        }
    }

    printf("Trabajador no encontrado.\n");//En caso de que no se encuentre al trabajador
    
}

float calcularIngresos(Trabajador trabajador) {
    float salarioBase = trabajador.salario;
    float pagoHorasExtras = trabajador.horasExtras * (((trabajador.salario / 30) / 8) * 2);
    float comisiones = trabajador.comisiones;

    float ingresos = salarioBase + pagoHorasExtras + comisiones;
    return ingresos;
}//calculamos ingresos, metemos una variable trabajador de tipo Trabajador como parametro para calcular los ingresos del trabajador

float calcularEgresos(Trabajador trabajador) {
    float deducciones = trabajador.deducciones;
    float seguroSocial = trabajador.salario * 0.07;
    float impuestoSobreRenta = 0.0;

    float ingresosTotales = calcularIngresos(trabajador);//creamos una variable ingresos totales y guarda el valor de los ingresos que retorna la funcion calcularIngresos para usar ese valor en el calculo del IR

    if ((ingresosTotales - seguroSocial) * 12 > 500000) {
        impuestoSobreRenta = ((((((ingresosTotales - seguroSocial) * 12) - 500000) * 0.30) + 82500) / 12);
    } else if ((ingresosTotales - seguroSocial) * 12 > 330000) {
        impuestoSobreRenta = ((((((ingresosTotales - seguroSocial) * 12) - 350000) * 0.25) + 45000) / 12);
    } else if ((ingresosTotales - seguroSocial) * 12 > 200000) {
        impuestoSobreRenta = ((((((ingresosTotales - seguroSocial) * 12) - 200000) * 0.20) + 15000) / 12);
    } else if ((ingresosTotales - seguroSocial) * 12 > 100000) {
        impuestoSobreRenta = (((((ingresosTotales - seguroSocial) * 12) - 100000) * 0.15) / 12);
    }

    float egresos = deducciones + seguroSocial + impuestoSobreRenta;
    return egresos;
}//calculamos egresos, metemos una variable trabajador de tipo Trabajador como parametro para calcular los egresos del trabajador

void mostrarPlanilla() {
    // Imprimir el encabezado de la tabla, la taba se imprime asignando espacios, por ejemplo el -20s alinea el texto a la izquierda con un ancho de 20 Caracteres
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-12s | %-12s | %-12s | %-15s | %-12s | %-12s | %-15s | %-20s | %-12s | %-12s | %-12s |\n", 
           "Nombre", "Salario Base", "Horas Extras", "Pago H.E.", "Comisiones", "Total Ingresos", "INSS laboral", "IR", "Otras deducciones", "Deducciones totales", "Neto", "INSS patronal", "INATEC");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Imprimir los datos de cada trabajador
    for (int i = 0; i < numTrabajadores; i++) {
        float ingresos = calcularIngresos(trabajadores[i]);
        float egresos = calcularEgresos(trabajadores[i]);
        float neto = ingresos - egresos;
        float inssPatronal = ingresos * 0.225;
        float inatec = trabajadores[i].salario * 0.02;
        float seguroSocial = trabajadores[i].salario * 0.07;
        float impuestoSobreRenta = 0.0;
        
        if ((ingresos - seguroSocial) * 12 > 500000) {
            impuestoSobreRenta = ((((((ingresos-seguroSocial) * 12) - 500000) * 0.30) + 82500) / 12);
        } else if ((ingresos - seguroSocial) * 12 > 330000) {
            impuestoSobreRenta = ((((((ingresos-seguroSocial) * 12) - 350000) * 0.25) + 45000) / 12);
        } else if ((ingresos - seguroSocial) * 12 > 200000) {
            impuestoSobreRenta = ((((((ingresos-seguroSocial) * 12) - 200000) * 0.20) + 15000) / 12);
        } else if ((ingresos - seguroSocial) * 12 > 100000) {
            impuestoSobreRenta = (((((ingresos-seguroSocial) * 12) - 100000) * 0.15) / 12);
        }

        printf("| %-20s | %-15.2f | %-12.2f | %-12.2f | %-12.2f | %-15.2f | %-12.2f | %-12.2f | %-15.2f | %-20.2f | %-12.2f | %-12.2f | %-12.2f |\n", 
               trabajadores[i].nombre, 
               trabajadores[i].salario, 
               trabajadores[i].horasExtras, 
               (trabajadores[i].horasExtras * (((trabajadores[i].salario / 30) / 8) * 2)),
               trabajadores[i].comisiones, 
               ingresos, 
               seguroSocial, 
               impuestoSobreRenta, 
               trabajadores[i].deducciones,
               (trabajadores[i].deducciones + seguroSocial + impuestoSobreRenta), 
               neto, 
               inssPatronal, 
               inatec);
    }
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void menuPlanilla(){
    int Opcion; //Menu sencillo utilizando Estructura switch para hacer llamado de cada una de las funciones dependiendo de la eleccion
    do
    {
        printf("\n Menu Planilla \n");
        printf("1. Buscar trabajador \n");
        printf("2. Agregar trabajador \n");
        printf("3. Actualizar trabajador \n");
        printf("4. Ver Trabajadores\n");
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
    int Opcion;//Menu principal
    do {
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
        
    }while (Opcion != 3);//si el usuario selecciona 3 automaticamente se cierra el sistema


    return 0;
}



int menuInicio(){
    int Opcion; // Menu de inicio donde se muestran las opciones
    char c; // Variable para leer caracteres no numéricos

    do {
        printf("\n Menu \n");
        printf("1. Iniciar Sesion\n");
        printf("2. Registrarse\n");
        printf("3. Cambiar contraseña\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");

        // Leer entrada y validar si es un número
        if (scanf("%d", &Opcion) != 1) {
            printf("Ingrese una opcion valida\n");

            // Limpiar el buffer de entrada
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // Volver a pedir la opción
        }

        switch(Opcion) {
            case 1:
                if (iniciarSesion()) {
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
                break;
        }
    } while (Opcion != 4);

    return 0;
}


//cuerpo principal del codigo para hacer llamado al menu de inicio
int main(){
    menuInicio();
    return 0;
}