# C++ Module 03 — Inheritance

A small robot "game" in C++98 to practise inheritance: `ClapTrap` → `ScavTrap` / `FragTrap` → `DiamondTrap`.

*This project was created as part of the 42 curriculum by jpflegha.*

## Exercises

| Exercise | Class | What it adds |
|:---|:---|:---|
| `ex00` | `ClapTrap` | Name, hit points (10), energy points (10), attack damage (0); `attack`, `takeDamage`, `beRepaired`. Attacking and repairing cost 1 energy point. |
| `ex01` | `ScavTrap : ClapTrap` | Own values (100 / 50 / 20), own constructor/destructor messages, `attack` override and `guardGate()`. |
| `ex02` | `FragTrap : ClapTrap` | Values 100 / 100 / 30 and `highFivesGuys()`. |
| `ex03` | `DiamondTrap : ScavTrap, FragTrap` | Diamond inheritance with **virtual inheritance**, so there is only one `ClapTrap` base; `whoAmI()` prints its own name and the `ClapTrap` name (`<name>_clap_name`). |

Each `main.cpp` plays a short fight with random damage and healing values, and the output is colored to show which class is acting and in which order constructors and destructors run.

## Key concepts

- Public inheritance, `protected` members, calling base constructors
- Constructor/destructor chaining order
- Overriding member functions
- Multiple inheritance, the diamond problem and `virtual` base classes

## Build and run

```bash
git clone https://github.com/jpfleghaar/CPP03.git
cd CPP03/ex03 && make && ./DiamondTrap
```

Example (`ex00`, values are random):

```
ClapTrap Bob is in the game!
Bob was attacked from! harl Energy: 9
Bob took 7 damage, HP: 3
Bob repaired to 9 HP: 9 Energy: 8
```

Program names: `ex00/ClapTrap`, `ex01/ScavTrap`, `ex02/FragTrap`, `ex03/DiamondTrap`. Each exercise has its own Makefile (`c++ -Wall -Wextra -Werror -std=c++98`).

## Project structure

```
ex00/  ClapTrap.{hpp,cpp}, main.cpp
ex01/  + ScavTrap.{hpp,cpp}
ex02/  + FragTrap.{hpp,cpp}
ex03/  + DiamondTrap.{hpp,cpp}
```

## What I learned

- Derived classes are built from the base up and destroyed in reverse order — the log output makes this visible.
- `protected` lets derived classes use base data without making it public.
- Without virtual inheritance, a diamond hierarchy contains two copies of the base class; with it, there is one shared base, which the most-derived class must construct.
