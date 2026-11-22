#include <string.h>

struct Stack;
void Clear(Stack* s);
struct Stack {
    size_t size;
    size_t capacity;
    char** stack;
  
    Stack()
    : size(0), capacity(10), stack(new char*[capacity]) {}

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
      Clear(this);
      delete[] stack;
    }

};

size_t Size(const Stack* s) {
  return s->size;
}

void Push(Stack* s, const char* str) {
  size_t len = strlen(str);

  if (Size(s) == s->capacity) {
    s->capacity = s->capacity*2;
    char** tmp = new char*[s->capacity];

    for (size_t i = 0; i < Size(s); i++) {
      tmp[i] = s->stack[i];
    }

    delete[] s->stack;
    s->stack = tmp;
  }
  s->stack[Size(s)] = new char[len+1];
  for (size_t i = 0; i < len; i++) {
      s->stack[Size(s)][i] = str[i];
  }
  s->stack[Size(s)][len] = '\0';

  s->size+=1;
}

void Pop(Stack* s) {
if (Size(s) > 0) {
  delete[] s->stack[Size(s)-1];
  s->size-=1;
}
}
const char* Top(const Stack* s) {
if (Size(s) > 0) {
  return s->stack[Size(s)-1];
} else {
  return nullptr;
}
}


void Clear(Stack* s) {
for (size_t i = 0; i < Size(s); i++) {
    delete[] s->stack[i];
  }
  s->size = 0;

  delete[] s->stack;
  s->capacity = 10;
  s->stack = new char*[s->capacity];
}