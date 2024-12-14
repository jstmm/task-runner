#include <print>
#include <vector>

typedef struct {
  std::string name;
  void (*function)();
  bool already_run;
  std::vector<std::string> dependencies;
} Task;

void before_task() {
  std::println("before");
}

void first_task() {
  std::println("first task");
}

void second_task() {
  std::println("second task");
}

void third_task() {
  std::println("third task");
}

std::vector<Task> tasks = {
  { "before_task", before_task, false, {
    }
  },
  { "first_task",  first_task,  false, {
      "before_task"
    }
  },
  { "second_task", second_task, false, {
      "before_task",
      "first_task"
    }
  },
  { "third_task",  third_task,  false, {
      "before_task",
      "first_task",
      "second_task"
    }
  }
};

void invoke(std::string task_name) {
  Task *task_to_run = nullptr;

  for (auto t : tasks) {
    if (task_name == t.name) {
      task_to_run = &t;
      break;
    }
  }

  if (!task_to_run) {
    return;
  }

  if (task_to_run->already_run) {
    std::println("\t({})", task_to_run->name);
    return;
  }

  for (auto d : task_to_run->dependencies) {
    invoke(d);
  }

  task_to_run->function();
  task_to_run->already_run = true;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::println("Usage: {} <task_name>...", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    invoke(argv[i]);
  }
}
