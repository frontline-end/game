cc = clang
c_flags = -Wall -Wextra -g
src = rockPaper
target = out

all: $(target)

$(target): $(src)
	$(cc) $(c_flags) $(src).c -o $(target)

run:
	./$(target)

clear:
	rm -f *c~ $(target) $(src)
