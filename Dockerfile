FROM gcc:latest as build

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y cmake qtdeclarative5-dev cppcheck doxygen clang-format

# ADD ./src /app/src
# ADD ./tests /app/tests
# ADD CMakeLists.txt /app

VOLUME ["/app"]
WORKDIR /app

USER app

# RUN cmake .
# RUN make


# Установим точку входа
# ENTRYPOINT ["./hello_world_app"]
# ENTRYPOINT ["./tests/tests"]
