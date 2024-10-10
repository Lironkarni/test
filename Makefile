# Makefile עבור הפרויקט assembler

# שם הקובץ הסופי
TARGET = assembler

# הקומפיילר
CC = gcc

# דגלי קומפילציה (ניתן להוסיף -g לדיבוג או -Wall להתרעות)
CFLAGS = -Wall -std=c11

# כל קבצי המקור (source files)
SRC = main.c utils.c

# כל קבצי האובייקט (object files) שנוצרים מקבצי המקור
OBJ = $(SRC:.c=.o)

# כלל ברירת מחדל
all: $(TARGET)

# כלל ליצירת הקובץ הסופי
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# כלל ליצירת קבצי אובייקט
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# כלל לניקוי קבצים
clean:
	rm -f $(OBJ) $(TARGET)
