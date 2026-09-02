```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int level = 1;

class Entity
{
private:
    string name;
    int health;
    int level;
    string type;

public:

    Entity()
    {
        name = "";
        health = 100;
        level = 1;
        type = "Player";
    }

    // Method chaining
    Entity& setName(const string& n)
    {
        name = n;
        return *this;
    }

    Entity& setHealth(int h)
    {
        health = h;
        return *this;
    }

    Entity& setLevel(int l)
    {
        level = l;
        return *this;
    }

    Entity& setType(const string& t)
    {
        type = t;
        return *this;
    }

    string getName() const
    {
        return name;
    }

    int getHealth() const
    {
        return health;
    }

    int getLevel() const
    {
        return level;
    }

    string getType() const
    {
        return type;
    }

    void displayInfo() const
    {
        cout << "Name: " << name
             << ", Type: " << type
             << ", Health: " << health
             << ", Level: " << level << endl;
    }
};


// Physics namespace
namespace Physics
{
    double clamp(double value, double min, double max)
    {
        if (value < min)
            return min;

        if (value > max)
            return max;

        return value;
    }

    double lerp(double a, double b, double t)
    {
        return a + t * (b - a);
    }
}


// GameMath namespace
namespace GameMath
{
    int clamp(int value, int min, int max)
    {
        if (value < min)
            return min;

        if (value > max)
            return max;

        return value;
    }

    double lerp(double a, double b, double t)
    {
        return a + t * (b - a);
    }
}


// Nested namespace
namespace Engine
{
    namespace Audio
    {
        void playSound(string name)
        {
            cout << "Playing sound: " << name << endl;
        }
    }
}


int main()
{
    srand(time(0));

    cout << "=== Method Chaining ===" << endl;

    Entity player;
    Entity enemy;
    Entity item;

    player.setName("Aragorn")
          .setHealth(100)
          .setLevel(10)
          .setType("Player");

    enemy.setName("Orc")
         .setHealth(60)
         .setLevel(5)
         .setType("Enemy");

    item.setName("HealthPotion")
        .setHealth(0)
        .setLevel(1)
        .setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();


    cout << "\n=== Namespace Example ===" << endl;

    cout << "Physics Clamp: "
         << Physics::clamp(12.5, 0.0, 10.0) << endl;

    cout << "GameMath Clamp: "
         << GameMath::clamp(45, 0, 100) << endl;

    {
        using namespace GameMath;

        cout << "Lerp value: "
             << lerp(10.0, 20.0, 0.5) << endl;
    }


    cout << "\n=== Dynamic 2D Game Map ===" << endl;

    int rows = 3;
    int cols = 4;

    int** gameMap = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        gameMap[i] = new int[cols];
    }

    // Filling the map with random values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            gameMap[i][j] = rand() % 5;
        }
    }

    cout << "\nGame Map:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << gameMap[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\n0 = Grass"
         << "\n1 = Water"
         << "\n2 = Mountain"
         << "\n3 = Forest"
         << "\n4 = Dungeon" << endl;


    int counts[5] = {0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int tile = gameMap[i][j];

            if (tile >= 0 && tile <= 4)
            {
                counts[tile]++;
            }
        }
    }

    cout << "\nTile Count:" << endl;
    cout << "Grass: " << counts[0] << endl;
    cout << "Water: " << counts[1] << endl;
    cout << "Mountain: " << counts[2] << endl;
    cout << "Forest: " << counts[3] << endl;
    cout << "Dungeon: " << counts[4] << endl;


    for (int i = 0; i < rows; i++)
    {
        delete[] gameMap[i];
    }

    delete[] gameMap;

    cout << "\nMemory released." << endl;


    cout << "\n=== Scope Resolution ===" << endl;

    int level = 5;

    cout << "Local level: " << level << endl;
    cout << "Global level: " << ::level << endl;


    Engine::Audio::playSound("sword_clash");

    return 0;
}

