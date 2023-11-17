#include<bits/stdc++.h>


enum EstadoPalavra {
    FORA_PALAVRA,
    DENTRO_PALAVRA
};

int main() {
    // Inicializando o dicionario que ira conter todas as palavras
    std::map<std::string, bool> dicionario;

    // Incializando o leitor que ira ler todas as linhas
    std::string linha;
    while (std::getline(std::cin, linha)) {
        std::stringstream ss(linha);
        std::string palavra;
        EstadoPalavra estado = FORA_PALAVRA;
        while (ss >> palavra) {
            for (char& c : palavra) {
                c = std::tolower(c);
                if (!std::isalpha(c)) {
                    c = ' ';
                }
            }
            std::stringstream ss_palavra(palavra);
            while (ss_palavra >> palavra) {
                if (estado == DENTRO_PALAVRA) {
                    dicionario[palavra] = true;
                }
                estado = DENTRO_PALAVRA;
            }
        }
    }

    for (const auto& par : dicionario) {
        std::cout << par.first << std::endl;
    }

    return 0;
}
