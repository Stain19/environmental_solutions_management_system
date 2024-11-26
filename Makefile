# Variáveis
CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lsqlite3 -lssl -lcrypto
SRCDIR = app
AUTHDIR = auth
TESTDIR = test/testes_unitarios
BINDIR = bin
TARGET = $(BINDIR)/run_tests
PROGRAM = $(BINDIR)/program

# Arquivos fonte
SRC = $(wildcard $(SRCDIR)/**/*.c) $(wildcard $(AUTHDIR)/*.c) $(wildcard db/*.c)
TESTS = $(wildcard $(TESTDIR)/*.test.c) test/testes_unitarios/all_tests.c

# Objetos
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TESTS:.c=.o)
PROG_OBJ = $(filter-out $(TEST_OBJ), $(OBJ))

# Regras
all: $(PROGRAM)

$(TARGET): $(filter-out test/testes_unitarios/db.test.o test/testes_unitarios/main.test.o, $(TEST_OBJ)) $(filter-out app/main/main.o, $(OBJ))
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(PROGRAM): $(PROG_OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(TEST_OBJ) $(TARGET) $(PROGRAM)

run_tests: $(TARGET)
	./$(TARGET)

run_program: $(PROGRAM)
	./$(PROGRAM)

.PHONY: all clean run_tests run_program