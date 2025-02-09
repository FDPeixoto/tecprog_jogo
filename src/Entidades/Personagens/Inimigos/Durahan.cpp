#include "Durahan.hpp"
#include "Colisao.hpp"
#define ALCANCEOGRO 50.f

namespace Entidades
{
    namespace Inimigos
    {
        Durahan::Durahan(const sf::Vector2f posicao)
            : Inimigo(sf::Vector2f(DURAHANLARGURA, DURAHANALTURA), posicao, IDDURAHAN),
              listaProjetil(),
              jaAtirou(false)
        {
            velocidade = sf::Vector2f(VELOCIDADEX_DU, VELOCIDADEY_DU);
            setVivo(true);
            antidoto_mortal = false;
            // Remove tiros initialization
            srand(static_cast<unsigned int>(time(nullptr)));
            aleatorio = rand() % (FAIXA_ALEATORIO * 5);
            criarProjetil();
            setAlcance(ALCANCEOGRO);
            if (!textura.loadFromFile("Texturas/Durahan2.png"))
            {
                // Handle error
            }
            setCor(sf::Color::White);
            Entidade::carregarTextura(&textura);
        }
        Durahan::~Durahan()
        {
            antidoto_mortal = false;

            listaProjetil.clear();
        }
        void Durahan::criarProjetil()
        {

            for (int i = 0; i < TAM_MAX_P; i++)
            {
                Entidades::Projetil *proj = new Entidades::Projetil(sf::Vector2f(1150.0f, 0.0f)); // posicão
                if (proj != nullptr)
                {
                    proj->setCor(sf::Color::White);
                    proj->setMediator(Gerenciadores::Colisao::getGerenciadorColisao());
                    listaProjetil.push_back(proj);
                }
            }
        }

        void Durahan::atualizarListP(float dt)
        {
            for (std::list<Entidades::Entidade *>::iterator it = listaProjetil.begin(); it != listaProjetil.end(); ++it)
            {
                if (*it != nullptr)
                {
                    if ((*it)->getAtivo() == true)
                    {
                        (*it)->atualizar(dt); // Chama a função atualizar para cada projétil
                    }
                }
            }
        }
        void Durahan::atualizar(float dt)
        {
            Inimigo::atualizar(dt);
            atualizarListP(dt);
        }
        void Durahan::atirar()
        {
            if (podeAtacar)
            {
                bool dir = false;
                sf::Vector2f posInimigo = corpo.getPosition();

                // Determine target direction (existing code)
                if ((pJogador1 != nullptr) && (pJogador2 != nullptr))
                {
                    sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                    sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();

                    float distx1 = fabs(posJogador1.x - posInimigo.x);
                    float distx2 = fabs(posJogador2.x - posInimigo.x);

                    if (distx1 <= distx2)
                    {
                        dir = (posJogador1.x - posInimigo.x) >= 0;
                    }
                    else
                    {
                        dir = (posJogador2.x - posInimigo.x) >= 0;
                    }
                }
                else if (pJogador1 != nullptr)
                {
                    sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                    dir = (posJogador1.x - posInimigo.x) >= 0;
                }
                else if (pJogador2 != nullptr)
                {
                    sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                    dir = (posJogador2.x - posInimigo.x) >= 0;
                }

                // Find and fire the first inactive projectile
                for (auto &proj : listaProjetil)
                {
                    if (proj != nullptr && !proj->getAtivo())
                    {
                        proj->setAtivo(true);
                        proj->atirar(posInimigo, dir);
                        proj->executar();
                        break; // Fire only one projectile per attack
                    }
                }
            }
        }
        void Durahan::salvar() {}
        void Durahan::salvarDataBuffer() {}
        void Durahan::executar()
        {
            Inimigo::executar();
            it++;
            if ((aleatorio <= FAIXA_ALEATORIO) && (jaAtirou == false))
            {
                atirar();
                jaAtirou = true;
            }
            if (it >= 100)
            {
                srand((unsigned int)time(NULL));
                aleatorio = (rand() % (FAIXA_ALEATORIO * 5));
                it = 0;
                jaAtirou = false;
                // setCor(sf::Color::Magenta);
            }
        }
        void Durahan::danificar(Entidades::Jogador *pJogador) {}
        void Durahan::golpeMortal() {}
        void Durahan::setAntidotoMortal(bool flg)
        {
            antidoto_mortal = flg;
        }
        // void Durahan::colisao(Entidade *outraEntidade){}
        std::list<Entidades::Entidade *> &Durahan::getListaProjetil()
        {
            return listaProjetil;
        }
    }
}