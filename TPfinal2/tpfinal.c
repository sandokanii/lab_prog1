/* 
 * File:   TPfinal.c
 * Author: sandro ivanovich y roberto calisto
 *
 * Created on 19 de junio de 2017, 15:41
 0 = Negro 
1 = azul 
2 = verde 
3 = Aqua 
4 = Rojo 
5 = Púrpura 
6 = Amarillo 
7 = blanco 
8 = gris 
9 = Azul claro 
A = Luz Verde 
B = Aqua Luz 
C = Rojo 
D = luz violeta 
E = = Amarillo claro 
F = blanco brillante
  */

#include <stdio.h>
#include <stdlib.h>
 
void menu();
 
typedef struct{
    int codigo;
    char detalle[30];
    float precio;
    float costo;
    char prov[30];
}Producto;
 
typedef struct{
    int codigo;
    char nombre[30];
    char telefono[30];
    char email[30];
}Proveedores;
 
typedef struct{
    char cuit[30];
    char cliente[30];
    char fechaalta[11];
    char email[30];
    char telefono[30];
}Clientes;
 
typedef struct{
    int codigo;
    char fecha[11];
    char cuit[30];
    float total;
    float descuento;
}Presupuesto;
 
typedef struct{
    int codigo;
    char producto[30];
    int cantidad;
    float precio;
}DetPresupuesto;
 
void AltaPresu();
void BajaPresu();
void ModifPresu();
void ListadoPresu();
void AltaProds();
void BajaProds();
void ModifProds();
void ListadoProds();
void AltaProvs();
void BajaProvs();
void ModifProvs();
void ListadoProvs();
void AltaClientes();
void BajaClientes();
void ModifClientes();
void ListadoClientes();
 
int main(){
    menu();
    return 0;
}
 
void menu(){
    int opcion,opcion2;
    do{
		system("color E");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");        
        printf("             -------------------------------------------\n");
        printf("                          1) Presupuestos\n");
        printf("                          2) Productos\n");
        printf("                          3) Proveedores\n");
        printf("                          4) Clientes\n");
        printf("                          5) Salir\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        
        scanf("%d",&opcion);
        system("clear");
        system("color A");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("                          1) Alta\n");
        printf("                          2) Baja\n");
        printf("                          3) Modificacion\n");
        printf("                          4) Listado\n");
        printf("                          5) Volver al Menu\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        printf("             -------------------------------------------\n");
        scanf("%d",&opcion2);
        system("clear");
            switch (opcion){
                case 1:
                        switch(opcion2){
                            case 1:
                                AltaPresu();
                                break;
                            case 2:
                                BajaPresu();
                                break;
                            case 3:
                                ModifPresu();
                                break;
                            case 4:
                                ListadoPresu();
                                break;
                            case 5:
                                break;
                        }
                    break;
                case 2:
                        switch(opcion2){
                            case 1:
                                AltaProds();
                                break;
                            case 2:
                                BajaProds();
                                break;
                            case 3:
                                ModifProds();
                                break;
                            case 4:
                                ListadoProds();
                                break;
                            case 5:
                                break;
                        }
                    break;
                case 3:
                        switch(opcion2){
                            case 1:
                               AltaProvs();
                                break;
                            case 2:
                                BajaProvs();
                                break;
                            case 3:
                                ModifProvs();
                                break;
                            case 4:
                                ListadoProvs();
                                break;
                            case 5:
                                break;
                        }
                    break;
                case 4:
                        switch(opcion2){
                            case 1:
                                AltaClientes();
                                break;
                            case 2:
                                BajaClientes();
                                break;
                            case 3:
                                ModifClientes();
                                break;
                            case 4:
                                ListadoClientes();
                                break;
                            case 5:
                                break;
                        }
                    break;
                case 5:
                    break;
 
            }
    }while (opcion!=5);
}
 

//**************   PRESUPUESTOS   ************************
void AltaPresu(){   
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","ab");
    printf("Ingrese Codigo\n");
    scanf("%i",&presu.codigo);
    printf("Ingrese Fecha\n");
    scanf("%s",presu.fecha);
    printf("Ingrese CUIT\n");
    scanf("%s",presu.cuit);
    printf("Ingrese Total\n");
    scanf("%f",&presu.total);
    printf("Ingrese Descuento\n");
    scanf("%f",&presu.descuento);
    fseek(pf,0L,SEEK_END);
    fwrite(&presu,sizeof(Presupuesto),1,pf);
    fclose(pf);
    system("clear");
  }
void BajaPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    int codigoaux;
    pf = fopen("Presupuesto.dat","r");
    pfaux = fopen("Presupuestoaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
} 
void ModifPresu(){
    FILE *pf,*pfaux;
    Presupuesto presu;
    int codigoaux;
    pf = fopen("Presupuesto.dat","r");
    pfaux = fopen("Presupuestoaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }else{
                    printf("Ingrese Fecha\n");
                    scanf("%s",presu.fecha);
                    printf("Ingrese CUIT\n");
                    scanf("%s",presu.cuit);
                    printf("Ingrese Total\n");
                    scanf("%f",&presu.total);
                    printf("Ingrese Descuento\n");
                    scanf("%f",&presu.descuento);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
}
void ListadoPresu(){
    FILE *pf;
    FILE *pfaux;
    Presupuesto presu;
    int codigoaux;
    pf = fopen("Presupuesto.dat","r");
    pfaux = fopen("Presupuestoaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&presu,sizeof(Presupuesto),1,pf);
        while (!feof(pf)){
                if (presu.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&presu,sizeof(Presupuesto),1,pfaux);
                }
            fread(&presu,sizeof(Presupuesto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Presupuesto.dat");
    rename("Presupuestoaux.dat","Presupuesto.dat");
}
  //*************   PRODUCTOS     ************************
void AltaProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&prod.codigo);
    printf("Ingrese Detalle\n");
    scanf("%s",prod.detalle);
    printf("Ingrese Precio\n");
    scanf("%f",&prod.precio);
    printf("Ingrese Costo\n");
    scanf("%f",&prod.costo);
    printf("Ingrese Proveedor\n");
    scanf("%s",prod.prov);
    fseek(pf,0L,SEEK_END);
    fwrite(&prod,sizeof(Producto),1,pf);
    fclose(pf);
    system("clear");
 }
void BajaProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
} 
void ModifProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prod,sizeof(Producto),1,pf);
        while (!feof(pf)){
                if (prod.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }else{
                    printf("Ingrese Detalle\n");
                    scanf("%s",prod.detalle);
                    printf("Ingrese Precio\n");
                    scanf("%f",&prod.precio);
                    printf("Ingrese Costo\n");
                    scanf("%f",&prod.costo);
                    printf("Ingrese Proveedor\n");
                    scanf("%s",prod.prov);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prod,sizeof(Producto),1,pfaux);
                }
            fread(&prod,sizeof(Producto),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Productos.dat");
    rename("Productosaux.dat","Productos.dat");
}
void ListadoProds(){
    FILE *pf;
    Producto prod;
    pf = fopen("Productos.dat","r");
    fread(&prod,sizeof(Producto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %.2f ; %.2f ; %s\n",prod.codigo,prod.detalle,prod.precio,prod.costo,prod.prov);
        fread(&prod,sizeof(Producto),1,pf);
    }
    fclose(pf);
}
//***************   CLIENTES      ************************
void AltaClientes(){
    FILE *pf;
    Clientes  cliente;
    pf = fopen("Clientes.dat","a");
    printf("Ingrese CUIT\n");
    scanf("%s",cliente.cuit);
    printf("Ingrese Cliente\n");
    scanf("%s",cliente.cliente);
    printf("Ingrese Fecha de alta\n");
    scanf("%s",cliente.fechaalta);
    printf("Ingrese Email\n");
    scanf("%s",cliente.email);
    printf("Ingrese Telefono\n");
    scanf("%s",cliente.telefono);
    fseek(pf,0L,SEEK_END);
    fwrite(&cliente,sizeof(Clientes),1,pf);
    fclose(pf);
    system("clear");
}
void BajaClientes(){
 FILE *pf,*pfaux;
    Clientes  cliente;
    char cuitaux;
    pf = fopen("Clientes.dat","r");
    pfaux = fopen("Clientesaux.dat","a");
    printf("Ingrese CUIT\n");
    scanf("%s",&cuitaux);
    fread(&cliente,sizeof(Clientes),1,pf);
        while (!feof(pf)){
                if (cliente.cuit != cuitaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&cliente,sizeof(Clientes),1,pfaux);
                }
            fread(&cliente,sizeof(Clientes),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat","Clientes.dat");
} 
void ModifClientes(){
FILE *pf,*pfaux;
    Clientes  cliente;
    char cuitaux;
    pf = fopen("Clientes.dat","r");
    pfaux = fopen("Clientesaux.dat","a");
    printf("Ingrese CUIT\n");
    scanf("%s",&cuitaux);
    fread(&cliente,sizeof(Clientes),1,pf);
        while (!feof(pf)){
                if (cliente.cuit != cuitaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&cliente,sizeof(Clientes),1,pfaux);
                }else{
					printf("Ingrese CUIT\n");
					scanf("%s",cliente.cuit);
					printf("Ingrese Cliente\n");
					scanf("%s",cliente.cliente);
					printf("Ingrese Fecha de alta\n");
					scanf("%s",cliente.fechaalta);
					printf("Ingrese Email\n");
					scanf("%s",cliente.email);
					printf("Ingrese Telefono\n");
					scanf("%s",cliente.telefono);
					fseek(pf,0L,SEEK_END);
					fwrite(&cliente,sizeof(Clientes),1,pf);
					fclose(pf);
					system("clear");
                   }
            fread(&cliente,sizeof(Clientes),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Clientes.dat");
    rename("Clientesaux.dat","Clientes.dat");
}
void ListadoClientes(){
FILE *pf;
    Clientes cliente;
    pf = fopen("Clientes.dat","r");
    fread(&cliente,sizeof(Clientes),1,pf);
    while(!feof(pf)){
        printf("%s ; %s ; %s ; %s ; %s \n",cliente.cuit,cliente.cliente,cliente.fechaalta,cliente.email,cliente.telefono);
        fread(&cliente,sizeof(Clientes),1,pf);
    }
    fclose(pf);
}
//***************   PROVEEDORES    ***********************
void AltaProvs(){
    FILE *pf;
    Proveedores  proveedor;
    pf = fopen("Proveedores.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&proveedor.codigo);
    printf("Ingrese Nombre\n");
    scanf("%c",proveedor.nombre);
    printf("Ingrese Telefono\n");
    scanf("%c",proveedor.telefono);
    printf("Ingrese Email\n");
    scanf("%c",proveedor.email);
    fseek(pf,0L,SEEK_END);
    fwrite(&proveedor,sizeof(Proveedores),1,pf);
    fclose(pf);
    system("clear");
}
void BajaProvs(){
    FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Provedores.dat","r");
    pfaux = fopen("Proveedoresaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&proveedor,sizeof(Proveedores),1,pf);
        while (!feof(pf)){
                if (proveedor.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }
            fread(&proveedor,sizeof(Proveedores),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.dat");
    rename("Proveedoresaux.dat","Proveedores.dat");
} 
void ModifProvs(){
    FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Provedores.dat","r");
    pfaux = fopen("Proveedoresaux.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&codigoaux);
    fread(&proveedor,sizeof(Proveedores),1,pf);
        while (!feof(pf)){
                if (proveedor.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }else{
                    printf("Ingrese Nombre\n");
                    scanf("%s",proveedor.nombre);
                    printf("Ingrese Telefono\n");
                    scanf("%s",proveedor.telefono);
                    printf("Ingrese Email\n");
                    scanf("%s",proveedor.email);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&proveedor,sizeof(Proveedores),1,pfaux);
                }
            fread(&proveedor,sizeof(Proveedores),1,pf);
        }
    fclose(pf);
    fclose(pfaux);
    remove("Proveedores.dat");
    rename("Proveedoresaux.dat","Proveedores.dat");
}
void ListadoProvs(){
    FILE *pf;
    Proveedores proveedor;
    pf = fopen("Proveedores.dat","r");
    fread(&proveedor,sizeof(Producto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %s ; %s \n",proveedor.codigo,proveedor.nombre,proveedor.telefono,proveedor.email);
        fread(&proveedor,sizeof(Proveedores),1,pf);
    }
    fclose(pf);
}
