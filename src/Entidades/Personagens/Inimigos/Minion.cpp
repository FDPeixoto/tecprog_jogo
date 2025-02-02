#include <Minion.hpp>

namespace Entidades
{
    namespace Inimigos
    {
        float distance(const sf::Vector2f &a, const sf::Vector2f &b)
        {
            return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
        }

        Minion::Minion(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(LARGURAMINION, ALTURAMINION), posicao, IDMINION)
        {
            setVelocidade(sf::Vector2f(50.f, 0.f));
            setCor(sf::Color::Red);
            // velocidade = sf::Vector2f(50.0f, 0.0f);
        }

        Minion::~Minion()
        {
        }
        void Minion::salvar()
        {
        }

        void Minion::salvarDataBuffer()
        {
        }

        /*void Minion::atualizar(float deltaTime, Jogador* jogador1, Jogador* jogador2, sf::RectangleShape& plataforma)
        {
            // Calculando a distância entre o Minion e os jogadores
            float dist1 = distance(getCorpo().getPosition(), jogador1->getCorpo().getPosition());
            float dist2 = distance(getCorpo().getPosition(), jogador2->getCorpo().getPosition());

            // Escolhendo o jogador mais próximo
            Jogador* alvo = (dist1 < dist2) ? jogador1 : jogador2; //Jogador& alvo -->> Jogador* alvo

            // Calculando a direção do movimento (apenas no eixo X)
            sf::Vector2f direcao = alvo->getCorpo().getPosition() - getCorpo().getPosition();
            float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

            // Normalizando a direção para ter uma unidade em X
            if (comprimento != 0.f) {
                direcao /= comprimento;
            }

            // Movendo o Minion horizontalmente, sem alterar a posição Y
            //getCorpo().move(direcao.x * velocidade * deltaTime, 0.f);//direção.x ser apenas para ver a direção, já que é unitário

            // Verifica se o Minion está sobre a plataforma
            if (getCorpo().getPosition().y + getCorpo().getSize().y >= plataforma.getPosition().y) {
                //setPos(getCorpo().getPosition().x, plataforma.getPosition().y - getCorpo().getSize().y);
            }





            float ds = velocidade.x * dt;//ou velocidadeFinal.x
            corpo.move(ds, 0.f);
        }*/

        /*void Minion::executar()
        {
        }*/

        int Minion::get_tam_grupo()
        {
            return tam_grupo;
        }

        /*void Minion::mover()
        {
        }*/
        int Minion::tam_grupo = 1;
    }
}
