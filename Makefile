
size ?= 10

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@./a.out $(ARG)

.PHONY: all clean fclean re