#include "cntrPresentation.hpp"

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
                                case 1: cntrAUsuario->executar(email);                 // Solicita serviço de pessoal.
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

void CntrAUsuario::executar(Email email){

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
            case 1: consultarDadosPessoais();
                    break;
            case 2: editarConta();
                    break;
            case 3: descadastrarConta();
                    break;
            case 4: apresentar = false;
                    break;
        }
    }
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

void CntrAUsuario::consultarDadosPessoais(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar dados pessoais nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

void CntrAUsuario::editarConta(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico editar conta nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}


void CntrAUsuario::descadastrarConta(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas na tela de apresentação de dados pessoais.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar conta nao implementado. Digite algo.";             // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::executar(){

    // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

    char texto1[]="Selecione um dos serviços : ";
    char texto2[]="1 - Consultar produto de investimento.";
    char texto3[]="2 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    while(apresentar){

        // Apresenta tela simplificada de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarHospedagem();
                    break;
            case 2: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::executar(Email){

    // Mensagens a serem apresentadas tela completa de produtos financeiros.

    char texto1[] ="Selecione um dos servicos : ";
    char texto2[] ="1 - Consultar hospedagem.";
    char texto3[] ="2 - Cadastrar avaliação.";
    char texto4[] ="3 - Descadastrar avaliação.";
    char texto5[] ="4 - Consultar avaliação.";
    char texto6[] ="5 - Acessar dados de hospedagens disponíveis.";
    char texto7[] ="6 - Listar Hospedagens.";
    char texto8[] ="7 - Retornar.";

    int campo;                                                                                  // Campo de entrada.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.

    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    echo();                                                                                     // Habilita eco.

    bool apresentar = true;                                                                     // Controle de laço.

    echo();                                                                                     // Habilita eco.

    while(apresentar){

        // Apresenta tela completa de produtos financeiros.

        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s",texto6);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s",texto7);                                            // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/4,"%s",texto8);                                            // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

        switch(campo){
            case 1: consultarHospedagem();
                    break;
            case 2: cadastrarAvaliacao();
                    break;
            case 3: descadastrarAvaliacao();
                    break;
            case 4: consultarAvaliacao();
                    break;
            case 5: acessarDadosHospedagens();
                    break;
            case 6: listarHospedagens();
                    break;
            case 7: apresentar = false;
                    break;
        }
    }
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::consultarHospedagem(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Serviço consultar hospedagem não implementado. Digite algo.";                      // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::cadastrarAvaliacao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico cadastrar avaliação não implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::descadastrarAvaliacao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico descadastrar avaliação não implementado. Digite algo.";    // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::consultarAvaliacao(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico consultar avaliação não implementado. Digite algo.";       // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::acessarDadosHospedagens(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                               // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                                  // Armazena quantidade de linhas e colunas.

    char texto[]="Servico acessar dados de hospedagens disponíveis não implementado. Digite algo."; // Mensagem a ser apresentada.
    clear();                                                                                        // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                          // Imprime nome do campo.
    noecho();
    getch();
    echo();
}

//--------------------------------------------------------------------------------------------

void CntrAHospedagem::listarHospedagens(){

    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------
    // Substituir código seguinte pela implementação do método.
    //--------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------

    // Mensagens a serem apresentadas.

    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.

    char texto[]="Servico listar hospedagens não implementado. Digite algo.";                    // Mensagem a ser apresentada.
    clear();                                                                                    // Limpa janela.
    mvprintw(linha/4,coluna/4,"%s",texto);                                                      // Imprime nome do campo.
    noecho();
    getch();
    echo();
}