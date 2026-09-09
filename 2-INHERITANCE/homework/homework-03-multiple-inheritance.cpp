#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Project {
    private:
    string ProjectName;
    public:
    Project(){
        ProjectName = "unknown";
    }
    Project(string ProjectName){
        this ->ProjectName = ProjectName;
    }
    string getProject(){
        return ProjectName;
    }
};
class TeamMember {
    private:
    string TeamMemberName;
    public:
    TeamMember(){
        TeamMemberName = "unknown";
    }
    TeamMember(string TeamMemberName){
        this -> TeamMemberName = TeamMemberName;
    }
    string getTeamMember(){
        return TeamMemberName;
    }
};

class Task {
    private:
    string TaskName;
    public:
    Task(){
        TaskName = "unknown";
    }
    Task(string TaskName){
        this -> TaskName = TaskName;
    }
    string getTask(){
        return TaskName;
    }
    
};

class ProjectTeamMember : public Project, public TeamMember {
    public:
    ProjectTeamMember(string Pname , string TMname) : Project(Pname) , TeamMember(TMname){
    }
    string displayProjectTeamMember(){
        cout << "Project Name: " << getProject() <<endl;
        cout << "Team Member Name: " << getTeamMember() <<endl;
    }
    
};

class TeamMemberTask : public TeamMember, public Task {
    public:
    TeamMemberTask(string TMname , string Tname) : TeamMember(TMname) , Task(Tname){
    }
    string displayTeamMemberTask(){
        cout << "Team Member Name: " << getTeamMember() << endl;
        cout << "Task Name: " << getTask() <<endl;
    }
};
int main() {

    system("cls");

    ProjectTeamMember ptm("Project X", "Alice");
    TeamMemberTask tmt("Bob", "Code Review");

    cout << "Project Team Member Information:" << endl;
    ptm.displayProjectTeamMember();

    cout << "\nTeam Member Task Information:" << endl;
    tmt.displayTeamMemberTask();


    return 0;
}
