#include "Evento.hpp"
#include "Estado.hpp"

namespace Observers
{
    class Observer
    {
    protected:
        static Gerenciadores::Evento *pEvento;
        static Gerenciadores::Estado *pEstado;

    private:
        bool ativar;

    public:
        Observer();
        virtual ~Observer();
        void mudarEstadoAtivar();
        const bool getAtivar() const;
        void removerObserver();
    };
}