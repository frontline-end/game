#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSIORS 2

#define STATUS 3

float transition[STATUS][STATUS] = {{0.4, 0.3, 0.3},
                                    {0.25, 0.4, 0.35},
                                    {0.2, 0.4, 0.4}};

char *status[STATUS] = {"rock", "paper", "scissiors"};

int trackTable[STATUS][STATUS] = {
    /*0 for win, 1 for lose, 2 for draw*/
    {2, 1, 0}, // rock
    {0, 2, 1}, // paper
    {1, 0, 2}};

int nextTransition(int current) {
  float limits = (float)rand() / (float)RAND_MAX;
  float cumulative = 0.0;
  for (int i = 0; i < STATUS; i++) {
    cumulative += transition[current][i];
    if (limits < cumulative) {
      return i;      
    }
  }
  return current;
}

/*clear char when user input a char or char**/
void clear() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void getValidGuess(int *user) {
  while (scanf("%d", user) != 1 || *user < 0 || *user > 2) {
    printf("just 0, 1, 2\n");    
    clear();
  }
}

void result(int botGuess, int playerGuess) {
  int result = trackTable[botGuess][playerGuess];
  switch (result) {
  case 0:
    printf("bot win\n");
    break;
  case 1:
    printf("bot lose\n");
    break;
  case 2:
    printf("draw\n");
    break;    
  }
}

int main() {

  srand(time(NULL));
  int current = ROCK; // start

  int playerGuess;

  for (int i = 0; i < 10; i++) {
    getValidGuess(&playerGuess);
    current = nextTransition(current);
    printf("bot: %s vs player: %s\n", status[current], status[playerGuess]);
    result(current, playerGuess);    
  }    
  
  return EXIT_SUCCESS;  
}  
