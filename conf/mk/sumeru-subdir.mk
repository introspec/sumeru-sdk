all:
	@$(foreach var,$(SUBDIRS),echo "Compiling: " $(var) && cd $(var) && make > compile.log; cd .. ;)

install:
	@$(foreach var,$(SUBDIRS),echo "Installing: " $(var) && cd $(var) && make install > install.log; cd .. ;)

clean:
	@$(foreach var,$(SUBDIRS),cd $(var) && make clean > clean.log; cd .. ;)

