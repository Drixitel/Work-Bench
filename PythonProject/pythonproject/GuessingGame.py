# You now have The Guessing Game! 
# Simple & easy-to-use because it's just a bunch of  WHILE LOOPS and CONDITIONS!

# Made by a slow learner: Michelle Pichardo Munoz
# Date: 7/12/2022 
# Time completed: 8:00 PM


#Packages 
import numpy as np
import sys

#Initial Statements
 
introduction = f" \t\t\t~ Welcome to the Guessing Game ~ \n"
introduction += f'\t\tI will choose a number at random, and you will guess!'

rules_and_initial_ask = f'\nNICE!'
rules_and_initial_ask += f'\nAlright, I will pick a number between 0 and 10 inclusive.\n'
rules_and_initial_ask += f'If at anypoint you want to give up just type: quit'
rules_and_initial_ask += f'\n\nNow, what is your guess?\n'

#Exit Statements
Exit_by_quiting = f'Want to give up?\nType: quit'
Exit_by_nonplay = f'Do you wish to play? (Y/N)'
goodbye = f'Game Terminated. See you next time!'




# initiate the game
print(introduction)
status = 'ON'

while status != 'quit': 

    # Ask the user to play with Rule statement -(Y/N)
    print(Exit_by_nonplay)
    # Take input
    condition_to_play = input("Type: (Y/N)  ").upper()

    #Check input to continue game
    if condition_to_play == "N":
        #Leave the Game
        print(condition_to_play)
        status = 'quit'

    elif condition_to_play == "Y": 
        # continue game 
        print(condition_to_play) #prints Y

        #Tell the user how to play
        print(rules_and_initial_ask)
#-------------------------------------------------------------------------------------
        number_select = 'on'
        while number_select != 'off':

            #Computer selects a number
            computer_stored_value = []
            value = np.random.randint(0,11)
            value_strformat = str(value)
            computer_stored_value.append(value_strformat)

            #Delete once program is complete
            # print(f'The stored number is: {computer_stored_value[0]}')

#-------------------------------------------------------------------------------------

            #Game questioning begins 
            answer = 'incorrect'
            while answer != 'correct':
                
                #Ask the user for a number
                ask_for_number = input('Guess a number between [0,10]:  ').lower()


                #Conditions
                if ask_for_number == "quit":
                    print(ask_for_number)
                    number_select = 'off'
                    answer = 'correct'

                elif ask_for_number == computer_stored_value[0]: 
                    print(ask_for_number)

                    #Congradualtion's Statement 
                    correct = f"Congrats! You guessed my number! : {computer_stored_value[0]}"
                    print(correct)

                    #Ask to play again
                    print('\nCare to play again?')

#-------------------------------------------------------------------------------------

                    play_again_question = 'active'
                    while play_again_question != 'completed':
                        condition_to_play_again = input("Type: (Y/N)  ").upper()

                        if condition_to_play_again == 'N':
                            print(condition_to_play_again)
                            answer = 'correct'
                            number_select = 'off'
                            play_again_question ='completed'

                        elif condition_to_play_again == 'Y':
                            print(condition_to_play_again)
                            print('Sweet!\n Give me a sec to think ... ... ... ok guess!')
                            answer = 'correct'
                            play_again_question = 'completed'

                        else: 
                            print(condition_to_play_again)
                            print('That was not a valid entry.')
                            #should continue the loop

#-------------------------------------------------------------------------------------

                else:
                    #check if they gave a number 
                    is_this_a_number = ask_for_number.isdigit()
                    if is_this_a_number == True:
                        print(ask_for_number)
                        
                        #Statements for incorrect values
                        incorrect = f"{ask_for_number} is not my number. Try again."
                        incorrect1 = f"Nope! {ask_for_number} is not my number. Try agian."
                        incorrect2 = f"Woah, not even close! {incorrect}"
                        incorrect3 = f"Seems like this game might be too difficult for you? {incorrect}"
                        incorrect4 = f"Still no luck. {incorrect}"
                        incorrect5 = f'hmmmm... maybe I should have chosen between [0,5]?\n{incorrect}'
                        incorrect6 = f'I would give you a hint if I was programed to give hints.\n{incorrect}'
                        incorrect7 = f'\t\t\tYes! You got it!\n\n\n\n\n\nis what I would say if you chose correctly.\n{incorrect}'
                        fails_list = [incorrect, incorrect1, incorrect2, incorrect3, incorrect4, incorrect5, incorrect6, incorrect7, Exit_by_quiting]
                        print(fails_list[np.random.randint(0,9)])

                    elif is_this_a_number == False: 
                        print('This is not a valid entry. Try again.')
#-------------------------------------------------------------------------------------

        status = 'quit'
#-------------------------------------------------------------------------------------

    else: 
        print(condition_to_play)
        print('That was not a valid entry.')
        #While (status = quit) loop continues asking for a Y/N 


print(goodbye)




