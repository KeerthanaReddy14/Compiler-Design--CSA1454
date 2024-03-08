#include <stdio.h>
#include <stdlib.h>

struct tac {
  char op;
  char *arg1;
  char *arg2;
  char *result;
};

struct tac *tac_create(char op, char *arg1, char *arg2, char *result) {
  struct tac *t = malloc(sizeof(struct tac));
  t->op = op;
  t->arg1 = arg1;
  t->arg2 = arg2;
  t->result = result;
  return t;
}

void tac_print(struct tac *t) {
  printf("%c %s %s %s\n", t->op, t->arg1, t->arg2, t->result);
}

int main() {
  struct tac *t1 = tac_create('+', "a", "b", "t1");
  struct tac *t2 = tac_create('*', "t1", "c", "t2");
  struct tac *t3 = tac_create('=', "t2", NULL, "a");

  tac_print(t1);
  tac_print(t2);
  tac_print(t3);

  return 0;
}
