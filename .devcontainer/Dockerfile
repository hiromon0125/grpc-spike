FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        build-essential \
        clang \
        cmake \
        git \
        pkg-config \
        protobuf-compiler \
        libprotobuf-dev \
        libprotoc-dev \
        protobuf-compiler-grpc \
        libgrpc-dev \
        libgrpc++-dev \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*
