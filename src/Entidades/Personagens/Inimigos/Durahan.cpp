#include "Durahan.hpp"

namespace Entidades
{
    namespace Inimigos
    {
        Durahan::Durahan(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(DURAHANLARGURA, DURAHANALTURA), posicao, IDDURAHAN), listaProjetil(), jaAtirou(false)
        {
            velocidade = sf::Vector2f(VELOCIDADEX_DU, VELOCIDADEY_DU);
            antidoto_mortal = false;
            tiros = 0;
            it = 0;
            srand((unsigned int)time(NULL));
            aleatorio = (rand() % (FAIXA_ALEATORIO * 5));
            //setCor(sf::Color::Red);
            criarProjetil();
            if (!textura.loadFromFile("Texturas/Durahan2.png")) {}
            setCor(sf::Color::White); //cor anterior: (6, 64, 43)
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

            if (tiros < TAM_MAX_P)
            {
                bool dir = false;
                sf::Vector2f posInimigo = corpo.getPosition();
                if ((pJogador1 != nullptr) && (pJogador2 != nullptr))
                {
                    sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                    sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();

                    float distx1 = fabs(posJogador1.x - posInimigo.x);
                    // float disty1=fabs(posJogador1.y-posInimigo.y);

                    float distx2 = fabs(posJogador2.x - posInimigo.x);
                    // float disty2=fabs(posJogador2.y-posInimigo.y);

                    if (distx1 <= distx2)
                    { // atira para o jogador 1
                        if ((posJogador1.x - posInimigo.x) >= 0)
                        { // Eh para a direita
                            dir = true;
                        }
                        else
                        { // tá para a esquerda
                            dir = false;
                        }
                    }
                    else
                    { // atira no jogador 2
                        if ((posJogador2.x - posInimigo.x) >= 0)
                        { // Eh para a direita
                            dir = true;
                        }
                        else
                        { // tá para a esquerda
                            dir = false;
                        }
                    }
                }
                else if (pJogador1 != nullptr)
                {
                    sf::Vector2f posJogador1 = pJogador1->getCorpo().getPosition();
                    if ((posJogador1.x - posInimigo.x) >= 0)
                    { // Eh para a direita
                        dir = true;
                    }
                    else
                    { // tá para a esquerda
                        dir = false;
                    }
                }
                else if (pJogador2 != nullptr)
                {
                    sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
                    if ((posJogador2.x - posInimigo.x) >= 0)
                    { // Eh para a direita
                        dir = true;
                    }
                    else
                    { // tá para a esquerda
                        dir = false;
                    }
                }

                int contador = 0;
                for (auto it = listaProjetil.begin(); it != listaProjetil.end(); ++it)
                {
                    if (contador == tiros)
                    {
                        Entidades::Entidade *proj = *it;
                        if (proj != nullptr)
                        {
                            proj->setAtivo(true);
                            proj->atirar(posInimigo, dir);
                            proj->executar();
                        }
                        break; // Não precisa continuar após encontrar
                    }
                    ++contador;
                }
                tiros++;
                /*if(listaProjetil[tiros]!=nullptr){
                    //Entidades::Projetil proj= new Entidades::Projetil(getPos(this));
                    Entidades::Projetil* proj=listaProjetil[tiros];
                    proj->setAtivo(true);
                    proj->executar();
                }*/
            }
            else
            {
                setCor(sf::Color::Red);
            }

            /*criarProjetil();
            proj->setAtivo(true);
            proj->atirar(this->getPos);*/
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
                setCor(sf::Color::Magenta);
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