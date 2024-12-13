#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char *name;
  void (*function)();
  bool already_run;
  char *dependencies[30];
} Task;

void before_task() {
  printf("before\n");
}

void first_task() {
  printf("first task\n");
}

void second_task() {
  printf("second task\n");
}

void third_task() {
  printf("third task\n");
}

Task tasks[] = {
  { "before_task", before_task, false, {
      NULL
    } 
  },
  { "first_task",  first_task,  false, {
      "before_task",
      NULL
    }
  },
  { "second_task", second_task, false, {
      "before_task",
      "first_task",
      NULL
    }
  },
  { "third_task",  third_task,  false, {
      "before_task",
      "first_task",
      "second_task",
      NULL
    }
  },
  { NULL, NULL, false, { NULL } }
};

void invoke(char *task_name) {
  Task *task_to_run = NULL;

  for (int i = 0; tasks[i].name != NULL; ++i) {
    if (strcmp(task_name, tasks[i].name) == 0) {
      task_to_run = &tasks[i];
      break;
    }
  }

  if (!task_to_run) {
    return;
  }

  if (task_to_run->already_run) {
    printf("    (%s)\n", task_to_run->name);
    return;
  }

  for (int j = 0; task_to_run->dependencies[j] != NULL; ++j) {
    invoke(task_to_run->dependencies[j]);
  }

  task_to_run->function();
  task_to_run->already_run = true;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <task_name>...\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    invoke(argv[i]);
  }
}
