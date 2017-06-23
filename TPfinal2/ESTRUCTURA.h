/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   struct.h
 * Author: usuario
 *
 * Created on 21 de junio de 2017, 16:57
 */

#ifndef STRUCT_H
#define STRUCT_H

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

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* STRUCT_H */

