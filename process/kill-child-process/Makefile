
APP := child parent
all: $(APP)
	@echo $(APP)


child: task.c
	gcc -g -Wall -o $@ $^

parent: kill-child-and-waitpid.c
	gcc -g -Wall -o $@ $^


.PHONY: clean
clean:
	rm $(APP)
