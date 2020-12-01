FROM ubuntu:bionic

RUN apt-get update && apt-get -y dist-upgrade && apt-get install -y --no-install-recommends \
    ca-certificates \
    curl \
    git \
    gcc \
    python3 \
    xz-utils

RUN curl -LO https://github.com/bazelbuild/bazelisk/releases/download/v1.7.4/bazelisk-linux-amd64
RUN mv bazelisk-linux-amd64 /usr/bin/bazel
RUN chmod +x usr/bin/bazel

RUN mkdir -p /home/.cache
RUN chmod 777 /home
RUN chmod 777 /home/.cache
