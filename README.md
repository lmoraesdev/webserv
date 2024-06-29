<h1 align=center>
	<b>webserv</b>
</h1>

<h2 align=center>
	 <i>42cursus' project</i>
</h2>

<p align=center>
	O projeto `webserv` é parte integrante do currículo da 42 São Paulo, focado em desenvolver um servidor HTTP a partir do zero, conforme as especificações do RFC 7230 até 7235.
</p>

---

<h2>
Descrição
</h2>

O `webserv` é um projeto desafiador que visa a construção de um servidor HTTP que seja capaz de lidar com várias requisições simultâneas, suportar diferentes métodos HTTP (GET, POST, DELETE, etc.) e seguir os padrões definidos pelo RFC 7230 até 7235. Este projeto é uma excelente oportunidade para entender melhor os protocolos de comunicação na web e desenvolver habilidades em programação de rede e gerenciamento de processos.

---

<h2>
Objetivos
</h2>

O projeto `webserv` tem como objetivos principais:

- Implementar um servidor HTTP conforme as especificações do RFC 7230 até 7235.
- Gerenciar várias conexões simultâneas e requisições concorrentes.
- Suportar os métodos HTTP mais comuns, como GET, POST e DELETE.
- Manter uma arquitetura modular e escalável, facilitando futuras expansões e manutenção.

---

<h2>
Requisitos do Projeto
</h2>

- **Servidor HTTP**: Capaz de responder a requisições HTTP e seguir as especificações do RFC 7230 até 7235.
- **Gerenciamento de Conexões**: Lidar com múltiplas conexões simultâneas, garantindo eficiência e escalabilidade.
- **Métodos HTTP Suportados**: Implementação dos métodos GET, POST e DELETE.
- **Configuração**: O servidor deve ser configurável através de arquivos de configuração detalhados.
- **Log de Atividades**: Manter um registro de todas as requisições recebidas e as respostas enviadas.

---

<h2>
Implementação
</h2>

### Clone este repositório

Clone o repositório `webserv` para sua máquina local:

```sh
git clone https://github.com/lmoraesdev/webserv.git
```

<h2>
Compilação
</h2>

Navegue até o diretório do projeto e compile o servidor:
```sh
cd webserv
make
```

<h2>
Uso
</h2>

Execute o servidor com o comando:
```sh
./webserv path/to/configuration/file
```
O arquivo de configuração deve especificar as portas, diretórios raiz e outras configurações relevantes para o servidor HTTP.
