
all: index.html contact.html forum.html sumeru.html sumeru-pinout.html

clean:
	rm -f index.html contact.html forum.html sumeru.html sumeru-pinout.html


%.html: %.hpp
	cpp $< -o - | egrep -v "^#" > $@
