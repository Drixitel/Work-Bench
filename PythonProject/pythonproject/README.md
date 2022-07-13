# Guessing Game 
- Computer selects a random number from 0-100 
  - Genertate random number 
  - Store random number per game 
  - This operation should only happen once per game 
- User inputs a value as a guess
- Computer takes input and checks against the value stored 
  - If it is the number the User wins 
  - Elif it is not the number 
    - Ask for a new input 

# Additional 
- store the inital guess and display it to the user 
- store the guesses and if the guess appears again show a message of it being a repeat
- each wrong guess displays a unique "wrong answer" output 
- Tell the user they input the wrong format (string, float, symbol)

# Template 
- `While loop` to keep the game running 
  - `Exit with a command` if the user no longer want to play 
  - `While the game still plays`: 
    - Have the computer generate a random number (once)
    - `Store` the number in a list/Directory
    - `Announce` to the user that a number was selected 
    - `Ask` the user to give a guess
      - `Store` the number given 
      - Compare the number to stored Computer value (CV)
        - If statements: 
          - `if guess == CV` return a congradualtions statement 
            - End game OR Ask if the user would like to play again 
              - (This might be difficult bc I need to figure out how to retart the program)
          - `elif guess != CV `return a statement to the user to guess again 
            - Statement: 
              - Store the value guessed 
              - Return: "Guess again! Values guessed so far: [list of stored guess values]"
- Need to add warnings for out of range guesses 
  - not a number guesses 
