<<<<<<< HEAD
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
=======
#include "compras.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
#include <limits>
#include "menu_general.h"
#include "bitacora.h"
#include "producto.h"
#include "utils.h"  // <- Importante para el cifrado XOR

using namespace std;
<<<<<<< HEAD

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
    cout << "Usuario actual: " << MenuGeneral::getUsuarioActual() << std::endl;

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
=======

void Compras::registrarCompra(vector<Producto>& listaCompras) {
    try {
        Producto p;
        string temp;

        cout << "Ingrese código del producto: ";
        getline(cin, temp);
        if (temp.empty()) throw invalid_argument("❌ El código no puede estar vacío.");
        p.setCodigo(temp);

        cout << "Ingrese nombre del producto: ";
        getline(cin, temp);
        if (temp.empty()) throw invalid_argument("❌ El nombre no puede estar vacío.");
        p.setNombre(temp);

        cout << "Ingrese descripción del producto: ";
        getline(cin, temp);
        if (temp.empty()) throw invalid_argument("❌ La descripción no puede estar vacía.");
        p.setDescripcion(temp);

        double precio;
        cout << "Ingrese precio: ";
        if (!(cin >> precio) || precio < 0) throw invalid_argument("❌ Precio inválido.");
        p.setPrecio(precio);

        int stock;
        cout << "Ingrese cantidad (stock): ";
        if (!(cin >> stock) || stock < 0) throw invalid_argument("❌ Stock inválido.");
        p.setStock(stock);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        listaCompras.push_back(p);
        cout << "✅ Compra registrada exitosamente.\n";
    }
    catch (const exception& e) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << e.what() << "\n";
    }
}

void Compras::mostrarHistorial(const vector<Producto>& listaCompras) {
    try {
        if (listaCompras.empty()) {
            throw runtime_error("⚠ No hay compras registradas.");
        }

        cout << "\n--- Historial de Compras ---\n";
        for (const auto& p : listaCompras) {
            cout << "Código: " << p.getCodigo() << "\n"
                 << "Nombre: " << p.getNombre() << "\n"
                 << "Descripción: " << p.getDescripcion() << "\n"
                 << "Precio: $" << fixed << setprecision(2) << p.getPrecio() << "\n"
                 << "Cantidad: " << p.getStock() << "\n\n";
        }
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    }

    cout << string(90, '=') << endl;
    cout << right << setw(79) << "TOTAL GASTADO: $"
         << fixed << setprecision(2) << calcularTotalGastado(listaCompras) << endl;
}

void Compras::buscarPorProveedor(const vector<Producto>& listaCompras) {
<<<<<<< HEAD
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
=======
    try {
        string proveedor;
        cout << "Ingrese nombre del proveedor para buscar: ";
        getline(cin, proveedor);
        if (proveedor.empty()) throw invalid_argument("❌ El nombre del proveedor no puede estar vacío.");

        bool encontrado = false;
        for (const auto& p : listaCompras) {
            if (p.getDescripcion() == proveedor) {
                cout << "Código: " << p.getCodigo() << "\n"
                     << "Nombre: " << p.getNombre() << "\n"
                     << "Precio: $" << fixed << setprecision(2) << p.getPrecio() << "\n"
                     << "Cantidad: " << p.getStock() << "\n\n";
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "⚠ No se encontraron compras de ese proveedor.\n";
        }
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    }
}

double Compras::calcularTotalGastado(const vector<Producto>& listaCompras) {
<<<<<<< HEAD
    double total = 0.0;
    for (const auto& producto : listaCompras) {
        total += producto.getPrecio() * producto.getStock();
=======
    try {
        if (listaCompras.empty()) {
            throw runtime_error("⚠ No hay compras para calcular el total.");
        }

        double total = 0.0;
        for (const auto& p : listaCompras) {
            total += p.getPrecio() * p.getStock();
        }
        return total;
    }
    catch (const exception& e) {
        cerr << e.what() << "\n";
        return 0.0;
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    }
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
