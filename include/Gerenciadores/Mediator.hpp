#pragma once
#include "Entidade.hpp"

namespace Entidades{
    class Entidade;
}


namespace Gerenciadores{
    class Mediator{
        public:
            virtual void registrarEntidade(Entidades::Entidade *entidade) = 0;
            virtual void notificar(Entidades::Entidade* sender, const std::string& evento) = 0;
            virtual ~Mediator() = default;
    };
}