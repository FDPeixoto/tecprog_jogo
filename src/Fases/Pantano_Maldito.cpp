#include "Pantano_Maldito.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

namespace Fases
{

    Pantano_Maldito::Pantano_Maldito() : Fase(IDPANTANOMALDITO), maxInimMedios(5), vetorDurahan(), it_D(0), cont_D(2)
    {
        //Fase::proximaFase();
        /*srand((unsigned int)time(NULL));
        cont_D= (rand() % (FAIXA_ALEATORIO))+2; */
        criarMapa();
        //, cont_D(2)

        vetorDurahan.clear();
    }
    /*void Pantano_Maldito::setLisPp(st::list<Entidades::Entidade*> l){
        Fase::setListP(pD->getListaProjetil());
    }*/

    Pantano_Maldito::~Pantano_Maldito()
    {
        // pD=nullptr;
        for (std::vector<Entidades::Inimigos::Durahan *>::iterator it = vetorDurahan.begin(); it != vetorDurahan.end(); ++it)
        {
            delete *it;
        }

        vetorDurahan.clear();
    }

    void Pantano_Maldito::criarInimMedio(const sf::Vector2f posicao)
    {
        Entidades::Inimigos::Esqueleto *esqueleto = new Entidades::Inimigos::Esqueleto(posicao);
        if (esqueleto != nullptr)
        {
            // esqueleto->setCor(sf::Color::Cyan);
            if(Fase::getJogador1() != nullptr){esqueleto->setJogador1(getJogador1());}
            if(Fase::getJogador2() != nullptr){esqueleto->setJogador2(getJogador2());}
            listaPersonagens->incluirEntidade(esqueleto);
        }
    }
    void Pantano_Maldito::criarInimDificil(const sf::Vector2f posicao)
    {
        it_D++;
        Entidades::Inimigos::Durahan *durahan = new Entidades::Inimigos::Durahan(posicao);
        if (durahan != nullptr)
        {
            // pD=durahan;
            // durahan->setCor(sf::Color::Magenta);
            if (Fase::getJogador1() != nullptr)
            {
                durahan->setJogador1(getJogador1());
            }
            if (Fase::getJogador2() != nullptr)
            {
                durahan->setJogador2(getJogador2());
            }
            vetorDurahan.push_back(durahan);
            listaPersonagens->incluirEntidade(durahan);
            // num_Durahan++; lemnrando que isso está em fase
        }
    }
    /*void Pantano_Maldito::setpD(Entidades::Inimigos::Durahan* pDurahan){
        pD=pDurahan;
    }
    Entidades::Inimigos::Durahan* Pantano_Maldito::getpD(){
        return pD;
    }*/
    void Pantano_Maldito::criarInimigos()
    {
        // criarInimFaceis();
        // criarInimMedios();
    }
    void Pantano_Maldito::criarObstaculos()
    {
        // criarObstFaceis();
    }

    const int Pantano_Maldito::getMaxInimMedios() { return maxInimMedios; }

    void Pantano_Maldito::criarMapa()
    {

        // criarPlataformaBase(sf::Vector2f(0.0f,660));
        // Está ao contrário as funções BordaV cria Horizontal e BordaH, vertical

        std::ifstream arquivo;
        std::string linha;
        arquivo.open("src/Fases/TestePrimeiraFase.txt");
        if (!arquivo.is_open())
        {
            std::cout << "NAo abriu o arquivo .txt Pantano_Maldito" << std::endl;
            exit(1);
        }
        int j = 0;
        while (std::getline(arquivo, linha))
        {
            for (int i = 0; i < linha.size(); i++)
            {
                if (linha[i] != ' ')
                {
                    criarEntidade(linha[i], sf::Vector2f(i, j));
                }
            }
            j++;
        }
        arquivo.close();
    }
    void Pantano_Maldito::executar()
    {
        Fase::executar();
        verificarCompletou();

        /*if(pD!= nullptr){
            pGerenciadorGrafico->desenharList(pD->getListaProjetil());
        }
        for (int i = 0; i < cont_D; i++)
        {
            if (vetorDurahan[i] != nullptr)
            {
                pGerenciadorGrafico->desenharList(vetorDurahan[i]->getListaProjetil());
            }
        }
        */
    }

    void Pantano_Maldito::criarEntidade(char letra, const sf::Vector2f posicao)
    {
        switch (letra)
        {
        case ('j'):
        {
            criarJogador(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('m'):
        {
            criarMinion(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('e'):
        {
            criarInimMedio(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('b'):
        {
            criarCaixa(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('s'):
        {
            criarEspinho(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        case ('#'):
        {
            criarPlataforma(sf::Vector2f(posicao.x * 64.f, posicao.y * 64.f));
        }
        break;
        }
    }
    void Pantano_Maldito::verificarCompletou(){
        
        if((pJogador1!=nullptr)){
            sf::Vector2f posJ1=pJogador1->getCorpo().getPosition();
            if(posJ1.x>=(LARGURA_JANELA/2)){
                    completou=true;
            }
        }
        else if(pJogador2!=nullptr){
            sf::Vector2f posJ2=pJogador2->getCorpo().getPosition();
            if(posJ2.x>=(LARGURA_JANELA/2)){
                    completou=true;
            }
        }
        
           // return false;
    }

}
