# T01_G11


# GROUP MEMBERS: 
- Duarte Filipe Campos Barbosa Lopes
- Pedro Nuno Ferreira Moura de Macedo

# PROGRAM DEVELOPMENT STATE:
- All the objetives were accomplished!
- Improvements:
	. Movements table explaining what the user input should be to move the player
	. Ask the user if he wants to play again and restart

# MAIN DIFFICULTIES (Everything is currenty solved):
- **Robots' movement**:
	. When two robots collided, one died and the other was still alive
	. If a robot would die, the next one wouldn't move
- **Winner's File**:
	. Store the game time of the player in the file MAZE_XX_WINNERS.TXT neatly
	. If the time was higher than the ones already stored in the file it wouldn't insert in the last line
	. As the winner's file was getting bigger it would duplicate or triplicate the line when inserting it
- **Options**:
	. When the user would insert a valid option followed by another character, the program would read only the first character and assume as a valid input

WINNING COMBINATIONS:
- MAZE_01
	. D D D D W Q Z C D C D D D D
- MAZE_02
	. E E X A W X D C Z Q E S D D S S D E C D D W W W S S S S S S S
- MAZE_03
	. X Z Z Z Q A C X X S Z C S S S S S S
