
volatile int trainingPhase=1; 
volatile int odor1cond=0; int odor2cond=0; int odor3cond=0; int odor4cond=0;  //First digit indicates NoGo or Go, second Stim or NoStim
volatile int numOdors=1;
volatile int soundcond=10;      //first digit is correct trials, second incorrect. 0: no sound; 1:beep; 2:buzz; 3:sound. For example 33: sound for all trials; 30:sound for correct, nothing for incoorect
volatile float waitforEntry=5000; 
volatile float settleTime=300; 
volatile float odorSettleTime=700; 
volatile double cuePeriod=200; 
volatile double getOffPeriod=2200; 
volatile double maxRespTime=1500; 
volatile float minLickDuration=1000; 
volatile double rewardDuration=100; 
volatile double beepPeriodShort=30; 
volatile double feedbackPeriod=200; 
volatile double durLaser=1000; 
volatile float durPulses=25; 
volatile float freqLaser=20; 
volatile double punishment=2500; 
volatile double iti=1000; 
volatile float minWaitPeriod=100;
volatile float maxWaitPeriod=1000; 
volatile float stepWaitPeriod=50; 
volatile double dt4Video=2000; 
volatile double dtBlank=200;
volatile double beepWaterInt=feedbackPeriod-rewardDuration;


// These are not in the gui
volatile int incrementInBlocksOf=10;  // in number of trials
volatile int correctSoFar=0; // number of correct trials
volatile int extraWaitTime=100;

