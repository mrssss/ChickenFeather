# docker build -t qniu/chicken-unit-test:latest .
FROM qniu/chicken-builder:latest

COPY gtest2html.xslt /gtest2html.xslt
COPY run.sh /run.sh

RUN chmod 0755 /run.sh

CMD ["/bin/bash", "/run.sh"]