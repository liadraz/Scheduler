# Simple Scheduler

A program that executes several operations (tasks) at predetermined time intervals.

## Usage
TODO
{
Tasks returns to the Scheduler unless the user asked to remove it from the queue.
Each task has an interval time which determines when the task will be executed.
Tasks can be added only when the scheduler is not Running.
Each task has a unique ID.
Tasks can remove themselves or other tasks.
Scheduler supports several main functions to the user.
Stopping the Scheduler only by calling Stop or terminating the process.
}

### How to add a task to the scheduler
    TODO

### Challenges and Features I wish to implement in the future
* Work in a multithreaded environment - each task will be executed in a thread
* Adding a task on run-time


## Run The Example Code

The repo comes with `run_sched.cpp` that runs the Scheduler
with a basic Print Massage task.
Tp try out the example code, run `make` and then run the executable.

```bash
    make
    ./run_sched.out
```


## Tests
To perform tests you can run scripts in test/ directory.
Each test unit consists a copy compile line which produces an executable.


## Git Commits Style Guide

    <type>[optional scope]: <description>
    [optional body]
    [optional footer(s)]

### Types

* api: creation and design of api
* code: Regular code maintenance.
* docs: Everything related to documentation
* test: Everything related to testing
* fix: A bug fix
* refactor: Refactoring a specific section of the codebase
* feat: The new feature you're adding to a particular application

