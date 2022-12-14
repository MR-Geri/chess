FROM gcc:latest as build

RUN apt-get update && \
    apt-get install -y cmake cppcheck graphviz doxygen clang-format libqt5svg5-dev qtdeclarative5-dev qtmultimedia5-dev

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
