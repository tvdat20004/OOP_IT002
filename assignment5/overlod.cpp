#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Character
{
public:
    string name;
    float hp;
    float atk;
    float def;
    Character(string name, float hp, float atk, float def) : name(name), hp(hp), atk(atk), def(def) {}
};

class Human : public Character
{
public:
    string job_class;
    Human(string name, float hp, float atk, float def, string job_class) : Character(name, hp, atk, def), job_class(job_class) {}
};

class Elf : public Character
{
public:
    string job_class;
    Elf(string name, float hp, float atk, float def, string job_class) : Character(name, hp, atk, def + def * 0.5), job_class(job_class) {}
};

class Orc : public Character
{
public:
    string racial_class;
    Orc(string name, float hp, float atk, float def, string racial_class) : Character(name, hp + hp * 0.5, atk, def), racial_class(racial_class) {}
};

class Goblin : public Character
{
public:
    string racial_class;
    Goblin(string name, float hp, float atk, float def, string racial_class) : Character(name, hp, atk + atk * 0.1, def), racial_class(racial_class) {}
};

class Vampire : public Character
{
public:
    Vampire(string name, float hp, float atk, float def, int human_count) : Character(name, hp + hp * 0.1 * human_count, atk, def) {}
};

class Devil : public Character
{
public:
    Devil(string name, float hp, float atk, float def, int devil_count) : Character(name, hp, atk + atk * 0.1 * devil_count, def + def * 0.1 * devil_count) {}
};

void simulate_battle(vector<Character *> guild_members, string boss_name, float boss_hp, float boss_atk, float boss_def)
{
    int n = guild_members.size();
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            if (guild_members[i]->hp > 0)
            {
                boss_hp -= max(0.0f, guild_members[i]->atk - boss_def);
            }
        }
        if (boss_hp <= 0)
        {
            // cout << "Guild wins" << endl;
            sort(guild_members.begin(), guild_members.end(), [](Character *a, Character *b)
                 { return a->hp < b->hp; });
            for (int i = 0; i < n; i++)
            {
                if (guild_members[i]->hp > 0)
                {
                    cout << guild_members[i]->name << " " << guild_members[i]->hp << endl;
                }
            }
            return;
        }
        int min_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (guild_members[i]->hp > 0)
            {
                if (min_index == -1 || guild_members[i]->hp < guild_members[min_index]->hp)
                {
                    min_index = i;
                }
            }
        }
        if (min_index == -1)
        {
            cout << boss_name << " " << boss_hp << endl;
            return;
        }
        guild_members[min_index]->hp -= max(0.0f, boss_atk - guild_members[min_index]->def);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Character *> guild_members(n);
    vector<int> types(n);
    vector<string> extra(n);
    int human_count = 0;
    int devil_count = 0;
    vector<float> hps(n), atks(n), defs(n);
    vector<string> names(n);

    for (int i = 0; i < n; i++)
    {
        cin >> types[i];
        cin >> names[i];
        cin >> hps[i] >> atks[i] >> defs[i];
        if (types[i] < 5) // If the character is not a Vampire or a Devil
        {
            cin >> extra[i]; // job_class or racial_class
        }
        if (types[i] == 1 || types[i] == 2)
        {
            human_count++;
        }
        else if (types[i] == 6)
        {
            devil_count++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (types[i] == 1)
        {
            guild_members[i] = new Human(names[i], hps[i], atks[i], defs[i], extra[i]);
        }
        else if (types[i] == 2)
        {
            guild_members[i] = new Elf(names[i], hps[i], atks[i], defs[i], extra[i]);
        }
        else if (types[i] == 3)
        {
            guild_members[i] = new Orc(names[i], hps[i], atks[i], defs[i], extra[i]);
        }
        else if (types[i] == 4)
        {
            guild_members[i] = new Goblin(names[i], hps[i], atks[i], defs[i], extra[i]);
        }
        else if (types[i] == 5)
        {
            guild_members[i] = new Vampire(names[i], hps[i], atks[i], defs[i], human_count);
        }
        else
        {
            guild_members[i] = new Devil(names[i], hps[i], atks[i], defs[i], devil_count);
        }
    }

    string boss_name;
    cin >> boss_name;
    float boss_hp, boss_atk, boss_def;
    cin >> boss_hp >> boss_atk >> boss_def;

    simulate_battle(guild_members, boss_name, boss_hp, boss_atk, boss_def);
    return 0;
}