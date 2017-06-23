/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */#include "funciones.c"
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

void menu();
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