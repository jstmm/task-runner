# Task Runner

Run 'make' to build the project.
Then run './task_run <task name> <task name>...'

To make a new task, create a function and add an entry to the tasks list:

```
void new_task() {
  printf("new task\n");
}

Task tasks[] = {
  ...
  { "new_task", new_task, false, {
      "before_task",
      NULL
    } 
  },
  ...
}
```

The format is:

```
// For C
{ <task name>, <function name>, <already-run flag>, { <prerequisite tasks>, NULL } }

// For C++
{ <task name>, <function name>, <already-run flag>, { <prerequisite tasks> } }
```
