#include <Minion.hpp>

namespace Entidades
{
    namespace Inimigos
    {
        Minion::Minion(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(LARGURAMINION, ALTURAMINION), posicao, IDMINION), super(false)
        {
            srand((unsigned int)time(NULL));
            int s = (rand() % (3));
            if(s==0){
                super=true;
                setNumVidas(2);
            }
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
       
    }
}
