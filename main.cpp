#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

void embaralhar(vector<string>& baralho);

void embaralhar(vector<string>& baralho) {
  srand(time(0));
  int n = baralho.size();
  for (int i = 0; i < n; ++i) {
    int r = rand();
    int j = r % n;
    swap(baralho[i], baralho[j]);
  }
}

int main() {
  vector<string> baralho(104);

  for (int n = 0; n < 4; ++n) {
    for (int i = 1; i <= 13; ++i) {
      for (int b = 1; b <= 2; ++b) {
        stringstream ss;
        ss << (n + 1) << "-" << (i < 10 ? "0" : "") << i << "-" << b;
        baralho[(n * 26) + ((i - 1) * 2) + (b - 1)] = ss.str();
      }
    }
  }

  embaralhar(baralho);

  vector<vector<string>> mao(4, vector<string>(11));
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
