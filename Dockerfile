FROM gcc:latest as build

RUN apt-get update && \
    apt-get install -y cmake qtdeclarative5-dev cppcheck

# ADD ./src /app/src
# ADD ./tests /app/tests
# ADD CMakeLists.txt /app

VOLUME ["/app"]
WORKDIR /app

RUN cmake .
RUN make

RUN groupadd -r sample && useradd -r -g sample sample
USER sample

# Установим точку входа
# ENTRYPOINT ["./hello_world_app"]
# ENTRYPOINT ["./tests/tests"]
