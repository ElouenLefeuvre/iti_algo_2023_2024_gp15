# Makefile

# Compiler and flags
CC = gcc
CFLAGS = -I./include
CUNIT_FLAGS = -lcunit


# Source files
TESTS_DIR = tests
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/CodeBinaire.c $(SRC_DIR)/Octet.c $(SRC_DIR)/Statistiques.c $(SRC_DIR)/ArbreHuffman.c $(SRC_DIR)/FileDePriorite.c $(SRC_DIR)/TableDeCodage.c $(SRC_DIR)/Decompression.c $(SRC_DIR)/Compression.c $(SRC_DIR)/main.c  
TEST_CODEBINAIRE_SRC = $(TESTS_DIR)/testCodeBinaire.c
TEST_OCTET_SRC = $(TESTS_DIR)/testOctet.c
TEST_STATISTIQUE_SRC = $(TESTS_DIR)/testStatistiques.c
TEST_AH_SRC = $(TESTS_DIR)/testArbreHuffman.c
TEST_FDP_SRC = $(TESTS_DIR)/testFileDePriorite.c
TEST_TDC_SRC = $(TESTS_DIR)/testTableDeCodage.c

# Object files
OBJ_FILES = CodeBinaire.o Octet.o Statistiques.o ArbreHuffman.o FileDePriorite.o TableDeCodage.o Decompression.o Compression.o

# Target executable
TARGET = prog
TEST_CODEBINAIRE_TARGET = testCodeBinaire
TEST_OCTET_TARGET = testOctet
TEST_STATISTIQUE_TARGET = testStatistiques
TEST_AH_TARGET = testArbreHuffman
TEST_FDP_TARGET = testFdp
TEST_TDC_TARGET = testTdc
# Targets and rules
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $@


$(TEST_CODEBINAIRE_TARGET): $(TEST_CODEBINAIRE_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_CODEBINAIRE_SRC) $(OBJ_FILES) -o $(TEST_CODEBINAIRE_TARGET) $(CUNIT_FLAGS)


$(TEST_OCTET_TARGET): $(TEST_OCTET_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_OCTET_SRC) $(OBJ_FILES) -o $(TEST_OCTET_TARGET) $(CUNIT_FLAGS)

$(TEST_STATISTIQUE_TARGET): $(TEST_STATISTIQUE_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_STATISTIQUE_SRC) $(OBJ_FILES) -o $(TEST_STATISTIQUE_TARGET) $(CUNIT_FLAGS)

$(TEST_AH_TARGET): $(TEST_AH_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_AH_SRC) $(OBJ_FILES) -o $(TEST_AH_TARGET) $(CUNIT_FLAGS)

$(TEST_FDP_TARGET): $(TEST_FDP_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_FDP_SRC) $(OBJ_FILES) -o $(TEST_FDP_TARGET) $(CUNIT_FLAGS)

$(TEST_TDC_TARGET): $(TEST_TDC_SRC) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_TDC_SRC) $(OBJ_FILES) -o $(TEST_TDC_TARGET) $(CUNIT_FLAGS)




CodeBinaire.o: $(SRC_DIR)/CodeBinaire.c
	$(CC) -c $< -o $@ $(CFLAGS)

Octet.o: $(SRC_DIR)/Octet.c
	$(CC) -c $< -o $@ $(CFLAGS)

Statistiques.o: $(SRC_DIR)/Statistiques.c
	$(CC) -c $< -o $@ $(CFLAGS)

ArbreHuffman.o: $(SRC_DIR)/ArbreHuffman.c
	$(CC) -c $< -o $@ $(CFLAGS)

FileDePriorite.o: $(SRC_DIR)/FileDePriorite.c
	$(CC) -c $< -o $@ $(CFLAGS)

TableDeCodage.o: $(SRC_DIR)/TableDeCodage.c
	$(CC) -c $< -o $@ $(CFLAGS)

Decompression.o:$(SRC_DIR)/Decompression.c
	$(CC) -c $< -o $@ $(CFLAGS)

Compress.o:$(SRC_DIR)/Compression.c
	$(CC) -c $< -o $@ $(CFLAGS)
 
clean:
	rm -f $(OBJ_FILES) $(TARGET) $(TEST_CODEBINAIRE_TARGET) $(TEST_OCTET_TARGET) $(TEST_STATISTIQUE_TARGET) $(TEST_AH_TARGET) $(TEST_FDP_TARGET) $(TEST_TDC_TARGET)



