#include "Projetil.hpp"
#include "Jogador.hpp"

namespace Entidades
{
    Projetil::Projetil(const sf::Vector2f posicao) : Entidade(sf::Vector2f(TAM_X_PROJETIL, TAM_Y_PROJETIL), posicao, ID_PROJETIL), vxP(0.0f), velocidade(sf::Vector2f(500.0f, 0.0f))
    {
    }
    Projetil::~Projetil() {}

    void Projetil::setVelocidade(sf::Vector2f vel)
    {
        velocidade = vel;
    }
    void Projetil::atirar(const sf::Vector2f posicaoInimigo, bool direita)
    {
        setPos(posicaoInimigo);
        if (direita == true)
        {
            setVelocidade(sf::Vector2f(VEL_X_P, 0.f));

            if (!textura.loadFromFile("Texturas/proj-Dir.png"))
            {
            }
            Entidade::carregarTextura(&textura);
        }
        else
        {

            if (!textura.loadFromFile("Texturas/proj-Esq.png"))
            {
            }
            Entidade::carregarTextura(&textura);
            setVelocidade(sf::Vector2f(-VEL_X_P, 0.f));
        }
    }
    void Projetil::executar()
    {
        return;
    }
    void Projetil::inicializar()
    {
        return;
    }
    void Projetil::atualizar(float dt)
    {
        float ds = velocidade.x * dt;
        corpo.move(ds, 0.05f);
        return;
    }
    void Projetil::atualizarPosicao(float dt) {}
    void Projetil::colisao(Entidade *outraEntidade)
    {
        int ID = outraEntidade->getID();
        if (ID == IDJOGADOR)
        {
            if (getAtivo())
            {
                static_cast<Entidades::Jogador *>(outraEntidade)->tomarDano(1);
                setAtivo(false);
            }
        }
        else if (ID == IDPLATAFORMA || ID == IDCAIXA || ID == IDESPINHO)
        {
            setAtivo(false);
            setPos(sf::Vector2f(0.f, 10000.f));
        }
    }
    void Projetil::salvar() {}
}