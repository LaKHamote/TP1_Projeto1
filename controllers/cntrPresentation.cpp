#include "cntrPresentation.hpp"
#include <string>
#include <list>

using namespace std;

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras.

void CntrAControle::executar(){

    // Mensagens a serem apresentadas na tela inicial.

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Acessar dados sobre Hospedagens.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    // Mensagens a serem apresentadas na tela de seleção de serviço.

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de usuario.";
    char texto8[]="2 - Selecionar servicos relacionados a Hospedagens.";
    char texto9[]="3 - Encerrar sessao.";

    char texto10[]="Falha na autenticacao. Digite algo para continuar.";                        // Mensagem a ser apresentada.

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela inicial.

        clear();                                                                                //limpa janela
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: if(cntrAAutenticacao->autenticar(&email)){                         // Solicita autenticação.
                        bool apresentar = true;                                                 // Controle de laço.
                        while(apresentar){

                            // Apresenta tela de seleção de serviço.

                            clear();                                                            // Limpa janela.
                            if (has_colors()){
                                start_color();
                                init_color(COLOR_CYAN, 930, 910, 850);
                                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                                attron(COLOR_PAIR(1));
                                for (int y = 0; y < linha; y++) {
                                    mvhline(y, 0, ' ', coluna);
                                }
                            }
                            box(stdscr, 0, 0);
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.
                            echo();

                            switch(campo){
                                case 1: if(cntrAUsuario->executar(email)){ // houve descadastramento
                                            apresentar = false;
                                        }
                                        break;
                                case 2: cntrAHospedagem->executar(email);     // Solicita serviço de Hospedagem.
                                        break;
                                case 3: apresentar = false;
                                        break;
                            }
                        }
                    }
                    else {
                        clear();                                                                // Limpa janela.
                        if (has_colors()){
                            start_color();
                            init_color(COLOR_CYAN, 930, 910, 850);
                            init_pair(1, COLOR_BLACK, COLOR_CYAN);
                            attron(COLOR_PAIR(1));
                            for (int y = 0; y < linha; y++) {
                                mvhline(y, 0, ' ', coluna);
                            }
                        }
                        box(stdscr, 0, 0);
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;
            case 2: cntrAUsuario->cadastrar();
                    break;
            case 3: cntrAHospedagem->executar();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return;
}

//--------------------------------------------------------------------------------------------

bool CntrAAutenticacao::autenticar(Email *email){

    // Mensagens a serem apresentadas na tela de autenticação.

    char texto1[]="Digite o Email: ";
    char texto2[]="Digite a Senha: ";
    char texto3[]="Dado em formato incorreto.";
    char texto4[]="1 - Tentar novamente.";
    char texto5[]="2 - Retornar ao menu principal";

    // Campos de entrada.

    int campo;
    char campo1[80];
    char campo2[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    Password senha;                                                                                // Instancia a classe Senha.

    echo();                                                                                     // Habilita eco.

    while(true){

        // Apresenta tela de autenticação.

        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lê valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);                                                                         // Lê valor do campo.

        try{
            email->setValue(string(campo1));                                                      // Atribui valor ao Email.
            senha.setValue(string(campo2));                                                     // Atribui Valor à senha.
            break;                                                                              // Abandona laço em caso de formatos corretos.
        }
        catch(invalid_argument &exp){                                                           // Captura exceção devido a formato incorreto.
            clear();                                                                            // Limpa janela.
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            echo();
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            mvprintw(linha/4 + 2,coluna/4,"%s",texto4);
            mvprintw(linha/4 + 4,coluna/4,"%s",texto5);
            noecho();
            campo = getch() - 48;                                                                            // Lê caracter digitado.
            echo();
            if (campo == 2)
                return false;
        }
    }
    return (cntr->autenticar(*email, senha));                                                     // Solicita serviço de autenticação.
}

//--------------------------------------------------------------------------------------------

bool CntrAUsuario::executar(Email email){

    // Mensagens a serem apresentadas na tela de seleção de serviço..

    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Consultar dados pessoais.";
    char texto3[]="2 - Editar conta.";
    char texto4[]="3 - Descadastrar conta.";
    char texto5[]="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela de selação de serviço.

        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarDadosPessoais(email);
                    break;
            case 2: editarConta(email);
                    break;
            case 3: if(descadastrarConta(email)){
                        apresentar = false;
                        return true; // houve descadastramento
                    }
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
    return false; // não houve descadastramento
}

//--------------------------------------------------------------------------------------------

void CntrAUsuario::cadastrar(){

    // Mensagens a serem apresentadas na tela de cadastramento.

    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Nome            :";
    char texto3[] ="Email           :";
    char texto4[] ="Senha           :";
    char texto5[] ="Idioma          :";
    char texto6[] ="Aniversario     :";
    char texto7[] ="Descricao       :";
    char texto8[] ="Dados em formato incorreto. Digite algo.";
    char texto9[] ="Sucesso no cadastramento. Digite algo.";
    char texto10[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80], campo6[80];                // Cria campos para entrada dos dados.

    // Instancia os domínios.

    Name nome;
    Email email;
    Password senha;
    Language idioma;
    Date aniversario;
    Description descricao;

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    // Apresenta tela de cadastramento.

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 10,coluna/4,"%s ",texto6);                                                // Imprime nome do campo.
    getstr(campo5);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 12,coluna/4,"%s ",texto7);                                                // Imprime nome do campo.
    getstr(campo6);                                                                             // Lê valor do campo.

    try{
        nome.setValue(string(campo1));
        email.setValue(string(campo2));
        senha.setValue(string(campo3));
        idioma.setValue(string(campo4));
        aniversario.setValue(string(campo5));
        descricao.setValue(string(campo6));
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    // Instancia e inicializa entidade usuario.

    User usuario;

    usuario.setName(nome);
    usuario.setEmail(email);
    usuario.setPassword(senha);
    usuario.setLanguage(idioma);
    usuario.setDate(aniversario);
    usuario.setDescription(descricao);

    // Cadastra usuário.
    if(cntr->cadastrar(usuario)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto10);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

//--------------------------------------------------------------------------------------------

void CntrAUsuario::consultarDadosPessoais(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    //char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    char texto1[] ="Nome            :";
    char texto2[] ="Email           :";
    char texto3[] ="Senha           :";
    char texto4[] ="Idioma          :";
    char texto5[] ="Aniversario     :";
    char texto6[] ="Descricao       :";
    char texto7[] ="Digite algo para retornar.";

    User usuario;

    usuario = cntr->consultarDadosPessoais(email);

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s %s",texto1, usuario.getName().getValue().c_str());                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s %s",texto2, usuario.getEmail().getValue().c_str()); 
    mvprintw(linha/4 + 4,coluna/4,"%s %s",texto3, usuario.getPassword().getValue().c_str()); 
    mvprintw(linha/4 + 6,coluna/4,"%s %s",texto4, usuario.getLanguage().getValue().c_str());
    mvprintw(linha/4 + 8,coluna/4,"%s %s",texto5, usuario.getDate().getValue().c_str());
    mvprintw(linha/4 + 10,coluna/4,"%s %s",texto6, usuario.getDescription().getValue().c_str());
    mvprintw(linha/4 + 12,coluna/4,"%s",texto7);
    noecho();
    getch();
    echo();
}

void CntrAUsuario::editarConta(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.
    char texto1[] ="Preencha os seguintes campos: (Deixe em branco caso nao queira alterar)";
    char texto2[] ="Nome            :";
    char texto3[] ="Senha           :";
    char texto4[] ="Idioma          :";
    char texto5[] ="Aniversario     :";
    char texto6[] ="Descricao       :";
    char texto7[] ="Dados em formato incorreto. Digite algo.";
    char texto8[] ="Sucesso na edicao. Digite algo.";
    char texto9[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80];

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.


    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo1);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    getstr(campo2);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
    getstr(campo3);
    mvprintw(linha/4 + 8,coluna/4,"%s",texto5);
    getstr(campo4);
    mvprintw(linha/4 + 10,coluna/4,"%s",texto6);
    getstr(campo5);

    // Instancia os domínios.

    Name nome;
    Password senha;
    Language idioma;
    Date aniversario;
    Description descricao;

    try{
        if (string(campo1) != "")
            nome.setValue(string(campo1));
        if (string(campo2) != "")
            senha.setValue(string(campo2));
        if (string(campo3) != "")
            idioma.setValue(string(campo3));
        if (string(campo4) != "")
            aniversario.setValue(string(campo4));
        if (string(campo5) != "")
            descricao.setValue(string(campo5));   
    }
    catch(invalid_argument &exp){
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    User usuario;

    usuario.setName(nome);
    usuario.setEmail(email);
    usuario.setPassword(senha);
    usuario.setLanguage(idioma);
    usuario.setDate(aniversario);
    usuario.setDescription(descricao);

    // Edita usuário.
    if(cntr->editarConta(usuario)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

bool CntrAUsuario::descadastrarConta(Email email){

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto1[]="Ao descadastrar sua conta todas as hospedagens e avaliacoes atreladas a sua conta serao descadastradas.";
    char texto2[]="Voce tem certeza que deseja descadastrar sua conta?";                         // Mensagem a ser apresentada.
    char texto3[]="1 - Descadastrar.";
    char texto4[]="2 - Retornar.";
    char texto5[]="Sucesso, conta descadastrada.";
    char texto6[]="Falha no descadastramento.";

    int campo;    

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/8,"%s",texto1);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/8,"%s",texto2);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto3);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
    noecho();
    campo = getch() - 48;
    echo();

    // Descadastra usuario
    if (campo == 1){
        if(cntr->descadastrarConta(email)){
            clear();
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            mvprintw(linha/4 + 2,coluna/4,"%s",texto5);                                               // Informa sucesso.
            noecho();
            getch();
            echo();
            return true;
        }
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto6);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return false;
    }
    return false;
}


//--------------------------------------------------------------------------------------------


void CntrAHospedagem::executar(){
    // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.
    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar hospedagens disponiveis.";
    char texto3[]="2 - Consultar hospedagem.";
    char texto4[]="3 - Acessar dados de anfitroes de hospedagens.";
    char texto5[]="4 - Retornar.";

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    echo();                                                                                     // Habilita eco.
    bool apresentar = true;                                                                     // Controle de laço.
    while(apresentar){
        clear();                                                                                // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        switch(campo){
            case 1:
                listarHospedagens();
                break;
            case 2:
                consultarHospedagem();
                break;
            case 3:
                acessarDadosAnfitriaoHospedagem();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}

void CntrAHospedagem::executar(Email email){
    char texto1[] ="Selecione um dos servicos:";
    char texto2[] ="0 - Listar hospedagens disponiveis.";
    char texto3[] ="1 - Acessar dados de anfitrao de hospedagem.";
    char texto4[] ="2 - Cadastrar hospedagem.";
    char texto5[] ="3 - Cadastrar avaliacao.";
    char texto6[] ="4 - Descadastrar hospedagem.";
    char texto7[] ="5 - Descadastrar avaliacao.";
    char texto8[] ="6 - Consultar hospedagem.";
    char texto9[] ="7 - Consultar avaliacao.";
    char texto10[] ="8 - Editar hospedagem.";
    char texto11[] ="9 - Editar avaliacao.";
    char texto12[] ="R - Retornar.";            // campo = 34 ou campo 66

    int campo;                                                                                  // Campo de entrada.
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;                                                                     // Controle de laço.
    echo();                                                                                     // Habilita eco.
    while(apresentar){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);                                                                               // Limpa janela.
        mvprintw(linha/4,coluna/8,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/8,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/8,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/8,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/8,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/8,"%s",texto6);
        mvprintw(linha/4 + 2,coluna/2,"%s",texto7);
        mvprintw(linha/4 + 4,coluna/2,"%s",texto8);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/2,"%s",texto9);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/2,"%s",texto10);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/2,"%s",texto11);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/8,"%s",texto12);
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        switch(campo){
            case 0:
                listarHospedagens();
                break;
            case 1:
                acessarDadosAnfitriaoHospedagem();
                break;
            case 2:
                cadastrarHospedagem(email);
                break;
            case 3:
                cadastrarAvaliacao(email);
                break;
            case 4:
                descadastrarHospedagem(email);
                break;
            case 5:
                descadastrarAvaliacao(email);
                break;
            case 6:
                consultarHospedagem();
                break;
            case 7:
                consultarAvaliacao();
                break;
            case 8:
                editarHospedagem(email);
                break;
            case 9:
                editarAvaliacao(email);
                break;
            case 34: // R
                apresentar = false;
                break;
            case 66: // r
                apresentar = false;
                break;
        }
    }
}

void CntrAHospedagem::listarHospedagens(){
    char texto1[] ="Hospedagens disponiveis:";
    char texto2[] ="Digite qualquer tecla para retornar.";

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    list<string> codigos;

    codigos = cntr->listarHospedagens();

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    int limite_linha = 12;
    int i = 2, j = 8;
    int count = 0;

    mvprintw(linha/8,coluna/8,"%s",texto1);
    for(list<string>::iterator item = codigos.begin(); item != codigos.end(); item++){
        i++;
        count++;
        mvprintw(linha/8 + i,coluna/j,"codigo %d: %s", count, (*item).c_str());
        if (i >= limite_linha){
            i = 2;
            j = 2;
        }
    }
    mvprintw(linha/8 + 14,coluna/8,"%s",texto2);

    noecho();
    getch();
    echo();
}

void CntrAHospedagem::acessarDadosAnfitriaoHospedagem(){
    int linha,coluna;                                                                               // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                                  // Armazena quantidade de linhas e colunas.

    char texto1[] ="Informe o codigo da hospedagem a ser acessada.";                                  // Mensagem a ser apresentada.
    char texto2[] ="Codigo: ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[] ="Nome            :";
    char texto5[] ="Email           :";
    char texto6[] ="Idioma          :";
    char texto7[] ="Aniversario     :";
    char texto8[] ="Descricao       :";
    char texto9[] ="Digite algo para retornar.";
    char texto10[]="Nao existe hospedagem com o codigo informado.";
    char campo[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo);

    Code code;
    User anfitriao;

    try {
        code.setValue(string(campo));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    anfitriao = cntr->acessarDadosAnfitriaoHospedagem(code);

    if (anfitriao.getEmail().getValue() != ""){         // achou um anfitriao
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s %s",texto4, anfitriao.getName().getValue().c_str());                                                      // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s %s",texto5, anfitriao.getEmail().getValue().c_str()); 
        mvprintw(linha/4 + 4,coluna/4,"%s %s",texto6, anfitriao.getLanguage().getValue().c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s %s",texto7, anfitriao.getDate().getValue().c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s %s",texto8, anfitriao.getDescription().getValue().c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s",texto9);
    }
    else {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto10);
    }
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::cadastrarHospedagem(Email email) {
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Preencha os seguintes campos da hospedagem: ";
    char texto2[] ="Codigo          :";
    char texto3[] ="Cidade          :";
    char texto4[] ="Pais            :";
    char texto5[] ="Descricao       :";
    char texto6[] ="Dados em formato incorreto. Digite algo.";
    char texto7[] ="Sucesso no cadastramento. Digite algo.";
    char texto8[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.

    Code codigo;
    City cidade;
    Country pais;
    Description descricao;

    try {
        codigo.setValue(string(campo1));
        cidade.setValue(string(campo2));
        pais.setValue(string(campo3));
        descricao.setValue(string(campo4));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto6);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    Accommodation hospedagem;

    hospedagem.setCode(codigo);
    hospedagem.setCity(cidade);
    hospedagem.setCountry(pais);
    hospedagem.setDescription(descricao);
    hospedagem.setEmail(email);

    // Cadastra hospedagem.
    if(cntr->cadastrarHospedagem(hospedagem)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrAHospedagem::cadastrarAvaliacao(Email email){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Preencha os seguintes campos: ";
    char texto2[] ="Codigo da avaliacao                :";
    char texto3[] ="Nota                               :";
    char texto4[] ="Descricao                          :";
    char texto5[] ="Codigo da hospedagem a ser avaliada:";
    char texto6[] ="Dados em formato incorreto. Digite algo.";
    char texto7[] ="Sucesso no cadastramento. Digite algo.";
    char texto8[]="Falha no cadastramento. Digite algo.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto2);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto3);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto4);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 8,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo4);                                                                             // Lê valor do campo.

    Code codigo;
    Grade nota;
    Description descricao;
    Code codigoHospedagemavaliada;

    try {
        codigo.setValue(string(campo1));
        nota.setValue(string(campo2));
        descricao.setValue(string(campo3));
        codigoHospedagemavaliada.setValue(string(campo4));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto6);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    Rating avaliacao;

    avaliacao.setCode(codigo);
    avaliacao.setGrade(nota);
    avaliacao.setDescription(descricao);
    avaliacao.setEmail(email);
    avaliacao.setAccommodationCode(codigoHospedagemavaliada);

    // Cadastra avaliacao.
    if(cntr->cadastrarAvaliacao(avaliacao)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrAHospedagem::consultarHospedagem(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Informe o codigo da hospedagem que deseja consultar os dados.";                                  // Mensagem a ser apresentada.
    char texto2[] ="Codigo: ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[] ="Codigo          :";
    char texto5[] ="Cidade          :";
    char texto6[] ="Pais            :";
    char texto7[] ="Nota            :";
    char texto8[] ="Descricao       :";
    char texto9[] ="Email anfitriao :";
    char texto10[] ="Digite algo para retornar.";
    char texto11[] ="Nao existe hospedagem com o codigo informado.";

    char campo[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo);

    Code code;

    try {
        code.setValue(string(campo));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    Accommodation hospedagem;

    hospedagem = cntr->consultarHospedagem(code);

    if (hospedagem.getEmail().getValue() != ""){         // achou hospedagem
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s %s",texto4, hospedagem.getCode().getValue().c_str());                                                      // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s %s",texto5, hospedagem.getCity().getValue().c_str()); 
        mvprintw(linha/4 + 4,coluna/4,"%s %s",texto6, hospedagem.getCountry().getValue().c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s %s",texto7, hospedagem.getGrade().getValue().c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s %s",texto8, hospedagem.getDescription().getValue().c_str());
        mvprintw(linha/4 + 10,coluna/4,"%s %s",texto9, hospedagem.getEmail().getValue().c_str());
        mvprintw(linha/4 + 12,coluna/4,"%s",texto10);
    }
    else {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto11);
    }
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::consultarAvaliacao(){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Informe o codigo da avaliacao que deseja consultar os dados.";                                  // Mensagem a ser apresentada.
    char texto2[] ="Codigo: ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[] ="Codigo                     :";
    char texto5[] ="Nota                       :";
    char texto6[] ="Descricao                  :";
    char texto7[] ="Email avaliador            :";
    char texto8[] ="Codigo hospedagem avaliada :";
    char texto9[] ="Digite algo para retornar.";
    char texto10[] ="Nao existe avaliacao com o codigo informado.";

    char campo[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(campo);

    Code code;

    try {
        code.setValue(string(campo));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    Rating avaliacao;

    avaliacao = cntr->consultarAvaliacao(code);

    if (avaliacao.getEmail().getValue() != ""){         // achou avaliacao
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s %s",texto4, avaliacao.getCode().getValue().c_str());                                                      // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s %s",texto5, avaliacao.getGrade().getValue().c_str()); 
        mvprintw(linha/4 + 4,coluna/4,"%s %s",texto6, avaliacao.getDescription().getValue().c_str());
        mvprintw(linha/4 + 6,coluna/4,"%s %s",texto7, avaliacao.getEmail().getValue().c_str());
        mvprintw(linha/4 + 8,coluna/4,"%s %s",texto8, avaliacao.getAccommodationCode().getValue().c_str());
        mvprintw(linha/4 + 12,coluna/4,"%s",texto9);
    }
    else {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/4,"%s",texto10);
    }
    noecho();
    getch();
    echo();
}

void CntrAHospedagem::descadastrarHospedagem(Email email){
    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto1[]="Digite o codigo da hospedagem que deseja descadastrar.";
    char texto2[]="Codigo : ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[]="Ao descadastrar uma hospedagem avaliacoes atreladas a ela serao descadastradas.";
    char texto5[]="Voce tem certeza que deseja descadastrar esta hospedagem?";                         // Mensagem a ser apresentada.
    char texto6[]="1 - Descadastrar.";
    char texto7[]="2 - Retornar.";
    char texto8[]="Sucesso, hospedagem descadastrada.";
    char texto9[]="Falha no descadastramento.";
    char texto10[]="Voce nao e o anfitriao desta hospedagem, nao pode descadastra-la.";
    char texto11[]="Digite algo para retornar.";

    int campo;
    char codigoDigitado[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(codigoDigitado);

    Code code;

    try {
        code.setValue(string(codigoDigitado));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    Accommodation hospedagem;
    hospedagem = cntr->consultarHospedagem(code);
    if (hospedagem.getEmail().getValue().compare(email.getValue()) != 0){               // não é o anfitriao
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/8,"%s",texto10);
        mvprintw(linha/4 + 2,coluna/8,"%s",texto11);
        noecho();
        getch();
        echo();
        return;
    }


    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/8,"%s",texto4);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/8,"%s",texto5);
    mvprintw(linha/4 + 4,coluna/4,"%s",texto6);
    mvprintw(linha/4 + 6,coluna/4,"%s",texto7);
    noecho();
    campo = getch() - 48;
    echo();

    // Descadastra hospedagem
    if (campo == 1){
        if(cntr->descadastrarHospedagem(code)){
            clear();
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                               // Informa sucesso.
            noecho();
            getch();
            echo();
            return;
        }
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }
    return;
}

void CntrAHospedagem::descadastrarAvaliacao(Email email){
    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto1[]="Digite o codigo da avaliacao que deseja descadastrar.";
    char texto2[]="Codigo : ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[]="Voce tem certeza que deseja descadastrar esta avaliacao?";                         // Mensagem a ser apresentada.
    char texto5[]="1 - Descadastrar.";
    char texto6[]="2 - Retornar.";
    char texto7[]="Sucesso, avaliacao descadastrada.";
    char texto8[]="Falha no descadastramento.";
    char texto9[]="Voce nao e o avaliador desta avaliacao, nao pode descadastra-la.";
    char texto10[]="Digite algo para retornar.";

    int campo;
    char codigoDigitado[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(codigoDigitado);

    Code code;

    try {
        code.setValue(string(codigoDigitado));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    Rating avaliacao;
    avaliacao = cntr->consultarAvaliacao(code);
    if (avaliacao.getEmail().getValue().compare(email.getValue()) != 0){               // não é o anfitriao
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4,coluna/8,"%s",texto9);
        mvprintw(linha/4 + 2,coluna/8,"%s",texto10);
        noecho();
        getch();
        echo();
        return;
    }

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/8,"%s",texto4);                                                      // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/8,"%s",texto5);
    mvprintw(linha/4 + 4,coluna/8,"%s",texto6);
    noecho();
    campo = getch() - 48;
    echo();

    // Descadastra hospedagem
    if (campo == 1){
        if(cntr->descadastrarAvaliacao(code)){
            clear();
            if (has_colors()){
                start_color();
                init_color(COLOR_CYAN, 930, 910, 850);
                init_pair(1, COLOR_BLACK, COLOR_CYAN);
                attron(COLOR_PAIR(1));
                for (int y = 0; y < linha; y++) {
                    mvhline(y, 0, ' ', coluna);
                }
            }
            box(stdscr, 0, 0);
            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                               // Informa sucesso.
            noecho();
            getch();
            echo();
            return;
        }
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }
    return;
}

void CntrAHospedagem::editarHospedagem(Email email){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Digite o codigo da hospedagem que deseja editar.";
    char texto2[] ="Codigo : ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[] ="Preencha os seguintes campos da hospedagem: (deixe em branco caso nao deseje alterar)";
    char texto5[] ="Cidade          :";
    char texto6[] ="Pais            :";
    char texto7[] ="Descricao       :";
    char texto8[] ="Dados em formato incorreto. Digite algo.";
    char texto9[] ="Sucesso na edicao. Digite algo.";
    char texto10[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], campo3[80], codigoDigitado[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(codigoDigitado);

    Code code;

    try {
        code.setValue(string(codigoDigitado));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto4);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto6);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 6,coluna/4,"%s ",texto7);                                                 // Imprime nome do campo.
    getstr(campo3);                                                                             // Lê valor do campo.

    City cidade;
    Country pais;
    Description descricao;

    try {
        if (string(campo1) != "")
            cidade.setValue(string(campo1));
        if (string(campo2) != "")
            pais.setValue(string(campo2));
        if (string(campo3) != "")
            descricao.setValue(string(campo3));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    Accommodation hospedagem;

    hospedagem.setCode(code);
    hospedagem.setCity(cidade);
    hospedagem.setCountry(pais);
    hospedagem.setDescription(descricao);
    hospedagem.setEmail(email);

    // edita hospedagem.
    if(cntr->editarHospedagem(hospedagem)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto10);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}

void CntrAHospedagem::editarAvaliacao(Email email){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    
    char texto1[] ="Digite o codigo da avaliacao que deseja editar.";
    char texto2[] ="Codigo : ";
    char texto3[] ="Formato de codigo invalido";
    char texto4[] ="Preencha os seguintes campos da avaliacao: (deixe em branco caso nao deseje alterar)";
    char texto5[] ="Nota            :";
    char texto6[] ="Descricao       :";
    char texto7[] ="Dados em formato incorreto. Digite algo.";
    char texto8[] ="Sucesso na edicao. Digite algo.";
    char texto9[]="Falha na edicao. Digite algo.";

    char campo1[80], campo2[80], codigoDigitado[80];

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto1);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto2);
    getstr(codigoDigitado);

    Code code;

    try {
        code.setValue(string(codigoDigitado));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto3);                                               // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }

    clear();                                                                                    // Limpa janela.
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4,coluna/4,"%s",texto4);                                                     // Imprime nome do campo.
    mvprintw(linha/4 + 2,coluna/4,"%s ",texto5);                                                 // Imprime nome do campo.
    getstr(campo1);                                                                             // Lê valor do campo.
    mvprintw(linha/4 + 4,coluna/4,"%s ",texto6);                                                 // Imprime nome do campo.
    getstr(campo2);                                                                             // Lê valor do campo.                                                                             // Lê valor do campo.

    Grade nota;
    Description descricao;

    try {
        if (string(campo1) != "")
            nota.setValue(string(campo1));
        if (string(campo2) != "")
            descricao.setValue(string(campo2));
    }
    catch(invalid_argument &exp) {
        clear();                                                                                    // Limpa janela.
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
        }
        box(stdscr, 0, 0);
        mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                                           // Informa formato incorreto.
        noecho();                                                                               // Desabilita eco.
        getch();                                                                                // Leitura de caracter digitado.
        echo();                                                                                 // Habilita eco.
        return;
    }
    Rating avaliacao;
    Code accommodationCode;

    avaliacao.setCode(code);
    avaliacao.setGrade(nota);
    avaliacao.setDescription(descricao);
    avaliacao.setEmail(email);
    avaliacao.setAccommodationCode(accommodationCode);

    // edita avaliacao.
    if(cntr->editarAvaliacao(avaliacao)){
        clear();
        if (has_colors()){
            start_color();
            init_color(COLOR_CYAN, 930, 910, 850);
            init_pair(1, COLOR_BLACK, COLOR_CYAN);
            attron(COLOR_PAIR(1));
            for (int y = 0; y < linha; y++) {
                mvhline(y, 0, ' ', coluna);
            }
            box(stdscr, 0, 0);
        }
        mvprintw(linha/4 + 2,coluna/4,"%s",texto8);                                               // Informa sucesso.
        noecho();
        getch();
        echo();
        return;
    }


    clear();
    if (has_colors()){
        start_color();
        init_color(COLOR_CYAN, 930, 910, 850);
        init_pair(1, COLOR_BLACK, COLOR_CYAN);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < linha; y++) {
            mvhline(y, 0, ' ', coluna);
        }
    }
    box(stdscr, 0, 0);
    mvprintw(linha/4 + 2,coluna/4,"%s",texto9);                                                       // Informa falha.
    noecho();
    getch();
    echo();

    return;
}
