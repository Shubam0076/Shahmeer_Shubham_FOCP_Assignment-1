# include <iostream>
# include <cstdlib> // for rand() and srand()
# include <ctime> // For seed time(0)
using namespace std;
// Global variable
 int battery=100;
 int drain;
 int whether;
 bool obstacle;
 //Function Prototype
 void startday();
 int getwhether();
 bool checkobstacle();
 string delivarystatus();
 void displaySummary(int success, int failed, int delayed);

// The program starts here,       
int main(){ // Declartion+Intialization of record of Mission Summary 
  int success=0,  failed=0, delayed=0,score;
  char choice ;
  // Seed for random situations
  srand(time(0)); 
  // Function Calling
    startday();
  // Loops to complete delivery
    for(int i= 1;i<=3;i++){
      cout<<"Delivary # "<<i<<endl;
      cout<<delivarystatus()<<endl;
    if((rand()%10==0)||((whether==2)&&(battery<40))||(battery==0))failed++;
    else if(whether==3)delayed++;
    else success++;
    if(whether!=3){ battery-=drain;}
    cout<<endl;
  // Option to recharge after every delivary
    if(battery<50){
        cout<<"Would you like to recharge?"<<endl;
        cout<<"Press 'y' for recharing and Press 'n' for continue with same battery ";
        cin>>choice;
        if(choice=='y'){battery+=30;}
    }
}
    // Summary function calling
      displaySummary( success , failed, delayed);
    // Calculation of Performance
    score = success * 10 - (100 - battery);
    cout << "Performance Score: " << score << endl;
    // Closing Program
     cout<<endl<<"Thanks for using it ";
     return 0;
      
    }

// Function Definations
// Starting of day
void startday(){
           cout<<"Welcome to Drone simulation "<<endl;
           cout<<"Intial battery is 100% "<<endl;
           cout<<"Get ready to fly off ! "<<endl;
           cout<<"Please press 'Enter' to start this wonderful day "<<endl;
  cin.get(); // It proceeds ahead with "Enter" key
          cout<<"Here, you go "<<endl;
          cout<<endl;
          return;
        }

// whether condition
int getwhether(){
         return (rand()%3+1); //1==sunny,2==windy,3==rainy 
  }

// Obstacle inspection
  bool checkobstacle(){
         return (rand()%2); // 0==none,1==Yes
  } 
//Conditionals to display environmental info
 string  delivarystatus(){
// Whether
    whether=getwhether();
    if(whether==1) cout<<"Whether: The day is balmy today."<<endl;
    if(whether==2) cout<<"Whether: The day is breezy today."<<endl;
    if(whether==3) cout<<"Whether: The day is showery today."<<endl; 

// Obstacle
   obstacle=checkobstacle();
    if(obstacle==1)cout<<"Obstacle: Yes, Please be patient !"<<endl;
    if(obstacle==0)cout<<"Obstacle: None, Please Go ahead"<<endl;

// Battery Drain
     drain=rand()%16+10;//  battery drain (10 to 25)% per trip
    cout<<"Base Battery Drain : "<<drain<<" %"<<endl;

// Reaction to different circumstances 
     if(whether==3) {cout<<"Sorry, Flight cancelled...."<<endl;
          return "Delayed ! \n";}

    else if((whether==2)&&(battery<40)) {   battery+=10; cout<<" Battery low! Returning to the base....(Recharging)"<<endl;
          return "Failed \n";}

    else  if(obstacle==1) {drain+=5;
          cout<<"Obstacle found!"<<endl<<"Rerouting.... Extra battery drain(+5%)"<<endl;}

    else if (rand()%10==0){cout<<"Sudden System Malfunction!"<<endl<<"Warning!"<<endl;
          return "Failed! \n";}

    else cout<<"Delivery Successful"<<endl;
    return "Please come again \n ";
  }

// Mission Summary
   void displaySummary(int success, int failed, int delayed){
    cout<<"Mission Summary* "<<endl;
    cout<<"Total Deliveries: 3"<<endl;
    cout<<"Successful: "<<success<<endl;
    cout<<"Failed: "<<failed<<endl;
    cout<<"Delayed: "<<delayed<<endl;
    cout<<"Remaining Battery: "<<battery<<endl;
    return;
  }