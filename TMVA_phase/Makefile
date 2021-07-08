.PHONY: branches default run clean build apply analyse

default:
	cmake --build build/

run: default
	@./run_TMVA
apply: default
	@./apply_TMVA
analyse: default
	@./analyse_output

clean:
	@rm -rv build/*

build:
	cmake -B build .
	cmake --build build/