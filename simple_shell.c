#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_TOKEN_LENGTH 32
#define MAX_TOKEN_COUNT 64
#define MAX_LINE_LENGTH 512

// Note: Current implementation ignores errors from fgets(), fork(), and
// waitpid(). Also, we assume a maximum of MAX_TOKEN_COUNT in each line.

int shell(char*, char**);

int main() {
  char line[MAX_LINE_LENGTH];
  while(printf("shell: ") && fgets(line, MAX_LINE_LENGTH, stdin)) {
    // Build the command and arguments, using execv conventions.
    line[strlen(line)-1] = '\0'; // get rid of the new line
    char* command = NULL;
    char* arguments[MAX_TOKEN_COUNT];
    int argument_count = 0;

    char* token = strtok(line, " ");
    while(token) {
      if(!command) command = token;
      arguments[argument_count] = token;
      argument_count++;

      token = strtok(NULL, " ");
    }
    arguments[argument_count] = NULL;
    
    // Call the command.
    shell(command, arguments);
  }
}

int shell(char* command, char** args) {
  pid_t pid = fork();
  if(pid) { // parent
    waitpid(pid, NULL, 0);
  } else { // child
    execvp(command, args);
  }
}
