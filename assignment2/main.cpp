#include <iostream>
# include <string>
#include <vector>

using namespace std;
class GameCharacter
{
/*public:visible inside the class and to the outside world.*/
/*private:can only be seen inside the class*/
/*protected:is valid in the case of inheritance*/
private:
	string m_Name;
    string m_Rank;
    string m_Gender;
	string m_Faction;

	unsigned int m_Score;
	unsigned short m_Health;
	unsigned short m_Level;
	unsigned short m_Strength;
	unsigned short m_Stamina;
	unsigned short m_Weapons;

	int m_Money;

	float m_Experience;


	vector<string>m_ValidRanks;
	void CreateRanks()
	{
		m_ValidRanks.push_back("Private");
		m_ValidRanks.push_back("Corporal");
		m_ValidRanks.push_back("Sargent");
		m_ValidRanks.push_back("Captain");
		m_ValidRanks.push_back("General");
		m_ValidRanks.push_back("Overlord");
	}
	vector<string>m_ValidFactions;
	void CreateFactions()
	{
		m_ValidFactions.push_back("Divergent");
		m_ValidFactions.push_back("Muggle");
	}
	//creating a function that transforms all user input into lower case.
	string ToLower(string text)
	{
		for (unsigned short i = 0; i < text.size(); i++)
		{
			text[i] = tolower(text[i]);
		}
		return text;
	}
	//methods: 
	//the one below is a constructor.
public:
	//Default Constructor always has no arguments
	GameCharacter()
	{
		//Initialize the 2 vectors
		CreateFactions();
		CreateRanks();
		//set default values
		m_Name = "";
		m_Rank = "Private";
		m_Gender = "";
		m_Faction = "Muggle";
		m_Score = 0;
		m_Health = 100;
		m_Level = 1;
		m_Strength = 100;
		m_Stamina = 500;
		m_Weapons = 1;
		m_Money = 0;
		m_Experience = 0.0f;
	}
	//overloaded constructor.
	GameCharacter( string name,
		           string rank,
				   string gender,
				   string faction,
				   unsigned int score,
				   unsigned short health,
				   unsigned short level,
				   unsigned short strength,
				   unsigned short stamina,
				   unsigned short weapons,
				   int money,
				   float experience)
	{
		CreateRanks();
		CreateFactions();
		m_Name = name;
		SetRank(rank);
		SetGender(gender);
		SetFaction(faction);
		SetScore(score);
		SetHealth(health);
		SetLevel(level);
		SetStrength(strength);
		SetStamina(stamina);
		SetWeapons(weapons);
		SetMoney(money);
		SetExperience(experience);
	}

	void OutputCharacter()
	{
		cout << "Name: \t\t" << m_Name << endl;
		cout << "Rank: \t\t" << m_Rank << endl;
		cout << "Gender: \t" << m_Gender << endl;
		cout << "Faction: \t" << m_Faction << endl;
		cout << "Score: \t\t" << m_Score << endl;
		cout << "Health: \t" << m_Health << endl;
		cout << "Level: \t\t" << m_Level << endl;
		cout << "Strength: \t" << m_Strength << endl;
		cout << "Stamina: \t" << m_Stamina << endl;
		cout << "Weapons: \t" << m_Weapons << endl;
		cout << "Money: \t\t" << m_Money << endl;
		cout << "Experience: \t" << m_Experience << endl << endl;
	}

	//Set Methods allow us to set integrity for our objects.
	//Name Set Method
	void SetName(string name){ m_Name = name; }
	//Rank Set Method
	void SetRank(string rank)
	{
		rank = ToLower(rank);
		rank[0] = toupper(rank[0]);
		for (unsigned short i = 0; i < m_ValidRanks.size(); i++)
		{
			if (rank == m_ValidRanks[i])
			{
				m_Rank = rank;
				break;
			}
			else
			{
				m_Rank = "Invalid Rank";
			}
		}

	}
	//Gender Set Method
	void SetGender(string gender)
	{
		gender = ToLower(gender);
		if (gender == "male" || gender == "female")
		{
			m_Gender = gender;
		}
		else if (m_Gender == "male" || m_Gender == "female")
		{
			return;
		}
		else
		{
			m_Gender = ":) New Gender!?!";
		}
	}
	//Faction Set Method
	void SetFaction(string faction)
	{
		for (unsigned short i = 0; i < m_ValidFactions.size(); i++)
		{
			faction = ToLower(faction);
			faction[0] = toupper(faction[0]);
			if (faction == m_ValidFactions[i])
			{
				m_Faction = faction;
				break;
			}
			else
			{
				m_Faction = "";
			}
		}

	}
	//Score Set Method
	void SetScore(unsigned int score)
	{
		if (score < 10, 000, 000)
		{
			m_Score = score;
		}
		else{
			m_Score = 0;
		}
	}
	//Health Set Method
	void SetHealth(unsigned short health)
	{ 
		if (health < 100)
		{
			m_Health = health;
		}
		else{
			m_Health = 10;
		}
		
	}
	//Level Set Method
	void SetLevel(unsigned short level)
	{ 
		if (level < 50)
		{
			m_Level = level;
		}
		else{
			m_Level = 1;
		}
	}
	//Strength Set Method
	void SetStrength(unsigned short strength)
	{
		if (strength > 0 && strength < 100)
		{
			m_Strength = strength;
		}
		else
		{
			m_Strength = 0;
		}	
	}
	//Stamina Set Method
	void SetStamina(unsigned short stamina)
	{
		if (stamina > 0 && stamina < 500)
		{
			m_Stamina = stamina;
		}
		else
		{
			m_Stamina = 0;
		}

	}
	//Weapons Set Method
	void SetWeapons(unsigned short weapons)
	{
		if (weapons > 1 && weapons < 10)
		{
			m_Weapons = weapons;
		}
		else
		{
			m_Weapons = 1;
		}

	}
	//Money Set Method
	void SetMoney(int money)
	{
		if (money > -1000, 000, 000 && money < 1000, 000, 000)
		{
			m_Money = money;
		}
		else
		{
			m_Money = 0;
		}
	}
	//Experience Set Method
	void SetExperience(float experience){
		if (experience < 100.0f)
		{
			m_Experience = experience;
		}
		else{
			m_Experience = 1.0f;
		}
	}
    //Get Methods
	string GetRank(){ return m_Rank; }
	string GetName(){ return m_Name; }
	string GetGender(){ return m_Gender; }
	string GetFaction(){ return m_Faction; }

	unsigned int GetScore(){ return m_Score; }
	unsigned short GetHealth(){ return m_Health;}
	unsigned short GetLevel(){ return m_Level; }
	unsigned short GetStrength(){ return m_Strength;}
	unsigned short GetStamina(){ return m_Stamina;}
	unsigned short GetWeapons(){ return m_Weapons; }

	int GetMoney(){ return m_Money; }

	float GetExperience(){ return m_Experience; }
	//Rank_Name Method
	string Rank_Name(string rank, string name)
	{
		string rankName = rank + " " + name;
		return rankName;
	}
};
  

int main(){
	//player 1
	GameCharacter player1;
	cout << "please enter your name: "; 
	string nameInput = "";
	cin >> nameInput;
	cout << "please enter your rank: ";
	string rankInput = "";
	cin >> rankInput;
	cout << "please enter your gender: ";
	string genderInput = "";
	cin >> genderInput;

	player1.SetName(nameInput);
	player1.SetRank(rankInput);
	player1.SetGender(genderInput);
	player1.Rank_Name(rankInput, nameInput);
	player1.OutputCharacter();
	
	//player 2
	GameCharacter player2;
	cout << "please enter your name: ";
	cin >> nameInput;
	cout << "please enter your rank: ";
	cin >> rankInput;
	cout << "please enter your gender: ";
	cin >> genderInput;

	player2.SetName(nameInput);
	player2.SetRank(rankInput);
	player2.SetGender(genderInput);
	player2.Rank_Name(rankInput, nameInput);
	player2.OutputCharacter();
	
	//player 3
	GameCharacter player3
	(   "Mark",
		"General",
		"male",
		"Divergent",
		20,
		80,
		9,
		60,
		433,
		3,
		2000545,
		20.3f
		) ;
	player3.Rank_Name("General", "Mark");
	player3.OutputCharacter();
	//Player 4
	GameCharacter player4(
		"Dalia",
		"Captain",
		"female",
		"Divergent",
		50,
		63,
		34,
		60,
		447,
		5,
		11904675,
		57.6f
		) ;
	player4.Rank_Name("Captain", "Dalia");
	player4.OutputCharacter();

	return 0;
}


















/*string s1 = "some text";
//s2 will copy s1. these are all samples of string constructors.
string s2(s1);
string s3 = s2;
string s4("somebody@her.com", 8);
string s5(200, '*');
cout << s4 << endl;
cout << s5 << endl;
return 0;*/