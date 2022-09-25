dns-message-fuzzer: dns-message-fuzzer.c
	./remove-main.sh
	clang -g -fsanitize=fuzzer -o dns-message-fuzzer dns-message-fuzzer.c