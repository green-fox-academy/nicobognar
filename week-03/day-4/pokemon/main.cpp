#include <iostream>
#include <vector>

#include "pokemon.h"


std::vector<Pokemon> initializePokemons()
{
    std::vector<Pokemon> pokemon;

    pokemon.push_back(Pokemon("Bulbasaur", "leaf", "water"));
    pokemon.push_back(Pokemon("Pikatchu", "electric", "water"));
    pokemon.push_back(Pokemon("Charizard", "fire", "leaf"));
    pokemon.push_back(Pokemon("Balbasaur", "water", "fire"));
    pokemon.push_back(Pokemon("Kingler", "water", "fire"));

    return pokemon;
}

int main(int argc, char* args[])
{
    std::vector<Pokemon> pokemonOfAsh = initializePokemons();

    // Every pokemon has a name and a type.
    // Certain types are effective against others, e.g. water is effective against fire.

    // Ash has a few pokemon.
    // A wild pokemon appeared!

    Pokemon wildPokemon("Oddish", "leaf", "water");
    std::string name;
    for (int i = 0; i < pokemonOfAsh.size(); ++i) {
        if (pokemonOfAsh.at(i).isEffectiveAgainst(wildPokemon)){
            name = pokemonOfAsh.at(i)._name;
        }
    }

    // Which pokemon should Ash use?

    std::cout << "I choose You, " << name << std::endl;
    return 0;
}