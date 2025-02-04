#include <iostream>

#include "../../include/Gerenciadores/Grafico.hpp"
#include "../../include/Entidades/Entidade.hpp"
#include "../../include/Listas/ListaEntidades.hpp"
#include "../../include/Listas/Lista.hpp"
#include "Grafico.hpp"
#include "stdafx.h"

namespace Gerenciadores
{
    Grafico *Grafico::pGrafico = nullptr;

    Grafico::Grafico() : janela(new sf::RenderWindow(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Medievo++")),
                         panorama(sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(LARGURA_JANELA, ALTURA_JANELA))), relogio()
    {
    }

    Grafico::~Grafico()
    {
        if (janela != nullptr)
        {
            delete (janela);
            janela = nullptr;
        }
    }

    Grafico *Grafico::getGerenciadorGrafico()
    {
        if (pGrafico == nullptr)
        {
            pGrafico = new Grafico();
        }
        return pGrafico;
    }

    sf::RenderWindow *Grafico::getJanela()
    {
        return janela;
    }

    void Grafico::redimensionarJanela()
    {
        float proporcaoJanela = float(janela->getSize().x) / float(janela->getSize().y);
        panorama.setSize(LARGURA_JANELA * proporcaoJanela, ALTURA_JANELA);
    }

    void Grafico::limparJanela()
    {
        janela->clear();
    }

    void Grafico::mostrarJanela()
    {
        janela->display();
    }

    void Grafico::desenharCorpo(sf::RectangleShape corpo)
    {
        janela->draw(corpo);
    }

    void Grafico::desenharTexto(sf::Text texto)
    {
        janela->draw(texto);
    }
    void Grafico::desenharEntidade(Entidades::Entidade *entidade)
    {
        janela->draw(entidade->getCorpo());
    }

    void Grafico::desenharListaEntidades(Listas::ListaEntidades *lista)
    {
        for (Listas::Lista<Entidades::Entidade>::Iterator it = lista->getListaEnt().inicio(); it != lista->getListaEnt().fim(); it++)
        {
            if (*it != nullptr)
            {
                /*if (((*it)->getID() == IDJOGADOR) || ((*it)->getID() == IDINIMIGO))
                {
                    if (((*it)->getVivo()) == true)
                    {
                        desenharEntidade(*it);
                    }
                    else
                    {
                    }
                }*/
                if((*it)->getID() == IDJOGADOR){
                    janela->draw((*it)->getSprite());
                }

                else
                {
                    desenharEntidade(*it);
                }
            }
        }
    }

    void Grafico::resetarRelogio()
    {
        relogio.restart();
    }

    void Grafico::desenharList(std::list<Entidades::Entidade *> &list)
    {
        for (std::list<Entidades::Entidade *>::iterator it = list.begin(); it != list.end(); it++)
        {
            desenharEntidade((*it));
            // desenharCorpo(it->getCorpo()); Esse funciona tambem so escolher qual voce prefere;
        }
    }

    void Grafico::fecharJanela()
    {
        janela->close();
    }

    sf::Clock *Grafico::getRelogio()
    {
        return &relogio;
    }
}
