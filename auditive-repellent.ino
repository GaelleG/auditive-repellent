struct HearingRange {
  char* species;
  long lo;
  long hi;
  bool enabled;
};

HearingRange HEARING_RANGE_LIST[] = {
  {'cow'               ,    23,  35000, false},
  {'cat'               ,    55,  77000, false},
  {'guinea pig'        ,    47,  49000, false},
  {'horse'             ,    55,  33500, false},
  {'human'             ,    31,  19000, false},
  {'dog'               ,    64,  44000, false},
  {'sheep'             ,   125,  42500, false},
  {'gerbil'            ,    56,  60000, false},
  {'albino rat'        ,   390,  72000, false},
  {'hooded rat'        ,   530,  75000, false},
  {'rabbit'            ,    96,  49000, false},
  {'mouse'             ,   900,  79000, false},
  {'little brown bat'  , 10300, 115000, false},
  {'chinchilla'        ,    52,  33000, false},
  {'elephant'          ,    17,  10500, false},
  {'sea lion'          ,   200,  50000, false},
  {'bottlenose dolphin',   150, 150000, false},
  {'human'             ,    64,  23000, false},
  {'dog'               ,    67,  45000, false},
  {'cat'               ,    45,  64000, false},
  {'cow'               ,    23,  35000, false},
  {'horse'             ,    55,  33500, false},
  {'sheep'             ,   100,  30000, false},
  {'rabbit'            ,   360,  42000, false},
  {'rat'               ,   200,  76000, false},
  {'mouse'             ,  1000,  91000, false},
  {'gerbil'            ,   100,  60000, false},
  {'guinea pig'        ,    54,  50000, false},
  {'hedgehog'          ,   250,  45000, false},
  {'raccoon'           ,   100,  40000, false},
  {'ferret'            ,    16,  44000, false},
  {'opossum'           ,   500,  64000, false},
  {'chinchilla'        ,    90,  22800, false},
  {'bat'               ,  2000, 110000, false},
  {'beluga whale'      ,  1000, 123000, false},
  {'elephant'          ,    16,  12000, false},
  {'porpoise'          ,    75, 150000, false},
  {'goldfish'          ,    20,   3000, false},
  {'catfish'           ,    50,   4000, false},
  {'tuna'              ,    50,   1100, false},
  {'bullfrog'          ,   100,   3000, false},
  {'tree frog'         ,    50,   4000, false},
  {'canary'            ,   250,   8000, false},
  {'parakeet'          ,   200,   8500, false},
  {'cockatiel'         ,   250,   8000, false},
  {'owl'               ,   200,  12000, false},
  {'chicken'           ,   125,   2000, false},
};
// source: https://commons.wikimedia.org/wiki/File:Animal_hearing_frequency_range.svg

int TONE_PIN = 8;
long TONE_DURATION = 1000;
unsigned long prevTime, elapsedTime, toneTimer = 0;
long toneRange[2];
long toneCurr;

void setup() {
  prevTime = millis();
  toneRange[0] = 20000;
  toneRange[1] = 77000;
  toneCurr = toneRange[0];
}

void loop() {
  elapsedTime = millis() - prevTime;
  prevTime = millis();
  toneTimer += elapsedTime;
  if (toneTimer >= TONE_DURATION) {
    toneTimer -= TONE_DURATION;
    toneCurr += 1000;
    if (toneCurr > toneRange[1]) toneCurr = toneRange[0];
    tone(TONE_PIN, toneCurr);
  }
}
