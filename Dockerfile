FROM debian:bookworm as builder

RUN apt update && \
    DEBIAN_FRONTEND=noninteractive apt install build-essential clang pcregrep -y

ADD . /simpledns
WORKDIR /simpledns/fuzz

RUN make

FROM debian:bookworm
COPY --from=builder /simpledns/fuzz/dns-message-fuzzer /