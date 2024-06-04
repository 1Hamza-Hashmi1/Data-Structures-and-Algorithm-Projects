#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//updated

extern char * pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch; // Input from stdin
  int chNext;
  char * topWord; // Word at the top of the stack
  int word;  

  while ((ch = getchar()) != EOF)
    {
    if(ch == '\n'){ //If there are no more inputs to be inputted, stop the while loop
      break;
    }
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/')){ //If input is not a letter/does not contains >, <, or /, skip current while loop
      continue;
    }
    if(ch == '<'){ //If current input is <, then it will check if the next input does or doesnt include /
      chNext = getchar();
      if(chNext == '/'){ //If input is /, compare with top of the stack and pop
        topWord = pop(); //retrieve start-tag from stack
        word = getchar(); //reading character after '/'
            // verify if popped end identity = start identity
            if ((char) word != *topWord) { 
                fprintf (stderr, "Invalid.\n");
                exit (1); // stop due to invalidity when not equal
            }
        }
        else { // start-tag
            char * chStart = malloc(sizeof(char)); // allocate start-tag memory
            *chStart = chNext; // set start-tag to next character
            push(chStart); // pushes start identity into stack
        }
    }
}

  if (isEmpty() == 1){ // Checks validity of stack.
        fprintf(stdout, "Valid.\n");
        exit(0); 
    } else {
        fprintf (stderr, "Invalid.\n");
        exit(1);
    }
  return 0;
}
