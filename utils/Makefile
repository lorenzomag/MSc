.PHONY: converter clean purge

converter:
	@cmake -B bin/ -S src/
	@cmake --build bin/
	@mv -v bin/converter .

clean:
	@rm -fv converter

purge: clean
	@echo "Clearing bin directory..."
	@rm -rf bin/*
	@echo "Done"