# Filler

Filler project is a game between two players. The main goal is capture opponent's territory.
In our case the oppenent is a bot. The virtual machine passes prepared gaming grid with initial positions of each player. It also passes randomly form token, which waiting to be placed on the grid. 

**There are some restrictions:**
- The token must overlap only one cell of ally player.
- The token cannot overlap enemy cells.
- The token cannot exceed boundaries of the grid.

The virtual machine receives coordinates of placed token and then rewrite the gaming grid with placed token.
The game stops when passed token cannot be placed and demonstrate the winner.

### Algorithm

The idea of algorithm is to place tokens close as possible to enemy cells and try to surround his area.
Creating heatmap is convenient way to realize the idea. Every empty cell of the grid assigns to digit.
This digit defines as minimum needed number of steps to reach this cell from any enemy positions.

![alt text](https://github.com/ITAlexey/Filler/blob/master/imgs/heat-map.png)

Second step is placing token according to restrictions. The best place of token is based on the minimum sum of empty cells.

![alt text](https://github.com/ITAlexey/Filler/blob/master/imgs/calculate-score.png)

### Usage
To compile run **make** and then
```
./filler_vm -p1 ./dshala.filler -p2./resources/players/[player_name].filler -f -v ./resources/map/map[0-2]
```
