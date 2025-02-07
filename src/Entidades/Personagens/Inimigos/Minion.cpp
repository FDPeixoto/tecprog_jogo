#include <Minion.hpp>

namespace Entidades
{
    namespace Inimigos
    {
        Minion::Minion(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(LARGURAMINION, ALTURAMINION), posicao, IDMINION)
        {
            setVelocidade(sf::Vector2f(50.f, 0.f));
            setCor(sf::Color::White);
            textura.loadFromFile("Texturas/minion1.png");
            Entidade::carregarTextura(&textura);
            setNumVidas(1);
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

        int Minion::get_tam_grupo()
        {
            return tam_grupo;
        }

        int Minion::tam_grupo = 1;
    }
}
