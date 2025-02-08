#include "Fase.hpp"
#include "stdafx.h"
#include "Esqueleto.hpp"
#include "Durahan.hpp" //para teste
#include <vector>

namespace Fases
{
    class Pantano_Maldito: public Fase
    {
        private:
        int  maxCaixas;
        int it_Caixas;
        int maxM;
        int it_M;
        int maxP;
        int it_P;
        int maxEsqueletos;
        int it_Esqueletos;
        int aleatoriedadeP;
        sf::RectangleShape fundo;
        sf::Texture textura;

    public:
        Pantano_Maldito(bool temSegundoJogador);
        ~Pantano_Maldito();
        void criarInimMedio(const sf::Vector2f posicao);
        void criarCaixa(const sf::Vector2f posicao);
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void criarMapa();
        void executar();
        void verificarCompletou();
    };
}