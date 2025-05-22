#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>
#include "bitacora.h"
#include "producto.h"
#include "utils.h"  // <- Importante para el cifrado XOR

using namespace std;

class Compras {
public:
    static void registrarCompra(vector<Producto>& listaCompras);
    static void mostrarHistorial(const vector<Producto>& listaCompras);
    static void buscarPorProveedor(const vector<Producto>& listaCompras);
    static double calcularTotalGastado(const vector<Producto>& listaCompras);
    static void guardarCompras(const vector<Producto>& listaCompras);
    static vector<Producto> cargarCompras();

private:
    static void escribirString(ofstream& archivo, const string& str);
    static bool leerString(ifstream& archivo, string& str);
};

// Funciones públicas

void Compras::registrarCompra(vector<Producto>& listaCompras) {
    Producto nuevoProducto;
    string input;
    double precio;
    int cantidad;

    cout << "\n--- REGISTRAR NUEVA COMPRA ---\n";

    cout << "Código del producto: ";
    getline(cin, input);
    nuevoProducto.setCodigo(input);

    cout << "Nombre del producto: ";
    getline(cin, input);
    nuevoProducto.setNombre(input);

    cout << "Descripción/Proveedor: ";
    getline(cin, input);
    nuevoProducto.setDescripcion(input);

    cout << "Precio unitario: $";
    while (!(cin >> precio) || precio <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Ingrese un precio válido: $";
    }
    nuevoProducto.setPrecio(precio);

    cout << "Cantidad: ";
    while (!(cin >> cantidad) || cantidad <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Ingrese una cantidad válida: ";
    }
    nuevoProducto.setStock(cantidad);
    cin.ignore();

    listaCompras.push_back(nuevoProducto);
    guardarCompras(listaCompras);  // Guardar en archivo binario cifrado

    cout << "✅ Compra registrada exitosamente\n";
    Bitacora::registrarAccion(Bitacora::obtenerUsuarioActual(),
                             CodigosAccion::CREACION_COMPRA,
                             "Nueva compra: " + nuevoProducto.getNombre());
}

void Compras::mostrarHistorial(const vector<Producto>& listaCompras) {
    if (listaCompras.empty()) {
        cout << "\n⚠ No hay compras registradas\n";
        return;
    }

    cout << "\n--- HISTORIAL DE COMPRAS (" << listaCompras.size() << ") ---\n";
    cout << left << setw(10) << "CÓDIGO"
         << setw(25) << "NOMBRE"
         << setw(20) << "PROVEEDOR"
         << setw(10) << "PRECIO"
         << setw(10) << "CANTIDAD"
         << setw(12) << "SUBTOTAL" << endl;
    cout << string(90, '-') << endl;

    for (const auto& producto : listaCompras) {
        cout << left << setw(10) << producto.getCodigo()
             << setw(25) << producto.getNombre().substr(0, 24)
             << setw(20) << producto.getDescripcion().substr(0, 19)
             << "$" << right << setw(9) << fixed << setprecision(2) << producto.getPrecio()
             << setw(10) << producto.getStock()
             << "$" << setw(11) << (producto.getPrecio() * producto.getStock()) << endl;
    }

    cout << string(90, '=') << endl;
    cout << right << setw(79) << "TOTAL GASTADO: $"
         << fixed << setprecision(2) << calcularTotalGastado(listaCompras) << endl;
}

void Compras::buscarPorProveedor(const vector<Producto>& listaCompras) {
    if (listaCompras.empty()) {
        cout << "\n⚠ No hay compras registradas\n";
        return;
    }

    string proveedor;
    cout << "\nIngrese nombre del proveedor a buscar: ";
    getline(cin, proveedor);
    transform(proveedor.begin(), proveedor.end(), proveedor.begin(), ::tolower);

    bool encontrado = false;
    cout << "\n--- RESULTADOS PARA: " << proveedor << " ---\n";

    for (const auto& producto : listaCompras) {
        string descLower = producto.getDescripcion();
        transform(descLower.begin(), descLower.end(), descLower.begin(), ::tolower);

        if (descLower.find(proveedor) != string::npos) {
            cout << "Código: " << producto.getCodigo() << "\n"
                 << "Producto: " << producto.getNombre() << "\n"
                 << "Precio: $" << fixed << setprecision(2) << producto.getPrecio() << "\n"
                 << "Cantidad: " << producto.getStock() << "\n"
                 << "Subtotal: $" << (producto.getPrecio() * producto.getStock()) << "\n\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "🔍 No se encontraron compras de ese proveedor\n";
    }
}

double Compras::calcularTotalGastado(const vector<Producto>& listaCompras) {
    double total = 0.0;
    for (const auto& producto : listaCompras) {
        total += producto.getPrecio() * producto.getStock();
    }
    return total;
}

// ✅ GUARDADO EN BINARIO CON CIFRADO XOR
void Compras::guardarCompras(const vector<Producto>& listaCompras) {
    ofstream archivo("compras.dat", ios::binary);
    if (!archivo) {
        cerr << "❌ Error al guardar compras.\n";
        return;
    }

    for (const auto& p : listaCompras) {
        escribirString(archivo, xorEncryptDecrypt(p.getCodigo()));
        escribirString(archivo, xorEncryptDecrypt(p.getNombre()));
        escribirString(archivo, xorEncryptDecrypt(p.getDescripcion()));

        double precio = p.getPrecio();
        int stock = p.getStock();
        archivo.write(reinterpret_cast<const char*>(&precio), sizeof(double));
        archivo.write(reinterpret_cast<const char*>(&stock), sizeof(int));
    }

    archivo.close();
}

// ✅ CARGA DESDE BINARIO CON DESCIFRADO XOR
vector<Producto> Compras::cargarCompras() {
    vector<Producto> lista;
    ifstream archivo("compras.dat", ios::binary);
    if (!archivo) return lista;

    while (archivo.peek() != EOF) {
        Producto p;
        string str;

        if (!leerString(archivo, str)) break;
        p.setCodigo(xorEncryptDecrypt(str));

        if (!leerString(archivo, str)) break;
        p.setNombre(xorEncryptDecrypt(str));

        if (!leerString(archivo, str)) break;
        p.setDescripcion(xorEncryptDecrypt(str));

        double precio;
        int stock;
        archivo.read(reinterpret_cast<char*>(&precio), sizeof(double));
        archivo.read(reinterpret_cast<char*>(&stock), sizeof(int));
        p.setPrecio(precio);
        p.setStock(stock);

        lista.push_back(p);
    }

    archivo.close();
    return lista;
}

// Funciones privadas

void Compras::escribirString(ofstream& archivo, const string& str) {
    size_t len = str.length();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
    archivo.write(str.c_str(), len);
}

bool Compras::leerString(ifstream& archivo, string& str) {
    size_t len;
    archivo.read(reinterpret_cast<char*>(&len), sizeof(size_t));
    if (archivo.eof()) return false;

    str.resize(len);
    archivo.read(&str[0], len);
    return true;
}
