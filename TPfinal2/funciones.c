/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "estruct.c"

void AltaPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","a");
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
    menu();
}
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
    menu();
     
 }
void BajaClientes(){
 FILE *pf,*pfaux;
    Clientes  cliente;
    int cuitaux;
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
    Clientes cliente;
    int cuitaux;
    pf = fopen("clientes.dat","r");
    pfaux = fopen("clientesaux.dat","a");
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
void AltaProvs(){
    FILE *pf;
    Proveedores  proveedor;
    pf = fopen("proveedores.dat","a");
    printf("Ingrese Codigo\n");
    scanf("%i",&proveedor.codigo);
    printf("Ingrese Nombre\n");
    scanf("%s",proveedor.nombre);
    printf("Ingrese Telefono\n");
    scanf("%s",proveedor.telefono);
    printf("Ingrese Email\n");
    scanf("%s",proveedor.email);
    fseek(pf,0L,SEEK_END);
    fwrite(&proveedor,sizeof(Proveedores),1,pf);
    fclose(pf);
    system("clear");
    menu();
 }
void ListadoPresu(){
    FILE *pf;
    Presupuesto presu;
    pf = fopen("Presupuesto.dat","r");
    fread(&presu,sizeof(Presupuesto),1,pf);
    while(!feof(pf)){
        printf("%i ; %s ; %s ; %.2f ; %.2f\n",presu.codigo,presu.fecha,presu.cuit,presu.total,presu.descuento);
        fread(&presu,sizeof(Presupuesto),1,pf);
    }
    fclose(pf);
}
void ListadoClientes(){
    FILE *pf;
    Clientes cliente;
    pf = fopen("Clientes.dat","r");
    fread(&cliente,sizeof(cliente),1,pf);
    while(!feof(pf)){
        printf("%s ; %s ; %s ; %s ; %s \n",cliente.cuit,cliente.cliente,cliente.email,cliente.fechaalta,cliente.telefono);
        fread(&cliente,sizeof(Clientes),1,pf);
    }
    fclose(pf);
} 
void ModifPresu(){
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
void BajaProvs(){
  FILE *pf,*pfaux;
    Proveedores proveedor;
    int codigoaux;
    pf = fopen("Proveedores.dat","r");
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
    menu();
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
void ModifProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Codigo\n");
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
void BajaProds(){
    FILE *pf,*pfaux;
    Producto prod;
    int codigoaux;
    pf = fopen("Productos.dat","r");
    pfaux = fopen("Productosaux.dat","a");
    printf("Ingrese Codigo\n");
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