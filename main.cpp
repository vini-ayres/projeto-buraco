#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void embaralhar(string* baralho, int tamanho) {
    srand(time(0));
    for (int i = 0; i < tamanho; ++i) {
        int r = rand() % tamanho;
        swap(baralho[i], baralho[r]);
    }
}

int main() {
    const int tamanho_baralho = 104;
    string baralho[tamanho_baralho];

    for (int n = 0; n < 4; ++n) {
        for (int i = 1; i <= 13; ++i) {
            for (int b = 1; b <= 2; ++b) {
                string s = to_string(n + 1) + "-" + (i < 10 ? "0" : "") + to_string(i) + "-" + to_string(b);
                baralho[(n * 26) + ((i - 1) * 2) + (b - 1)] = s;
            }
        }
    }

    embaralhar(baralho, tamanho_baralho);

    string mao[4][11];
    int cartaAtual = 0;

    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            mao[j][c] = baralho[cartaAtual++];
        }
    }

    for (int j = 0; j < 4; ++j) {
        cout << "Mão do Jogador " << j + 1 << ":\n";
        for (int c = 0; c < 11; ++c) {
            cout << mao[j][c] << endl;
        }
        cout << endl;
    }

    return 0;
}
