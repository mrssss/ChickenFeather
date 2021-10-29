# docker build -t qniu/chicken-unit-test:latest .
FROM qniu/chicken-builder:latest

RUN apt-get update \
    && apt-get install -y \
        xsltproc \
        --yes --no-install-recommends

COPY run.sh /run.sh

RUN chmod 0755 /run.sh

ENTRYPOINT ["/bin/bash", "/run.sh"]