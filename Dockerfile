FROM ubuntu:18.04

ARG USERNAME=code
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd -g $USER_GID $USERNAME \
    && useradd -u $USER_UID -g $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y build-essential cmake git ninja-build python \
    libgl1-mesa-dev libicu-dev xorg-dev

USER $USERNAME
