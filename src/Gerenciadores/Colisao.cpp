#include "Colisao.hpp"
// O colisao tem como inspiracao o video tutorial: https://www.youtube.com/watch?v=l2iCYCLi6MU&t=945s,; Canal: Hilze Vonck, Título: SFML 2.4 For Beginners - 12: Collision Detection (AABB).

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

    float calculaDistancia(Entidades::Entidade *entidade1, Entidades::Entidade *entidade2)
    {
        sf::Vector2f pos1 = entidade1->getCorpo().getPosition();
        sf::Vector2f pos2 = entidade2->getCorpo().getPosition();

        sf::Vector2f tam1 = entidade1->getTam();
        sf::Vector2f tam2 = entidade2->getTam();

        sf::Vector2f center1(pos1.x + tam1.x / 2.f, pos1.y + tam1.y / 2.f);

        sf::Vector2f center2(pos2.x + tam2.x / 2.f, pos2.y + tam2.y / 2.f);

        float dx = center2.x - center1.x;
        float dy = center2.y - center1.y;

        return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
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
        for (std::list<Entidades::Jogador *>::iterator itJogador = listJogadores.begin(); itJogador != listJogadores.end(); itJogador++)
        {
            (*itJogador)->verificarColisao();
        }

        for (std::list<Entidades::Inimigos::Inimigo *>::iterator itInimigo = listInimigos.begin(); itInimigo != listInimigos.end(); itInimigo++)
        {
            (*itInimigo)->verificarColisao();
        }

        for (Listas::Lista<Entidades::Entidade>::Iterator entidade = todasEntidades->getListaEnt().inicio(); entidade != todasEntidades->getListaEnt().fim(); entidade++)
        {
            if ((*entidade)->getID() == ID_PROJETIL)
            {
                (*entidade)->verificarColisao();
            }

            if ((*entidade)->getID() == IDCAIXA)
            {
                (*entidade)->verificarColisao();
            }
        }
    }

    void Colisao::registrarEntidade(Entidades::Entidade *entidade)
    {
        todasEntidades->incluirEntidade(entidade);
    }

    void Colisao::notificar(Entidades::Entidade *sender, const std::string &evento)
    {

        if (evento == "verificarColisao")
        {
            for (Listas::Lista<Entidades::Entidade>::Iterator itOutraEntidade = todasEntidades->getListaEnt().inicio(); itOutraEntidade != todasEntidades->getListaEnt().fim(); itOutraEntidade++)
            {
                if (sender != *itOutraEntidade)
                {
                    if (checarColisao(sender, *itOutraEntidade))
                    {
                        sender->colisao(*itOutraEntidade);
                        (*itOutraEntidade)->colisao(sender);
                    }
                }
            }
        }
        else if (evento == "ataqueDoJogador")
        {
            for (std::list<Entidades::Inimigos::Inimigo *>::iterator itInimigo = listInimigos.begin(); itInimigo != listInimigos.end(); itInimigo++)
            {
                if (*itInimigo != nullptr)
                {
                    if (calculaDistancia(sender, *itInimigo) < 96.f)
                    {
                        (*itInimigo)->tomarDano(1);
                        if (!(*itInimigo)->getVivo())
                        {
                            if ((*itInimigo)->getID() == IDMINION)
                            {
                                static_cast<Entidades::Jogador *>(sender)->setPontos(static_cast<Entidades::Jogador *>(sender)->getPontos() + 1);
                            }
                            else if ((*itInimigo)->getID() == IDESQUELETO)
                            {
                                static_cast<Entidades::Jogador *>(sender)->setPontos(static_cast<Entidades::Jogador *>(sender)->getPontos() + 2);
                            }
                            else if ((*itInimigo)->getID() == IDOGRO)
                            {
                                static_cast<Entidades::Jogador *>(sender)->setPontos(static_cast<Entidades::Jogador *>(sender)->getPontos() + 3);
                            }
                        }
                    }
                }
            }
        }
        else if (evento == "ataqueDoInimigo")
        {
            for (std::list<Entidades::Jogador *>::iterator itJogador = listJogadores.begin(); itJogador != listJogadores.end(); itJogador++)
            {
                if (*itJogador != nullptr)
                {
                    if ((*itJogador)->getUltimoDano() > 2.0f && calculaDistancia(*itJogador, sender) < static_cast<Entidades::Inimigos::Inimigo *>(sender)->getAlcance())
                    {
                        switch (sender->getID())
                        {
                        case IDMINION:
                            (*itJogador)->tomarDano(1);
                            break;
                        case IDESQUELETO:
                            (*itJogador)->tomarDano(2);
                            break;
                        case IDOGRO:
                            (*itJogador)->tomarDano(3);
                            break;
                        }
                        (*itJogador)->setUltimoDano(0.f);
                    }
                }
            }
        }
    }
    void Colisao::removerEntidade(Entidades::Entidade *entidade)
    {
        todasEntidades->removerEntidade(entidade);
        if (entidade->getID() == IDJOGADOR)
        {
            listJogadores.remove(static_cast<Entidades::Jogador *>(entidade));
        }
        else if (entidade->getID() == IDMINION || entidade->getID() == IDESQUELETO || entidade->getID() == IDOGRO)
        {
            listInimigos.remove(static_cast<Entidades::Inimigos::Inimigo *>(entidade));
        }
        else if (entidade->getID() == IDESPINHO || entidade->getID() == IDPLATAFORMA || entidade->getID() == IDCAIXA)
        {
            listObstaculos.remove(static_cast<Entidades::Obstaculos::Obstaculo *>(entidade));
        }
    }
    void Colisao::limparListas()
    {
        listInimigos.clear();
        listJogadores.clear();
        listObstaculos.clear();
        todasEntidades->limparLista();
    }
}
