#include <string.h>

struct Stack;
void Clear(Stack* s);
struct Stack {
    size_t size = 0;
    size_t capacity = 10;
    char** stack = new char*[capacity]; // stack указывает на первый указатель на char
    ~Stack() {
      Clear(this);
      delete[] stack;
    }

};

  void Push(Stack* s, const char* str) {
    size_t len = strlen(str);

    if (s->size == s->capacity) {
      s->capacity = s->capacity*2;
      char** tmp = new char*[s->capacity];

      for (size_t i = 0; i < s->size; i++) {
        tmp[i] = s->stack[i];
      }

      delete[] s->stack;
      s->stack = tmp;
    }
    s->stack[s->size] = new char[len+1];
    for (size_t i = 0; i < len; i++) {
        s->stack[s->size][i] = str[i];
    }
    s->stack[s->size][len] = '\0';

    s->size+=1;
  }

void Pop(Stack* s) {
  if (s->size > 0) {
    delete[] s->stack[s->size-1];
    s->size-=1;
  }
}
char* Top(const Stack* s) {
  if (s->size > 0) {
    return s->stack[s->size-1];
  } else {
    return nullptr;
  }
}

size_t Size(const Stack* s) {
  return s->size;
}

void Clear(Stack* s) {
  for (size_t i = 0; i < s->size; i++) {
      delete[] s->stack[i];
    }
    s->size = 0;
}