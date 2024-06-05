#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


//------------------------ESTRUTURAS------------------------

struct consultas{
    int cpf;
    int codigoMedico;
    int codigoCid;
    int codigoMedicamento;
    int quantMedicamento;
};

struct cidades{
    int codigo;
    string nome;
    string uf;
};

struct especialidade{
    int codigo;
    string descricao;
};

struct medicos{
    int codigo;
    string nome;
    int codigoEspecialidade;
    string endereco;
    string telefone;
    int codigoCidade;
};

struct  pacientes{
    int cpf;
    string nome;
    string endereco;
    int codigoCidade;
};

struct cid{
    int codigo;
    string descricao;
};

struct medicamentos{
    int codigo;
    string descricao;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;
};


//----------------FUNÇÕES DE LEITURA--------------------

void lerCidade(struct cidades a[], int tamanho, int &cont){
    for(int i = 0; i < tamanho && a[i].codigo != 0; i++, cont++){
        cout << "\n\tCidade " << i << endl;
        cout << "\n\tCodigo cidade: ";
        cin >> a[i].codigo;
        cout << "\tNome da cidade: ";
        cin >> a[i].nome;
        cout << "\tUF da cidade: ";
        cin >> a[i].uf;
    }
}

void lerEspecialidade(struct especialidade a[], int tamanho, int &cont){
    for(int i = 0; i < tamanho && a[i].codigo != 0; i++, cont++){
        cout << "\n\tEspecialidade " << i << endl;
        cout << "\n\tCodigo especialidade: ";
        cin >> a[i].codigo;
        cout << "\tDescricao: ";
        cin >> a[i].descricao;
    }
}

void lerCid(struct cid a[], int tamanho, int &cont){
    for(int i = 0; i < tamanho && a[i].codigo != 0; i++, cont++){
        cout << "\n\tCID " << i << endl;
        cout << "\n\tCodigo doenca: ";
        cin >> a[i].codigo;
        cout << "\tDescricao: ";
        cin >> a[i].descricao;
    }
}

void lerMedicamentos(struct medicamentos a[], int tamanho, int &cont){
    for(int i = 0; i < tamanho && a[i].codigo != 0; i++, cont++){
        cout << "\n\tMedicamento " << i << endl;
        cout << "\n\tCodigo medicamento: ";
        cin >> a[i].codigo;
        cout << "\tDescricao: ";
        cin >> a[i].descricao;
        cout << "\tQuantia em estoque: ";
        cin >> a[i].quantEstoque;
        cout << "\tEstoque minimo: ";
        cin >> a[i].estoqueMinimo;
        cout << "\tEstoque maximo: ";
        cin >> a[i].estoqueMaximo;
        cout << "\tPreco unitario: ";
        cin >> a[i].precoUnitario;
    }
}

//------------------------FUNÇÕES DE IMPRESSÃO--------------------

void imprimirPaciente(struct pacientes vetPaciente[], int &contPaciente1){
    for(int i = 0; i < contPaciente1; i++){
        cout << "\n\tPaciente " << i << endl;
        cout << "\tCPF: " << vetPaciente[i].cpf << endl;
        cout << "\tNome: " << vetPaciente[i].nome << endl;
        cout << "\tEndereco: " << vetPaciente[i].endereco << endl;
        cout << "\tCodigo Cidade: " << vetPaciente[i].codigoCidade << endl;
    }
}

void imprimirCidade(struct cidades vetCidade[], int &contCidade){
    for(int i = 0; i < contCidade; i++){
        cout << "\n\tCidade " << i << endl;
        cout << "\n\tCodigo: " << vetCidade[i].codigo << endl;
        cout << "\n\tNome: " << vetCidade[i].nome << endl;
        cout << "\n\tUF: " << vetCidade[i].uf << endl;
    }
}

void imprimirEspecialidade(struct especialidade vetEspecialidade[], int &contEspecialidade){
    for(int i = 0; i < contEspecialidade; i++){
        cout << "\tEspecialidade " << i << endl;
        cout << "\tCodigo: " << vetEspecialidade[i].codigo << endl;
        cout << "\tDescricao: " << vetEspecialidade[i].descricao << endl;
    }
}

void imprimirCid(struct cid vetCid[], int &contCid){
    for(int i = 0; i < contCid; i++){
        cout << "\tCidu " << i << endl;
        cout << "\tCodigo: " << vetCid[i].codigo << endl;
        cout << "\tDescricao: " << vetCid[i].descricao << endl;
    }
}

void imprimirMedicamentos(struct medicamentos vetMedicamentos[], int &contMedicamentos){
    for(int i = 0; i < contMedicamentos; i++){
        cout << "\n\tMedicamento " << i << endl;
        cout << "\tCodigo: " << vetMedicamentos[i].codigo << endl;
        cout << "\tDescricao: " << vetMedicamentos[i].descricao << endl;
        cout << "\tQuantidade em estoque: " << vetMedicamentos[i].quantEstoque << endl;
        cout << "\tEstoque Minimo: " << vetMedicamentos[i].estoqueMinimo << endl;
        cout << "\tEstoque Maximo: " << vetMedicamentos[i].estoqueMaximo << endl;
        cout << "\tPreco unitario: " << vetMedicamentos[i].precoUnitario << endl;
    }
}

void imprimirConsultas(struct consultas vetConsultas[], int &contConsultas){
    for(int i = 0; i < contConsultas; i++){
        cout << "\n\tMedicamento " << i << endl;
        cout << "\tCpf: " << vetConsultas[i].cpf << endl;
        cout << "\tCodigo Medico: " << vetConsultas[i].codigoMedico << endl;
        cout << "\tCodigo CID: " << vetConsultas[i].codigoCid << endl;
        cout << "\tCodigo Medicamento: " << vetConsultas[i].codigoMedicamento << endl;
        cout << "\tQuantidade de Medicamento: " << vetConsultas[i].quantMedicamento << endl;
    }
}

//------------------------FUNÇÕES DE BUSCA--------------------


void exibirMedicamento(struct medicamentos medicamento[], int tamanhoMedicamento, int &contMedicamento){
        cout << "\n\tExibir medicamentos com estoque escasso" << endl;
        for(int i = 0; i < contMedicamento; i++){
            if(medicamento[i].quantEstoque < medicamento[i].estoqueMinimo){
                cout << "\n\tMedicamento " << i << endl;
                cout << "\tCodigo: " << medicamento[i].codigo << endl;
                cout << "\tDescricao: " << medicamento[i].descricao << endl;
                cout << "\tQuantidade em estoque: " << medicamento[i].quantEstoque << endl;
                cout << "\tEstoque Minimo: " << medicamento[i].estoqueMinimo << endl;
                cout << "\tEstoque Maximo: " << medicamento[i].estoqueMaximo << endl;
                cout << "\tPreco unitario: " << medicamento[i].precoUnitario << endl;
                cout << "\tQuantidade a ser comprada: " << medicamento[i].estoqueMaximo - medicamento[i].quantEstoque;
                cout << "\n\tValor total: " << medicamento[i].precoUnitario * (medicamento[i].estoqueMaximo - medicamento[i].quantEstoque);
            }
        }
}

bool ConsultarMedicamento(struct medicamentos medicamento[], int cod, int &contMedicamento){
        int i = 0, f = contMedicamento;
        int m = (i + f) / 2;
        for (; f >= i && cod != medicamento[m].codigo; m = (i + f) / 2){
            if (cod > medicamento[m].codigo)
                i = m + 1;
            else
                f = m - 1;
        }
        if (cod == medicamento[m].codigo){
            cout << "\n\tMedicamento " << cod << ": " << medicamento[m].descricao << endl;
            cout << "\tQuantidade em Estoque: " << medicamento[m].quantEstoque << endl;
            cout << "\tEstoque Minimo: " << medicamento[m].estoqueMinimo << endl;
            cout << "\tEstoque Maximo: " << medicamento[m].estoqueMaximo << endl;
            cout << "\tPreco Unitario: " << medicamento[m].precoUnitario << endl;
            cout << "\tValor Total no estoque: " << medicamento[m].quantEstoque * medicamento[m].precoUnitario << endl;
            return 1;
        }
        else{
            return 0;
        }
}


bool buscaAleatoriaConsultaQuantMedicamento(struct medicamentos medicamento[], int cod, int quantidade, int &contMedicamento){
                int i = 0, f = contMedicamento;
                int m = (i + f) / 2;
                for (; f >= i && cod != medicamento[m].codigo; m = (i + f) / 2){
                    if (cod > medicamento[m].codigo)
                        i = m + 1;
                    else
                        f = m - 1;
                }
                if (cod == medicamento[m].codigo){
                    if(medicamento[m].quantEstoque > quantidade){
                        medicamento[m].quantEstoque = medicamento[m].quantEstoque - quantidade;
                        return 1;
                    }   else{
                            return 0;
                    }
                }
}

bool buscaAleatoriaConsultaMedicamento(struct medicamentos medicamento[], int cod, int &contMedicamento){
        int i = 0, f = contMedicamento;
        int m = (i + f) / 2;
        for (; f >= i && cod != medicamento[m].codigo; m = (i + f) / 2){
            if (cod > medicamento[m].codigo)
                i = m + 1;
            else
                f = m - 1;
        }
        if (cod == medicamento[m].codigo){
            cout << "Medicamento " << cod << ": " << medicamento[m].descricao << endl;
            return 1;
        }
        else{
            return 0;
        }
}

void buscaAleatoriaConsultaMedicosCodEspec (struct especialidade a[], int cod, int &contEspecialidade){
    int i = 0, f = contEspecialidade;
    int m = (i + f) / 2;
    for (; f >= i && cod != a[m].codigo; m = (i + f) / 2){
        if (cod > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == a[m].codigo){
        cout << "\tEspecialidade " << cod << ": " << a[m].descricao << endl;
    }
}

bool buscaAleatoriaConsultaCid(struct cid doenca[], int cod, int &contCid){
    int i = 0, f = contCid;
    int m = (i + f) / 2;
    for (; f >= i && cod != doenca[m].codigo; m = (i + f) / 2){
        if (cod > doenca[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == doenca[m].codigo){
        cout << "Doenca " << cod << ": " << doenca[m].descricao;
        return 1;
    }
    else{
        return 0;
    }
}


bool buscaAleatoriaConsultaMedicosCod(struct medicos medico[], int codigoMedico, int &contMedicos, struct especialidade especialidades[], int &contEspecialidade){
    int i = 0, f = contMedicos;
    int m = (i + f) / 2;
    for (; f >= i && codigoMedico != medico[m].codigo; m = (i + f) / 2){
        if (codigoMedico > medico[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (codigoMedico == medico[m].codigo){
        cout << "Nome do medico: " << medico[m].nome << endl;
        buscaAleatoriaConsultaMedicosCodEspec(especialidades, medico[m].codigoEspecialidade, contEspecialidade);
        return 1;
    }
    else{
        return 0;
    }
}

bool buscaAleatoriaPacientesCodCidade(struct cidades a[], int cod, int &contCidade){
    int i = 0, f = contCidade;
    int m = (i + f) / 2;
    for (; f >= i && cod != a[m].codigo; m = (i + f) / 2){
        if (cod > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == a[m].codigo){
        cout << "\tCidade " << cod << ": " << a[m].nome << " - " << a[m].uf << endl;
        return 1;
    }
    else{
        return 0;
    }
}

bool buscaAleatoriaConsultaCpf(struct pacientes a[], int cpf, int &contPacientes, struct cidades b[], int &contCidade){
     int i = 0, f = contPacientes;
    int m = (i + f) / 2;
    for (; f >= i && cpf != a[m].cpf; m = (i + f) / 2){
        if (cpf > a[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cpf == a[m].cpf){
        cout << "Paciente " << a[i].nome << ": " << endl;
        buscaAleatoriaPacientesCodCidade(b, a[i].codigoCidade, contCidade);
        return 1;
    }
    else{
        return 0;
    }
}

bool buscaAleatoriaPacientesCpf(struct pacientes a[], int cpf, int &contPacientes){
     int i = 0, f = contPacientes;
    int m = (i + f) / 2;
    for (; f >= i && cpf != a[m].cpf; m = (i + f) / 2){
        if (cpf > a[m].cpf)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cpf == a[m].cpf){
        return 1;
    }
    else{
        return 0;
    }
}



bool buscaAleatoriaMedicosCod (struct medicos a[], int cod, int&contMedicos){
    int i = 0, f = contMedicos;
    int m = (i + f) / 2;
    for (; f >= i && cod != a[m].codigo; m = (i + f) / 2){
        if (cod > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == a[m].codigo){
        return 1;
    }
    else{
        return 0;
    }
}

bool buscaAleatoriaMedicosCodEspec (struct especialidade a[], int cod, int &contEspecialidade){
    int i = 0, f = contEspecialidade;
    int m = (i + f) / 2;
    for (; f >= i && cod != a[m].codigo; m = (i + f) / 2){
        if (cod > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == a[m].codigo){
        cout << "\tEspecialidade " << cod << ": " << a[m].descricao << endl;
        return 1;
    }
    else{
        return 0;
    }
}

bool buscaAleatoriaMedicosCodCidade (struct cidades a[], int cod, int &contCidade){
    int i = 0, f = contCidade;
    int m = (i + f) / 2;
    for (; f >= i && cod != a[m].codigo; m = (i + f) / 2){
        if (cod > a[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == a[m].codigo){
        cout << "\tCidade " << cod << ": " << a[m].nome << " - " << a[m].uf << endl;
        return 1;
    }
    else{
        return 0;
    }
}

//---------------------------EXERCICIO 2---------------------


void incluirMedico(struct medicos a[], struct medicos b[], struct medicos medicoAt[], struct especialidade c[],
                   struct cidades d[], int tamanho, int &cont1, int &cont2, int &cont3, int &contEspecialidade, int &contCidade){
    cout << "\n\tQuais medicos deseja incluir?" << endl;
    b[0].codigo = 1;
    for(int i = 0; i < tamanho && b[i].codigo != 0; i++, cont2++){
        cout << "\n\tRegistro Medico " << i << endl;
        cout << "\tCodigo: ";
        cin >> b[i].codigo;
        while (buscaAleatoriaMedicosCod(a, b[i].codigo, cont1) == 1){
                cout << "\n\tCodigo ja existente na tabela Medicos, favor inserir um novo: ";
                cin >> b[i].codigo;
        }
        cout << "\tNome: ";
        cin >> b[i].nome;
        cout << "\tCod especialidade: ";
        cin >> b[i].codigoEspecialidade;
        while (buscaAleatoriaMedicosCodEspec(c, b[i].codigoEspecialidade, contEspecialidade) == 0){
            cout << "\n\tEsse codigo nao esta presente na tabela Especialidades, favor inserir um novo: ";
            cin >> b[i].codigoEspecialidade;
        }
        cout << "\tEndereco: ";
        cin >> b[i].endereco;
        cout << "\tTelefone:";
        cin >> b[i].telefone;
        cout << "\tCod cidade: ";
        cin >> b[i].codigoCidade;
        while(buscaAleatoriaMedicosCodCidade(d, b[i].codigoCidade, contCidade) == 0){
            cout << "\n\tEsse codigo nao esta presente na tabela Especialidades, favor inserir um novo: ";
            cin >> b[i].codigoCidade;
        }
    }

    int i = 0, j = 0, k = 0;
    for (;i < cont1 && j < cont2;k++){
        if (a[i].codigo < b[j].codigo){
            medicoAt[k] = a[i];
            i++;
            }
        else {
            medicoAt[k] = b[j];
            j++;
        }
    }
    while (i < cont1){
        medicoAt[k] = a[i];
        i++;
        k++;
    }
    while (j < cont2){
        medicoAt[k] = b[j];
        j++;
        k++;
    }
    cont3 = k;
}

//------------------------------------EXERCICIO 3---------------------------------------

void incluirPaciente(struct pacientes a[], struct pacientes b[], struct pacientes pacientesAt[], struct cidades c[], int tamanho, int &cont1, int &cont2, int &cont3, int &contCidade){
    cout << "\n\tQuais pacientes deseja incluir?" << endl;
    b[0].cpf = 1;
    for(int i = 0; i < tamanho && b[i].cpf != 0; i++, cont2++){
        cout << "\n\tRegistro Paciente " << i << endl;

        cout << "\tCpf: ";
        cin >> b[i].cpf;
        while (buscaAleatoriaPacientesCpf(a, b[i].cpf, cont1) == 1){
                cout << "\n\tCpf ja existente na tabela Pacientes, favor inserir um novo: ";
                cin >> b[i].cpf;
        }
        cout << "\tNome: ";
        cin >> b[i].nome;
        cout << "\tEndereco: ";
        cin >> b[i].endereco;
        cout << "\tCod cidade: ";
        cin >> b[i].codigoCidade;
        while(buscaAleatoriaPacientesCodCidade(c, b[i].codigoCidade, contCidade) == 0){
            cout << "\n\tEsse codigo nao esta presente na tabela Cidade, favor inserir um novo: ";
            cin >> b[i].codigoCidade;
        }

    }

    int i = 0, j = 0, k = 0;
    for (;i < cont1 && j < cont2;k++){
        if (a[i].cpf < b[j].cpf){
            pacientesAt[k] = a[i];
            i++;
            }
        else {
            pacientesAt[k] = b[j];
            j++;
        }
    }
    while (i < cont1){
        pacientesAt[k] = a[i];
        i++;
        k++;
    }
    while (j < cont2){
        pacientesAt[k] = b[j];
        j++;
        k++;
    }
    cont3 = k;
}


//------------------------------------EXERCICIO 4---------------------------------------


void lerExcluirPacientes(int b[], int tamanhoPacientesExcluir, int &contPacientesExcluir){
    int i=0;
    cout << "\nQuais pacientes deseja remover? (digite o cpf) " << endl;
    for(int saida=1; i<tamanhoPacientesExcluir && saida != 0; i++){
        cin >> b[i];
        while (buscaAleatoriaPacientesCpf == 0){
            cout << "O cpf nao existe ";
            cin >> b[i];
        }
        if(b[i]<=0){
            saida = 0;
        }
    }
    contPacientesExcluir = i - 1;
}

void atualizacaoExcluirPacientes(struct pacientes a[], struct pacientes b[], int tamanho, int vetPacientesExcluir[], int &contPacientesExcluir, int &cont3){
    for(int i=0, j=0, k=0; i<tamanho && j<=contPacientesExcluir; i++){
        if(a[i].cpf != vetPacientesExcluir[j]){
            b[k] = a[i];
            k = k+1;
            cont3++;
        }else {
            j++;
            }
        }
    }



//------------------------------------EXERCICIO 5---------------------------------------

// Função para agendamento de consultas
void agendarConsulta(struct consultas a[], struct cidades cidade[], struct pacientes paciente[], struct medicos medico[],
                                    struct cid cids[], struct medicamentos medicamento[], struct especialidade especialidades[],
                                    int tamanhoConsulta, int &contConsulta, int &contPaciente, int &contCidade, int &contEspecialidade,
                                    int &contMedico, int &contCid, int &contMedicamento) {

        char continuar = 's';

        for(int i=0; i < tamanhoConsulta && continuar == 's' ; i++, contConsulta++){
                cout << "\n\tAgendamento Consulta " << i << endl;
                cout << "\n\tCpf: ";
                cin >> a[i].cpf;
                while(buscaAleatoriaConsultaCpf(paciente, a[i].cpf,  contPaciente, cidade, contCidade ) == 0){
                    cout << "Paciente nao encontrado, digite novamente: ";
                    cin >> a[i].cpf;
                }
                cout << "\tCodigo do Medico: ";
                cin >> a[i].codigoMedico;
                while(buscaAleatoriaConsultaMedicosCod(medico, a[i].codigoMedico, contMedico, especialidades, contEspecialidade) == 0){
                    cout << "Medico nao encontrado, digite novamente: ";
                    cin >> a[i].codigoMedico;
                }
                cout << "\tCodigo CID: ";
                cin >> a[i].codigoCid;
                while(buscaAleatoriaConsultaCid(cids, a[i].codigoCid, contCid) == 0){
                    cout << "Doenca nao encontrada, digite novamente: ";
                    cin >> a[i].codigoCid;
                }
                cout << "\tCodigo Medicamento: ";
                cin >> a[i].codigoMedicamento;
                while(buscaAleatoriaConsultaMedicamento(medicamento, a[i].codigoMedicamento, contMedicamento) == 0){
                    cout << "Medicamento nao encontrado, digite novamente: ";
                    cin >> a[i].codigoMedicamento;
                }
                cout << "\tQuantidade de Medicamento: ";
                cin >> a[i].quantMedicamento;
                while(buscaAleatoriaConsultaQuantMedicamento(medicamento, a[i].codigoMedicamento, a[i].quantMedicamento, contMedicamento) == 0){
                    cout << "Quantidade de medicamento insuficiente, digite novamente: ";
                    cin >> a[i].codigoMedicamento;
                    }

                if(i < (tamanhoConsulta - 1)){
                    cout << "deseja agendar mais uma consulta? (s/n) ";
                    cin >> continuar;
                }
        }
}

//---------------------------------------------------------------------------------------------------------



//------------------------------continuar no programa------------------------------------------

void continuarPrograma(char &continuar){
    cout << "\n\tDeseja continuar no programa?(s/n) ";
    cin >> continuar;
}

void menu(struct cidades vetCidade[], int tamanhoCidade, int &contCidade, struct especialidade vetEspecialidade[],
                  int tamanhoEspecialidade, int &contEspecialidade, struct cid vetCid[], int tamanhoCid, int &contCid,
                  struct medicamentos vetMedicamentos[], int tamanhoMedicamentos, int &contMedicamentos, struct medicos vetMedico[],
                  struct medicos vetMedico2[], struct medicos vetMedicoFinal[], int tamanhoMedico, int &contMedico1, int &contMedico2,
                  int &contMedico3, struct pacientes vetPacientes[], struct pacientes vetPacientes2[], struct pacientes vetPacientesFinal[],
                  int tamanhoPacientes, int &contPacientes1, int &contPacientes2, int &contPacientes3, int vetPacientesExcluir[], int contPacientesExcluir,
                  struct consultas vetConsulta[], int tamanhoConsulta, int &contConsulta){


    char continuar = 's';
    int escolheFunc;
    while(continuar == 's'){
    cout << "\n\n\tMENU ARQUIVOS SEQUENCIAIS" << endl;
    cout << "\n\n\tQual funcao deseja usar?" << endl;

    cout << "\n\t[01] Ler vetor Cidade" << endl;
    cout << "\n\t[02] Ler vetor Especialidades" << endl;
    cout << "\n\t[03] Ler vetor CID" << endl;
    cout << "\n\t[04] Ler vetor Medicamentos" << endl;

    cout << "\n\t[05] Imprimir vetor Cidade" << endl;
    cout << "\n\t[06] Imprimir vetor Especialidades" << endl;
    cout << "\n\t[07] Imprimir vetor CID" << endl;
    cout << "\n\t[08] Imprimir vetor Medicamentos" << endl;

    cout << "\n\t[09] Inserir Medicos" << endl;
    cout << "\n\t[10] Inserir Pacientes" << endl;
    cout << "\n\t[11] Excluir Pacientes" << endl;
    cout << "\n\t[12] Imprimir Pacientes" << endl;

    cout << "\n\t[13] Agendar Consultas" << endl;
    cout << "\n\t[14] Imprimir Consultas" << endl;
    cout << "\n\t[15] Consultar Medicamento" << endl;
    cout << "\n\t[16] Exibir Medicamentos com estoque escasso" << endl;


    cout << "\n\n\tEscolha: ";
    cin >> escolheFunc;

    switch(escolheFunc){
        case 1:
            lerCidade(vetCidade, tamanhoCidade, contCidade);
            continuarPrograma(continuar);
            break;
        case 2:
            lerEspecialidade(vetEspecialidade, tamanhoEspecialidade, contEspecialidade);
            continuarPrograma(continuar);
            break;
        case 3:
            lerCid(vetCid, tamanhoCid, contCid);
            continuarPrograma(continuar);
            break;
        case 4:
            lerMedicamentos(vetMedicamentos, tamanhoMedicamentos, contMedicamentos);
            continuarPrograma(continuar);
            break;
        case 5:
            imprimirCidade(vetCidade, contCidade);
            continuarPrograma(continuar);
            break;
        case 6:
            imprimirEspecialidade(vetEspecialidade, contEspecialidade);
            continuarPrograma(continuar);
            break;
        case 7:
            imprimirCid(vetCid, contCid);
            continuarPrograma(continuar);
            break;
        case 8:
            imprimirMedicamentos(vetMedicamentos, contMedicamentos);
            continuarPrograma(continuar);
            break;
        case 9:
            incluirMedico(vetMedico, vetMedico2, vetMedicoFinal, vetEspecialidade, vetCidade,
                           tamanhoMedico, contMedico1, contMedico2, contMedico3, contEspecialidade, contCidade);
            continuarPrograma(continuar);
            break;
        case 10:
            incluirPaciente(vetPacientes, vetPacientes2, vetPacientesFinal, vetCidade, tamanhoPacientes,
                            contPacientes1, contPacientes2, contPacientes3, contCidade);
            continuarPrograma(continuar);
            break;
        case 11:
            lerExcluirPacientes(vetPacientesExcluir, tamanhoPacientes, contPacientesExcluir);
            atualizacaoExcluirPacientes(vetPacientes, vetPacientesFinal, tamanhoPacientes, vetPacientesExcluir, contPacientes1, contPacientes3);
            continuarPrograma(continuar);
            break;
        case 12:
            imprimirPaciente(vetPacientes, contPacientes1);
            continuarPrograma(continuar);
            break;
        case 13:
            agendarConsulta(vetConsulta, vetCidade, vetPacientes, vetMedico, vetCid, vetMedicamentos, vetEspecialidade,
                            tamanhoConsulta, contConsulta, contPacientes1,contCidade, contEspecialidade, contMedico1,
                             contCid, contMedicamentos);
            continuarPrograma(continuar);
            break;
        case 14:
            imprimirConsultas(vetConsulta, contConsulta);
            continuarPrograma(continuar);
            break;
        case 15:
            int medconsultar;
            cout << "\n\tQual o codigo do medicamento que deseja buscar? ";
            cin >> medconsultar;
            while(ConsultarMedicamento(vetMedicamentos, medconsultar, contMedicamentos) == 0){
                cout << "\n\tMedicamento nao encontrado, digite outro codigo " << endl;
                cin >> medconsultar;
            };
            continuarPrograma(continuar);
            break;
        case 16:
            exibirMedicamento(vetMedicamentos, tamanhoMedicamentos, contMedicamentos);
            continuarPrograma(continuar);
            break;

        default:
            cout << "escolha não esta nos parametros" << endl;

    }

}
                  }


int main()
{

    const int tamanhoCidade = 10, tamanhoEspecialidade = 10, tamanhoCid = 10,
    tamanhoMedicamentos = 10, tamanhoMedico = 10, tamanhoPacientes = 10, tamanhoConsulta = 10;

    int contCidade = 3, contEspecialidade = 3, contCid = 3, contMedicamentos = 3,
     contMedico1 = 3, contMedico2 = 0, contMedico3 = 0, contPacientes1 = 3, contPacientes2 = 0,
      contPacientes3 = 0, contPacientesExcluir = 0, contConsulta = 0;


    struct cidades vetCidade[tamanhoCidade];
    vetCidade[0].codigo = 2;
    vetCidade[0].nome = "Sao Paulo";
    vetCidade[0].uf = "SP";

    vetCidade[1].codigo = 3;
    vetCidade[1].nome = "Sao Carlos";
    vetCidade[1].uf = "SP";

    vetCidade[2].codigo = 5;
    vetCidade[2].nome = "Londrina";
    vetCidade[2].uf = "PR";

    struct especialidade vetEspecialidade[tamanhoEspecialidade];
    vetEspecialidade[0].codigo = 1;
    vetEspecialidade[0].descricao = "Cardiologista";

    vetEspecialidade[1].codigo = 3;
    vetEspecialidade[1].descricao = "Fisioterapeuta";

    vetEspecialidade[2].codigo = 5;
    vetEspecialidade[2].descricao = "Dermatologista";

    struct cid vetCid[tamanhoCid];
    vetCid[0].codigo = 2;
    vetCid[0].descricao = "Dengue";

    vetCid[1].codigo = 4;
    vetCid[1].descricao = "Virose";

    vetCid[2].codigo = 6;
    vetCid[2].descricao = "COVID";

    struct medicamentos vetMedicamentos[tamanhoMedicamentos];
    vetMedicamentos[0].codigo = 1;
    vetMedicamentos[0].descricao = "dipirona";
    vetMedicamentos[0].quantEstoque = 20;
    vetMedicamentos[0].estoqueMinimo = 10;
    vetMedicamentos[0].estoqueMaximo = 40;
    vetMedicamentos[0].precoUnitario = 15.5;

    vetMedicamentos[1].codigo = 3;
    vetMedicamentos[1].descricao = "loratadina";
    vetMedicamentos[1].quantEstoque = 15;
    vetMedicamentos[1].estoqueMinimo = 10;
    vetMedicamentos[1].estoqueMaximo = 30;
    vetMedicamentos[1].precoUnitario = 10;

    vetMedicamentos[2].codigo = 4;
    vetMedicamentos[2].descricao = "cimegripe";
    vetMedicamentos[2].quantEstoque = 10;
    vetMedicamentos[2].estoqueMinimo = 15;
    vetMedicamentos[2].estoqueMaximo = 40;
    vetMedicamentos[2].precoUnitario = 23.5;

    struct medicos vetMedico[tamanhoMedico];
    vetMedico[0].codigo = 1;
    vetMedico[0].nome = "jorge";
    vetMedico[0].codigoEspecialidade = 2;
    vetMedico[0].endereco = "Sao Paulo";
    vetMedico[0].telefone = "18 93232-3232";
    vetMedico[0].codigoCidade = 2;

    vetMedico[1].codigo = 3;
    vetMedico[1].nome = "Sao Carlos";
    vetMedico[1].codigoEspecialidade = 2;
    vetMedico[1].endereco = "taruma";
    vetMedico[1].telefone = "18 94242-4242";
    vetMedico[1].codigoCidade = 3;

    vetMedico[2].codigo = 5;
    vetMedico[2].nome = "vinicius";
    vetMedico[2].codigoEspecialidade = 3;
    vetMedico[2].endereco = "Londrina";
    vetMedico[2].telefone = "18 95252-5252";
    vetMedico[2].codigoCidade = 5;

    struct medicos vetMedico2[tamanhoMedico];
    struct medicos vetMedicoFinal[tamanhoMedico];
    struct pacientes vetPacientes[tamanhoPacientes];
    vetPacientes[0].cpf = 2;
    vetPacientes[0].nome = "vinicius";
    vetPacientes[0].endereco = "Londrina";
    vetPacientes[0].codigoCidade =5;

    vetPacientes[0].cpf = 6;
    vetPacientes[0].nome = "manuela";
    vetPacientes[0].endereco = "Sao Carlos";
    vetPacientes[0].codigoCidade =2;

    vetPacientes[0].cpf = 2;
    vetPacientes[0].nome = "diego";
    vetPacientes[0].endereco = "Londrina";
    vetPacientes[0].codigoCidade =5;

    struct pacientes vetPacientes2[tamanhoPacientes];
    struct pacientes vetPacientesFinal[tamanhoPacientes];
    int vetPacientesExcluir[tamanhoPacientes];
    struct consultas vetConsulta[tamanhoConsulta];

    menu(vetCidade, tamanhoCidade, contCidade, vetEspecialidade, tamanhoCidade, contEspecialidade,
          vetCid , tamanhoCid, contCid, vetMedicamentos, tamanhoMedicamentos, contMedicamentos, vetMedico,
          vetMedico2, vetMedicoFinal, tamanhoMedico, contMedico1, contMedico2, contMedico3, vetPacientes,
          vetPacientes2, vetPacientesFinal, tamanhoPacientes, contPacientes1, contPacientes2, contPacientes3,
           vetPacientesExcluir, contPacientesExcluir, vetConsulta, tamanhoConsulta, contConsulta);


    return 0;
}
