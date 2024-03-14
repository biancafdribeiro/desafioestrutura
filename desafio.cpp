#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;

// Estrutura para representar cada poltrona no teatro
struct Poltrona {
    bool ocupada;
};

// Classe para o controle do teatro
class Teatro {
private:
    vector<vector<Poltrona>> mapa;
    int lugaresOcupados;
    float valorTotal;

public:
    Teatro() : lugaresOcupados(0), valorTotal(0) {
        // Inicializa o mapa do teatro com todas as poltronas vazias
        mapa.resize(NUM_FILEIRAS, vector<Poltrona>(POLTRONAS_POR_FILEIRA, {false}));
    }

    void reservarPoltrona(int fileira, int poltrona) {
        if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
            cout << "Fileira ou poltrona inválida!" << endl;
            return;
        }

        if (mapa[fileira - 1][poltrona - 1].ocupada) {
            cout << "Esta poltrona já está ocupada!" << endl;
            return;
        }

        mapa[fileira - 1][poltrona - 1].ocupada = true;
        lugaresOcupados++;

        // Calcula o valor da bilheteria com base na fileira
        float valor;
        if (fileira >= 1 && fileira <= 5)
            valor = 50.00;
        else if (fileira >= 6 && fileira <= 10)
            valor = 30.00;
        else
            valor = 15.00;
        valorTotal += valor;

        cout << "Poltrona reservada com sucesso!" << endl;
    }

    void mostrarMapaOcupacao() {
        cout << "Mapa de ocupação do teatro:" << endl;
        for (int i = 0; i < NUM_FILEIRAS; ++i) {
            for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
                cout << (mapa[i][j].ocupada ? "#" : ".");
            }
            cout << endl;
        }
    }

    void mostrarFaturamento() {
        cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
        cout << fixed << setprecision(2);
        cout << "Valor da bilheteria: R$ " << valorTotal << endl;
    }
};

int main() {
    Teatro teatro;
    int opcao;

    do {
        cout << "Selecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;
        cin >> opcao;

        switch(opcao) {
            case 0:
                cout << "Programa finalizado." << endl;
                break;
            case 1:
                int fileira, poltrona;
                cout << "Informe a fileira e a poltrona desejada: ";
                cin >> fileira >> poltrona;
                teatro.reservarPoltrona(fileira, poltrona);
                break;
            case 2:
                teatro.mostrarMapaOcupacao();
                break;
            case 3:
                teatro.mostrarFaturamento();
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
