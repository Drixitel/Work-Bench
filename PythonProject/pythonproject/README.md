# The Guessing Game - Information 

- Overview: 
  - The computer randomly selects a number between [0,10] inclusive. The user inputs values until the correct number is chosen or until the user gives up. 

# Mechanics 
- 4 While loops and several conditions 
- Introduce the game with a print statement outside of the while loop. 
- `WHILE - 1`: 
  - This loop will keep the game running so long as `status != "quit"` 
  - This loop has one `asking input` and `3 conditions`
    - `asking input`: Does the user wish to play: Y/N/invalid  
    - if No- Break
    - if invalid - loop again 
    - if yes continue into the next while loop 
- `WHILE - 2`: 
  - This loop will allow the computer to randomly generate a number and store it for comparison testing. It will break if `input_number == "off"`.
  Following this, the user moves into the while loop to check for the correct ansqwer. 
- `WHILE - 3`: 
  - This loop has one `asking input` and `3 conditions` and ends when `answer == "correct"`
    - `asking input`: Guess a number [0,10]
    - if the user wants to give up they type `quit`, causing several breaks in the loops to end the game. 
    - if the input is wrong the value is checked. If it is a number it will prompt a random `incorrect statement`. If it is not a number it will prompt an `error message` and loop the question again. 
    - if the input is correct. The user gets a `congradulations statement` and is moved into the next while loop. 
- `WHILE - 4`: 
  - This loop checks if the user wants to play again. 
  - This has an `asking input` and `3 conditions`. Breaks when `play_again_question == "completed"`.
    - `asking input`: Y/N/Invalid (play again?)
      - if N several breaks occur to exit the game 
      - if invalid the loop repeats until a valid option is selected 
      - if Y several breaks occur: 
        -  `play_again_question == "completed"`
        -  `answer == "correct"`
        - but `input_number != "off"` and the computer will guess a new number, replacing the old one and continue into game until the user quits or selects NO in a prompt. 
- Once all the while loops are broken, display the Goodbye statement. 
# Additions 
- Each wrong answer recieves a unique and random `incorrect response`
# Future Potentials 
- Store the number given by the user and let them know if they've already selected a previous number. 
- Add more interactive templates 
- adjust how long it takes the program to respond. 
  - currently instaneous 
  - would be nice to slow it down to make it seem as tho the computer is thinking. 