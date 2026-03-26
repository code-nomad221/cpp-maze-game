Maze Adventure Game (C++ Console Game)

A classic maze adventure survival game made using C++, featuring:

**Moving enemies**
Collectible items
Shooting mechanics
Health system
Key + exit puzzle
Lava hazards
Real-time keyboard input
Animated shooting effect

This game runs in the Windows console using <windows.h> and <conio.h>.

**Gameplay**

You play as a character trying to escape the maze.
Collect items, avoid enemies, and find the key to unlock the exit.
########################
#K      #        E    X#
# ####  #   #######    #
#      L#              #
#  #######     ######  #
#        #             #
#   G    #      E      #
#        #######       #
#   L                 ##
#        K             #
#                     ##
########################
**Controls**
| Key | Action |
| ----- | ------------------------------ |
| **W** | Move Up |
| **A** | Move Left |
| **S** | Move Down |
| **D** | Move Right |
| **F** | Shoot (only if you have a gun) |
| **Q** | Quit the game |

**Objectives**

-> Collect the key (K) to unlock the final exit
-> Collect the gun (G) to shoot enemies
-> Avoid lava (L) — it damages health
-> Avoid enemies (E) — they chase or patrol
-> Escape through the exit (X)

**Hazards & Items**
| Symbol | Meaning | Effect |
| ------ | ------------ | ----------------------- |
| **#** | Wall | Blocks movement |
| **K** | Key | Unlocks exit |
| **G** | Gun | Enables shooting |
| **L** | Lava | -20 health |
| **E** | Enemy | Touch = -10 health |
| **X** | Exit | Win if you have the key |
| **p** | Player | You |
| **\*** | Bullet Trail | Appears when shooting |

**Losing Condition**

You lose the game if:
health <= 0

**Winning Condition**

Reach X with the key, and you win:
"You opened the exit and won the game. Congratulations!"

**Features Implemented**
-> Smooth movement using _kbhit() + _getch()

No need to press ENTER — real-time input.

-> Enemy AI (patrolling enemies)
Enemy 1 moves left
Enemy 2 moves right
Both reset positions when reaching limits
-> Shooting Animation

Bullet moves until hitting:

Wall
Enemy (enemy dies)
-> Health System

Displayed every frame.

-> Inventory System
Key (to exit)
Gun (to shoot)

-> Fully animated console redraw
Using:
system("cls");

**Code Structure**
drawmaze() — draws the maze on every frame
movePlayer() — handles movement + collisions
moveEnemy() — enemy patrol logic
shoot() — bullet animation
declarations() — HUD (health, items)
main() — game loop

**Requirements**
Windows OS
C++ compiler (MinGW / MSVC / g++)
Console must support Unicode if emojis are used
