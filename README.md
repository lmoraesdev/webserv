*This project was created as part of the 42 curriculum by lmoraes.*

# webserv

A non-blocking HTTP/1.1 server written from scratch in C++98. No frameworks, no libraries — just sockets, `poll()`, and the RFC.

![c++](https://img.shields.io/badge/C%2B%2B-98-00599C?logo=cplusplus&logoColor=white)
![http](https://img.shields.io/badge/HTTP%2F1.1-RFC%207230--7235-blue)
![status](https://img.shields.io/badge/status-functional-green)

---

## Description

The goal was to build an HTTP server that holds up under the same kind of constraints a production server has to deal with: many clients connected at the same time, no thread per request, configurable routes, and behavior consistent with the RFC under load.

The project forced me to think about networking, parsing, and resource management at a level most web work hides behind a framework.

## What it does

- Listens on multiple `interface:port` pairs defined in an NGINX-style config file
- Handles many concurrent connections through a single `poll()` loop (no threads, no fork-per-request, no read/write outside of `poll`)
- Parses HTTP/1.1 requests by hand — request line, headers, body
- Serves `GET`, `POST`, and `DELETE`
- Serves static files, lists directories when `autoindex` is on, applies index files and custom error pages
- Supports HTTP redirects per route
- Supports file upload via `multipart/form-data` with a configurable upload directory
- Runs CGI scripts based on file extension (executed via `execve`, communicates over pipes)
- Returns proper status codes and stays available under sustained load
- Enforces `client_max_body_size` per server

## Architecture

```
                ┌──────────────┐
                │  Config      │   parses NGINX-style file once at boot
                └──────┬───────┘
                       ▼
                ┌──────────────┐
client ───────▶ │  poll() loop │ ──┐  one loop, all sockets non-blocking
                └──────┬───────┘   │
                       ▼            │
                ┌─────────────┐     │
                │  Request    │ ◀───┘  parses bytes as they arrive
                │  parser     │
                └──────┬──────┘
                       ▼
                ┌──────────────┐
                │  Handler     │  static / upload / CGI / redirect / error
                └──────┬───────┘
                       ▼
                ┌──────────────┐
                │  Response    │  writes back when socket is ready
                └──────────────┘
```

Every socket — listening or connected — is registered with the same `poll()` call. When the kernel reports a socket as ready to read or write, the loop services it for one step and goes back to polling. No request blocks another, and no read or write happens without `poll()` clearing it first.

## Project layout

```
.
├── Makefile
├── main.cpp
├── includes/        # headers
├── src/             # server, parser, response, CGI, config
├── config/          # example config files
└── www/             # default document root for testing
```

## Instructions

Requires a C++98 compiler (`g++` works) and `make`. Tested on Linux.

```bash
git clone https://github.com/lmoraesdev/webserv.git
cd webserv
make
./webserv config/default.conf
```

Then point a browser or `curl` at any of the host/port pairs declared in the config:

```bash
curl -i http://localhost:8080/
curl -i -X POST -F "file=@photo.png" http://localhost:8080/upload
```

## Configuration

The server reads an NGINX-style config file. A minimal example:

```nginx
server {
    listen          8080;
    root            ./www;
    index           index.html;
    error_page 404  /errors/404.html;
    client_max_body_size 10M;

    location / {
        allow_methods   GET POST DELETE;
        autoindex       on;
    }

    location /old {
        return 301 /new;
    }

    location /upload {
        allow_methods   POST;
        upload_store    ./uploads;
    }

    location /cgi-bin/ {
        cgi_extension   .py;
        cgi_path        /usr/bin/python3;
    }
}
```

Multiple `server` blocks on different ports are supported.

## What I learned

- That `poll()` looks simple in the man page and is brutal in practice — the bug isn't in poll, it's in how you treat partial reads, half-closed sockets, and the order of events you process
- How TCP actually behaves: requests don't arrive in one piece, responses don't leave in one piece, and any code that assumes they do will eventually break
- Why writing an HTTP parser by hand makes you respect every framework that did it for you
- The cost of every `malloc`, every `read`, every `close` when there are no abstractions to hide them
- That C++98 without smart pointers is a real exercise in RAII discipline

## Resources

- [RFC 7230](https://datatracker.ietf.org/doc/html/rfc7230) — HTTP/1.1 message syntax
- [RFC 7231](https://datatracker.ietf.org/doc/html/rfc7231) — HTTP/1.1 semantics
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [NGINX directives](https://nginx.org/en/docs/dirindex.html)
- [CGI specification — RFC 3875](https://datatracker.ietf.org/doc/html/rfc3875)

### Note on AI

This project was delivered before AI assistants were allowed by the 42 curriculum. All design, code, and debugging were done manually using the RFCs, man pages, and peer discussions.
