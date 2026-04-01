#include <iostream>
#include <string>
using namespace std;

struct TeamNode {
    int id;
    string name;
    string president;
    TeamNode* next;
};

struct PlayerNode {
    int id;
    string name;
    string teamName;
    string position;
    int age;
    double salary;
    PlayerNode* next;
};

class LeagueSystem {
private:
    TeamNode* teamHead;
    PlayerNode* playerHead;

public:
    LeagueSystem() {
        teamHead = NULL;
        playerHead = NULL;
    }

    void addTeam(int id, string name, string president) {
        TeamNode* newTeam = new TeamNode();
        newTeam->id = id;
        newTeam->name = name;
        newTeam->president = president;
        newTeam->next = NULL;

        if (teamHead == NULL) {
            teamHead = newTeam;
        } else {
            TeamNode* temp = teamHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newTeam;
        }
        cout << ">> Team added successfully!\n";
    }

    void displayTeams() {
        if (teamHead == NULL) {
            cout << ">> No teams found.\n";
            return;
        }
        TeamNode* temp = teamHead;
        cout << "\n--- Teams List ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << " | Name: " << temp->name 
                 << " | President: " << temp->president << endl;
            temp = temp->next;
        }
        cout << "------------------\n";
    }
 
    void searchTeamByID(int id) {
        TeamNode* temp = teamHead;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "\n>> Team Found:\n";
                cout << "Name: " << temp->name << ", President: " << temp->president << endl;
                return;
            }
            temp = temp->next;
        }
        cout << ">> Team with ID " << id << " not found.\n";
    }
  
    void addPlayer(int id, string name, string tName, string pos, int age, double sal) {
        PlayerNode* newPlayer = new PlayerNode();
        newPlayer->id = id;
        newPlayer->name = name;
        newPlayer->teamName = tName;
        newPlayer->position = pos;
        newPlayer->age = age;
        newPlayer->salary = sal;
        newPlayer->next = NULL;

        if (playerHead == NULL) {
            playerHead = newPlayer;
        } else {
            PlayerNode* temp = playerHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newPlayer;
        }
        cout << ">> Player added successfully!\n";
    }
   
    void removePlayer(int id) {
        if (playerHead == NULL) {
            cout << ">> List is empty.\n";
            return;
        }
       
        if (playerHead->id == id) {
            PlayerNode* toDelete = playerHead;
            playerHead = playerHead->next;
            delete toDelete;
            cout << ">> Player removed successfully.\n";
            return;
        }
       
        PlayerNode* temp = playerHead;
        while (temp->next != NULL && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << ">> Player ID not found.\n";
        } else {
            PlayerNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << ">> Player removed successfully.\n";
        }
    }
   
    void displayPlayers() {
        if (playerHead == NULL) {
            cout << ">> No players found.\n";
            return;
        }
        PlayerNode* temp = playerHead;
        cout << "\n--- Players List ---\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id << " | Name: " << temp->name 
                 << " | Team: " << temp->teamName << " | Pos: " << temp->position 
                 << " | Age: " << temp->age << " | Salary: " << temp->salary << endl;
            temp = temp->next;
        }
        cout << "--------------------\n";
    }
  
    void searchPlayerByName(string name) {
        PlayerNode* temp = playerHead;
        bool found = false;
        while (temp != NULL) {
            if (temp->name == name) {
                cout << "\n>> Player Found: " << temp->name << " plays for " << temp->teamName << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << ">> Player named " << name << " not found.\n";
    }
  
    void updatePlayerTeam(string playerName, string newTeamName) {
        PlayerNode* temp = playerHead;
        while (temp != NULL) {
            if (temp->name == playerName) {
                temp->teamName = newTeamName;
                cout << ">> Player " << playerName << " moved to " << newTeamName << " successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << ">> Player not found.\n";
    }

    void displayPlayersBySalary(string tName) {
        if (playerHead == NULL) {
            cout << ">> No players to sort.\n";
            return;
        }
      
        PlayerNode* i = playerHead;
        while (i != NULL) {
            PlayerNode* j = i->next;
            while (j != NULL) {
                
                if (i->salary < j->salary) {

                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->teamName, j->teamName);
                    swap(i->position, j->position);
                    swap(i->age, j->age);
                    swap(i->salary, j->salary);
                }
                j = j->next;
            }
            i = i->next;
        }
   
        cout << "\n--- Players of " << tName << " Ordered by Salary ---\n";
        PlayerNode* temp = playerHead;
        bool foundAny = false;
        while (temp != NULL) {
            if (temp->teamName == tName) {
                cout << "Name: " << temp->name << " | Salary: " << temp->salary << endl;
                foundAny = true;
            }
            temp = temp->next;
        }
        if (!foundAny) cout << ">> No players found for this team.\n";
        cout << "------------------------------------------\n";
    }
 
    double calculateAvgAge(string tName) {
        PlayerNode* temp = playerHead;
        double sum = 0;
        int count = 0;
        while (temp != NULL) {
            if (temp->teamName == tName) {
                sum += temp->age;
                count++;
            }
            temp = temp->next;
        }
        if (count == 0) return 0;
        return sum / count;
    }
 
    void displayTeamsByAvgAge() {
        if (teamHead == NULL) {
            cout << ">> No teams found.\n";
            return;
        }

        TeamNode* i = teamHead;
        while (i != NULL) {
            TeamNode* j = i->next;
            while (j != NULL) {
                if (calculateAvgAge(i->name) < calculateAvgAge(j->name)) {
                   
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->president, j->president);
                }
                j = j->next;
            }
            i = i->next;
        }

        cout << "\n--- Teams Ordered by Average Age ---\n";
        TeamNode* temp = teamHead;
        while (temp != NULL) {
            cout << "Team: " << temp->name << " | Avg Age: " << calculateAvgAge(temp->name) << endl;
            temp = temp->next;
        }
        cout << "------------------------------------\n";
    }

    void removeTeam(int id) {

        string teamName = "";
        bool found = false;

        
        TeamNode* tSearch = teamHead;
        while (tSearch != NULL) {
            if (tSearch->id == id) {
                teamName = tSearch->name;
                found = true;
                break;
            }
            tSearch = tSearch->next;
        }

        if (!found) {
            cout << ">> Team ID not found.\n";
            return;
        }
     
        if (teamHead->id == id) {
            TeamNode* toDel = teamHead;
            teamHead = teamHead->next;
            delete toDel;
        } else {
            TeamNode* temp = teamHead;
            while (temp->next != NULL && temp->next->id != id) {
                temp = temp->next;
            }
            TeamNode* toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
        cout << ">> Team (" << teamName << ") removed successfully.\n";
      
        bool deletedSomething = true;
        while (deletedSomething) {
            deletedSomething = false;
            PlayerNode* pTemp = playerHead;
            while (pTemp != NULL) {
                if (pTemp->teamName == teamName) {
                 
                    removePlayer(pTemp->id); 
                    deletedSomething = true;
                   
                    break; 
                }
                pTemp = pTemp->next;
            }
        }
        cout << ">> All players associated with (" << teamName << ") have been removed.\n";
    }

};

int main() {

    LeagueSystem sys;
    int choice;

    sys.addTeam(101, "Ahly", "Elkhatib");
    sys.addTeam(102, "Zamalek", "Labib");
    sys.addPlayer(1, "Shenawy", "Ahly", "GK", 34, 50000);
    sys.addPlayer(2, "Zizo", "Zamalek", "RW", 27, 60000);
    sys.addPlayer(3, "Imam", "Ahly", "CM", 25, 40000);
    sys.addPlayer(4, "Shikabala", "Zamalek", "AM", 37, 30000);

    do {

        cout << "\n=== Egyptian League System (Bonus Included) ===\n";
        cout << "1. Add Team\n";
        cout << "2. Display Teams\n";
        cout << "3. Search Team by ID\n";
        cout << "4. Add Player\n";
        cout << "5. Remove Player\n";
        cout << "6. Display Players\n";
        cout << "7. Search Player by Name\n";
        cout << "8. Update Player's Team\n";
        cout << "9. [Bonus] Show Team Players by Salary\n";
        cout << "10. [Bonus] Show Teams by Avg Age\n";
        cout << "11. [Bonus] Remove Team\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, age;
        double salary;
        string name, team, pos, pres;

        switch(choice) {

            case 1:
                cout << "Enter Team ID, Name, President: ";
                cin >> id >> name >> pres;
                sys.addTeam(id, name, pres);
                break;

            case 2:
                sys.displayTeams();
                break;

            case 3:
                cout << "Enter Team ID: ";
                cin >> id;
                sys.searchTeamByID(id);
                break;

            case 4:
                cout << "Enter Player ID: ";
                cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Team Name: "; cin >> team;
                cout << "Enter Position: "; cin >> pos;
                cout << "Enter Age: "; cin >> age;
                cout << "Enter Salary: "; cin >> salary;
                sys.addPlayer(id, name, team, pos, age, salary);
                break;

            case 5:
                cout << "Enter Player ID to remove: ";
                cin >> id;
                sys.removePlayer(id);
                break;

            case 6:
                sys.displayPlayers();
                break;

            case 7:
                cout << "Enter Player Name: ";
                cin >> name;
                sys.searchPlayerByName(name);
                break;

            case 8:
                cout << "Enter Player Name: ";
                cin >> name;
                cout << "Enter New Team Name: "; cin >> team;
                sys.updatePlayerTeam(name, team);
                break;
            
            case 9:
                cout << "Enter Team Name: ";
                cin >> team;
                sys.displayPlayersBySalary(team);
                break;

            case 10:
                sys.displayTeamsByAvgAge();
                break;

            case 11:
                cout << "Enter Team ID to remove: ";
                cin >> id;
                sys.removeTeam(id);
                break;

            case 0:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}