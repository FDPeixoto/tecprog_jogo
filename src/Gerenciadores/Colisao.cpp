#include "Colisao.hpp"

/*Codigo dos gerenciadores foi inspirado pelo monitor Giovani https://github.com/Giovanenero/JogoPlataforma2D-Jungle/blob/main/Jungle%2B%2B/src/Gerenciador/GerenciadorColisao.cpp */
namespace Gerenciadores
{
    Colisao *Colisao::pColisao = nullptr;
    Colisao::Colisao() : todasEntidades(new Listas::ListaEntidades())
    {
        listJogadores.clear();
        listInimigos.clear();
        listObstaculos.clear();
    }
    Colisao::~Colisao()
    {
    }
    Colisao *Colisao::getGerenciadorColisao()
    {
        if (pColisao == nullptr)
        {
            pColisao = new Colisao();
        }
        return pColisao;
    }
    void Colisao::setMoveis(Listas::ListaEntidades *moveis)
    {
        listaMoveis = moveis;
    }
    Listas::ListaEntidades *Colisao::getListaMoveis()
    {
        return listaMoveis;
    }
    Listas::ListaEntidades *Colisao::getListaFixos()
    {
        return listaFixos;
    }
    void Colisao::setFixos(Listas::ListaEntidades *fixos)
    {
        listaFixos = fixos;
    }
    const sf::Vector2f Colisao::calculaColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2)
    {
        sf::Vector2f pos1 = entidade1->getPos();
        sf::Vector2f pos2 = entidade2->getPos();

        sf::Vector2f tam1 = entidade1->getTam();
        sf::Vector2f tam2 = entidade2->getTam();

        sf::Vector2f distanciaEntreCentros(
            fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
            fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));
        sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
        return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
    }

    bool Colisao::checarColisao(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2)
    {
        return entidade1->getCorpo().getGlobalBounds().intersects(entidade2->getCorpo().getGlobalBounds());
    }

    void Colisao::adicionarJogador(Entidades::Jogador *jogador)
    {
        listJogadores.push_back(jogador);
        todasEntidades->incluirEntidade(jogador);
    }

    void Colisao::adicionarInimigo(Entidades::Inimigos::Inimigo *inimigo)
    {
        listInimigos.push_back(inimigo);
        todasEntidades->incluirEntidade(inimigo);
    }

    void Colisao::adicionarObstaculo(Entidades::Obstaculos::Obstaculo *obstaculo)
    {
        listObstaculos.push_back(obstaculo);
        todasEntidades->incluirEntidade(obstaculo);
    }

    void Colisao::executar()
    {
        for (auto jogador : listJogadores)
        {
            for (auto inimigo : listInimigos)
            {

                if (checarColisao(jogador, inimigo))
                {
                    jogador->colisao(inimigo); // Notify player of collision
                    // inimigo->colisao(jogador); // Notify enemy of collision
                }
            }
        }

        // Check collisions between players and obstacles
        for (auto jogador : listJogadores)
        {
            for (auto obstaculo : listObstaculos)
            {
                if (obstaculo != nullptr && jogador != nullptr)
                {
                    if (checarColisao(jogador, obstaculo))
                    {
                        jogador->colisao(obstaculo); // Notify player of collision
                        // obstaculo->colisao(jogador); // Notify obstacle of collision
                    }
                }
            }
        }

        // Check collisions between enemies and obstacles
        for (auto inimigo : listInimigos)
        {
            for (auto obstaculo : listObstaculos)
            {
                if (checarColisao(inimigo, obstaculo))
                {
                    inimigo->colisao(obstaculo); // Notify enemy of collision
                    // obstaculo->colisao(inimigo); // Notify obstacle of collision
                }
            }
        }
    }

    void Colisao::registrarEntidade(Entidades::Entidade *entidade)
    {
        return;
    }

    void Colisao::notificar(Entidades::Entidade *sender, const std::string &evento)
    {
        if (evento == "verificarColisao")
        {
            for (std::vector<Entidades::Entidade *>::iterator it = vectorEntidades.begin(); it != vectorEntidades.end(); ++it)
            {
                Entidades::Entidade *entidade = *it;
                {
                    if (sender != entidade)
                    {
                        if (sender->getCorpo().getGlobalBounds().intersects(entidade->getCorpo().getGlobalBounds()))
                        {
                            sender->setCor(sf::Color::Red);
                        }
                    }
                }
            }
        }
        else if (evento == "atacar")
        {
        }
        else if (evento == "obstacular")
        {
        }
    }
}
