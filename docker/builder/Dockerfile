# docker build -t qniu/chicken-builder:latest .
FROM ubuntu:20.04 

ENV DEBIAN_FRONTEND=noninteractive LLVM_VERSION=13

RUN apt-get update \
    && apt-get install \
        apt-transport-https \
        apt-utils \
        ca-certificates \
        dnsutils \
        gnupg \
        iputils-ping \
        lsb-release \
        wget \
        --yes --no-install-recommends --verbose-versions \
    && export LLVM_PUBKEY_HASH="bda960a8da687a275a2078d43c111d66b1c6a893a3275271beedf266c1ff4a0cdecb429c7a5cccf9f486ea7aa43fd27f" \
    && wget -nv -O /tmp/llvm-snapshot.gpg.key https://apt.llvm.org/llvm-snapshot.gpg.key \
    && echo "${LLVM_PUBKEY_HASH} /tmp/llvm-snapshot.gpg.key" | sha384sum -c \
    && apt-key add /tmp/llvm-snapshot.gpg.key \
    && export CODENAME="$(lsb_release --codename --short | tr 'A-Z' 'a-z')" \
    && echo "deb [trusted=yes] https://apt.llvm.org/${CODENAME}/ llvm-toolchain-${CODENAME}-${LLVM_VERSION} main" >> \
        /etc/apt/sources.list

# initial packages
RUN apt-get update \
    && apt-get install \
        bash \
        fakeroot \
        ccache \
        curl \
        software-properties-common \
        --yes --no-install-recommends

RUN apt-get update \
    && apt-get install \
        bash \
        build-essential \
        ccache \
        cmake \
        curl \
        gdb \
        git \
        gperf \
        clang-${LLVM_VERSION} \
        clang-tidy-${LLVM_VERSION} \
        clang-format-${LLVM_VERSION} \
        lld-${LLVM_VERSION} \
        llvm-${LLVM_VERSION} \
        llvm-${LLVM_VERSION}-dev \
        libicu-dev \
        libreadline-dev \
        moreutils \
        ninja-build \
        pigz \
        rename \
        tzdata \
        --yes --no-install-recommends

# Install some library
RUN apt-get update \
    && apt-get install \
        libpoco-dev \
        libgtest-dev \
        --yes --no-install-recommends

# This symlink required by gcc to find lld compiler
RUN ln -s /usr/bin/lld-${LLVM_VERSION} /usr/bin/ld.lld
RUN ln -s /usr/bin/lld-${LLVM_VERSION} /usr/bin/ld


ENV CC=clang-${LLVM_VERSION}
ENV CXX=clang++-${LLVM_VERSION}

COPY build.sh /
CMD ["bash", "-c", "/build.sh 2>&1 | ts"]