//estructura de una factura 
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define IVA 0.15

struct direccion {
  char ciudad[40];
  char sector[40];
  char calle[40];
  char codigo[5];
};

struct cabecera {
  char empresa[40];
  char ruc[15];
  char numFactura[100];
  char fecha[10];
  char vendedor[40];
  char cliente[40];
  char cedula[15];
  struct direccion direccion;
  char telefono[10];
  char correo[40];
};

struct detalles {
  char codigo[5];
  char producto[40];
  int cantidad;
  float precio;
  float valor;
};

struct factura {
  struct cabecera cabecera;
  struct detalles detalles;
  float subtotal;
  float iva; 
  float total; 
};

int main(void) {

  struct factura factura = {{"TECH SOLUTIONS S.A" , "1234567890001" , "001" , "01/01/2024" , "Catalina Pedregoza" , "Maria Gomez" , "45351291" , {"Quito" , "Tumbaco" , "Rumiñahui" , "420"} , "0994552206" , "mariagomez@gmail.com"} , { "001" , "Laptop HP" , 1 , 750.00 , (750.00 * 1)} , (750.00 * 1) , (750.00 * 1) * IVA , (750.00 * 1) + ((750.00 * 1) * IVA) } ; 
  
  printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
  printf("\e[1;34m                               FACTURA                            \e[0m\n");
  printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
  printf("EMPRESA: %s\t\t\tRUC: %s\n\nNo.FACTURA: %s\n\nFECHA DE EMISION: %s\n\nNOMBRE VENDEDOR: %s\n",factura.cabecera.empresa, factura.cabecera.ruc, factura.cabecera.numFactura, factura.cabecera.fecha, factura.cabecera.vendedor );

  printf("-----------------------------------------------------------------------\n");
  printf("\e[1;34m                          DATOS CLIENTE                           \e[0m\n");
  printf("-----------------------------------------------------------------------\n");
  printf("NOMBRE: %s\n\nNo.CEDULA: %s\n\nDIRECCION:\n\t\tCIUDAD: %s\n\n\t\tSECTOR: %s\n\n\t\tCALLE: %s\n\n\t\tCODIGO POSTAL: %s\n\nCELULAR: %s\n\nCORREO ELECTRONICO: %s\n",factura.cabecera.cliente, factura.cabecera.cedula, factura.cabecera.direccion.ciudad, factura.cabecera.direccion.sector, factura.cabecera.direccion.calle, factura.cabecera.direccion.codigo, factura.cabecera.telefono, factura.cabecera.correo  );

  printf("-----------------------------------------------------------------------\n");
  printf("\e[1;34m                          DETALLE DE COMPRA                            \e[0m\n");
  printf("-----------------------------------------------------------------------\n");
  printf("CODIGO: %s\t\t\tNOMBRE DEL PRODUCTO: %s\n\nCANTIDAD: %d\t\t\tPRECIO UNITARIO: %.2f\n\n\t\t\t\tVALOR TOTAL: %.2f\n\n\n-----------------------------------------------------------------------\nSUBTOTAL: %.2f\n\nIVA (15%%): %.2f\n\nTOTAL A PAGAR: %.2f\n\n", factura.detalles.codigo, factura.detalles.producto, factura.detalles.cantidad, factura.detalles.precio, factura.detalles.valor, factura.subtotal, factura.iva, factura.total );
  printf("-----------------------------------------------------------------------\n");
  
  return 0;
}