#include <iostream>
#include <iomanip>
#include <string>
#include<bits/stdc++.h>
struct Medicamento {
    std::string nombre;
    int codigo;
    int stockMinimo;
    int unidadesExistentes;
};

void imprimirTabla(const std::vector<Medicamento>& medicamentos) {
    // Encabezado de la tabla
    std::cout << std::setw(15) << "Nombre"
              << std::setw(10) << "Código"
              << std::setw(15) << "Stock Mínimo"
              << std::setw(20) << "Unidades Existentes"
              << std::endl;

    // Línea separadora
    std::cout << std::setfill('-') << std::setw(60) << "-" << std::setfill(' ') << std::endl;

    // Datos de la tabla
    for (const auto& medicamento : medicamentos) {
        std::cout << std::setw(15) << medicamento.nombre
                  << std::setw(10) << medicamento.codigo
                  << std::setw(15) << medicamento.stockMinimo
                  << std::setw(20) << medicamento.unidadesExistentes
                  << std::endl;
    }
}

int main() {
    // Crear algunos medicamentos para el ejemplo
    std::vector<Medicamento> medicamentos = {
        {"Sertralina", 1, 10, 50},
        {"Fluoxetina", 2, 15, 30},
        {"Escitalopram", 3, 12, 40}
        // Puedes agregar más medicamentos según tus necesidades
    };

    // Imprimir la tabla
    imprimirTabla(medicamentos);

    return 0;
}
