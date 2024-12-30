#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool checkCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2) {
    return rect1.getGlobalBounds().intersects(rect2.getGlobalBounds());
}

void resolveCollision(sf::RectangleShape& rect1, sf::RectangleShape& rect2) {
    sf::FloatRect intersection = rect1.getGlobalBounds();
    intersection.intersects(rect2.getGlobalBounds());
    if (intersection.width > intersection.height) {
        if (rect1.getPosition().x < rect2.getPosition().x) {
            rect1.setPosition(rect1.getPosition().x - intersection.width, rect1.getPosition().y);
        } else {
            rect1.setPosition(rect1.getPosition().x + intersection.width, rect1.getPosition().y);
        }
    } else {
        if (rect1.getPosition().y < rect2.getPosition().y) {
            rect1.setPosition(rect1.getPosition().x, rect1.getPosition().y - intersection.height);
        } else {
            rect2.setPosition(rect2.getPosition().x, rect2.getPosition().y - intersection.height);
        }
    }
}

class Jogador {
public:
    Jogador(sf::Color cor, float x, float y, sf::Keyboard::Key esquerda, sf::Keyboard::Key direita, sf::Keyboard::Key pulo, float puloForca)
        : cor(cor), teclaEsquerda(esquerda), teclaDireita(direita), teclaPulo(pulo), puloForca(puloForca) {
        retangulo.setSize(sf::Vector2f(50.f, 50.f));
        retangulo.setFillColor(cor);
        retangulo.setPosition(x, y);
        velocidadeY = 0.f;
        noChao = false;
        pulando = false;
    }

    void atualizar(float deltaTime, bool& noChao, sf::RectangleShape& plataforma, float gravidade) {
        velocidadeY += gravidade * deltaTime;
        retangulo.move(0.f, velocidadeY * deltaTime);

        if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
            retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
            velocidadeY = 0.f;
            noChao = true;
            pulando = false;
        }

        if (sf::Keyboard::isKeyPressed(teclaEsquerda) && retangulo.getPosition().x > 0.f)
            retangulo.move(-200.f * deltaTime, 0.f);
        if (sf::Keyboard::isKeyPressed(teclaDireita) && retangulo.getPosition().x + retangulo.getSize().x < 800.f)
            retangulo.move(200.f * deltaTime, 0.f);

        if (sf::Keyboard::isKeyPressed(teclaPulo) && (noChao || !pulando)) {
            velocidadeY = puloForca;
            noChao = false;
            pulando = !noChao;
        }
    }

    void desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
    }

    sf::RectangleShape& getRetangulo() {
        return retangulo;
    }

private:
    sf::RectangleShape retangulo;
    sf::Color cor;
    float velocidadeY;
    bool noChao;
    bool pulando;

    sf::Keyboard::Key teclaEsquerda;
    sf::Keyboard::Key teclaDireita;
    sf::Keyboard::Key teclaPulo;
    float puloForca;
};

class Inimigo {
public:
    Inimigo(float x, float y, float velocidade, float gravidade) : velocidade(velocidade), gravidade(gravidade) {
        retangulo.setSize(sf::Vector2f(50.f, 50.f));
        retangulo.setFillColor(sf::Color::Red);
        retangulo.setPosition(x, y);
        velocidadeY = 0.f;
    }

    void atualizar(float deltaTime, Jogador& jogador1, Jogador& jogador2, sf::RectangleShape& plataforma) {
        float dist1 = distance(retangulo.getPosition(), jogador1.getRetangulo().getPosition());
        float dist2 = distance(retangulo.getPosition(), jogador2.getRetangulo().getPosition());
        Jogador& alvo = (dist1 < dist2) ? jogador1 : jogador2;

        sf::Vector2f direcao = alvo.getRetangulo().getPosition() - retangulo.getPosition();
        float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
        if (comprimento != 0.f) {
            direcao /= comprimento;
        }
        retangulo.move(direcao.x * velocidade * deltaTime, direcao.y * velocidade * deltaTime);

        velocidadeY += gravidade * deltaTime;
        retangulo.move(0.f, velocidadeY * deltaTime);

        if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
            retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
            velocidadeY = 0.f;
        }
    }

    void desenhar(sf::RenderWindow& window) {
        window.draw(retangulo);
    }

    sf::RectangleShape& getRetangulo() {
        return retangulo;
    }

private:
    sf::RectangleShape retangulo;
    float velocidade;
    float gravidade;
    float velocidadeY;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo com Colisão entre Jogadores");

    const float gravidade = 500.f;
    const float puloForca = -std::sqrt(2 * gravidade * 2 * 50.f);

    Jogador jogadorAzul(sf::Color::Blue, 375.f, 475.f, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Space, puloForca);
    Jogador jogadorAmarelo(sf::Color::Yellow, 200.f, 475.f, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, puloForca);

    Inimigo inimigo(100.f, 100.f, 50.f, gravidade);

    sf::RectangleShape plataforma(sf::Vector2f(800.f, 50.f));
    plataforma.setFillColor(sf::Color::Green);
    plataforma.setPosition(0.f, 550.f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        bool noChaoAzul = false;
        bool noChaoAmarelo = false;

        jogadorAzul.atualizar(deltaTime, noChaoAzul, plataforma, gravidade);
        jogadorAmarelo.atualizar(deltaTime, noChaoAmarelo, plataforma, gravidade);

        inimigo.atualizar(deltaTime, jogadorAzul, jogadorAmarelo, plataforma);

        if (checkCollision(jogadorAzul.getRetangulo(), inimigo.getRetangulo()) || checkCollision(jogadorAmarelo.getRetangulo(), inimigo.getRetangulo())) {
            std::cout << "Game Over!" << std::endl;
            window.close();
        }

        if (checkCollision(jogadorAzul.getRetangulo(), jogadorAmarelo.getRetangulo())) {
            resolveCollision(jogadorAzul.getRetangulo(), jogadorAmarelo.getRetangulo());
        }

        window.clear();
        window.draw(plataforma);
        jogadorAzul.desenhar(window);
        jogadorAmarelo.desenhar(window);
        inimigo.desenhar(window);
        window.display();
    }

    return 0;
}
