.PHONY: default run clean build

default:
	cmake --build build/

run: default
	@./analyse_features

clean:
	@rm -rv build/*
	@rm -v analyse_features

build:
	cmake -B build .
	cmake --build build/

