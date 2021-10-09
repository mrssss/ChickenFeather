# docker build -t qniu/chicken-unit-test:latest .
FROM qniu/chicken-builder:latest

RUN apt-get update \
    && apt-get install -y \
        xsltproc

COPY gtest2html.xslt /gtest2html.xslt
COPY run.sh /run.sh

RUN chmod 0755 /run.sh

CMD ["/bin/bash", "/run.sh"]