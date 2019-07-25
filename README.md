# Fillit

**Fillit** is a project that familiarize us with a recurring problematic
in programming: **searching the optimal solution** among a huge set of
possi-bilities, **in a respectable timing**.

![tete](https://user-images.githubusercontent.com/45558274/61868506-2e0da980-aee2-11e9-83a9-80c45abfbe44.png)

In this particular project, I have to find a way to assemble a given ***Tetriminos**
set in the smallest possible square.

A ***Tetriminos** is a 4-blocks geometric figure you probably already heard of, thanks tothe popular game Tetris.

## Description

Program take a file as parameter, which contains a list of **Tetriminos**, and arrange them in order
to create the smallest square possible. Obviously, main goal is to find the smallest square in the minimal amount of time,
despite an exponentially growing number of possibilities each time a piece is added.

The description of a **Tetriminosmust respect the following rules**:
- Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
- A Tetrimino is a classic piece of Tetris composed of 4 blocks.
- Each character must be either a block character `#` or an empty character `.`.
- Each block of a Tetriminomust touch at least one other block on any of his 4 sides (up, down, left and right).


A few **examples of valid** descriptions of Tetriminos:

```
....   ....   ####   ....   .##.   ....   .#..   ....   ....
..##   ....   ....   ....   ..##   .##.   ###.   ##..   .##.
..#.   ..##   ....   ##..   ....   ##..   ....   #...   ..#.
..#.   ..##   ....   ##..   ....   ....   ....   #...   ..#.
```
**No rotation** is possible.

**Prrogram** must display the smallest assembled square on the standard output.

**Each** Tetrimino will assign a **capital letter**, starting with `A` and increasing for each one.

**Examples:**

 <p align="center"><img width="612" alt="Снимок экрана 2019-07-25 в 22 13 30" src="https://user-images.githubusercontent.com/45558274/61903786-0a705080-af2e-11e9-9c96-772ead9cd0ce.png"></p>

## Installation

```
git clone git@github.com:lmaron-g/fillit.git; cd fillit; make
```

## Run

```
./fillit samples/test7
```

### Simple usage:

`./fillit input_file`
