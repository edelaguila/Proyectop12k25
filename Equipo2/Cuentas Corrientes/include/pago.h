//Programado por Britany Mishel Hernandez Davila 9959-24-4178


#ifndef PAGO_H
#define PAGO_H

#include <iostream>
using namespace std;

class pago
{
    public:
        pago(); //Constructor de la clase pago
        void menuPagos(); //Menu de opcciones de la clase pagos
        void registrarPago(); //Aqui se registra un nuevo pago
        void listarPagosPorProveedor(); //Muestra los pagos especificamente a un proveedor/Acreedor
        void listarHistorialPagos(); //Muestra todo el historial de pagos
        void mostrarCuentasPorPagar(); //Muestra las facturas pendientes de pago
        void buscarPagosPorFacura(); //Para realizar una busqueda con el id de la factura especifica

        void reportePagos(); //Reporte todos los pagos registrados
        void reporteCuentasPorPagar(); //Reporte para todas las facturas pendientes de pago
        bool backupPagos();

    private:
        string idPago; //Id del pago realizado
        string idFactura; //Id de la factura asociada al pago
        string fechaPago; //Fecha en que se realizo el pago
        float montoPago; //Monto del pago realizado
        string metodoPago; // efectivo, transferencia, cheque, etc.
        string nitEntidad; //Nit del acreedor o proveedor a quien se le pago
        string tipoEntidad; //Tipo de entidad a quien se pago
        string estadoPago; // programado, ejecutado, rechazado
};
#endif // PAGO_H
