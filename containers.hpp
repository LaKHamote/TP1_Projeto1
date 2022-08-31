#ifndef CONTAINERS_HPP_INCLUDED
#define CONTAINERS_HPP_INCLUDED

#include "lib/Domains/domain.hpp"
#include "lib/Entities/entity.hpp"

#include <map>

using namespace std;

//----------------------------------------------------------------------------------------
// Declaração de classe container.
//
// Declaração adota padrão de projeto Singleton.

class ContainerUsuario{
    private:
        map<string, User> container;                    // Mapa de usuários.
        static ContainerUsuario *instancia;             // Ponteiro para instância da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // Método para instanciar classe.
        bool incluir(User);                             // Métodos responsáveis por prestar serviços.
        bool remover(Email);
        bool pesquisar(User*);
        bool atualizar(User);
};

class ContainerAvaliacao{
    private:
        map<string, Rating> container;                    // Mapa de usuários.
        static ContainerAvaliacao *instancia;             // Ponteiro para instância da classe.
        ContainerAvaliacao(){};                           // Construtor.
    public:
        static  ContainerAvaliacao* getInstancia();       // Método para instanciar classe.
        bool incluir(Rating);                             // Métodos responsáveis por prestar serviços.
        bool remover(Code);
        bool pesquisar(Rating*);
        bool pesquisar_usuario(Rating*, Email);
        bool pesquisar_hospedagem(Rating*, Code);
        bool atualizar(Rating);
};

class ContainerHospedagem{
    private:
        map<string, Accommodation> container;                 // Mapa de usuários.
        static ContainerHospedagem *instancia;                // Ponteiro para instância da classe.
        ContainerHospedagem(){};                              // Construtor.
    public:
        static  ContainerHospedagem* getInstancia();          // Método para instanciar classe.
        bool incluir(Accommodation);                          // Métodos responsáveis por prestar serviços.
        bool remover(Code);
        bool pesquisar(Accommodation*);
        bool pesquisar_anfitriao(Accommodation*, Email);
        bool atualizar(Accommodation);
};

#endif // CONTAINERS_HPP_INCLUDED