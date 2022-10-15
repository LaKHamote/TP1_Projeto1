#include "cntrService.hpp"
#include "../lib/Curses/curses.h"
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../containers.hpp"
#include <list>
#include <bits/stdc++.h>

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes controladoras da camada de serviço.

bool CntrSAutenticacao::autenticar(Email email, Password senha){

    // Instancia container de usuários.
    ContainerUsuario *container;

    User usuario;

    container = ContainerUsuario::getInstancia();
    usuario.setEmail(email);

    //recupera usuario
    if (container->pesquisar(&usuario)){ 
        if (usuario.getPassword().getValue().compare(senha.getValue()) == 0)
            return true;  // sucesso na autenticação
        else 
            return false; // falha na autenticação
        
    } 

    
    return false;
}

//--------------------------------------------------------------------------------------------

bool CntrSUsuario::cadastrar(User usuario){

    // Instancia container de usuários.
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    if (container->pesquisar(&usuario))
        return false;

    return container->incluir(usuario);
}

bool CntrSUsuario::descadastrarConta(Email email){
    ContainerUsuario *container_usuario;
    ContainerHospedagem *container_hospedagem;
    ContainerAvaliacao *container_avaliacao;

    container_usuario = ContainerUsuario::getInstancia();
    container_hospedagem = ContainerHospedagem::getInstancia();
    container_avaliacao = ContainerAvaliacao::getInstancia();

    User usuario;
    Accommodation hospedagem;
    Rating avaliacao;

    usuario.setEmail(email);
    
    if (container_usuario->pesquisar(&usuario)){
        while (container_hospedagem->pesquisar_anfitriao(&hospedagem, usuario.getEmail())){         // busca hospedagens do usuario (enquanto houver)
            container_hospedagem->remover(hospedagem.getCode());                                    // remove hospedagem
            while (container_avaliacao->pesquisar_hospedagem(&avaliacao, hospedagem.getCode())){    // busca avaliacoes relacionada a hospedagem encontrada (enquanto houver)
                container_avaliacao->remover(avaliacao.getCode());                                  // remove avaliacao
            }
        }
        while (container_avaliacao->pesquisar_usuario(&avaliacao, usuario.getEmail())){
            container_avaliacao->remover(avaliacao.getCode());
        }
        return container_usuario->remover(usuario.getEmail());
    }
    return false;
}

bool CntrSUsuario::editarConta(User usuario){
    // Instancia container de usuários.
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    User usuario_antes_da_edicao;

    usuario_antes_da_edicao.setEmail(usuario.getEmail());
    container->pesquisar(&usuario_antes_da_edicao);
    if (usuario.getName().getValue() == "")
        usuario.setName(usuario_antes_da_edicao.getName());
    if (usuario.getPassword().getValue() == "")
        usuario.setPassword(usuario_antes_da_edicao.getPassword());
    if (usuario.getLanguage().getValue() == "")
        usuario.setLanguage(usuario_antes_da_edicao.getLanguage());
    if (usuario.getDate().getValue() == "")
        usuario.setDate(usuario_antes_da_edicao.getDate());
    if (usuario.getDescription().getValue() == "")
        usuario.setDescription(usuario_antes_da_edicao.getDescription());

    return container->atualizar(usuario);
}

User CntrSUsuario::consultarDadosPessoais(Email email){
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    User usuario;

    usuario.setEmail(email);
    container->pesquisar(&usuario);

    return usuario;
}

//--------------------------------------------------------------------------------------------

list<string> CntrSHospedagem::listarHospedagens(){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    return container->getKeys();
}

bool CntrSHospedagem::cadastrarHospedagem(Accommodation hospedagem){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    if (container->pesquisar(&hospedagem))
        return false;

    return container->incluir(hospedagem);
}

bool CntrSHospedagem::descadastrarHospedagem(Code codigo){

    ContainerHospedagem *container_hospedagem;
    ContainerAvaliacao *container_avaliacao;

    container_hospedagem = ContainerHospedagem::getInstancia();
    container_avaliacao = ContainerAvaliacao::getInstancia();

    Accommodation hospedagem;
    Rating avaliacao;

    hospedagem.setCode(codigo);

    if (container_hospedagem->pesquisar(&hospedagem)){
        while (container_avaliacao->pesquisar_hospedagem(&avaliacao, codigo)){                  // busca avaliacoes relacionada a hospedagem encontrada (enquanto houver)
            container_avaliacao->remover(avaliacao.getCode());                                  // remove avaliacao
        }
        return container_hospedagem->remover(codigo);
    }
    return false;
}

bool CntrSHospedagem::editarHospedagem(Accommodation hospedagem){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    Accommodation hospedagem_antes_da_edicao;

    hospedagem_antes_da_edicao.setCode(hospedagem.getCode());
    container->pesquisar(&hospedagem_antes_da_edicao);
    if (hospedagem.getCity().getValue() == "")
        hospedagem.setCity(hospedagem_antes_da_edicao.getCity());
    if (hospedagem.getCountry().getValue() == "")
        hospedagem.setCountry(hospedagem_antes_da_edicao.getCountry());
    if (hospedagem.getGrade().getValue() == "")
        hospedagem.setGrade(hospedagem_antes_da_edicao.getGrade());
    if (hospedagem.getEmail().getValue() == "")
        hospedagem.setEmail(hospedagem_antes_da_edicao.getEmail());
    if (hospedagem.getDescription().getValue() == "")
        hospedagem.setDescription(hospedagem_antes_da_edicao.getDescription());

    return container->atualizar(hospedagem);
}

Accommodation CntrSHospedagem::consultarHospedagem(Code code){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    Accommodation hospedagem;

    hospedagem.setCode(code);
    container->pesquisar(&hospedagem);

    return hospedagem;
}

bool CntrSHospedagem::cadastrarAvaliacao(Rating avaliacao){

    ContainerAvaliacao *container_avaliacao;
    ContainerHospedagem *container_hospedagem;

    container_avaliacao = ContainerAvaliacao::getInstancia();
    container_hospedagem = ContainerHospedagem::getInstancia();

    Accommodation hospedagem;
    hospedagem.setCode(avaliacao.getAccommodationCode());
    if (container_avaliacao->pesquisar(&avaliacao) || !container_hospedagem->pesquisar(&hospedagem))
        return false;

    if (container_avaliacao->incluir(avaliacao)){           // inclui a nota na hospedagem avaliada
        container_hospedagem->pesquisar(&hospedagem);
        list<string> codigosAvaliacoes;
        codigosAvaliacoes = container_avaliacao->getKeys();
        Rating avaliacao_existente;
        Code codigo;
        int qtd_avaliacoes_ja_existentes = 0;                   // para verificar a existencia de outras avaliacoes
        for(list<string>::iterator elemento = codigosAvaliacoes.begin(); elemento != codigosAvaliacoes.end(); elemento++){
            codigo.setValue(*elemento);
            avaliacao_existente.setCode(codigo);
            if (avaliacao_existente.getAccommodationCode().getValue().compare(hospedagem.getCode().getValue())){
                qtd_avaliacoes_ja_existentes++;
            }
        }
        string nota_anterior;
        int nota_anterior_int, nova_nota;
        Grade nota;
        nota_anterior = hospedagem.getGrade().getValue();
        if (nota_anterior == ""){
            nota.setValue(avaliacao.getGrade().getValue());
            hospedagem.setGrade(nota);
        }
        else {
            nota_anterior_int = stoi(nota_anterior);
            nova_nota = nota_anterior_int - ((nota_anterior_int - (stoi(avaliacao.getGrade().getValue()))) / (qtd_avaliacoes_ja_existentes));
            nota.setValue(to_string(nova_nota));
            hospedagem.setGrade(nota);
        }
        return container_hospedagem->atualizar(hospedagem);
    }
    return false;
}

bool CntrSHospedagem::descadastrarAvaliacao(Code codigo){
    ContainerAvaliacao *container_avaliacao;

    container_avaliacao = ContainerAvaliacao::getInstancia();

    return container_avaliacao->remover(codigo);
}

bool CntrSHospedagem::editarAvaliacao(Rating avaliacao){
    ContainerAvaliacao *container;

    container = ContainerAvaliacao::getInstancia();

    Rating avaliacao_antes_da_edicao;

    avaliacao_antes_da_edicao.setCode(avaliacao.getCode());
    container->pesquisar(&avaliacao_antes_da_edicao);
    if (avaliacao.getGrade().getValue() == "")
        avaliacao.setGrade(avaliacao_antes_da_edicao.getGrade());
    if (avaliacao.getDescription().getValue() == "")
        avaliacao.setDescription(avaliacao_antes_da_edicao.getDescription());
    avaliacao.setAccommodationCode(avaliacao_antes_da_edicao.getAccommodationCode());

    return container->atualizar(avaliacao);
}

User CntrSHospedagem::acessarDadosAnfitriaoHospedagem(Code code){
    ContainerHospedagem *container_hospedagem;
    ContainerUsuario *container_usuario;

    container_hospedagem = ContainerHospedagem::getInstancia();
    container_usuario = ContainerUsuario::getInstancia();

    User user;
    Accommodation hospedagem;

    hospedagem.setCode(code);
    container_hospedagem->pesquisar(&hospedagem);
    user.setEmail(hospedagem.getEmail());
    container_usuario->pesquisar(&user);

    return user;
}

Rating CntrSHospedagem::consultarAvaliacao(Code code){
    ContainerAvaliacao *container;

    container = ContainerAvaliacao::getInstancia();

    Rating avaliacao;

    avaliacao.setCode(code);
    container->pesquisar(&avaliacao);

    return avaliacao;
}