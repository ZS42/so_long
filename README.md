# so_long



https://user-images.githubusercontent.com/82111543/215132140-a974e1a4-2222-47e7-ba44-66cd41ca375a.mov


<img width="1175" alt="so_long" src="https://user-images.githubusercontent.com/82111543/218946125-982b65a7-a567-47d7-8ef2-f2978a3826e8.png">

So_long was our first graphics project. In it, we had to make a 2D game using minilibx. This project helped us improve our skills in window management, event handling, colors, textures, etc. The rules were:
• The player’s goal is to collect every collectible present on the map, then escape
by choosing the shortest possible route.
• The W, A, S, and D keys must be used to move the main character.
• The player should be able to move in these 4 directions: up, down, left, and right.
• The player should not be able to move into walls.
• At every move, the current number of movements must be displayed in the shell.
• You have to use a 2D view (top-down or profile).
• The game doesn’t have to be real-time.
• Although the given examples show a dolphin theme, you can create the world you want.
If you prefer, you can use the arrow keys on your keyboard to move your main character.
• Your program has to display the image in a window.
• The management of your window must remain smooth (changing to another window, minimizing, and so forth).
• Pressing ESC must close the window and quit the program in a clean way.
• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
• The use of the images of the MiniLibX is mandatory.
• The map has to be constructed with 3 components: walls, collectibles, and free
space.
• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.
• The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.If the map contains a duplicate character (exit/start), you should display an error message.
• The map must be rectangular.
• The map must be closed/surrounded by walls. If it’s not, the program must return an error.
• You have to check if there’s a valid path in the map. I did this using a breath first search.
• You must be able to parse any kind of map, as long as it respects the above rules.
• If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.
There were bonus points for making the player lose when they touched an enemy patrol, adding some sprite animation, and displaying the movement count directly on the screen instead of writing it in the shell.














