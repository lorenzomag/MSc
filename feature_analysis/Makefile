.PHONY: branches default run clean build

default:
	cmake --build build/

run: default
	@./bin/analyse_features

clean:
	@rm -rv build/*
	@rm -v analyse_features

build:
	cmake -B build .
	cmake --build build/

branches:
	python3 select_branches/getBranchNames.py
