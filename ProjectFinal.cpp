//A drone simulation project that manages autonomous flight dynamics and control systems in virtual environments.
# include <iostream>
#include <windows.h> // For Sleep on Window
# include <cstdlib> // for rand() and srand()
# include <ctime> // For seed time(0)
using namespace std;
// -----------------Global variable---------------------
 int battery=100;
 int baseDrain=0;
 int extraDrain=0;
 int netDrain=0;
 int whether;
 bool obstacle;
// -----------------Function Prototype---------------------
 void startDay();
 int getWhether();
 bool checkObstacle();
 string delivaryStatus();
 void displaySummary(int success, int failed, int delayed,int declined);
 void glitterDot(int dot,int delay);
 void rechargeBattery(char choice);

 // -----------------Main Function---------------------   
int main(){ 
  // Declartion+Intialization of record of Mission Summary 
  int success=0,  failed=0, delayed=0, declined=0, score, permit;
  float weight;
  char choice;
  // Seed for random situations
  srand(time(0));
  // Function Calling
    startDay();
  // Loops to complete delivery after every it is being asked about Accpetance and Rejections
    int i=1;
    while(i<=3){
      cout<<"Delivery to location to "<<(char)(i+64)<<endl;
      cout<<"Please Enter 1 to deliver this package and Enter -1 to decline the order: ";
      cin>>permit;

      if(permit==-1){
         // Increament in decline count
          declined++;
          cout<<endl;
          cout<<"--------------------------------------------------------------------"<<endl;
          cout<<"Declining the order";
                                   glitterDot(3,300 );
                                     cout<<"\r";// Overwrites the statement in the same line
          cout<<"                    Order Declined Successfully"<<endl;
          cout<<"--------------------------------------------------------------------"<<endl<<endl;
          i++;
          continue;
        
      }
      else if(permit==1){
      cout<<endl;
      // Rechecking of Battery
      if(battery<=10){
        cout<<"Insuffient battery!"<<endl;
        cout<<"Enter 'y' to recharge or 'n' to skip the delivery";
        cin>>choice;
        if(choice=='y'){
           rechargeBattery(choice);
        }

        else{
          cout<<"Delivery Skipped"<<endl;
          failed++;
          i++;
          continue;
        }

      }
      // Reset drain = 0 after every delivery 
      baseDrain=0;
      extraDrain=0;
      netDrain=0;
      // Prompt user to tell the drone about weight of package 
      cout<<"Enter the weight of Package in (Gram) from (1 to 2000) : ";
      cin>>weight;
      if((weight>700)&&(weight<=2000)){
      cout<<"It is overloaded, so it may consume little more battery"<<endl;
      extraDrain+=10; 
      }
      else if (weight<=0){
        cout<<"Invalid Input"<<endl<<"Please Give Valid input of weight "<<endl;
        continue;
      }
      else if(weight>2000){
        cout<<"It can't carry so heavy load"<<endl<<"Please unload some weight"<<endl;
        continue;
      }
      else{
        cout<<"Package Loaded"<<endl<<"Ready to dispatch the package "<<endl;
      }
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Preparing to take off";
        glitterDot(3,300 );
        cout<<"\r"; // Overwrites the statement in the same line
        cout<<"                      Ready to take off"<<endl;   
        cout<<"--------------------------------------------------------------------"<<endl<<endl;
        cout<<"FlightCheck";
        glitterDot(3,3000);
        cout<<"\r";// Overwrites the statement in the same line
        }
      else{
        cout<<"ERROR 404"<<endl;
        continue;
      }
  // Calling delivery info
       string result=delivaryStatus(); 
  // Checking Delivary status
    if(result=="Failed due to low battery and rough weather\n"||result=="Failed due to systematic fault\n"){
       failed++;
      }
    else if(result=="Delayed\n"){
       delayed++;
      }
    else{ 
      success++;
    }
  // Battery Remianing calculator. It will drain battery in every case except weather delay
    if(whether!=3){
      battery-=netDrain;
      if(battery<0){
         battery=0;
      }
    } 
    // Emergency auto recharge if battery is fully drained
    if (battery == 0) {
    cout << "Battery completely drained!" << endl;
    cout << "Drone entering emergency recharge mode..." << endl;
    rechargeBattery('y');
}

    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"                        Battery = "<<battery<<"%"<<endl;                          
    cout<<"--------------------------------------------------------------------"<<endl<<endl;

  // Recharge battery after delivery
    if(battery<100){
      cout<<"Would you like to recharge the drone? "<<endl;
      cout<<"Please Press 'y' to recharge or Press 'n' to continue :  ";
      cin>>choice;
    if(choice=='y'){
      rechargeBattery(choice);
    }
      
    
    else if(choice=='n'){
      cout<<endl;
     }
      cout<<endl;
      i++;
    }
  
    }
  // Mission Summary Evalution
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"Evaluating Performance";
        glitterDot(5,1000 );
        cout<<"\r"; // Overwrites the statement in the same line
        cout<<"                          MISSION SUMMARY"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl<<endl;
  // Summary function calling
      displaySummary( success , failed, delayed,declined);
  // Performance calculator to inspect the drone One success= 30 points
      score = (success * 15) - (100 - battery);
      cout << "Performance Score : " << score <<" Points"<< endl;
      if(score>0){
        cout<<"Congrats, The drone performance was admireable. "<<endl<<endl;
       }
      else if (score==0){
        cout<<"The Drone is just fine."<<endl<<endl;
      } 
      else {
        cout<<"Alas!, It's performance was very concerning!"<<endl<<endl;
      }
  // Program Closing   
      cout<<"\t**********************************************************************"<<endl;
      cout<<"                                     THANK YOU"<<endl;
      cout<<"\t**********************************************************************";
      return 0;
      
    }
// -----------------Function Defination---------------------
  // Glittering of stars with delay 
void glitterDot(int dot,int delay ){
          for(int i=1;i<=dot;i++){
          cout<<"."<<flush;
          Sleep(delay);// it delays the next output on console 
          }
}  
    // Starting of day
void startDay(){
           cout<<endl;
           cout<<"Loading, Please Wait";
           glitterDot(4,300);
           cout<<"\r";// Overwrites the statement in the same line
           cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
           cout<<"                                                Welcome to Drone Simulation "<<endl;
           cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
           cout<<"Intial battery is 100% "<<endl;
           cout<<"Get ready to fly off ! "<<endl;
           cout<<"Please press 'Enter' to start this wonderful day "<<endl;
           // It proceeds ahead with "Enter" key
           cin.get();
           cout<<"Here, you go "<<endl;
           cout<<endl;
           return;
        }

  // whether condition
         int getWhether(){
         return (rand()%3+1); //1==sunny,2==windy,3==rainy 
  }

  // Obstacle inspection
         bool checkObstacle(){
         return (rand()%2); // 0==none,1==Yes
  } 
  //Conditionals to display environmental info
        string  delivaryStatus(){
    // Whether
        whether=getWhether();
        if(whether==1) cout<<"Whether: The day is sunny today."<<endl;
        if(whether==2) cout<<"Whether: The day is breezy today."<<endl;
        if(whether==3) cout<<"Whether: The day is showery today."<<endl; 

    // Obstacle
       obstacle=checkObstacle();
       if(obstacle==1)cout<<"Obstacle: Yes, Please be patient and careful !"<<endl;
       if(obstacle==0)cout<<"Obstacle: None"<<endl;

    // Battery Drain
       baseDrain+=rand()%16+10;//  battery drain (10 to 25)% per trip
       if(obstacle==1) extraDrain+=5; //Extra Drain 
       netDrain=baseDrain+extraDrain;
       cout<<"Base Battery Drain : "<<baseDrain<<" %"<<endl;
       cout<<"Extra Battery Drain : "<<extraDrain<<" %"<<endl;
       cout<<"Net Battery Drain : "<<netDrain<<" %"<<endl;
    // Reaction to different circumstances 
       if(whether==3) {cout<<"Flight impacted by local weather – rescheduling in progress ";
       glitterDot(4,500);
       cout<<"\r"<<string(70,' ')<<"\r"; // Overwrites the statement in the same line with 70 spaces
       cout<<"Raining !"<<endl;

       return "Delayed\n";}

       else if((whether==2)&&(battery<40)) {
       cout<<"Drone may crash these condition"<<endl;
       cout<<"Returning to the base";
       glitterDot(3,500 );
       cout<<"\r"; // Overwrites the statement in the same line
       cout<<"Returned Successfully"<<endl;
       return "Failed due to low battery and rough weather\n";}

       else  if(obstacle==1) {
       cout<<"Obstacle found!"<<endl;
       cout<<"Rerouting";
       glitterDot(3,500 );
       cout<<"\r"; // Overwrites the statement in the same line
       cout<<"Route changed \nIt may lead to extra battery drain"<<endl;}

      else if (rand()%10==0){ 
      cout<<" Critical Error Landing Immediately ";
      glitterDot(4,200);
      cout << "\r" << string(70, ' ') << "\r"; // Overwrites the statement in the same line with 40 spaces
      cout<<"Sudden System Malfunction!"<<endl<<"Warning!"<<endl;
      return "Failed due to systematic fault\n";
    }

      else cout<<"Paracel Delivered";
      return "Successfully\n";
  }

 // Mission Summary
     void displaySummary(int success, int failed, int delayed,int declined){
     cout<<"Total Deliveries: 3"<<endl;
     cout<<"Declined: "<<declined<<endl;
     cout<<"Successful: "<<success<<endl;
     cout<<"Failed: "<<failed<<endl;
     cout<<"Delayed: "<<delayed<<endl;
     cout<<"Remaining Battery: "<<battery<<endl;
     return;
  }
  void rechargeBattery(char choice){

     if(choice=='y'){
      cout<<"Recharinging";
      glitterDot(5,5000 );
      cout<<"\r"; // Overwrites the statement in the same line
      cout<<"Recharged, Battery is full."<<endl;
      battery=100;
      cout<<"--------------------------------------------------------------------"<<endl;
      cout<<"                        Battery = "<<battery<<"%"<<endl;                          
      cout<<"--------------------------------------------------------------------"<<endl<<endl;
     }

  }  